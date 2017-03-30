#include<stdio.h>
#include<stdlib.h>

struct Qnode{
	int key;
	struct Qnode *next;
};

struct Queue{
	struct Qnode *front;
	struct Qnode *rear;
};

struct Qnode* newnode(int data){
	struct Qnode *temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->key=data;
	temp->next=NULL;
	return temp;
}

struct Queue* createQueue(){
	struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->front=NULL;
	temp->rear=NULL;
	return temp;
}

void enqueue(struct Queue *q,int k){
	struct Qnode *temp=newnode(k);
	if(q->rear==NULL){
		q->front=q->rear=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
}
void dequeue(struct Queue *q){
	if(q->front==NULL){
		return;
	}
	struct Qnode *temp=q->front;
	printf("item deleted is %d ",q->front->key);
	q->front=q->front->next;
	if(q->front==NULL){
		q->rear=q->front;
	}
	free(temp);
}

int main(){
	struct Queue *qq=createQueue();
	enqueue(qq,1);
	enqueue(qq,2);
	enqueue(qq,3);
	enqueue(qq,4);
	
	dequeue(qq);
		dequeue(qq);
			dequeue(qq);
	return 0;
}
