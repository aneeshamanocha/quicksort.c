/*
find bottom pivot, middle pivot, large pivot --> find median
choose pivot --> switch with last element --> compare all elements to last element
*/

#include <stdio.h>
#include <stdlib.h>

int getMedian(int arr[], int num1, int num2, int num3);
void quicksort(int arr[], int left, int right);
void print(int arr[], int size);
int partition(int arr[], int left, int right, int pivot);

int main(void) {
  //stores & seeds random numbers into array size 100
  srand(1);
  int arr[20];
  for(int i = 0; i < 20; i++) {
    arr[i] = rand() % 100;
  }
  int size = sizeof(arr)/sizeof(arr[0]);
  puts("before");
  print(arr, size);
  quicksort(arr, 0, size-1);
  puts("after");
  print(arr, size);
}

int getMedian(int arr[], int num1, int num2, int num3) {
  if(arr[num1] > arr[num2]) {
    if(arr[num2] >= arr[num3]) { //num 2 is in middle
      return num2;
    } else if(arr[num1] >= arr[num3]){ //num2 is smallest, num1 is largest --> num3 must be middle
      return num3;
    } else {
      return num1; //num1 is in middle
    }
  } else { //num2 >= num1
    if(arr[num1] >= arr[num3]) {
      return num1; //num1 is in middle
    } else if(arr[num2] >= arr[num3]){
      return num3;
    } else {
      return num2;
    }
  }
}

void quicksort(int arr[], int left, int right){
  if(left < right) {
    int index = getMedian(arr, left, (right+left+1)/2, right);
    //printf("input of index: %d %d %d\n", left, (right+1)/2, right);
    //printf("pivot: %d index: %d\n", arr[index], index);
    //printf("left: %d right: %d\n", left, right);

    //switch pivot to very end of array
    //printf("at index: %d right: %d\n", arr[index], arr[right]);
    int pivot = arr[index];
    arr[index] = arr[right];
    arr[right] = pivot;

    //print(arr, right+1);
    //sort appropriately
    int r = partition(arr, left, right-1, pivot);
    //printf("r = %d\n", r);
    //puts("hello");

    //divide & conquer on subarrays
    //printf("left: %d, r-1: %d, r+1: %d, right: %d\n", left, r-1, r+1, right);
    quicksort(arr, left, r-1);
    quicksort(arr, r+1, right);
  }

}

int partition(int arr[], int left, int right, int pivot){
  int l = left;
  int r = right;
  int tmp = 0;
  while(l < r){
    while(arr[l] <= pivot && l < r) {
      l++;
    }
    //printf("l: %d ", l);
    while(arr[r] >= pivot && r > l) {
      r--;
    }
    //printf("r: %d\n", r);
    if(l < r) {
      tmp = arr[l];
      arr[l] = arr[r];
      arr[r] = tmp;
      //print(arr, right+2);
    }
  }


  tmp = arr[r];
  arr[r] = arr[right+1];
  arr[right+1] = tmp;
  //print(arr, right+2);
  return r;
}

//print array
void print(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}
