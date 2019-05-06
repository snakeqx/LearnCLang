#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

typedef int ElemType;

typedef struct {
    ElemType *Data;
    int MaxSize;
    int Head;
    int Tail;
    int Size;
} Queue;

// 列队是否非空
bool isQueueEmtpy(Queue *q){
    //如果头等于尾，列队尾空
    if (q->Head == q->Tail) return true;
    return false;
}

// 列队是否为满
bool isQueueFull(Queue *q){
    //如果尾大于最大值，列队满，但有可能为假溢出
    if(q->Tail >= q->MaxSize) return true;
    return false;
}

// 列队是否刚刚被创建
bool isQueueInitialed(Queue *q){
    // 如果头尾都等于0，则刚刚被创建
    if(q->Tail==0 && q->Head==0) return true;
    return false;
}

// 列队是否假溢出
bool isQueueFakeOverflow(Queue *q){
    // 如果尾大于等于最大值，且头大于0，则为假溢出
    if((q->Tail >= q->MaxSize) &&(q->Head > 0)) return true;
    return false;
}

// 初始化列队
Queue *queueInit(int maxsize){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->Data = malloc(sizeof(ElemType)*maxsize);
    q->MaxSize = maxsize;
    q->Head = 0;
    q->Tail = 0;
    q->Size = 0;
    return q;
}

// 入队
bool enQueue(Queue *q, ElemType value){
    if(isQueueFull(q)) return false;
    *(q->Data+q->Tail++) = value;
    q->Size++;
    return true;
}

// 出队
bool deQueue(Queue *q, int* ret){
    *ret=0;
    if(isQueueEmtpy(q)) return false;
    *ret=q->Data[q->Head++];
    q->Size--;
    return true;
}

// 打印队列
void printQueue(Queue *q){
    for(int i=q->Head;i<q->Tail;i++)
        printf("%d,",q->Data[i]);
    printf("\n");
}