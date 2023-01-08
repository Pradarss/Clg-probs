#include <stdio.h>
#include <stdlib.h>

// Iterate through the list of elements.
// Compare each element with the next element.
// If the element is greater than the next element, swap them.
// Repeat this process until the list is sorted.
void bubble_sort(int arr[], int n) {
    int arr[] = {5, 1, 4, 2, 8};
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  display(arr, n);
}

// Iterate through the list of elements.
// For each element, compare it with the elements on its left.
// If the element is smaller than any of the elements on its left, shift those elements one position to the right and insert the element in its correct position.
// Repeat this process until the list is sorted.
void insertion_sort(int arr[], int n) {
    int arr[] = {5, 1, 4, 2, 8};
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  display(arr, n);
}

// Select a pivot element from the list.
// Divide the list into two sublists: one containing elements less than the pivot, and one containing elements greater than the pivot.
// Recursively sort the two sublists.
// Combine the sorted sublists and the pivot element to get the sorted list.
void quick_sort(int arr[], int low, int high) {
    int arr[] = {5, 1, 4, 2, 8};
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
  display(arr, n);
}

// Iterate through the list of elements.
// For each element, find the minimum element in the list.
// Swap the element with the minimum element.
// Repeat this process until the list is sorted.
void selection_sort(int arr[], int n) {
    int arr[] = {5, 1, 4, 2, 8};
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
  display(arr, n);
}

// If the list has more than one element, divide the list into two sublists.
// Recursively sort the two sublists.
// Merge the two sorted sublists to get the sorted list.
void merge(int arr[], int l, int m, int r) {
    int arr[] = {5, 1, 4, 2, 8};
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void merge_sort(int arr[], int l, int r) {
    int arr[] = {5, 1, 4, 2, 8};
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
  display(arr, n);
}

// Build a heap from the list of elements.
// Swap the first element (which is the largest) with the last element.
// Discard the last element and heapify the remaining list.
// Repeat this process until the list is sorted.
void heapify(int arr[], int n, int i) {
    int arr[] = {5, 1, 4, 2, 8};
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }
  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}
void heap_sort(int arr[], int n) {
    int arr[] = {5, 1, 4, 2, 8};
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
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

  insertion_sort(arr, n);
  printf("Array after Insertion sort: \n");
  display(arr, n);

  quick_sort(arr, 0, n - 1);
  printf("Array after Quick sort: \n");
  display(arr, n);

  selection_sort(arr, n);
  printf("Array after Selection sort: \n");
  display(arr, n);

  merge_sort(arr, 0, n - 1);
  printf("Array after Merge sort: \n");
  display(arr, n);

  heap_sort(arr, n);
  printf("Array after Heap sort: \n");
  display(arr, n);

  return 0;
}