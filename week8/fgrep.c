// Write a C program, fgrep.c, which is given 1+ command-line arguments which is a string to search for.
// If there is only 1 command-line argument it should read lines from stdin and print them to stdout iff they contain the string specified as the first command line argument.
// 
// If there are 2 or more command line arguments, it should treat arguments after the first as filenames and print any lines they contain which contain the string specified as the first command line arguments.
// 
// When printing lines your program should prefix them with a line number.
// 
// It should print suitable error messages if given an incorrect number of arguments or if there is an error opening a file.

#include <stdio.h>
#include <string.h>

int in_line(char *to_search, char *line) {
    return strstr(line, to_search) != NULL;
}

void do_thing(char *to_search, FILE *f) {
    // search lines in stdin for to_search and print them if its present
    // fgets helps us achieve this
    char buffer[1024];
    while (fgets(buffer, 1024, f) != NULL) {
        // buffer will be a line including the newline
        // check if to_search appears in buffer, and print it if so
        if (in_line(to_search, buffer)) {
            printf("%s", buffer);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s string_to_search ...\n", argv[0]);
    }
    char *to_search = argv[1]; 
    if (argc == 2) {
        do_thing(to_search, stdin);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                perror(argv[i]);
                return 1;
            }
            do_thing(to_search, f);
        }
    }
}
