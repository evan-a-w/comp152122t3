#include <stdio.h>

// for (initialiser; condition; increment)
// for (int i = 0; i < 10; i++)
// int i = 0;
// while (i < 10) {
//     i++;
// }

int main(int argc, char *argv[]) {
    // char *argv[] is an array of strings
    // char * = string
    // [] = array
    // char **argv
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    // turns into
    int i = 0;
    while (i < argc) {
        printf("argv[%d]=%s\n", i, argv[i]);

        i++;
    }
    return 0;
}
