#include <iostream>

void fill_rand(int arr[], int& n);
void print_array(int arr[], int& n);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n, value, index;
	std::cout << "¬ведите размер массива: ";
	std::cin >> n;
	int* arr = new int[n];
	fill_rand(arr, n);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите значение которое будет добавлено в конец массива: ";
	std::cin >> value;
	arr = push_back(arr, n, value);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите значение которое будет добавлено в начало масива:";
	std::cin >> value;
	arr = push_front(arr, n, value);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите номер €чейки в которую будет добавлено значение:";
	std::cin >> index;
	std::cout << "¬ведите значение: ";
	std::cin >> value;
	arr = insert(arr, n, value, index);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "”даление последнего елемента в массиве:";
	std::cout << std::endl;
	arr = pop_back(arr, n);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "”даление первого елемента в массиве:";
	std::cout << std::endl;
	arr = pop_front(arr, n);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите номер €чейки которую нужно удалить из массива:";
	std::cin >> index;
	arr = erase(arr, n, index);
	std::cout << "»сходный массив:";
	print_array(arr, n);

	delete[] arr;
	
}
void fill_rand(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void print_array(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int index, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n-1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}