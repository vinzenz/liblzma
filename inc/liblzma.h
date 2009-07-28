#ifndef GUARD_LIB_LZMA_H_INCLUDED
#define GUARD_LIB_LZMA_H_INCLUDED

#if _MSC_VER > 1200
#    pragma once
#endif 

#if defined(WIN32) || defined(WIN64)
#   include <windows.h>

typedef UINT8  lz_uint8_t;
typedef UINT32 lz_uint32_t;
typedef UINT64 lz_uint64_t;
typedef SIZE_T lz_size_t;
#else
# error Please use liblzma from http://tukaani.org/xz/
#endif

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum {
    LZMA_RESERVED_ENUM      = 0
} lzma_reserved_enum;
    
typedef enum {
    LZMA_OK                 = 0,
    LZMA_STREAM_END         = 1,
    LZMA_NO_CHECK           = 2,
    LZMA_UNSUPPORTED_CHECK  = 3,
    LZMA_GET_CHECK          = 4,
    LZMA_MEM_ERROR          = 5,
    LZMA_MEMLIMIT_ERROR     = 6,
    LZMA_FORMAT_ERROR       = 7,
    LZMA_OPTIONS_ERROR      = 8,
    LZMA_DATA_ERROR         = 9,
    LZMA_BUF_ERROR          = 10,
    LZMA_PROG_ERROR         = 11,
} lzma_ret;


typedef enum {
    LZMA_RUN = 0,
    LZMA_SYNC_FLUSH = 1,
    LZMA_FULL_FLUSH = 2,
    LZMA_FINISH = 3
} lzma_action;

typedef struct {
    void *(*alloc)(void *opaque, lz_size_t nmemb, lz_size_t size);
    void (*free)(void *opaque, void *ptr);
    void *opaque;
} lzma_allocator;

typedef struct lzma_internal_s lzma_internal;
typedef struct {
    lz_uint8_t const *next_in;     /**< Pointer to the next input byte. */
    lz_size_t avail_in;                 /**< Number of available input bytes in next_in. */
    lz_uint64_t total_in;         /**< Total number of bytes read by liblzma. */

    lz_uint8_t *next_out;         /**< Pointer to the next output position. */
    lz_size_t avail_out;                 /**< Amount of free space in next_out. */
    lz_uint64_t total_out;         /**< Total number of bytes written by liblzma. */

    lzma_allocator *allocator;
    lzma_internal *internal;
    void *reserved_ptr1;
    void *reserved_ptr2;
    lz_uint64_t reserved_int1;
    lz_uint64_t reserved_int2;
    lzma_reserved_enum reserved_enum1;
    lzma_reserved_enum reserved_enum2;
} lzma_stream;

typedef struct 
{
    lz_uint64_t id;
    void *options;
} lzma_filter;

enum lzma_check
{
    LZMA_CHECK_NONE     = 0,
    LZMA_CHECK_CRC32    = 1,
    LZMA_CHECK_CRC64    = 4,
    LZMA_CHECK_SHA256   = 10
};    

lz_uint32_t lzma_version_number(void);
lzma_ret lzma_code(lzma_stream *strm, lzma_action action);
void lzma_end(lzma_stream *strm);

lz_uint64_t lzma_easy_encoder_memusage(lz_uint32_t preset);
lz_uint64_t lzma_easy_decoder_memusage(lz_uint32_t preset);

lzma_ret lzma_auto_decoder(lzma_stream *strm, lz_uint64_t memlimit, lz_uint32_t flags);
lzma_ret lzma_easy_encoder(lzma_stream * strm, lz_uint32_t preset,lzma_check check);

#if defined(__cplusplus)
}
#endif


#endif // GUARD_LIB_LZMA_H_INCLUDED

