#include<stdio.h>
#include<stdlib.h>

// Select a pivot element from the list.
// Divide the list into two sublists: one containing elements less than the pivot, and one containing elements greater than the pivot.
// Recursively sort the two sublists.
// Combine the sorted sublists and the pivot element to get the sorted list.
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = low;
    int i = low;
    int j = high;
    while (i < j) {
      while (arr[i] <= arr[pivot] && i <= high) {
        i++;
      }
      while (arr[j] > arr[pivot] && j >= low) {
        j--;
      }
      if (i < j) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
    int temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    quick_sort(arr, low, j - 1);
    quick_sort(arr, j + 1, high);
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

  quick_sort(arr, 0, n - 1);
  printf("Array after quick sort: \n");
  display(arr, n);

  return 0;
}