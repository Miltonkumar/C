#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **href,int d){
    	struct node *newnode=(struct node*)malloc(sizeof(struct node));
    	newnode->data=d;
    	newnode->next=*href;
    	*href=newnode;
}

void printnode(struct node *href){
	
	while(href!=NULL){
		printf("   %d",href->data);
		href=href->next;
	}
}

struct node *rotate(struct node *href,int d){
	int c=0;
	struct node *temp=href,*newtemp;
	if(href==NULL)return;
	while(temp!=NULL&& c<d){
		c++;
		temp=temp->next;
	}
	newtemp=temp->next;
	temp->next=NULL;
	temp=newtemp;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=href;
	return newtemp;
}

int main(){
	struct node *head=NULL;
	struct node *newhead=NULL;
	push(&head,3);
	push(&head,6);
	push(&head,5);
    push(&head,7);
	push(&head,8);
	push(&head,9);
	printnode(head);
	printf("\n ");
	
	newhead=rotate(head,3);
	printf("\n rotated");
	printnode(newhead);
	
	
	return 0;
}

