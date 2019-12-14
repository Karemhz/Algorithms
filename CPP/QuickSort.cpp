#include<iostream>

void swap(int *x, int *y){    
    
 int temp = *x;
 *x = *y;
 *y = temp;

}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
   
  
int main(void) 
{ 
    const int n = 7;
    int arr[] = {89, 45, 68, 90, 29, 34, 17}; 
    quickSort(arr, 0, n-1); 
    for(int i = 0; i < n; i++)
      std::cout<<arr[i]<<' ';
    return 0; 
} 