#include<stdio.h>
#include<stdlib.h>

struct stack{
	int capacity;
	int top;
	int *array;
};

struct stack* createStack(int capa){
	struct stack *newstack=(struct stack*)malloc(sizeof(struct stack));
	newstack->top=-1;
	newstack->capacity=capa;
	newstack->array=(int *)malloc(newstack->capacity*sizeof(int));
	return newstack;
}


void push(struct stack *full,int data){
	if(isfull(full))return;
	full->array[++full->top]=data;
	
}


void printstack(struct stack *dis){
	if(isempty(dis))return ;
	while(dis->top>-1){
		printf("%d\n",dis->array[dis->top]);
		dis->top--;
	}
}

int isfull(struct stack *check){
	 return check->top==check->capacity-1;
}

int isempty(struct stack *check){
	return check->top==-1;
}
int main(){
	struct stack *n=createStack(2);
	push(n,1);
	push(n,2);
	push(n,3);
	printstack(n);
	
	return 0;
}

