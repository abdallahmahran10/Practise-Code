#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b =tmp;
}

int partition(char arr[], int start, int end)
{
	int x = arr[end];
	int i = start;
	for(int j = start; j <= end-1; j++)
	{
		if(arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			++i;
		}
	}
	swap(&arr[i], &arr[end]);
	return i;
}

void quickSort(char arr[], int start, int end)
{
	if(start<end)
	{
		int q = partition(arr, start, end);
		quickSort(arr, start, q-1);
		quickSort(arr, q+1, end);
	}
}


int main()
{
	char str[] = "Lokesh";

	cout << "Before : " << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	quickSort(str, 0, 4);

	cout << "After : " << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	return 0;
}
