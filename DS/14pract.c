#include<stdio.h>
#include<stdlib.h>

// Iterate through the list of elements.
// For each element, find the minimum element in the list.
// Swap the element with the minimum element.
// Repeat this process until the list is sorted.
void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

void display(int arr[], int n){
  for (int i = 0; i < n; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n\n");
}


int main() {
  int arr[] = {5, 1, 4, 2, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array before sorting:\n");
  display(arr, n);

  selection_sort(arr, n);
  printf("Array after selection sort: \n");
  display(arr, n);

  return 0;
}