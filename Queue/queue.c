#include"queue.h"
#include<stdio.h>

int main(){
    Queue *q = queueInit(3);
    enQueue(q, 50);
    enQueue(q, 20);
    enQueue(q, 10);
    printQueue(q);
    enQueue(q, 100);
    printQueue(q);
    int p=0;
    deQueue(q, &p);
    printf("%d\n", p);
    printQueue(q);
    free(q);
    return 0;
}