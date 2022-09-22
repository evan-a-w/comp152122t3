// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    int x = 24;
loop:
    if (x >= 42) {
        goto after_loop;
    }

    printf("%d\n", x);

    x = x + 3;

    goto loop;
after_loop:

    return 0;
}
