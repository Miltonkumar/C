#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void push(struct node **href,int d){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->prev=NULL;
	newnode->next=*href;
	*href=newnode;
}

void pushafter(struct node *href,int d){
	while(href->next!=NULL){
		href=href->next;
	}
	struct node *newnode=(struct  node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	newnode->prev=href;
	href->next=newnode;
	
}

void deletenode(struct node **href,struct node *del){
	if(del==NULL || *href==NULL){
		return;
	}
	 if(del==*href){
		del->next->prev=NULL;
		*href=del->next;
	}
		if(del->next!=NULL && del->prev!=NULL){
		del->prev->next=del->next;
		del->next->prev=del->prev;
	}
	 if(del->next==NULL){
		del->prev->next=del->next;
	}

	free(del);
	return;
}

void printnode(struct node *href){
	while(href!=NULL){
		printf("\n %d",href->data);
		href=href->next;
	}
	
}
int main(){
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
		push(&head,3);
		//	push(&head,4);
			//	push(&head,5);
			//		push(&head,6);
				//	pushafter(head,34);
					
					printf("\n the doubly linked list");
					printnode(head);
					deletenode(&head,head->next);
					
						printf("\n the doubly linked list after deleted");
					printnode(head);	
	getchar();
}
