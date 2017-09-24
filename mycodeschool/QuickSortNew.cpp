#include <iostream>

using namespace std;
template<typename T>
void swap(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b =tmp;
}
template<typename T>
int partition(T *arr, int start, int end)
{
	T x = arr[end];
	int i = start - 1;
	for(int j = start; j <= end-1; j++)
	{
		if(arr[j] <= x)
		{
			i = i + 1;
			swap<T>(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return i+1;
}

template<typename T>
void quickSort(T *arr, int start, int end)
{
	if(start<end)
	{
		int q = partition<T>(arr, start, end);
		quickSort<T>(arr, start, q-1);
		quickSort<T>(arr, q+1, end);
	}
}

int main()
{
	char arr[] = "Lokesh";
	quickSort<char>(arr, 0, 5);
	cout << arr << endl;
	return 0;
}
