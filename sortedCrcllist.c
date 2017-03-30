#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(int d, struct node **href){
	struct node *temp=*href;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=newnode;
	if(*href==NULL){
		*href=newnode;
	}
	else{
		while(temp->next!=*href){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=*href;
		*href=newnode;
	}
}

void printnode(struct node *href){
	struct node *temp=href;
	do{
		printf("\n %d",temp->data);
		temp=temp->next;
	}while(temp!=href);
		
}

void sortlist(struct node **href,int d){
	struct node *current=*href;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(*href==NULL){
		newnode->data=d;
		newnode->next=newnode;
		*href=newnode;
	}
	else if(current->data>d){
		newnode->data=d;
		newnode->next=*href;
		current->next=newnode;
		*href=newnode;
	}
	else{
		while(current->next!=*href && current->next->data<d){
			current=current->next;
		}
		newnode->data=d;
		newnode->next=current->next;
	    current->next=newnode;
		
	}
}

int main(){
	struct node *head=NULL;
//	push(1,&head);
//	push(2,&head);
//	push(3,&head);
//	push(4,&head);
//	push(5,&head);
//	push(6,&head);
		sortlist(&head,3);
		sortlist(&head,6);
		sortlist(&head,9);
		sortlist(&head,7);
		printnode(head);
//	struct node *first=NULL,*second=NULL;
	
//	printf("\n new first half");
//		printnode(first);
//		printf("\n second half");
  //  	printnode(second);	

	return 0;
}
