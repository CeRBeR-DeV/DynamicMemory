#include <iostream>

template<typename T>void fill_rand(T arr[], T& n);
template<typename T>void print_array(T arr[], T& n);
template<typename T>void push_back(T* &arr, T& n, T value);
template<typename T>void push_front(T* &arr, T& n, T value);
template<typename T>void insert(T* &arr, T& n, int index, T value);
template<typename T>void pop_back(T* &arr, T& n);
template<typename T>void pop_front(T* &arr, T& n);
template<typename T>void erase(T* &arr, T& n, int index);

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
	push_back(arr, n, value);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите значение которое будет добавлено в начало масива:";
	std::cin >> value;
	push_front(arr, n, value);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите номер €чейки в которую будет добавлено значение:";
	std::cin >> index;
	std::cout << "¬ведите значение: ";
	std::cin >> value;
	insert(arr, n, value, index);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "”даление последнего елемента в массиве:";
	std::cout << std::endl;
	pop_back(arr, n);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "”даление первого елемента в массиве:";
	std::cout << std::endl;
	pop_front(arr, n);
	std::cout << "»сходный массив: ";
	print_array(arr, n);
	std::cout << std::endl;
	std::cout << "¬ведите номер €чейки которую нужно удалить из массива:";
	std::cin >> index;
	erase(arr, n, index);
	std::cout << "»сходный массив:";
	print_array(arr, n);
	delete[] arr;
}
template<typename T>void fill_rand(T arr[], T& n)
{
	for (T i = 0; i < n; i++)arr[i] = rand() % 100;
}
template<typename T>void print_array(T arr[], T& n)
{
	for (T i = 0; i < n; i++)std::cout << arr[i] << "\t";
}
template<typename T>void push_back(T* &arr, T& n, T value)
{
	T* buffer = new T[n + 1];
	for (T i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>void push_front(T* &arr, T& n, T value)
{
	T* buffer = new T[n + 1];
	for (T i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>void insert(T* &arr, T& n, int index, T value)
{
	T* buffer = new T[n + 1];
	for (T i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = value;
	for (T i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	n++;
}
template<typename T>void pop_back(T* &arr, T& n)
{
	T* buffer = new T[n];
	for (T i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>void pop_front(T* &arr, T& n)
{
	T* buffer = new T[n];
	for (T i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>void erase(T* &arr, T& n, int index)
{
	T* buffer = new T[n];
	for (T i = 0; i < index; i++)buffer[i] = arr[i];
	for (T i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	n--;
}