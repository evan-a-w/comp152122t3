#include <stdio.h>
#include <pthread.h>

int x;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *main1(void *data) {
    // here
    pthread_mutex_lock(&mutex);
    x = 1; // between this and the printf, no other thread should be able to change x
    for (int i = 0; i < 10000; i++) {
        // 
    }
    printf("%d\n", x);
    pthread_mutex_unlock(&mutex);
    //here

    return NULL;
}

void *main2(void *data) {
    // here
    pthread_mutex_lock(&mutex);
    x = 2;
    for (int i = 0; i < 10000; i++) {
        // 
    }
    printf("%d\n", x);
    pthread_mutex_unlock(&mutex);
    //here

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, main1, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, main2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
