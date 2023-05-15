#include "stack.h"

void STInit(ST* pst) {
	assert(pst);
	pst->a = (STDataType*)malloc(sizeof(STDataType)*100);
	if (pst->a==NULL){
		perror("malloc fail");
		return;
	}
	pst->capacity = 100;
	pst->top = -1;
}

void STDestroy(ST* pst) {
	assert(pst);
	free(pst->a);
	pst->capacity = 0;
	pst->top = -1;
}

void STPush(ST* pst, STDataType x);

STDataType STTop(ST* pst) {
	
}

void STPop(ST* pst) {
	


	pst->top--;
}

bool STEmpty(ST* pst) {
	return pst->top == -1 ? true : false;

}

int STSize(ST* pst) {
	return pst->top + 1;
}