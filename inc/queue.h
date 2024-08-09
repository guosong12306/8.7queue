#pragma once
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 20

// 定义队列结构体，主题是浮点数数组，有队头队尾指针
typedef struct queue_t
{
    float data[MAX_SIZE];
    unsigned int head;
    unsigned int tail;
}queue_t;

void queue_init(queue_t *queue);
bool enqueue(queue_t *queue, float value);
bool dequeue(queue_t *queue, float *value);
bool queue_front(queue_t *queue, float *value);
bool queue_is_full(queue_t *queue);
bool queue_is_empty(queue_t *queue);


