#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(void) {
    char *home = getenv("HOME");
    if (home == NULL) {
        perror("HOME");
        return 1;
    }

    // we want to open "$HOME/.diary"
    // WRONG because we haven't allocated memory for it
    // strcat(home, "/.diary");
    int length = strlen(home) + strlen("/.diary") + 1;
    char *path = malloc(length);
    strcpy(path, home);
    strcat(path, "/.diary");
    
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return 1;
    }

    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }

    fclose(f);
    free(path);
}
