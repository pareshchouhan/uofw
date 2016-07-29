/* Copyright (C) 2011 - 2015 The uOFW team
   See the file COPYING for copying permission.
*/

#ifndef COMMON_INCLUDED
# error "Only include common_asm.h, common_imp.h or common_header.h!"
#endif

/**
 * uofw/include/common/errors.h
 *
 * Defines error codes used by the system software. Throughout the kernel, error codes
 * are organized as negative values expressed in hexadecimal notation.
 */

/**
 * PSP error value format
 *
 *  31  30  29   28 27              16 15                    0
 * +---+---+-------+------------------+-----------------------+
 * | E | C | Rsrvd | F A C I L I T Y  |  E R R O R   C O D E  |
 * +---+---+-------+------------------+-----------------------+
 *
 *  bit 31: Error
 *      1 = Error
 *      0 = Success
 *
 *  bit 30: Critical
 *      1 = Critical error
 *      0 = Normal error
 *
 *  bits 29-28: Reserved
 *      always zero
 *
 *  bits 27-16: Facility
 *      One of the below facility codes
 * 
 *  bits 15-0: Error code
 *      Define the concrete meaning of the error code. The meaning is depending
 *      on the facility code, in other words, if for two error values the 
 *      error code fields are equal, but the facility differs, then the meaning of the
 *      error value might differ as well.
 *      
 */

/**
 * Definition of facility codes
 */

#define SCE_ERROR_FACILITY_NULL			0x000
#define SCE_ERROR_FACILITY_ERRNO		0x001
#define SCE_ERROR_FACILITY_KERNEL		0x002
#define SCE_ERROR_FACILITY_REGISTRY		0x008
#define SCE_ERROR_FACILITY_VSH			0x010
#define SCE_ERROR_FACILITY_UTILITY		0x011
#define SCE_ERROR_FACILITY_SYSFILE		0x012
#define SCE_ERROR_FACILITY_MSAPP		0x013

#define SCE_ERROR_FACILITY_UMD			0x021
#define SCE_ERROR_FACILITY_MEMSTICK		0x022
#define SCE_ERROR_FACILITY_FLASH		0x023
#define SCE_ERROR_FACILITY_USB			0x024
#define SCE_ERROR_FACILITY_SYSCON		0x025
#define SCE_ERROR_FACILITY_AUDIO		0x026
#define SCE_ERROR_FACILITY_LFLASH		0x027
#define SCE_ERROR_FACILITY_LFATFS		0x028
#define SCE_ERROR_FACILITY_SIRCS		0x029
#define SCE_ERROR_FACILITY_IRDA			0x02A
#define SCE_ERROR_FACILITY_POWER		0x02B
#define SCE_ERROR_FACILITY_AUDIOROUTING	0x02C
#define SCE_ERROR_FACILITY_MEDIASYNC	0x02D
#define SCE_ERROR_FACILITY_PERIPH		0x03F

#define SCE_ERROR_FACILITY_NETWORK		0x041
#define SCE_ERROR_FACILITY_SAS			0x042
#define SCE_ERROR_FACILITY_HTTP			0x043
#define SCE_ERROR_FACILITY_WAVE			0x044
#define SCE_ERROR_FACILITY_SND			0x045
#define SCE_ERROR_FACILITY_FONT			0x046
#define SCE_ERROR_FACILITY_P3DA			0x047
#define SCE_ERROR_FACILITY_MAGICGATE	0x050
#define SCE_ERROR_FACILITY_CPHIO		0x051
#define SCE_ERROR_FACILITY_OPENPSID		0x052
#define SCE_ERROR_FACILITY_DNAS			0x053
#define SCE_ERROR_FACILITY_MTP			0x054
#define SCE_ERROR_FACILITY_NP			0x055
#define SCE_ERROR_FACILITY_GAMEUPDATE	0x056
#define SCE_ERROR_FACILITY_FMAC			0x057
#define SCE_ERROR_FACILITY_FACE			0x058
#define SCE_ERROR_FACILITY_LIBRARY		0x05F

#define SCE_ERROR_FACILITY_MPEG			0x061
#define SCE_ERROR_FACILITY_AVC			0x062
#define SCE_ERROR_FACILITY_ATRAC		0x063
#define SCE_ERROR_FACILITY_ASF			0x064
#define SCE_ERROR_FACILITY_JPEG			0x065
#define SCE_ERROR_FACILITY_AVI			0x066
#define SCE_ERROR_FACILITY_MP3			0x067
#define SCE_ERROR_FACILITY_G729			0x068
#define SCE_ERROR_FACILITY_AAC			0x069
#define SCE_ERROR_FACILITY_CODEC		0x07F

/**
 * Error definitions belonging to SCE_ERROR_FACILITY_NULL
 */

