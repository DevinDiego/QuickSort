#include <iostream>

int partition(int* arr, int low, int high)
{
	int pivot = arr[low];
	int i = low;
	int j = high;
	do {
		do { i++; } while (arr[i] <= pivot);
		do { j--; } while (arr[j] > pivot);

		if (i < j)
		{
			std::swap(arr[i], arr[j]);
		}

	} while (i < j);

	std::swap(arr[low], arr[j]);
	return j;
}

void quick(int* arr, int low, int high)
{
	if (low < high)
	{
		int j = partition(arr, low, high);
		quick(arr, low, j);
		quick(arr, j + 1, high);
	}
}

void display(int* arr, const int& size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
}
int main()
{
	int arr[] = { 9, 2, 1, 3, 7, 0, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	quick(arr, 0, size);
	display(arr, size);






	std::cout << "\n\n";
	system("pause");
	return 0;
}