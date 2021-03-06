#include <iostream>

using namespace std;

const int size = 21;
int *arr;
int index = 1;

void insert(int x)
{
	int count = index;
	if (count == size - 1)
		cout << "Heap is full. ";
	else
	{
		arr[count] = x;
		while (count != 1 && arr[count/2] < arr[count])
		{
			swap(arr[count/2], arr[count]);
			count /= 2;
		}
	}
	index++;
}

void deletion()
{
	int i=1;
	int x = arr[1];
	arr[i] = arr[index-1];
	arr[index--] = NULL;

	while (arr[i] < arr[2*i] || arr[i] < arr[2*i + 1] && arr[2*i] != NULL)
	{
		if (arr[2*i] < arr[2*i+1]) 
		{
			swap(arr[i], arr[2*i+1]);
			i = 2*i+1;
		}
		else
		{
			swap(arr[i], arr[2*i]);
			i *= 2;
		}
	}
}

void print()
{
	for (int i=1; i < index; i++)
		cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
	
	return 0;
}
