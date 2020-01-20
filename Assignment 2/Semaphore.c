#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


typedef int semaphore;
semaphore lock = 0;
int account = 0123456;
int balance = 100;

void *account1(){
    for (int i = 1; i < 3; i++) {
        if (account == 0123456 && lock != 1 ) {
            lock = 1;
            printf("Account# %d balance = $%d\n", account, balance);
            balance += 25;
            printf("$0 Deposited. balance is now $%d\n", balance);
            lock = 0;
        } else {
            printf("Account %d is locked.\n", account);
        }
        
    }
    return (0);
}

void *account2() {
    for (int i = 1; i < 3; i++){
        if (account == 0123456 && lock != 1 ) {
             lock = 1;
            printf("Account# %d balance = $%d\n", account, balance);
            balance += 25;
            printf("$25 Deposited. balance is now $%d\n", balance);
            lock = 0;
        } else {
            printf("Account %d is locked.\n", account);
        }
    }
    return (0);
}


int main() {
    pthread_t first, second;
    pthread_create(&first, 0, account1, 0);
    pthread_create(&second, 0, account2, 0);

    printf("Starting \n\n");
    pthread_join(first, 0);
    pthread_join(second, 0);

    printf("Threads completeand the balance is now $%d \n", balance);

    return 0;
}
