#include <stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r){
	
       int n1=m-l+1;
       int n2=r-m;
       int i=0,j=0,k=0;
	   int ll[n1],rr[n2];
	   for(i=0;i<n1;i++){
	   	ll[i]=arr[l+i];
	   }	
	   for(j=0;j<n2;j++){
	   	rr[j]=arr[m+1+j];
	   }
	   i=0;j=0;k=l;
	   while(i<n1 && j<n2){
	   	if(ll[i]<rr[j]){
	   		arr[k]=ll[i];
	   		i++;
	   		k++;
		   }
		   else{
		   	arr[k]=rr[j];
		   	j++;
		   	k++;
		   }
	   }
	   while(i<n1){
	   		arr[k]=ll[i];
	   		i++;
	   		k++;
	   }
	   while(j<n2){
	   		arr[k]=rr[j];
		   	j++;
		   	k++;
	   }
	
}


 void mergesort(int arr[],int l,int r){
 	
 	 if(l<r){ 
 	 int m= (l+r)/2;
 	 mergesort(arr,l,m);
 	 mergesort(arr,m+1,r);
 	 merge(arr,l,m,r);
     }
 }
 
 void printArray(int ar[],int s){
 	int i=0;
 	for(i=0;i<s;i++){
 		printf("%d ",ar[i]);
	 }
 }
 
 int main(){
 	int arr[]={7,3,2,87,5,9,8};
 	int arr_size=sizeof(arr)/sizeof(arr[0]);
 	printf("the array unsorted is ...");
 	printArray(arr,arr_size);
 	mergesort(arr,0,arr_size-1);
 	
 	printf("the array sorted is ...");
 	printArray(arr,arr_size);
    
    return 0;
 }
