#include<stdio.h>
#include<stdlib.h>

// Iterate through the list of elements.
// For each element, compare it with the elements on its left.
// If the element is smaller than any of the elements on its left, shift those elements one position to the right and insert the element in its correct position.
// Repeat this process until the list is sorted.
void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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

  insertion_sort(arr, n);
  printf("Array after insertion sort: \n");
  display(arr, n);

  return 0;
}