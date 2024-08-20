#include <iostream>
using namespace std;
//space complexity is O(n)
//time complexity is O(nlogn)
//Inversion count problem is important application of it

void printArray(int arr[], int size);
void merge(int arr3[], int s, int e);
void mergeSort(int arr[], int s, int e);
int main() {
	int arr[4] = { 4,3,2,1 };
	printArray(arr, 4);
	mergeSort(arr, 0, 3);
	printArray(arr, 4);
	return 0;
}

//this function simply prints the array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//this function takes an array divide it into two parts, merge these two arrays back into it in sorted way
void merge(int arr3[],int s,int e) {
	int mid = s + ((e - s) / 2);
	int size1 = mid - s + 1;
	int size2 = e - mid;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	int k = s;
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = arr3[k];
		k++;
	}
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = arr3[k];
		k++;
	}
	k = mid + 1;
	int s1 = 0;
	int s2 = 0;
	int s3 = s;
	while (s1<size1 && s2<size2)
	{
		if (arr1[s1]>arr2[s2])
		{
			arr3[s3] = arr2[s2];
			s3++;
			s2++;
		}
		else
		{
			arr3[s3] = arr1[s1];
			s3++;
			s1++;
		}
	}
	while (s1<size1)
	{
		arr3[s3] = arr1[s1];
		s3++;
		s1++;
	}
	while (s2<size2)
	{
		arr3[s3] = arr2[s2];
		s3++;
		s2++;
	}
	cout << "Array 1 is : " << endl;
	printArray(arr1, size1);
	cout << "Array 2 is : " << endl;
	printArray(arr2, size2);
	cout << "Array 3 is : " << endl;
	printArray(arr3, e+1);
	delete[] arr1;
	delete[] arr2;
}


//this function implements merge sort using recursion 
void mergeSort(int arr[], int s, int e) {
	if (s>=e)
	{
		return;
	}
	int mid = s + ((e - s) / 2);
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	merge(arr, s, e);
}