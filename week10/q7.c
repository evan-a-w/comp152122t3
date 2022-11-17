#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int global_total = 1;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 50000; i++) {
        // increment the global total by 1
        // lock
        // global_total *= 2; // 2 ^ 20 WORKS
        global_total++;
        // global_total = global_total + 1 DOESNT WORK (load and store separated)
        // unlock
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 100000
    printf("Final total: %d\n", global_total);
}
