#include<stdio.h>

int linsearch(int arr[],int n,int key){
    int i;
    for(i=0;i<n;++i)
        if(arr[i]==key)
            break;
     
    if(i<n)
        printf("By using Linear search\nElement is found at index %d",i);
    else
        printf("Element not found\n");
  
return -1;
}

int binsearch(int arr[],int n,int key){
	int  counter=1, swap,s=0, e=n;
	while(counter<n){
		for(int i=0;i<n-counter;i++){
			if(arr[i]>arr[i+1]){
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		counter++;
	}

	while(s<=e){
		int mid=(s+e)/2;
		
		if(arr[mid]==key){
			printf("\n\nBy using Binary search\nElement is found at index %d",mid);
            return 0;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
return -1;
}

void main(){
    int n,i,key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search : ");
    scanf("%d",&key);
    linsearch(arr,n,key);
    binsearch(arr,n,key);
}