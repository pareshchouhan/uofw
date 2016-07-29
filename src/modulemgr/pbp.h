/* Copyright (C) 2011 - 2015 The uOFW team
   See the file COPYING for copying permission.
*/

#include "common_header.h"

/**
 * A PSP Boot Package (PBP) - such as EBOOT.PBP - is used to distribute PSP applications, i.e. game software.
 * It contains a PSP system file (PARAM.SFO), content information files (ICON0.PNG, ICON1.PMF, PIC0.PNG,
 * PIC1.PNG, SND0.AT3) and files containing executable and linking information (DATA.PSP, DATA.PSAR).
 *
 * Content information files include data used in the display of games/applications and save data by the 
 * system software. The displayed data includes icon graphics, description graphics, background music, 
 * and the title name.
 *
 * For more information about the above listed files, check the following document in the uPSPD wiki: TODO
 */

/*
 *  PBP file layout: 
 *
 * +--------------------------------------------+
 * |             PBP header (40 Byte)           |
 * |--------------------------------------------|
 * |            PSF header (20 Byte)            |
 * |--------------------------------------------|
 * |          PSF keyInfo (n x 16 Byte)*        |
 * | (*)n > 0; depends on the application type  |
 * |--------------------------------------------|
 * |           n x Keys & n x Values *          |
 * |      (*)size depends on the used keys      |
 * |--------------------------------------------|
 * |    Content information files (if any)*     |
 * |                (*)size >= 0                |
 * |--------------------------------------------|-------------------
 * |      SCE Header (64 Byte) (optional)       |                   |
 * |--------------------------------------------|                   |
 * |            PSP header (336 Byte)*          |                   |    
 * |   (*)ONLY for encrypted/compressed files   |                   |
 * |--------------------------------------------|                DATA.PSP
 * |            ELF header (52 Byte)            |                   |
 * |--------------------------------------------|                   |
 * |            Rest of ELF file                |                   |
 * |--------------------------------------------|-------------------
 * |            PSAR header (optional)          |                   |
 * |--------------------------------------------|               DATA.PSAR
 * |              PSAR data (if any)            |                   |
 * +--------------------------------------------+-------------------
 *
 *
 */

/* Identifies a file as a .PBP file. */
#define PBP_MAGIC       (0x00504250) /* " PBP" */

/*
 * This structure represents the .PBP header.
 *
 * If an application does not have any specified content information files,
 * the members icon0Off to snd0Off can be filled with default values.
 */
typedef struct {
    /* PBP magic value. */
    u8 magic[4]; // 0
    /* PBP header version. */
    u32 version; // 4
    /* The PARAM.SFO file offset in bytes. */
    u32 paramOff; // 8
    /* The ICON0.PNG file offset in bytes. */
    u32 icon0Off; // 12
    /* The ICON1.PMF file offset in bytes. */
    u32 icon1Off; // 16
    /* The PIC0.PNG file offset in bytes. */
    u32 pic0Off; // 20
    /* The PIC1.PNG file offset in bytes. */
    u32 pic1Off; // 24
    /* The SND0.AT3 file offset in bytes. */
    u32 snd0Off; // 28
    /* The DATA.PSP file offset in bytes. */
    u32 dataPSPOff; // 32
    /* The DATA.PSAR file offset in bytes. */
    u32 dataPSAROff; // 36
} PBPHeader; // size = 40

/* Identifies a file as a PARAM.SFO file. */
#define PSF_MAGIC       (0x00505346) /* " PSF" */

/**
 * This structure represents the PARAM.SFO (PSF) header.
 *
 * The .SFO header belongs to the PARAM.SFO file, a system file which stores 
 * parameters used for display by the PSP system software, such as the game title,
 * user age restriction value, etc., as well as parameters used internally, such as 
 * the product number or the disc serial number. The required parameters depend on 
 * the type of the executable file (i.e. game, video, audio).
 */
typedef struct {
    /** PSF magic value. */
    u8 magic[4];
    /** PSF header version. */
    u32 version;
    /** File offset in bytes to the table containing the used keys. */
    u32 keyTableOffset;
    /** File offset in bytes to the table containing the values for the used keys. */
    u32 dataTableOffset;
    /** The number of keys used in the file. */
    u32 numKeys;
} PSFHeader;

typedef struct {
    /** Offset relative to start of the keyTable (in bytes). Directs to a key. */
    u16 keyOffset;
    /** Type of the value of the key specified by <keyOffset>. */
    u16 valueFmt;
    /** Actual length of the value of the key specified by <keyOffset>. */
    u32 valueLen;
    /** Maximum length of the value of the key specified by <keyOffset>. */
    u32 valueMaxLen;
    /** 
     * Offset relative to start of the dataTable (in bytes). Directs to the value of the key
     * specified by <keyOffset>.
     */
    u32 valueOffset;
} PSFKeyInfo;

