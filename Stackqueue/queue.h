#pragma once

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
