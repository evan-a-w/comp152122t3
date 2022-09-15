#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
        // atoi(string) converts string to the integer it represents
    }
    printf("sum of command-line arguments = %d\n", sum);
    return 0;
}
