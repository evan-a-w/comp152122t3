// Prints the square of a number

#include <stdio.h>

char *str = "Enter a number: ";

int main(void) {
    int x, y;

    puts(str);
    scanf("%d", &x);

    y = x * x;

    printf("%d\n", y);

    return 0;
}
