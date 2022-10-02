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
	int  counter, counter1, swap,s=0, e=n;
    for (counter = 0 ; counter < n - 1; counter++){
        for (counter1 = 0 ; counter1 < n - counter - 1; counter1++){
            if (arr[counter1] > arr[counter1+1]){
                swap = arr[counter1];
                arr[counter1]   = arr[counter1+1];
                arr[counter1+1] = swap;
            }
        }
    }
	while(s<=e){
		int mid=(s+e)/2;
		
		if(arr[mid]==key){
			printf("\n\nBy using Binary search\nElement is found at index %d",mid);
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
    scanf("%d",&key);
    linsearch(arr,n,key);
    printf("%d",binsearch(arr,n,key));
}