#include <stdio.h>
#include <stdlib.h>

char arr[10];

int main(void) {
    // stack allocated because its a local variable
    char str[10] = {};
    str[0] = 'H';
    str[1] = 'i';

    printf("%s", str);

    int *x = malloc(sizeof(int));

    // string literal "hi"
    char *s = "hi";

    // malloc gives a pointer to memory in the heap
    char *l = malloc(sizeof(char) * 10);

    s[0] = 'H';

    int n;
    scanf("%d", &n);


    // allocate an array of size n
    int *arr = malloc(sizeof(int) * n);

    return 0;
}
