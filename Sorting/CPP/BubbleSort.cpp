#include<iostream>

void swap(int *x, int *y){
 
 int temp = *x;
 *x = *y;
 *y = temp;

}

int main(void){
   
   const int n = 7;
   int arr[n] = {89,45,68,90,29,34,17};

   for(int i = 0; i < n-1; i++)
       for(int j = 0; j < n-1-i; j++)
          if(arr[j+1] < arr[j])
             swap(&arr[j], &arr[j+1]);


    for(int i = 0; i < n; i++)
    std::cout<<arr[i] << ' ';
    
    return 0;
}