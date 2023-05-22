#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* queue);

void QueueDestroy(Queue* queue);

void QueuePush(Queue* queue, QDataType x);

void QueuePop(Queue* queue);

QDataType QueueFront(Queue* queue);

QDataType QueueBack(Queue* queue);

int QueueSize(Queue* queue);

bool QueueEmpty(Queue* queue);

void QueuePrint(Queue* queue);