#define SCE_ERROR_OK                                            0x0
#define SCE_ERROR_NOT_SUPPORTED                                 0x80000004
#define SCE_ERROR_ALREADY                                       0x80000020
#define SCE_ERROR_BUSY                                          0x80000021
#define SCE_ERROR_OUT_OF_MEMORY                                 0x80000022
#define SCE_ERROR_PRIV_REQUIRED                                 0x80000023
#define SCE_ERROR_NOT_FOUND                                     0x80000025
#define SCE_ERROR_ILLEGAL_CONTEXT                               0x80000030
#define SCE_ERROR_CPUDI                                         0x80000031
#define SCE_ERROR_SEMAPHORE                                     0x80000041
#define SCE_ERROR_INVALID_ID                                    0x80000100
#define SCE_ERROR_INVALID_NAME                                  0x80000101
#define SCE_ERROR_INVALID_INDEX                                 0x80000102
#define SCE_ERROR_INVALID_POINTER                               0x80000103
#define SCE_ERROR_INVALID_SIZE                                  0x80000104
#define SCE_ERROR_INVALID_FLAG                                  0x80000105
#define SCE_ERROR_INVALID_COMMAND                               0x80000106
#define SCE_ERROR_INVALID_MODE                                  0x80000107
#define SCE_ERROR_INVALID_FORMAT                                0x80000108
#define SCE_ERROR_INVALID_VALUE                                 0x800001FE
#define SCE_ERROR_INVALID_ARGUMENT                              0x800001FF
#define SCE_ERROR_NOENT                                         0x80000202
#define SCE_ERROR_BAD_FILE                                      0x80000209
#define SCE_ERROR_ACCESS_ERROR                                  0x8000020D
#define SCE_ERROR_EXIST                                         0x80000211
#define SCE_ERROR_INVAL                                         0x80000216
#define SCE_ERROR_MFILE                                         0x80000218
#define SCE_ERROR_NOSPC                                         0x8000021C
#define SCE_ERROR_DFUNC                                         0x800002FF

/**
 * Error definitions belonging to SCE_ERROR_FACILITY_ERRNO
 */

#define SCE_ERROR_ERRNO_OPERATION_NOT_PERMITTED                 0x80010001
#define SCE_ERROR_ERRNO_FILE_NOT_FOUND                          0x80010002
#define SCE_ERROR_ERRNO_FILE_OPEN_ERROR                         0x80010003
#define SCE_ERROR_ERRNO_IO_ERROR                                0x80010005
#define SCE_ERROR_ERRNO_ARG_LIST_TOO_LONG                       0x80010007
#define SCE_ERROR_ERRNO_INVALID_FILE_DESCRIPTOR                 0x80010009
#define SCE_ERROR_ERRNO_RESOURCE_UNAVAILABLE                    0x8001000B
#define SCE_ERROR_ERRNO_NO_MEMORY                               0x8001000C
#define SCE_ERROR_ERRNO_NO_PERM                                 0x8001000D
#define SCE_ERROR_ERRNO_FILE_INVALID_ADDR                       0x8001000E
#define SCE_ERROR_ERRNO_DEVICE_BUSY                             0x80010010
#define SCE_ERROR_ERRNO_FILE_ALREADY_EXISTS                     0x80010011
#define SCE_ERROR_ERRNO_CROSS_DEV_LINK                          0x80010012
#define SCE_ERROR_ERRNO_DEVICE_NOT_FOUND                        0x80010013
#define SCE_ERROR_ERRNO_NOT_A_DIRECTORY                         0x80010014
#define SCE_ERROR_ERRNO_IS_DIRECTORY                            0x80010015
#define SCE_ERROR_ERRNO_INVALID_ARGUMENT                        0x80010016
#define SCE_ERROR_ERRNO_TOO_MANY_OPEN_SYSTEM_FILES              0x80010018
#define SCE_ERROR_ERRNO_FILE_IS_TOO_BIG                         0x8001001B
#define SCE_ERROR_ERRNO_DEVICE_NO_FREE_SPACE                    0x8001001C
#define SCE_ERROR_ERRNO_READ_ONLY                               0x8001001E
#define SCE_ERROR_ERRNO_CLOSED                                  0x80010020
// #define SCE_ERROR_ERRNO_EIDRM                                   0x80010024 -- Note: Keep this undefined.
#define SCE_ERROR_ERRNO_FILE_PROTOCOL                           0x80010047
#define SCE_ERROR_ERRNO_DIRECTORY_IS_NOT_EMPTY                  0x8001005A
#define SCE_ERROR_ERRNO_NAME_TOO_LONG                           0x8001005B /* File name or path name too long */
#define SCE_ERROR_ERRNO_TOO_MANY_SYMBOLIC_LINKS                 0x8001005C
#define SCE_ERROR_ERRNO_CONNECTION_RESET                        0x80010068
#define SCE_ERROR_ERRNO_NO_FREE_BUF_SPACE                       0x80010069
#define SCE_ERROR_ERRNO_ESHUTDOWN                               0x8001006E /* Error sending package after socket was shutdown */
#define SCE_ERROR_ERRNO_EADDRINUSE                              0x80010070 /* The address is already in use. */
#define SCE_ERROR_ERRNO_CONNECTION_ABORTED                      0x80010071 /* Connection was aborted by software. */
#define SCE_ERROR_ERRNO_ETIMEDOUT                               0x80010074 /* Operation timed out. */
#define SCE_ERROR_ERRNO_IN_PROGRESS                             0x80010077
#define SCE_ERROR_ERRNO_ALREADY                                 0x80010078
#define SCE_ERROR_ERRNO_INVALID_PROTOCOL                        0x8001007B /* Protocol is not supported. */
#define SCE_ERROR_ERRNO_INVALID_SOCKET_TYPE                     0x8001007C /* Unsupported socket type. */
#define SCE_ERROR_ERRNO_ADDRESS_NOT_AVAILABLE                   0x8001007D
#define SCE_ERROR_ERRNO_IS_ALREADY_CONNECTED                    0x8001007F    
#define SCE_ERROR_ERRNO_NOT_CONNECTED                           0x80010080
#define SCE_ERROR_ERRNO_FILE_QUOTA_EXCEEDED                     0x80010084
#define SCE_ERROR_ERRNO_NOT_SUPPORTED                           0x80010086
#define SCE_ERROR_ERRNO_ENOMEDIUM                               0x80010087 /* No medium was found. */

