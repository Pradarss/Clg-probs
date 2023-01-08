#include<stdio.h>
#include<stdlib.h>

// If the list has more than one element, divide the list into two sublists.
// Recursively sort the two sublists.
// Merge the two sorted sublists to get the sorted list.
void merge(int arr[], int l, int m, int r) {
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
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
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

  merge_sort(arr, 0, n - 1);
  printf("Array after merge sort: \n");
  display(arr, n);

  return 0;
}