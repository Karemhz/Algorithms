#include<iostream>


void swap(int *x , int *y){

  int temp = *x;
  *x = *y;
  *y = temp;
}



int main(void)
{
   const int n = 7;
   int min;
   int arr[n] = {89,45,68,90,29,34,17};
   
   for(int i = 0; i < n-1; i++){
      min = i;
      for(int j = i + 1; j < n; j++)
        if(arr[j] < arr[min])
        min = j;
    swap(&arr[i] , &arr[min]);
   }

  for(int i = 0; i < n; i++)
    std::cout<<arr[i] << ' ';

    return 0;
}