/* 
 * Non-standard error code definitions 
 */

#define SCE_ERROR_ERRNO_ADDR_OUT_OF_MAIN_MEM                    0x8001B001
#define SCE_ERROR_ERRNO_INVALID_UNIT_NUM                        0x8001B002
#define SCE_ERROR_ERRNO_INVALID_FILE_SIZE                       0x8001B003
#define SCE_ERROR_ERRNO_INVALID_FLAG                            0x8001B004
#define SCE_ERROR_ERRNO_NO_CACHE                                0x8001B005
#define SCE_ERROR_ERRNO_WRONG_MEDIUM_TYPE                       0x8001B006

/* 
 * Flash memory (UMD, MS) up to 1.5.0 mistakenly had returned these values. 
 */

#define SCE_ERROR_ERRNO150_ENAMETOOLONG                         0x80010024
#define SCE_ERROR_ERRNO150_EADDRINUSE                           0x80010062
#define SCE_ERROR_ERRNO150_ECONNABORTED                         0x80010067
#define SCE_ERROR_ERRNO150_ETIMEDOUT                            0x8001006E
#define SCE_ERROR_ERRNO150_ENOMEDIUM                            0x8001007B
#define SCE_ERROR_ERRNO150_EMEDIUMTYPE                          0x8001007C
#define SCE_ERROR_ERRNO150_ENOTSUP                              0x8001B000

/**
 * Error definitions belonging to SCE_ERROR_FACILITY_KERNEL
 */

