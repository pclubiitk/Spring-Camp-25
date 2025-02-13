#include "util.h"

int pclubgit_init(void);
int pclubgit_add(const char* filename);
int pclubgit_rm(const char* filename);
int pclubgit_commit(const char* message);
int pclubgit_status();
int pclubgit_log(int limit);
int pclubgit_branch();
int pclubgit_checkout(const char* arg, int new_branch);
int pclubgit_reset(const char* commit_id, const char* filename);
int pclubgit_merge(const char* arg);

// Helper functions
int get_branch_number(const char* branch_name);
void next_commit_id(char* commit_id);

// Number of bytes in a commit id
#define COMMIT_ID_BYTES SHA_HEX_BYTES

// Preprocessor macros capturing the maximum size of different  structures
#define FILENAME_SIZE 512
#define COMMIT_ID_SIZE (COMMIT_ID_BYTES+1)
#define MSG_SIZE 512

#define BRANCHNAME_SIZE 128
#define COMMIT_ID_BRANCH_BYTES 10
