int pclubgit_init(void);
int pclubgit_add(const char* filename);
int pclubgit_rm(const char* filename);
int pclubgit_commit(const char* message);
int pclubgit_status();
int pclubgit_log();

// Number of bytes in a commit id
#define COMMIT_ID_BYTES 40

// Preprocessor macros capturing the maximum size of different  structures
#define FILENAME_SIZE 512
#define COMMIT_ID_SIZE (COMMIT_ID_BYTES+1)
#define MSG_SIZE 512