#define SCE_ERROR_KERNEL_ERROR                                  0x80020001
#define SCE_ERROR_KERNEL_NOT_IMPLEMENTED                        0x80020002
#define SCE_ERROR_KERNEL_CANNOT_BE_CALLED_FROM_INTERRUPT        0x80020064
#define SCE_ERROR_KERNEL_INTERRUPTS_ALREADY_DISABLED            0x80020066
#define SCE_ERROR_KERNEL_NO_TIMER                               0x80020096
#define SCE_ERROR_KERNEL_ILLEGAL_TIMER_ID                       0x80020097
#define SCE_ERROR_KERNEL_ILLEGAL_PRESCALE                       0x80020099
#define SCE_ERROR_KERNEL_TIMER_BUSY                             0x8002009A
#define SCE_ERROR_KERNEL_UNKNOWN_UID                            0x800200CB
#define SCE_ERROR_KERNEL_UNMATCH_TYPE_UID                       0x800200CC
#define SCE_ERROR_KERNEL_NOT_EXIST_ID                           0x800200CD
#define SCE_ERROR_KERNEL_NOT_FOUND_FUNCTION_UID                 0x800200CE
#define SCE_ERROR_KERNEL_ALREADY_HOLDER_UID                     0x800200CF
#define SCE_ERROR_KERNEL_NOT_HOLDER_UID                         0x800200D0
#define SCE_ERROR_KERNEL_ILLEGAL_PERMISSION                     0x800200D1
#define SCE_ERROR_KERNEL_ILLEGAL_ARGUMENT                       0x800200D2
#define SCE_ERROR_KERNEL_ILLEGAL_ADDR                           0x800200D3
#define SCE_ERROR_KERNEL_MEMORY_AREA_OUT_OF_RANGE               0x800200D4
#define SCE_ERROR_KERNEL_MEMORY_AREA_IS_OVERLAP                 0x800200D5
#define SCE_ERROR_KERNEL_ILLEGAL_PARTITION_ID                   0x800200D6
#define SCE_ERROR_KERNEL_PARTITION_IN_USE                       0x800200D7
#define SCE_ERROR_KERNEL_ILLEGAL_MEMBLOCK_ALLOC_TYPE            0x800200D8
#define SCE_ERROR_KERNEL_FAILED_ALLOC_MEMBLOCK                  0x800200D9
#define SCE_ERROR_KERNEL_INHIBITED_RESIZE_MEMBLOCK              0x800200DA
#define SCE_ERROR_KERNEL_FAILED_RESIZE_MEMBLOCK                 0x800200DB
#define SCE_ERROR_KERNEL_FAILED_ALLOC_HEAPBLOCK                 0x800200DC
#define SCE_ERROR_KERNEL_FAILED_ALLOC_HEAP                      0x800200DD
#define SCE_ERROR_KERNEL_ILLEGAL_CHUNK_ID                       0x800200DE
#define SCE_ERROR_KERNEL_CANNOT_FIND_CHUNK_NAME                 0x800200DF
#define SCE_ERROR_KERNEL_NO_FREE_CHUNK                          0x800200E0
#define SCE_ERROR_KERNEL_MEMBLOCK_FRAGMENTED                    0x800200E1
#define SCE_ERROR_KERNEL_MEMBLOCK_CANNOT_JOINT                  0x800200E2
#define SCE_ERROR_KERNEL_MEMBLOCK_CANNOT_SEPARATE               0x800200E3
#define SCE_ERROR_KERNEL_ILLEGAL_ALIGNMENT_SIZE                 0x800200E4
#define SCE_ERROR_KERNEL_ILLEGAL_DEVKIT_VER                     0x800200E5
#define SCE_ERROR_KERNEL_MODULE_LINK_ERROR                      0x8002012C
#define SCE_ERROR_KERNEL_ILLEGAL_OBJECT_FORMAT                  0x8002012D
#define SCE_ERROR_KERNEL_UNKNOWN_MODULE                         0x8002012E
#define SCE_ERROR_KERNEL_UNKNOWN_MODULE_FILE                    0x8002012F
#define SCE_ERROR_KERNEL_FILE_READ_ERROR                        0x80020130
#define SCE_ERROR_KERNEL_MEMORY_IN_USE                          0x80020131
#define SCE_ERROR_KERNEL_PARTITION_MISMATCH                     0x80020132
#define SCE_ERROR_KERNEL_MODULE_ALREADY_STARTED                 0x80020133
#define SCE_ERROR_KERNEL_MODULE_NOT_STARTED                     0x80020134
#define SCE_ERROR_KERNEL_MODULE_ALREADY_STOPPED                 0x80020135
#define SCE_ERROR_KERNEL_MODULE_CANNOT_STOP                     0x80020136
#define SCE_ERROR_KERNEL_MODULE_NOT_STOPPED                     0x80020137
#define SCE_ERROR_KERNEL_MODULE_CANNOT_REMOVE                   0x80020138
#define SCE_ERROR_KERNEL_EXCLUSIVE_LOAD                         0x80020139
#define SCE_ERROR_KERNEL_LIBRARY_IS_NOT_LINKED                  0x8002013A
#define SCE_ERROR_KERNEL_LIBRARY_ALREADY_EXISTS                 0x8002013B
#define SCE_ERROR_KERNEL_LIBRARY_NOT_FOUND                      0x8002013C
#define SCE_ERROR_KERNEL_ILLEGAL_LIBRARY_HEADER                 0x8002013D
#define SCE_ERROR_KERNEL_LIBRARY_IN_USE                         0x8002013E
#define SCE_ERROR_KERNEL_MODULE_ALREADY_STOPPING                0x8002013F
#define SCE_ERROR_KERNEL_ILLEGAL_OFFSET_VALUE                   0x80020140
#define SCE_ERROR_KERNEL_ILLEGAL_POSITION_CODE                  0x80020141
#define SCE_ERROR_KERNEL_ILLEGAL_ACCESS_CODE                    0x80020142
#define SCE_ERROR_KERNEL_MODULE_MANAGER_BUSY                    0x80020143
#define SCE_ERROR_KERNEL_ILLEGAL_FLAG                           0x80020144
#define SCE_ERROR_KERNEL_CANNOT_GET_MODULE_LIST                 0x80020145
#define SCE_ERROR_KERNEL_PROHIBIT_LOADMODULE_DEVICE             0x80020146
#define SCE_ERROR_KERNEL_PROHIBIT_LOADEXEC_DEVICE               0x80020147
#define SCE_ERROR_KERNEL_UNSUPPORTED_PRX_TYPE                   0x80020148
#define SCE_ERROR_KERNEL_ILLEGAL_PERMISSION_CALL                0x80020149
#define SCE_ERROR_KERNEL_CANNOT_GET_MODULE_INFO                 0x8002014A
#define SCE_ERROR_KERNEL_ILLEGAL_LOADEXEC_BUFFER                0x8002014B
#define SCE_ERROR_KERNEL_ILLEGAL_LOADEXEC_FILENAME              0x8002014C
#define SCE_ERROR_KERNEL_NO_EXIT_CALLBACK                       0x8002014D
#define SCE_ERROR_KERNEL_MEDIA_CHANGED                          0x8002014E
#define SCE_ERROR_KERNEL_CANNOT_USE_BETA_VER_MODULE             0x8002014F
#define SCE_ERROR_KERNEL_NO_MEMORY                              0x80020190
#define SCE_ERROR_KERNEL_ILLEGAL_ATTR                           0x80020191
#define SCE_ERROR_KERNEL_ILLEGAL_THREAD_ENTRY_ADDR              0x80020192
#define SCE_ERROR_KERNEL_ILLEGAL_PRIORITY                       0x80020193
#define SCE_ERROR_KERNEL_ILLEGAL_STACK_SIZE                     0x80020194
#define SCE_ERROR_KERNEL_ILLEGAL_MODE                           0x80020195
#define SCE_ERROR_KERNEL_ILLEGAL_MASK                           0x80020196
#define SCE_ERROR_KERNEL_ILLEGAL_THREAD                         0x80020197
#define SCE_ERROR_KERNEL_NOT_FOUND_THREAD                       0x80020198
#define SCE_ERROR_KERNEL_NOT_FOUND_SEMAPHORE                    0x80020199
#define SCE_ERROR_KERNEL_NOT_FOUND_EVENT_FLAG                   0x8002019A
#define SCE_ERROR_KERNEL_NOT_FOUND_MESSAGE_BOX                  0x8002019B
#define SCE_ERROR_KERNEL_NOT_FOUND_VPOOL                        0x8002019C
#define SCE_ERROR_KERNEL_NOT_FOUND_FPOOL                        0x8002019D
#define SCE_ERROR_KERNEL_NOT_FOUND_MESSAGE_PIPE                 0x8002019E
#define SCE_ERROR_KERNEL_NOT_FOUND_ALARM                        0x8002019F
#define SCE_ERROR_KERNEL_NOT_FOUND_THREAD_EVENT_HANDLER         0x800201A0
#define SCE_ERROR_KERNEL_NOT_FOUND_CALLBACK                     0x800201A1
#define SCE_ERROR_KERNEL_THREAD_ALREADY_DORMANT                 0x800201A2
#define SCE_ERROR_KERNEL_THREAD_ALREADY_SUSPEND                 0x800201A3
#define SCE_ERROR_KERNEL_THREAD_IS_NOT_DORMANT                  0x800201A4
#define SCE_ERROR_KERNEL_THREAD_IS_NOT_SUSPEND                  0x800201A5
#define SCE_ERROR_KERNEL_THREAD_IS_NOT_WAIT                     0x800201A6
#define SCE_ERROR_KERNEL_WAIT_CAN_NOT_WAIT                      0x800201A7
#define SCE_ERROR_KERNEL_WAIT_TIMEOUT                           0x800201A8
#define SCE_ERROR_KERNEL_WAIT_CANCELLED                         0x800201A9
#define SCE_ERROR_KERNEL_WAIT_STATUS_RELEASED                   0x800201AA
#define SCE_ERROR_KERNEL_WAIT_STATUS_RELEASED_CALLBACK          0x800201AB
#define SCE_ERROR_KERNEL_THREAD_IS_TERMINATED                   0x800201AC
#define SCE_ERROR_KERNEL_SEMA_ZERO                              0x800201AD
#define SCE_ERROR_KERNEL_SEMA_OVERFLOW                          0x800201AE
#define SCE_ERROR_KERNEL_EVENT_FLAG_POLL_FAILED                 0x800201AF
#define SCE_ERROR_KERNEL_EVENT_FLAG_NO_MULTI_PERM               0x800201B0
#define SCE_ERROR_KERNEL_EVENT_FLAG_ILLEGAL_WAIT_PATTERN        0x800201B1
#define SCE_ERROR_KERNEL_MESSAGEBOX_NO_MESSAGE                  0x800201B2
#define SCE_ERROR_KERNEL_MESSAGE_PIPE_FULL                      0x800201B3
#define SCE_ERROR_KERNEL_MESSAGE_PIPE_EMPTY                     0x800201B4
#define SCE_ERROR_KERNEL_WAIT_DELETE                            0x800201B5
#define SCE_ERROR_KERNEL_ILLEGAL_MEMBLOCK                       0x800201B6
#define SCE_ERROR_KERNEL_ILLEGAL_MEMSIZE                        0x800201B7
#define SCE_ERROR_KERNEL_ILLEGAL_SCRATCHPAD_ADDR                0x800201B8
#define SCE_ERROR_KERNEL_SCRATCHPAD_IN_USE                      0x800201B9
#define SCE_ERROR_KERNEL_SCRATCHPAD_NOT_IN_USE                  0x800201BA
#define SCE_ERROR_KERNEL_ILLEGAL_TYPE                           0x800201BB
#define SCE_ERROR_KERNEL_ILLEGAL_SIZE                           0x800201BC
#define SCE_ERROR_KERNEL_ILLEGAL_COUNT                          0x800201BD
#define SCE_ERROR_KERNEL_NOT_FOUND_VTIMER                       0x800201BE
#define SCE_ERROR_KERNEL_ILLEGAL_VTIMER                         0x800201BF
#define SCE_ERROR_KERNEL_ILLEGAL_KTLS                           0x800201C0
#define SCE_ERROR_KERNEL_KTLS_IS_FULL                           0x800201C1
#define SCE_ERROR_KERNEL_KTLS_IS_BUSY                           0x800201C2
#define SCE_ERROR_KERNEL_MUTEX_NOT_FOUND                        0x800201C3
#define SCE_ERROR_KERNEL_MUTEX_LOCKED                           0x800201C4
#define SCE_ERROR_KERNEL_MUTEX_UNLOCKED                         0x800201C5
#define SCE_ERROR_KERNEL_MUTEX_LOCK_OVERFLOW                    0x800201C6
#define SCE_ERROR_KERNEL_MUTEX_UNLOCK_UNDERFLOW                 0x800201C7
#define SCE_ERROR_KERNEL_MUTEX_RECURSIVE_NOT_ALLOWED            0x800201C8
#define SCE_ERROR_KERNEL_MESSAGEBOX_DUPLICATE_MESSAGE           0x800201C9
#define SCE_ERROR_KERNEL_LWMUTEX_NOT_FOUND                      0x800201CA
#define SCE_ERROR_KERNEL_LWMUTEX_LOCKED                         0x800201CB
#define SCE_ERROR_KERNEL_LWMUTEX_UNLOCKED                       0x800201CC
#define SCE_ERROR_KERNEL_LWMUTEX_LOCK_OVERFLOW                  0x800201CD
#define SCE_ERROR_KERNEL_LWMUTEX_UNLOCK_UNDERFLOW               0x800201CE
#define SCE_ERROR_KERNEL_LWMUTEX_RECURSIVE_NOT_ALLOWED          0x800201CF
#define SCE_ERROR_KERNEL_POWER_CANNOT_CANCEL                    0x80020261
#define SCE_ERROR_KERNEL_TOO_MANY_OPEN_FILES                    0x80020320
#define SCE_ERROR_KERNEL_NO_SUCH_DEVICE                         0x80020321
#define SCE_ERROR_KERNEL_BAD_FILE_DESCRIPTOR                    0x80020323
#define SCE_ERROR_KERNEL_INVALID_ARGUMENT                       0x80020324
#define SCE_ERROR_KERNEL_UNSUPPORTED_OPERATION                  0x80020325
#define SCE_ERROR_KERNEL_NOCWD                                  0x8002032C
#define SCE_ERROR_KERNEL_FILENAME_TOO_LONG                      0x8002032D
#define SCE_ERROR_KERNEL_ASYNC_BUSY                             0x80020329
#define SCE_ERROR_KERNEL_NO_ASYNC_OP                            0x8002032A
#define SCE_ERROR_KERNEL_NOT_CACHE_ALIGNED                      0x8002044C
#define SCE_ERROR_KERNEL_MAX_ERROR                              0x8002044D

