#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

// not for the question, extra thing
void make_no_other_perms(char *filename) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror(filename);
        exit(1);
    }
    
    // xxx xxx xxx
    // xxx xxx 000
    // and with 000 in first 3 bits, 1 everywhere else
    // ~0b111 = ~07
    // 0b111 == 00000000000000000111
    // ~00000000000000000111 == 1111111111111111111000
    if (chmod(filename, st.st_mode & ~07) != 0) {
        perror(filename);
        exit(1);
    }

    if (S_ISDIR(st.st_mode)) {
        // set the character to d
    } else {
        // set the character to -
    }
}

void change_perms(char *filename) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror(filename);
        exit(1);
    }

    if (st.st_mode & 0b10) {
        // make a new mode where its the same except the 1st bit is 0
        mode_t new_mode = st.st_mode ^ 0b10;
        if (chmod(filename, new_mode) != 0) {
            perror(filename);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        char *current_file = argv[i];
        change_perms(current_file);
    }
}
