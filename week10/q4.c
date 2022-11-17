#include <stdio.h>
#include <pthread.h>

void *thread(void *data) {
    char *print = data; // void * can point to anything, including a char

    for (int i = 0; ; i++) {
        printf("%s\n", print);
    }

    return "Thread finished";
}

int main(void) {
    pthread_t t;
    pthread_create(&t, NULL, thread, "Hello\n");

    for (int i = 0; ; i++) {
        printf("tehre\n");
    }

    void *res;
    pthread_join(t, &res); // this is the way we access the return value of a thread
    printf("Res from thread: %s\n", (char *)res); 

    return 0;
}
