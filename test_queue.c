#include <stdio.h>
#include <assert.h>

#include "../../src/queue/queue.h"

int main(void)
{
    Queue q;

    initQueue(&q);

    assert(isEmpty(&q) == 1);

    enqueue(&q, 100);
    enqueue(&q, 200);

    assert(isEmpty(&q) == 0);

    assert(dequeue(&q) == 100);
    assert(dequeue(&q) == 200);

    assert(isEmpty(&q) == 1);

    printf("Queue Unit Test Passed\n");

    return 0;
}