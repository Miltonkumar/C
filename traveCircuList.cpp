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

void splitlist(struct node *href,struct node **onehead,struct node **twohead){
	struct node *temp=href;
	if(href==NULL){
	    return;
	}
	struct node *fastp=href;
	struct node *slowp=href;
	while(fastp->next!=href && fastp->next->next!=href){
		fastp=fastp->next->next;
		slowp=slowp->next;
	}
	if(fastp->next->next==href){
		fastp=fastp->next;
	}
	*onehead=href;
	if(href->next!=href){
		*twohead=slowp->next;
	}
	
	slowp->next=href;
	fastp->next=*twohead;
}

int main(){
	struct node *head=NULL;
	push(1,&head);
	push(2,&head);
	push(3,&head);
	push(4,&head);
	push(5,&head);
	push(6,&head);
		printnode(head);
	struct node *first=NULL,*second=NULL;
	splitlist(head,&first,&second);
	printf("\n new first half");
		printnode(first);
		printf("\n second half");
    	printnode(second);	

	return 0;
}
