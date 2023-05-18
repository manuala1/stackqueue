#include "stack.h"

void STInit(ST* pst) {
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STDestroy(ST* pst) {
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x) {
	if (pst->top==pst->capacity){
		int newCapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp=(STDataType*)realloc(pst->a,newCapacity*sizeof(STDataType));
		if (tmp==NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[(pst->top)++] = x;
}

STDataType STTop(ST* pst) {
	assert(pst);
	assert(!STEmpty(pst));
	return pst->a[pst->top - 1];
}

void STPop(ST* pst) {
	assert(pst);
	assert(!STEmpty(pst));
	pst->top--;
}

bool STEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;

}

int STSize(ST* pst) {
	assert(pst);
	return pst->top;

}