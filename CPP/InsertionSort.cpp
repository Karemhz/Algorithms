#include <iostream> 
using namespace std; 
  
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  

int main(void)  
{  
    const int n = 7;
    int arr[] = {89, 45, 68, 90, 29, 34, 17};    
    insertionSort(arr, n); 
     
     for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";   
  
    return 0;  
}  