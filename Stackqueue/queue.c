#include "queue.h"
void QueueInit(Queue* queue) {
	assert(queue);
	queue->phead = NULL;
	queue->ptail = NULL;
	queue->size = 0;
}

void QueueDestroy(Queue* queue) {
	assert(queue);
	QNode* cur = queue->phead;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	queue->phead = queue->ptail = NULL;
	queue->size = 0;
}


void QueuePush(Queue* queue, QDataType x) {
	assert(queue);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode==NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (queue->phead==NULL)
	{
		assert(queue->ptail==NULL);
		queue->phead = queue->ptail = newnode;
	}
	else {
		queue->ptail->next = newnode;
		queue->ptail = newnode;
	}
	queue->size++;
}

void QueuePop(Queue* queue) {
	assert(queue);
	assert(!QueueEmpty(queue));
	//1个节点
	if (queue->phead->next == NULL) {
		free(queue->phead);
		queue->phead = queue->ptail = NULL;
	}
	else { 
	  //多个节点
	  QNode* next = queue->phead->next;
	  free(queue->phead);
      queue->phead = next;
	}	
	queue->size--;
}

QDataType QueueFront(Queue* queue) {
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->phead->data;
}

QDataType QueueBack(Queue* queue) {
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->ptail->data;
}

int QueueSize(Queue* queue) {
	assert(queue);
	return queue->size;
}

bool QueueEmpty(Queue* queue) {
	assert(queue);
	return !queue->phead;
}

void QueuePrint(Queue* queue) {
	assert(queue);
	QNode* cur = queue->phead;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}