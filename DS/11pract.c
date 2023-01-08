#include <stdio.h>
#include <stdlib.h>

// Iterate through the list of elements.
// Compare each element with the next element.
// If the element is greater than the next element, swap them.
// Repeat this process until the list is sorted.
void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
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

  bubble_sort(arr, n);
  printf("Array after Bubble sort: \n");
  display(arr, n);

  return 0;
}