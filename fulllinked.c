#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *href){
	printf("linked list are---");
	while(href!=NULL){
		printf(" \n  %d  ",href->data);
		href=href->next;
	}
}

void push(struct node **href,int d){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data= d;
	newnode->next=(* href);
	(* href)=newnode;
}

 void insertAfter(struct node* ref,int d){
	if(ref==NULL){
		printf("previous node cannot be null");
		return;
	}
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=ref->next;
	ref=newnode;
}

void swap(struct node **href, int x,int y){
	struct node *currentx=*href;
	struct node *prevx=NULL;
		 struct node *currenty=*href;
		 	struct node *prevy=NULL;
	if(x==y)return;
	while(currentx && currentx->data!=x){
		prevx=currentx;
		currentx=currentx->next;
	}


		while(currenty && currenty->data!=y){
		prevy=currenty;
		currenty=currenty->next;
	}
	if(currentx==NULL || currenty==NULL){
		return;
	}
	if(prevx!=NULL){
		prevx->next=prevy;
	}
	else{
		*href=currenty;
	}
	if(prevy!=NULL){
		prevy->next=prevx;
	}
	else{
		*href=currentx;
	}
	struct node *temp=currentx;
	currentx->next=currenty->next;
	currenty->next=temp;

}

void reverse(struct node **href){
	struct node *current=*href;
	struct node *prev=NULL;
	struct node *next=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*href=prev;
}


void append(struct node **ref,int d){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *last=(* ref);
	if(*ref==NULL){
		(*ref)=newnode;
		return;
	}
	newnode->data=d;
	newnode->next=NULL;
	while(last->next != NULL){
		last=last->next;
		
	}
	last->next=newnode;
	return;
}
/*
 struct node* merge(struct node *a, struct node *b){
 	struct node* tempo=NULL;
 	if(a==NULL) return b;
 	else if(b==NULL) return a;
 	if(a->data <= b->data){
 		tempo= a;
 		tempo->next=merge(a->next,b);
	 }
	 else{
	 	tempo=b;
	 	tempo->next=merge(a,b->next);
	 }
	 return (tempo);
 }
 */
 
  struct node *merge(struct node *a, struct node *b){
     struct node *temp=NULL;  	
	  if(a==NULL)return b;
  	else if(b==NULL)return a;
  	if(a->data<= b->data){
  		temp= a;
  		temp->next=merge(a->next,b);
	  }
	else{
		temp= b;
		temp->next=merge(a,b->next);
	}
	return temp;
  }
 
int main(){
	struct node *head=NULL;
	push(&head,2);
	append(&head,4);
	append(&head,6);
	append(&head,8);
/*	append(&head,10);
	append(&head,12);
		display(head);
	swap(&head,2,4);
	printf("\n new");
	display(head);
	reverse(&head);
		printf("\n new reverse");
		*/
	display(head);
		struct node *newhead=NULL;
	push(&newhead,3);
	append(&newhead,5);
	append(&newhead,15);
		display(newhead);
	struct node *my=NULL;
      my=merge(head,newhead);
   display(my);

	return 0;
}
