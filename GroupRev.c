#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

 struct node* createnode(int d){
     printf("milton"); 	
	 struct node *p=(struct node*)malloc(sizeof(struct node));
 	p->data=d;
 	p->next=NULL;
 	return p;
 }
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

struct node* summation(struct node *one, struct node *two){
//	printf("milton");
     struct node *temp=NULL;
     struct node* current=NULL;
     struct node *temp2=NULL;
	int carry=0;
	while(one!=NULL || two!=NULL){
		int sum=carry+(one!=NULL?one->data:0)+(two!=NULL?two->data:0);
		if(sum>=10){
			carry=1;
		}
		else{carry=0;
		}
		sum=sum%10;
		temp=createnode(sum);
		if(temp2==NULL){
			temp2=temp;
			current=temp;
		}
		current->next=temp;
		current=temp;
		if(one){
		one=one->next;
	}
	  if(two){
	  	two=two->next;}
	  	
	}
	if(carry>0){
			temp=createnode(carry);
				current->next=temp;
		current=temp;
	}
	return temp2;
}

int main(){
	struct node *head=NULL;
	struct node *newhead=NULL;
	push(&head,3);
	push(&head,6);
	push(&head,5);
	
	printf("first nodelist");
	printnode(head);
	
	push(&newhead,2);
	push(&newhead,4);
	push(&newhead,8);
	
	printf("second nodelist");
	printnode(newhead);
	
	struct node *sss=summation(head,newhead);
	printf("after function called");
	printnode(sss);
	
	return 0;
}
