#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STACK_INIT_SIZE 1000
#define STACKINCREMENT 10
#define SElemType char
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
void InitStack(SqStack* S) {
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)printf("创建失败\n");
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}
void Push(SqStack* S, SElemType e)
{
	if (S->top - S->base >= S->stacksize) {
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)printf("创建失败\n");
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;

}
void Pop(SqStack* S, SElemType* e) {

	e = *S->top;
	S->top --;

}
char GetTop(SqStack* S) {
	char e;

	S->top--;
	e = *(S->top);
	S->top++;

	return e;
}
int BracketCorrespondency(char* a)
{
	int i = 0,n;
	SqStack s;
	InitStack(&s);
	SElemType x;
	n = strlen(a);

	for (i = 0; i< n;i++) {

		switch (a[i]) {
		case '(':
			Push(&s, a[i]);
			break;
		case '[':
			Push(&s, a[i]);
			break;
		case '{':
			Push(&s, a[i]);
			break;
		case ')':
			x = GetTop(&s);
			if (x == '(')	Pop(&s, &x);
			else return 0;
			break;
		case ']':
			x = GetTop(&s);
			if (x == '[')Pop(&s, &x);
			else return 0;
			break;
		case '}':
			x = GetTop(&s);
			if (x == '{') Pop(&s, &x);
			else return 0;
			break;
		default:
			break;
		}


	}

	if (s.top != s.base) return 0;
	   else return 1;
}
int main() {

	char* s[1000]; int i;

	gets(s);

	i = BracketCorrespondency(s);
	printf("%d", i);


}
