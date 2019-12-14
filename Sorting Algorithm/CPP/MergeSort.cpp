#include<iostream>

using namespace std;

void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}
 
int main(void)
{
    const int n = 7;

 
	int arr[n] = {89,45,68,90,29,34,17};
 
	MergeSort(arr, 0, n-1);
 
	for (int i = 0; i < n; i++)
        cout<<arr[i]<<' ';
 
	return 0;
}