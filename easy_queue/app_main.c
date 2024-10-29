#include <stdio.h>
#include <stdbool.h>
#define QUEUE_SIZE 5 // 队列的最大大小

typedef struct
{
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}

// 判断队列是否已满
bool isFull(Queue *q)
{
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

// 入队操作
bool enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("队列已满，无法入队\n");
        return false;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % QUEUE_SIZE; // 循环队列
    return true;
}

// 出队操作
bool dequeue(Queue *q, int *value)
{
    if (isEmpty(q))
    {
        printf("队列为空，无法出队\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE; // 循环队列
    return true;
}

// 打印队列内容
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return;
    }
    int i = q->front;
    printf("队列内容：");
    while (i != q->rear)
    {
        printf("%d ", q->data[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);

    int value;
    dequeue(&q, &value);
    printf("出队元素: %d\n", value);

    printQueue(&q);

    return 0;
}