/** PSF Keys */

#define PSF_KEY_APP_VER                 "APP_VER"           /** Version of the application or patch. */
#define PSF_KEY_ATTRIBUTE               "ATTRIBUTE"
#define PSF_KEY_BOOTABLE                "BOOTABLE"          /** Whether or not the application is bootable. */
#define PSF_KEY_DISC_ID                 "DISC_ID"           /** Product number. */
#define PSF_KEY_CATEGORY                "CATEGORY"          /** System file category. */
#define PSF_KEY_DISC_NUMBER             "DISC_NUMBER"       /** Disc number within a disc set. */
#define PSF_KEY_DISC_TOTAL              "DISC_TOTAL"        /** The total number of discs in a disc set. */
#define PSF_KEY_DISC_VERSION            "DISC_VERSION"      /** The disc version. Format X.YZ (X,Y,Z: 0-9). */
#define PSF_KEY_DRIVER_PATH             "DRIVER_PATH"       /** Pathname of the device driver. */
#define PSF_KEY_GAMEDATA_ID             "GAMEDATA_ID"       /** Identifier used in place of the product number to allow patch sharing. */
#define PSF_KEY_HRKGMP_VER              "HRKGMP_VER"
#define PSF_KEY_MEMSIZE                 "MEMSIZE"           /** Add extra RAM for application (not for PSP-100X). */
#define PSF_KEY_PARENTAL_LEVEL          "PARENTAL_LEVEL"    /** Restriction level for applications. */
#define PSF_KEY_PBOOT_TITLE             "PBOOT_TITLE"       /** Patch title name. */
#define PSF_KEY_PSP_SYSTEM_VER          "PSP_SYSTEM_VER"    /** PSP system software version required to execute the application. */
#define PSF_KEY_REGION                  "REGION"            /** The region of the PSP hardware where the application can be executed. */
#define PSF_KEY_TARGET_APP_VER          "TARGET_APP_VER"
/** 
 * Title of the application (default language). USE "TITLE_XY" (X,Y:0-9) for every other
 * instance of translated title. 
 */
#define PSF_KEY_TITLE                   "TITLE"
#define PSF_KEY_UPDATER_VER             "UPDATER_VER"       /** The version of the updater. */
#define PSF_KEY_USE_USB                 "USE_USB"           /** Indicates whether or not the USB accessory is used. */

/** PSF Values */

#define PSF_VALUE_CATEGORY_APPS                     "MA" /** category: Memory Stick application */
#define PSF_VALUE_CATEGORY_PS1_GAME                 "ME" /** category: PS1 game */
#define PSF_VALUE_CATEGORY_MS_GAME                  "MG" /** category: Memory Stick game */
#define PSF_VALUE_CATEGORY_SAVEDATA                 "MS" /** category: Save data for games & applications */
#define PSF_VALUE_CATEGORY_PATCH_GAME               "PG" /** category: Patch for a game */
#define PSF_VALUE_CATEGORY_UMD_GAME                 "UG" /** category: UMD game */
#define PSF_VALUE_CATEGORY_WLAN_GAME                "WG" /** category: External bootable binary */
#define PSF_VALUE_CATEGORY_SYSTEM_SOFTWARE_UPDATE   "MSTKUPDATE" /** category: System Software update */

#define PSF_VALUE_TITLE_MAX_LEN         (128) /* Including '\0'. */
#define PSF_VALUE_PBOOT_TITLE_MAX_LEN   (128) /* Including '\0'. */

/* Parental lock level - Lower level means less restrictions. */
#define PSF_VALUE_PARENTAL_LEVEL_0      (0)
#define PSF_VALUE_PARENTAL_LEVEL_1      (1)
#define PSF_VALUE_PARENTAL_LEVEL_2      (2)
#define PSF_VALUE_PARENTAL_LEVEL_3      (3)
#define PSF_VALUE_PARENTAL_LEVEL_4      (4)
#define PSF_VALUE_PARENTAL_LEVEL_5      (5)
#define PSF_VALUE_PARENTAL_LEVEL_6      (6)
#define PSF_VALUE_PARENTAL_LEVEL_7      (7)
#define PSF_VALUE_PARENTAL_LEVEL_8      (8)
#define PSF_VALUE_PARENTAL_LEVEL_9      (9)
#define PSF_VALUE_PARENTAL_LEVEL_10     (10)
#define PSF_VALUE_PARENTAL_LEVEL_11     (11)

#define PSF_VALUE_REGION_ALL_REGIONS    (0x8000)

/* Product number - allowed characters: A-Z, 0-9 */
#define PSF_VALUE_DISC_ID_MAX_LEN       (16) /* Including '\0'. */

#define PSF_VALUE_DRIVER_PATH_MAX_LEN   (64)
