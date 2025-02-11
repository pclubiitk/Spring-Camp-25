#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>

#include "pclubgit.h"
#include "util.h"

/* Implementation Notes:
 *
 * - Functions return 0 if successful, 1 if there is an error.
 * - All error conditions in the function description need to be implemented
 *   and written to stderr. We catch some additional errors for you in main.c.
 * - Output to stdout needs to be exactly as specified in the function description.
 * - Only edit this file (pclubgit.c)
 * - Here are some of the helper functions from util.h:
 *   * fs_mkdir(dirname): create directory <dirname>
 *   * fs_rm(filename): delete file <filename>
 *   * fs_mv(src,dst): move file <src> to <dst>, overwriting <dst> if it exists
 *   * fs_cp(src,dst): copy file <src> to <dst>, overwriting <dst> if it exists
 *   * write_string_to_file(filename,str): write <str> to filename (overwriting contents)
 *   * read_string_from_file(filename,str,size): read a string of at most <size> (incl.
 *     NULL character) from file <filename> and store it into <str>. Note that <str>
 *     needs to be large enough to hold that string.
 */

/* pclubgit init
 *
 * - Create .pclubgit directory
 * - Create empty .pclubgit/.index file
 * - Create .pclubgit/.prev file containing 0..0 commit id
 *
 * Output (to stdout):
 * - None if successful
 */

int pclubgit_init(void) {
  fs_mkdir(".pclubgit");

  FILE* findex = fopen(".pclubgit/.index", "w");
  fclose(findex);

  FILE* fbranches = fopen(".pclubgit/.branches", "w");
  fprintf(fbranches, "%s\n", "master");
  fclose(fbranches);

  write_string_to_file(".pclubgit/.prev", "0000000000000000000000000000000000000000");
  write_string_to_file(".pclubgit/.current_branch", "master");

  return 0;
}



/* pclubgit add <filename>
 *
 * - Append filename to list in .pclubgit/.index if it isn't in there yet
 *
 * Possible errors (to stderr):
 * >> ERROR:  File <filename> has already been added.
 *
 * Output (to stdout):
 * - None if successful
 */

int pclubgit_add(const char* filename) {
  FILE* findex = fopen(".pclubgit/.index", "r");
  FILE *fnewindex = fopen(".pclubgit/.newindex", "w");

  char line[FILENAME_SIZE];
  while(fgets(line, sizeof(line), findex)) {
    strtok(line, "\n");
    if (strcmp(line, filename) == 0) {
      fprintf(stderr, "ERROR:  File %s has already been added.\n", filename);
      fclose(findex);
      fclose(fnewindex);
      fs_rm(".pclubgit/.newindex");
      return 3;
    }

    fprintf(fnewindex, "%s\n", line);
  }

  fprintf(fnewindex, "%s\n", filename);
  fclose(findex);
  fclose(fnewindex);

  fs_mv(".pclubgit/.newindex", ".pclubgit/.index");

  return 0;
}

/* pclubgit status
 *
 * See "Step 1" in the project spec.
 *
 */

int pclubgit_status() {
  /* COMPLETE THE REST */

  return 0;
}

/* pclubgit rm <filename>
 *
 * See "Step 2" in the project spec.
 *
 */

int pclubgit_rm(const char* filename) {
  /* COMPLETE THE REST */

  return 0;
}

/* pclubgit commit -m <msg>
 *
 * See "Step 3" in the project spec.
 *
 */

const char* go_pclubs = "THIS IS PCLUB TERRITORY!";

int is_commit_msg_ok(const char* msg) {
  /* COMPLETE THE REST */
  return 0;
}

/* Use next_commit_id to fill in the rest of the commit ID.
 *
 * Hints:
 * You will need a destination string buffer to hold your next_commit_id, before you copy it back to commit_id
 * You will need to use a function we have provided for you.
 */

void next_commit_id(char* commit_id) {
     /* COMPLETE THE REST */
}

int pclubgit_commit(const char* msg) {
  if (!is_commit_msg_ok(msg)) {
    fprintf(stderr, "ERROR:  Message must contain \"%s\"\n", go_pclubs);
    return 1;
  }

  char commit_id[COMMIT_ID_SIZE];
  read_string_from_file(".pclubgit/.prev", commit_id, COMMIT_ID_SIZE);
  next_commit_id(commit_id);

  /* COMPLETE THE REST */

  return 0;
}

/* pclubgit log
 *
 * See "Step 4" in the project spec.
 *
 */

int pclubgit_log(int limit) {
  /* COMPLETE THE REST */
  return 0;
}


