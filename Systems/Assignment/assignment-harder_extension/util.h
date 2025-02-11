/**
 * This file contains utility functions to use in the homework. Do not modify!
 */
#ifndef _PCLUBGIT_UTIL_H_
#define _PCLUBGIT_UTIL_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>
#include <openssl/sha.h>

int is_sane_path(const char* path);


static const char* path = "";
static const char* dirname = "";
static const char* filename = "";
static const char* src = "";
static const char* dst = "";

#define PRINT_FILENAME(fn) \
  if (strlen(fn) > 0) \
    fprintf(stderr, "  * %s = %s\n", # fn, fn);

#define ASSERT_ERROR_MESSAGE(fn, msg) \
  if (!(fn)) { \
    fprintf(stderr, "\n        *** AN ERROR OCCURRED IN %s ***\n\n", __func__); \
    fprintf(stderr, "  This should not happen. Most likely, you tried to access\n"); \
    fprintf(stderr, "  or manipulate a file that doesn't exist, or create one\n"); \
    fprintf(stderr, "  that already does. You should first try to delete the\n"); \
    fprintf(stderr, "  .pclubgit directory and start over; maybe a previous run\n"); \
    fprintf(stderr, "  corrupted it. If not, you need to fix the problem in\n"); \
    fprintf(stderr, "  your program -- the following error message might give\n"); \
    fprintf(stderr, "  more information about what went wrong:\n\n"); \
    fprintf(stderr, "  Error in %s: %s\n\n", __func__, msg); \
    fprintf(stderr, "  Non-empty variables in scope:\n"); \
    PRINT_FILENAME(path) \
    PRINT_FILENAME(dirname) \
    PRINT_FILENAME(filename) \
    PRINT_FILENAME(src) \
    PRINT_FILENAME(dst) \
    fprintf(stderr, "\n"); \
    exit(1); \
  }

void fs_mkdir(const char* dirname);
void fs_rm(const char* filename);
void fs_force_rm_pclubgit_dir();
void fs_mv(const char* src, const char* dst);
void fs_cp(const char* src, const char* dst);
void write_string_to_file(const char* filename, const char* str);
void read_string_from_file(const char* filename, char* str, int size);
int fs_check_dir_exists(const char* dirname);

#define SHA_HEX_BYTES (SHA_DIGEST_LENGTH * 2)

void cryptohash(const char* str, char dst[SHA_HEX_BYTES + 1]);

#endif // _PCLUBGIT_UTIL_H_