#define SCE_ERROR_UTILITY_INVALID_STATUS                        0x80110001
#define SCE_ERROR_UTILITY_INVALID_PARAM_ADDR                    0x80110002
#define SCE_ERROR_UTILITY_IS_UNKNOWN                            0x80110003
#define SCE_ERROR_UTILITY_INVALID_PARAM_SIZE                    0x80110004
#define SCE_ERROR_UTILITY_WRONG_TYPE                            0x80110005
#define SCE_ERROR_UTILITY_MODULE_NOT_FOUND                      0x80110006
#define SCE_ERROR_SAVEDATA_LOAD_NO_MEMSTICK                     0x80110301
#define SCE_ERROR_SAVEDATA_LOAD_MEMSTICK_REMOVED                0x80110302
#define SCE_ERROR_SAVEDATA_LOAD_ACCESS_ERROR                    0x80110305
#define SCE_ERROR_SAVEDATA_LOAD_DATA_BROKEN                     0x80110306
#define SCE_ERROR_SAVEDATA_LOAD_NO_DATA                         0x80110307
#define SCE_ERROR_SAVEDATA_LOAD_BAD_PARAMS                      0x80110308
#define SCE_ERROR_SAVEDATA_LOAD_NO_UMD                          0x80110309
#define SCE_ERROR_SAVEDATA_LOAD_INTERNAL_ERROR                  0x80110309
#define SCE_ERROR_SAVEDATA_RW_NO_MEMSTICK                       0x80110321
#define SCE_ERROR_SAVEDATA_RW_MEMSTICK_REMOVED                  0x80110322
#define SCE_ERROR_SAVEDATA_RW_MEMSTICK_FULL                     0x80110323
#define SCE_ERROR_SAVEDATA_RW_MEMSTICK_PROTECTED                0x80110324
#define SCE_ERROR_SAVEDATA_RW_ACCESS_ERROR                      0x80110325
#define SCE_ERROR_SAVEDATA_RW_DATA_BROKEN                       0x80110326
#define SCE_ERROR_SAVEDATA_RW_NO_DATA                           0x80110327
#define SCE_ERROR_SAVEDATA_RW_BAD_PARAMS                        0x80110328
#define SCE_ERROR_SAVEDATA_RW_FILE_NOT_FOUND                    0x80110329
#define SCE_ERROR_SAVEDATA_RW_CAN_NOT_SUSPEND                   0x8011032A
#define SCE_ERROR_SAVEDATA_RW_INTERNAL_ERROR                    0x8011032B
#define SCE_ERROR_SAVEDATA_RW_BAD_STATUS                        0x8011032C
#define SCE_ERROR_SAVEDATA_RW_SECURE_FILE_FULL                  0x8011032D
#define SCE_ERROR_SAVEDATA_DELETE_NO_MEMSTICK                   0x80110341
#define SCE_ERROR_SAVEDATA_DELETE_MEMSTICK_REMOVED              0x80110342
#define SCE_ERROR_SAVEDATA_DELETE_MEMSTICK_PROTECTED            0x80110344
#define SCE_ERROR_SAVEDATA_DELETE_ACCESS_ERROR                  0x80110345
#define SCE_ERROR_SAVEDATA_DELETE_DATA_BROKEN                   0x80110346
#define SCE_ERROR_SAVEDATA_DELETE_NO_DATA                       0x80110347
#define SCE_ERROR_SAVEDATA_DELETE_BAD_PARAMS                    0x80110348
#define SCE_ERROR_SAVEDATA_DELETE_INTERNAL_ERROR                0x8011034B
#define SCE_ERROR_SAVEDATA_SAVE_NO_MEMSTICK                     0x80110381
#define SCE_ERROR_SAVEDATA_SAVE_MEMSTICK_REMOVED                0x80110382
#define SCE_ERROR_SAVEDATA_SAVE_NO_SPACE                        0x80110383
#define SCE_ERROR_SAVEDATA_SAVE_MEMSTICK_PROTECTED              0x80110384
#define SCE_ERROR_SAVEDATA_SAVE_ACCESS_ERROR                    0x80110385
#define SCE_ERROR_SAVEDATA_SAVE_BAD_PARAMS                      0x80110388
#define SCE_ERROR_SAVEDATA_SAVE_NO_UMD                          0x80110389
#define SCE_ERROR_SAVEDATA_SAVE_WRONG_UMD                       0x8011038A
#define SCE_ERROR_SAVEDATA_SAVE_INTERNAL_ERROR                  0x8011038B
#define SCE_ERROR_SAVEDATA_SIZES_NO_MEMSTICK                    0x801103C1
#define SCE_ERROR_SAVEDATA_SIZES_MEMSTICK_REMOVED               0x801103C2
#define SCE_ERROR_SAVEDATA_SIZES_ACCESS_ERROR                   0x801103C5
#define SCE_ERROR_SAVEDATA_SIZES_DATA_BROKEN                    0x801103C6
#define SCE_ERROR_SAVEDATA_SIZES_NO_DATA                        0x801103C7
#define SCE_ERROR_SAVEDATA_SIZES_BAD_PARAMS                     0x801103C8
#define SCE_ERROR_SAVEDATA_SIZES_INTERNAL_ERROR                 0x801103CB
#define SCE_ERROR_NETPARAM_BAD_NETCONF                          0x80110601
#define SCE_ERROR_NETPARAM_BAD_PARAM                            0x80110604
#define SCE_ERROR_NET_MODULE_BAD_ID                             0x80110801
#define SCE_ERROR_NET_MODULE_ALREADY_LOADED                     0x80110802
#define SCE_ERROR_NET_MODULE_NOT_LOADED                         0x80110803
#define SCE_ERROR_AV_MODULE_BAD_ID                              0x80110901
#define SCE_ERROR_AV_MODULE_ALREADY_LOADED                      0x80110902
#define SCE_ERROR_AV_MODULE_NOT_LOADED                          0x80110903
#define SCE_ERROR_MODULE_BAD_ID                                 0x80111101
#define SCE_ERROR_MODULE_ALREADY_LOADED                         0x80111102
#define SCE_ERROR_MODULE_NOT_LOADED                             0x80111103
#define SCE_ERROR_SCREENSHOT_CONT_MODE_NOT_INIT                 0x80111229
#define SCE_ERROR_MEMSTICK_DEVCTL_BAD_PARAMS                    0x80220081
#define SCE_ERROR_MEMSTICK_DEVCTL_TOO_MANY_CALLBACKS            0x80220082
#define SCE_ERROR_AUDIO_NOT_INITIALIZED                         0x80260001
#define SCE_ERROR_AUDIO_OUTPUT_BUSY                             0x80260002
#define SCE_ERROR_AUDIO_INVALID_CH                              0x80260003
#define SCE_ERROR_AUDIO_PRIV_REQUIRED                           0x80260004
#define SCE_ERROR_AUDIO_NOT_FOUND                               0x80260005
#define SCE_ERROR_AUDIO_INVALID_SIZE                            0x80260006
#define SCE_ERROR_AUDIO_INVALID_FORMAT                          0x80260007
#define SCE_ERROR_AUDIO_NOT_RESERVED                            0x80260008
#define SCE_ERROR_AUDIO_NOT_OUTPUT                              0x80260009
#define SCE_ERROR_AUDIO_INVALID_FREQUENCY                       0x8026000A
#define SCE_ERROR_AUDIO_INVALID_VOLUME                          0x8026000B
#define SCE_ERROR_AUDIO_INPUT_BUSY                              0x80260010
#define SCE_ERROR_POWER_VMEM_IN_USE                             0x802B0200
#define SCE_ERROR_NET_RESOLVER_BAD_ID                           0x80410408
#define SCE_ERROR_NET_RESOLVER_ALREADY_STOPPED                  0x8041040A
#define SCE_ERROR_NET_RESOLVER_INVALID_HOST                     0x80410414
#define SCE_ERROR_WLAN_BAD_PARAMS                               0x80410D13
#define SCE_ERROR_SAS_INVALID_VOICE                             0x80420010
#define SCE_ERROR_SAS_INVALID_ADSR_CURVE_MODE                   0x80420013
#define SCE_ERROR_SAS_INVALID_PARAMETER                         0x80420014
#define SCE_ERROR_SAS_VOICE_PAUSED                              0x80420016
#define SCE_ERROR_SAS_BUSY                                      0x80420030
#define SCE_ERROR_SAS_NOT_INIT                                  0x80420100
#define SCE_ERROR_HTTP_NOT_INIT                                 0x80431001
#define SCE_ERROR_HTTP_ALREADY_INIT                             0x80431020
#define SCE_ERROR_HTTP_NO_MEMORY                                0x80431077
#define SCE_ERROR_HTTP_SYSTEM_COOKIE_NOT_LOADED                 0x80431078
#define SCE_ERROR_HTTP_INVALID_PARAMETER                        0x804311FE
#define SCE_ERROR_SSL_NOT_INIT                                  0x80435001
#define SCE_ERROR_SSL_ALREADY_INIT                              0x80435020
#define SCE_ERROR_SSL_OUT_OF_MEMORY                             0x80435022
#define SCE_ERROR_HTTPS_CERT_ERROR                              0x80435060
#define SCE_ERROR_HTTPS_HANDSHAKE_ERROR                         0x80435061
#define SCE_ERROR_HTTPS_IO_ERROR                                0x80435062
#define SCE_ERROR_HTTPS_INTERNAL_ERROR                          0x80435063
#define SCE_ERROR_HTTPS_PROXY_ERROR                             0x80435064
#define SCE_ERROR_SSL_INVALID_PARAMETER                         0x804351FE
#define SCE_ERROR_WAVE_NOT_INIT                                 0x80440001
#define SCE_ERROR_WAVE_FAILED_EXIT                              0x80440002
#define SCE_ERROR_WAVE_BAD_VOL                                  0x8044000A
#define SCE_ERROR_WAVE_INVALID_CHANNEL                          0x80440010
#define SCE_ERROR_WAVE_INVALID_SAMPLE_COUNT                     0x80440011
#define SCE_ERROR_FONT_INVALID_LIBID                            0x80460002
#define SCE_ERROR_FONT_INVALID_PARAMETER                        0x80460003
#define SCE_ERROR_FONT_TOO_MANY_OPEN_FONTS                      0x80460009
#define SCE_ERROR_MPEG_BAD_VERSION                              0x80610002
#define SCE_ERROR_MPEG_NO_MEMORY                                0x80610022
#define SCE_ERROR_MPEG_INVALID_ADDR                             0x80610103
#define SCE_ERROR_MPEG_INVALID_VALUE                            0x806101FE
#define SCE_ERROR_PSMF_NOT_INITIALIZED                          0x80615001
#define SCE_ERROR_PSMF_BAD_VERSION                              0x80615002
#define SCE_ERROR_PSMF_NOT_FOUND                                0x80615025
#define SCE_ERROR_PSMF_INVALID_ID                               0x80615100
#define SCE_ERROR_PSMF_INVALID_VALUE                            0x806151FE
#define SCE_ERROR_PSMF_INVALID_TIMESTAMP                        0x80615500
#define SCE_ERROR_PSMF_INVALID_PSMF                             0x80615501
#define SCE_ERROR_PSMFPLAYER_NOT_INITIALIZED                    0x80616001
#define SCE_ERROR_PSMFPLAYER_NO_MORE_DATA                       0x8061600C
#define SCE_ERROR_MPEG_NO_DATA                                  0x80618001
#define SCE_ERROR_AVC_VIDEO_FATAL                               0x80628002
#define SCE_ERROR_ATRAC_NO_ID                                   0x80630003
#define SCE_ERROR_ATRAC_INVALID_CODEC                           0x80630004
#define SCE_ERROR_ATRAC_BAD_ID                                  0x80630005
#define SCE_ERROR_ATRAC_ALL_DATA_LOADED                         0x80630009
#define SCE_ERROR_ATRAC_NO_DATA                                 0x80630010
#define SCE_ERROR_ATRAC_SECOND_BUFFER_NEEDED                    0x80630012
#define SCE_ERROR_ATRAC_SECOND_BUFFER_NOT_NEEDED                0x80630022
#define SCE_ERROR_ATRAC_BUFFER_IS_EMPTY                         0x80630023
#define SCE_ERROR_ATRAC_ALL_DATA_DECODED                        0x80630024
#define SCE_ERROR_CODEC_AUDIO_FATAL                             0x807F00FC

/* 
 * Error-similar definitions. 
 */
#define SCE_KERNEL_VALUE_UNITIALIZED                            (-1)
#define SCE_KERNEL_PTR_UNITIALIZED                              ((void *)SCE_KERNEL_VALUE_UNITIALIZED)

