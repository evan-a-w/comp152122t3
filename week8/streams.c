#include <stdio.h>
// standard io = standard input output 
// printf
// FILE *
// store the position in the file
// when reading or writing anything it will increment the position


int main(void) {
    // fopen(filename, mode);
    // modes can be "r" for read, "w" for write (from the beginning), "a" for append (write from the end)
    FILE *f = fopen("test.txt", "r"); // fails if the file doesn't exist
    if (f == NULL) {
        // errno was set to indicate error
        perror("test.txt"); // prints to stderr
        fprintf(stderr, "custom error message\n");
        return 1; // error code 1
    }

    // fprintf(f, "%d\n", 1); // exactly the same as printf
    
    // get a character from a file
    int ch = fgetc(f); // ch = EOF when reaching the end of the file
    printf("%c\n", ch);


    // go to the start of the file (no matter where we are now)
    if (fseek(f, 0, SEEK_SET) != 0) {
        perror("test.txt");
        return 1;
    }
    // move ahead 10
    if (fseek(f, 10, SEEK_CUR) != 0) {
        perror("test.txt");
        return 1;
    }
    // move back 10 from the end
    if (fseek(f, -10, SEEK_SET) != 0) {
        perror("test.txt");
        return 1;
    }

    // fprintf
    // fscanf
    // fgets
    // fputc
    // fgets
    // fputs


    // fseek
}
