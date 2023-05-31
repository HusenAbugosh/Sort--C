// Husen Abugosh/ 1210338 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// to fill the array randomly 
void RandomFill(int a[], int length, int max){

    for(int i=0; i<length; i++){
        a[i] = (rand() % max) + 1;  //  random num from 1 --> max
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////


// InsertionsSort: Complexity: nlogN 
void InsertionsSort(int a[], int length){

  for (int i = 1; i < length; i++)
  {

    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////


// MergeSort  Complexity: nlogN   /
void merge_sorted_arrays(int a[], int l, int m, int r){

  int left_length = m - l + 1;
  int right_length = r - m;
  
  int temp_left[left_length];
  int temp_right[right_length];
  
  int i, j, k;
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  
  for (i = 0, j = 0, k = l; k <= r; k++)
  {

    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    } else {
      a[k] = temp_right[j];
      j++;
    }
  }  
}

void merge_sort_recursion(int a[], int l, int r){
  // we stop recursion when l >= r
  if (l < r)
  {

    int m = l + (r - l) / 2;

    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sort(int a[], int length){
  merge_sort_recursion(a, 0, length - 1);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

//selctionSort  Complexity: O(n^2)  / 
void SelctionSort(int a[], int length){

    for(int i=0; i < length -1; i++){  // N

        int minPos = i;  
        for(int j = i+1; j < length; j++){    // N
            if(a[j] < a[minPos] ){    // > for descending
                minPos = j;
            }
        }
        // after comparing an elemnt with all the next elemnt of it will save the min elemnt in minPos var and then swape it .
        if (minPos != i){
            int temp = a[i];
            a[i] = a[minPos];
            a[minPos] = temp;
        }
    }


}

int main(){

    //  // small test
    // int a[] = {9,4,8,1,7,0,3,2 ,5,6};
    // int length = 10;

   
    srand(time(NULL));
    int length = 100000;
    int a[length];
    RandomFill(a,length,1000);
    int ticks = clock();

   // to try the sort just remove the:  // 

    // SelctionSort(a,length);
    // merge_sort(a,length);
    InsertionsSort(a, length);

   printf("%f\n", (float)ticks/CLOCKS_PER_SEC);

    // to print the result:
    // for(int i=0; i<length;i++){
    //     printf("a[%d] = %d\n",i,a[i]);
    // }
return 0;

}