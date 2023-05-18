#include <stdio.h>
#include "stack.h"
#include <string.h>
void TestStack1() {
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	STDestroy(&st);
}
bool isValid(char* s) {
    ST st;
    STInit(&st);
    while (*s) {
        if (*s == '(' || *s == '{' || *s == '[') {
            STPush(&st, *s);
        }
        else {
            if (STEmpty(&st)) {
                return false;
            }
            char top = STTop(&st);
            if (*s == ')' && top != '(' || *s == ']' && top != '[' || *s == '}' && top != '{') {
                return false;
            }
            STPop(&st);
        }
        s++;
    }
    STDestroy(&st);
    return STEmpty(&st) ? true : false;

}
int main() {

    bool a=isValid("()");
    if (a==true)
    {
        printf("%d", 1);
    }
	return 0;
}
