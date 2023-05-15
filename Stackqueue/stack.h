#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

void STPush(ST* pst, STDataType x);

STDataType STTop(ST* pst);

void STPop(ST* pst);

bool STEmpty(ST* pst);

int STSize(ST* pst);