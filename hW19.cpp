#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
template <typename T>
T divide(T num1, T num2) {
	T divider = 0;
	for (int i = 1; i < num1 or i < num2; i++) {
		if (num1 % i == 0 and num2 % i == 0)
			divider = i;
	}
	return divider;
}
template <typename T>
//
T mirror_number(T number) {
	if (number < 10)
		return number;
	T bumber = 0;
	do {
		bumber *= 10;
		bumber += number % 10;
		number /= 10;
	} while (number);

	return bumber;
}
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
T after_sort(T arr[], const int length, T num) {
	int index = -1;
	for (int i = 0; i < length; i++)
		if (arr[i] == num) {
			index = i;
			break;
		}
	
	for (int i = length-1; i > 0; i--)
		for (int j = index+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	return index;
}
template <typename T>
void fill_arr(T arr[], const int length, T value1 = 1, T value2 = 10) {
	srand(time(0));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (value2+1-value1) + value1;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	cout << "Домашнее задание №19.\n\nЗадача №1.\n";
	cout << "Введите первое число: ";
	cin >> n;
	cout << "Введите второе число: ";
	cin >> m;
	cout << "Наибольший общий делитель чисел " << n << " и " << m << " = " << divide(n, m) << ".\n\n";

	cout << "Задача №2.\nВведите число: ";
	cin >> n;
	cout << "Число в отраженном виде = " << mirror_number(n) << ".\n\n";

	cout << "Задача №3.\nИзначальный массив: \n";
	const int size = 15;
	int arr[size];
	fill_arr(arr, size);
	show_arr(arr, size);
	cout << "Введите число: ";
	cin >> n;
	if (after_sort(arr, size, n) < 0)
		cout << "В массиве нет такого элемента.\n\n";
	else{
		cout << "Первая позиция числа " << n << " в массиве = " << after_sort(arr, size, n) << ".\n";
		cout << "Итоговый массив: \n";
		show_arr(arr, size);
		cout << endl;
		}
	cout << "Задача №4.\nВведите начало диапазона: ";
	cin >> n;
	cout << "Введите конец диапазона: ";
	cin >> m;
	const int size_4 = 10;
	int arr_4[size_4]{};
	fill_arr(arr_4, size_4, n, m);
	cout << "Итоговый массив: \n";
	show_arr(arr_4, size_4);
	cout << endl;

	return 0;
}