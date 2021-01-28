#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printmessage(void *mystring) {
    printf("%s\n", (char*)mystring);
    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;
    char msg1[] = "Here is message 1.\n";
    char msg2[] = "Here is message 2.\n";

    pthread_create(&thread1, NULL, printmessage, msg1);

    pthread_create(&thread2, NULL, printmessage, msg2);

    pthread_join(thread1, NULL);    // wait for thread 1 to finish
    pthread_join(thread2, NULL);    // thread 2
    printf("Back to single thread of execution");
    return 0;
}