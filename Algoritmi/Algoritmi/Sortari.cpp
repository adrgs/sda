#include <iostream>
#include <random>
#include <cassert>

template <typename T>
void Swap(T*a, T*b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T>
void ControlSort(T *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				Swap(arr + j, arr + i);
		}
	}
}

template <typename T>
void BubbleSort(T *arr, int n)
{
	bool sorted = false;
	while (sorted==false)
	{
		sorted = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i + 1] < arr[i]) {
				sorted = false;
				Swap<T>(arr + i, arr + i + 1);
			}
		}
		if (sorted == true) break;
	}
}

template <typename T>
void SelectionSort(T *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			Swap(arr + i, arr + min_idx);
		}
	}
}

template <typename T>
void InsertionSort(T *arr, int n)
{
	int i, j;
	T key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template <typename T>
int partition(T *arr, int low, int high)
{
	T pivot = arr[high]; // pivot  
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			Swap<T>(arr+i, arr+j);
		}
	}
	Swap<T>(arr + i + 1, arr + high);
	return (i + 1);
}

template <typename T>
void quickSort(T *arr, int low, int high)
{
	if (low < high)
	{
		int p = partition<T>(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

template <typename T>
void QuickSort(T *arr, int n)
{
	quickSort(arr, 0, n-1);
}

template <typename T>
void ShellSort(T *arr, int n)
{
	for (int gap = n / 2; gap > 0; gap = gap / 2)
	{
		for (int i = gap; i < n; i++)
		{
			T tmp = arr[i];
			int j;
			for (j = i;j>=gap && arr[j-gap]>tmp; j-=gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = tmp;
		}
	}
}

template <typename T>
void merge(T *arr, int low, int mid, int high) 
{
	int n1 = mid-low+1;
	int n2 = high-mid;

	T *arrL = new T[n1];
	T *arrR = new T[n2];

	for (int i = 0; i < n1; i++)
		arrL[i] = arr[low + i];
	for (int j = 0; j < n2; j++)
		arrR[j] = arr[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = low;
	while (i < n1 && j < n2)
	{
		if (arrL[i] < arrR[j]) {
			arr[k] = arrL[i];
			i++;
		}
		else {
			arr[k] = arrR[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = arrL[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = arrR[j];
		j++;
		k++;
	}

	delete[] arrL;
	delete[] arrR;
}

template <typename T>
void mergeSort(T *arr, int low, int high)
{
	if (low < high) {
		int m = (low + high) / 2;
		mergeSort(arr, low, m);
		mergeSort(arr, m+1, high);
		merge(arr, low, m, high);
	}
}

template <typename T>
void MergeSort(T *arr, int n)
{
	mergeSort(arr, 0, n - 1);
}

int* GenerateRandomArray(int len)
{
	int* arr = new int[len];
	for (int i=0;i<len;i++)
		arr[i] = rand() % (len+30);

	return arr;
}

void UnitTests(int n)
{
	std::cout << "Started unit test\n";
	int *InitialArray = GenerateRandomArray(n);
	int *ControlArray = new int[n];
	int *BubbleArray = new int[n];
	int *SelectionArray = new int[n];
	int *InsertionArray = new int[n];
	int *QuickArray = new int[n];
	int *ShellArray = new int[n];
	int *MergeArray = new int[n];
	std::cout << "Resources allocated\n";
	memcpy(ControlArray, InitialArray, n*sizeof(int));
	memcpy(BubbleArray, InitialArray, n * sizeof(int));
	memcpy(SelectionArray, InitialArray, n * sizeof(int));
	memcpy(InsertionArray, InitialArray, n * sizeof(int));
	memcpy(QuickArray, InitialArray, n * sizeof(int));
	memcpy(ShellArray, InitialArray, n * sizeof(int));
	memcpy(MergeArray, InitialArray, n * sizeof(int));
	std::cout << "Arrays copied\n";

	ControlSort<int>(ControlArray, n);
	std::cout << "Control done\n";
	BubbleSort<int>(BubbleArray, n);
	std::cout << "Bubble done\n";
	SelectionSort<int>(SelectionArray, n);
	std::cout << "Selection done\n";
	InsertionSort<int>(InsertionArray, n);
	std::cout << "Insertion done\n";
	QuickSort<int>(QuickArray, n);
	std::cout << "Quick done\n";
	ShellSort<int>(ShellArray, n);
	std::cout << "Shell done\n";
	MergeSort<int>(MergeArray, n);
	std::cout << "Merge done\n";

	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == BubbleArray[i]);
	}
	std::cout << "BubbleSort Test Passed\n";
	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == SelectionArray[i]);
	}
	std::cout << "SelectionSort Test Passed\n";
	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == InsertionArray[i]);
	}
	std::cout << "InsertionSort Test Passed\n";
	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == QuickArray[i]);
	}
	std::cout << "QuickSort Test Passed\n";
	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == ShellArray[i]);
	}
	std::cout << "ShellSort Test Passed\n";
	for (int i = 0; i < n; i++)
	{
		assert(ControlArray[i] == MergeArray[i]);
	}
	std::cout << "MergeSort Test Passed\n";
}