/**
 * This file contains functionality to parse command line arguments. Do not modify!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>

#include "pclubgit.h"

int check_initialized(void) {
  struct stat s;
  int ret_code = stat(".pclubgit", &s);
  return !(ret_code == -1 || !(S_ISDIR(s.st_mode)));
}

int check_filename(const char* filename) {
  if (strlen(filename) > FILENAME_SIZE-1 || strlen(filename) == 0)
    return 0;

  if (filename[0] == '.')
    return 0;

  struct stat s;
  int ret_code = stat(filename, &s);
  return (ret_code != -1 && !(S_ISDIR(s.st_mode)));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [<args>]\n", argv[0]);
        return 2;
    }

    if (strcmp(argv[1], "init") == 0) {
        if (check_initialized()) {
            fprintf(stderr, "ERROR: Repository is already initialized\n");
            return 1;
        }
        return pclubgit_init();
    }

    if (!check_initialized()) {
        fprintf(stderr, "ERROR: Repository is not initialized\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 || strcmp(argv[1], "rm") == 0) {
        if (argc < 3 || !check_filename(argv[2])) {
            fprintf(stderr, "ERROR: No or invalid filename given\n");
            return 1;
        }
        return (strcmp(argv[1], "rm") == 0) ? pclubgit_rm(argv[2]) : pclubgit_add(argv[2]);
    }

    if (strcmp(argv[1], "commit") == 0) {
        if (argc < 4 || strcmp(argv[2], "-m") != 0) {
            fprintf(stderr, "ERROR: Need a commit message (-m <msg>)\n");
            return 1;
        }
        if (strlen(argv[3]) > MSG_SIZE - 1) {
            fprintf(stderr, "ERROR: Message is too long!\n");
            return 1;
        }
        return pclubgit_commit(argv[3]);
    }

    if (strcmp(argv[1], "status") == 0) return pclubgit_status();
    if (strcmp(argv[1], "log") == 0) {
        int limit = INT_MAX;
        if (argc > 2 && strcmp(argv[2], "-n") == 0) {
            if (argc == 3) {
                fprintf(stderr, "ERROR: No log limit specified!\n");
                return 1;
            }
            limit = atoi(argv[3]);
            if (limit < 0) {
                fprintf(stderr, "ERROR: Illegal log limit specified!\n");
                return 1;
            }
        }
        return pclubgit_log(limit);
    }

    if (strcmp(argv[1], "branch") == 0) return pclubgit_branch();

    if (strcmp(argv[1], "checkout") == 0) {
        int branch_new = 0;
        char *arg = NULL;

        for (int i = 2; i < argc; i++) {
            if (argv[i][0] == '-') {
                if (strcmp(argv[i], "-b") == 0) {
                    branch_new = 1;
                    continue;
                }
                fprintf(stderr, "ERROR: Invalid argument: %s\n", argv[i]);
                return 1;
            }
            if (arg) {
                fprintf(stderr, "ERROR: Too many arguments for checkout!\n");
                return 1;
            }
            arg = argv[i];
        }
        return pclubgit_checkout(arg, branch_new);
    }

    if (strcmp(argv[1], "reset") == 0) {
        if (argc < 4) {
            fprintf(stderr, "ERROR: Need to specify a commit id and a filename\n");
            return 1;
        }
        return pclubgit_reset(argv[2], argv[3]);
    }

    if (strcmp(argv[1], "merge") == 0) {
        if (argc < 3) {
            fprintf(stderr, "ERROR: Need to specify a commit id or branch name\n");
            return 1;
        }
        return pclubgit_merge(argv[2]);
    }

    fprintf(stderr, "ERROR: Unknown command \"%s\"\n", argv[1]);
    return 1;
}

