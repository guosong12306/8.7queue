#include "inc/queue.h"

// 队列的初始化，传入队列的指针，将队头队尾指针设定为0
void queue_init(queue_t *queue)
{
    queue->head = 0;
    queue->tail = 0;
};

// 入队，传入队列的指针以及入队的数据，若队列已满会返回false
bool enqueue(queue_t *queue, float value)
{
    if(queue_is_full(queue))
    {
        return false;
    }
    else
    {
        queue->data[queue->tail%MAX_SIZE] = value;
        queue->tail++;
    }
};

// 出队，传入队列的指针以及出队的数据指针，若队列为空会返回false
bool dequeue(queue_t *queue, float *value)
{
    if (queue_is_empty(queue))
    {
        return false;
    }
    else
    {
        *value = queue->data[queue->head%MAX_SIZE];
        queue->head++;
    }
};

// 读队头元素，传入队列的指针和一个浮点数指针，队列为空会报错
bool queue_front(queue_t *queue, float *value)
{
    if (queue_is_empty(queue))
    {
        return false;
    }
    else
    {
        *value = queue->data[queue->head%MAX_SIZE];
    }
};

// 判断队列是否满，传入队列指针参数
bool queue_is_full(queue_t *queue)
{
    if(queue->tail-queue->head==MAX_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
};

// 判断队列是否空，传入队列指针参数
bool queue_is_empty(queue_t *queue)
{
    if(queue->head == queue->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
};

// 代码测试，通过循环向队列中加入1~9九个浮点数，然后用循环将其读出
int main(int argc, char const *argv[])
{
    queue_t *queue;
    queue_init(queue);
    for(int i = 0; i < 10; i++)
    {
        enqueue(queue, (float)i);
    }
    for(int i = 0; i < 10; i++)
    {
        float temp;
        dequeue(queue, &temp);
        printf("%f\n", temp);
    }
    return 0;

}