// This helper function returns the branch number for a specific branch, or
// returns -1 if the branch does not exist.
int get_branch_number(const char* branch_name) {
  FILE* fbranches = fopen(".pclubgit/.branches", "r");

  int branch_index = -1;
  int counter = 0;
  char line[FILENAME_SIZE];
  while(fgets(line, sizeof(line), fbranches)) {
    strtok(line, "\n");
    if (strcmp(line, branch_name) == 0) {
      branch_index = counter;
    }
    counter++;
  }

  fclose(fbranches);

  return branch_index;
}

/* pclubgit branch
 *
 * See "Step 5" in the project spec.
 *
 */

int pclubgit_branch() {
  /* COMPLETE THE REST */

  return 0;
}

/* pclubgit checkout
 *
 * See "Step 6" in the project spec.
 *
 */

int checkout_commit(const char* commit_id) {
  /* COMPLETE THE REST */
  return 0;
}

int is_it_a_commit_id(const char* commit_id) {
  /* COMPLETE THE REST */
  return 1;
}

int pclubgit_checkout(const char* arg, int new_branch) {
  // Get the current branch
  char current_branch[BRANCHNAME_SIZE];
  read_string_from_file(".pclubgit/.current_branch", "current_branch", BRANCHNAME_SIZE);

  // If not detached, leave the current branch by storing the current HEAD into that branch's file...
  if (strlen(current_branch)) {
    char current_branch_file[BRANCHNAME_SIZE+50];
    sprintf(current_branch_file, ".pclubgit/.branch_%s", current_branch);
    fs_cp(".pclubgit/.prev", current_branch_file);
  }

   // Check whether the argument is a commit ID. If yes, we just change to detached mode
  // without actually having to change into any other branch.
  if (is_it_a_commit_id(arg)) {
    char commit_dir[FILENAME_SIZE] = ".pclubgit/";
    strcat(commit_dir, arg);
    // ...and setting the current branch to none (i.e., detached).
    write_string_to_file(".pclubgit/.current_branch", "");

    return checkout_commit(arg);
  }



  // Read branches file (giving us the HEAD commit id for that branch).
  int branch_exists = (get_branch_number(arg) >= 0);

  // Check for errors.
  if (!(!branch_exists || !new_branch)) {
    fprintf(stderr, "ERROR:  A branch named %s already exists.\n", arg);
    return 1;
  } else if (!branch_exists && new_branch) {
    fprintf(stderr, "ERROR:  No branch or commit %s exists.\n", arg);
    return 1;
  }

  // Just a better name, since we now know the argument is a branch name.
  const char* branch_name = arg;

  // File for the branch we are changing into.
  char* branch_file = ".pclubgit/.branch_";
  strcat(branch_file, branch_name);

  // Update the branch file if new branch is created (now it can't go wrong anymore)
  if (new_branch) {
    FILE* fbranches = fopen(".pclubgit/.branches", "a");
    fprintf(fbranches, "%s\n", branch_name);
    fclose(fbranches);
    fs_cp(".pclubgit/.prev", branch_file);
  }

  write_string_to_file(".pclubgit/.current_branch", branch_name);

  // Read the head commit ID of this branch.
  char branch_head_commit_id[COMMIT_ID_SIZE];
  read_string_from_file(branch_file, branch_head_commit_id, COMMIT_ID_SIZE);

  // Check out the actual commit.
  return checkout_commit(branch_head_commit_id);
}

/* pclubgit reset
 *
 * See "Step 7" in the project spec.
 *
 */

int pclubgit_reset(const char* commit_id, const char* filename) {
  if (!is_it_a_commit_id(commit_id)) {
      fprintf(stderr, "ERROR:  Commit %s does not exist.\n", commit_id);
      return 1;
  }

  // Check if the file is in the commit directory
  /* COMPLETE THIS PART */

  // Copy the file to the current working directory
  /* COMPLETE THIS PART */

  // Add the file if it wasn't already there
  /* COMPLETE THIS PART */

  return 0;
}

/* pclubgit merge
 *
 * See "Step 8" in the project spec.
 *
 */

int pclubgit_merge(const char* arg) {
  // Get the commit_id or throw an error
  char commit_id[COMMIT_ID_SIZE];
  if (!is_it_a_commit_id(arg)) {
      if (get_branch_number(arg) == -1) {
            fprintf(stderr, "ERROR:  No branch or commit %s exists.\n", arg);
            return 1;
      }
      char branch_file[FILENAME_SIZE];
      snprintf(branch_file, FILENAME_SIZE, ".pclubgit/.branch_%s", arg);
      read_string_from_file(branch_file, commit_id, COMMIT_ID_SIZE);
  } else {
      snprintf(commit_id, COMMIT_ID_SIZE, "%s", arg);
  }

  // Iterate through each line of the commit_id index and determine how you
  // should copy the index file over
   /* COMPLETE THE REST */

  return 0;
}
