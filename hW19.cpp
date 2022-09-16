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

	cout << "�������� ������� �19.\n\n������ �1.\n";
	cout << "������� ������ �����: ";
	cin >> n;
	cout << "������� ������ �����: ";
	cin >> m;
	cout << "���������� ����� �������� ����� " << n << " � " << m << " = " << divide(n, m) << ".\n\n";

	cout << "������ �2.\n������� �����: ";
	cin >> n;
	cout << "����� � ���������� ���� = " << mirror_number(n) << ".\n\n";

	cout << "������ �3.\n����������� ������: \n";
	const int size = 15;
	int arr[size];
	fill_arr(arr, size);
	show_arr(arr, size);
	cout << "������� �����: ";
	cin >> n;
	if (after_sort(arr, size, n) < 0)
		cout << "� ������� ��� ������ ��������.\n\n";
	else{
		cout << "������ ������� ����� " << n << " � ������� = " << after_sort(arr, size, n) << ".\n";
		cout << "�������� ������: \n";
		show_arr(arr, size);
		cout << endl;
		}
	cout << "������ �4.\n������� ������ ���������: ";
	cin >> n;
	cout << "������� ����� ���������: ";
	cin >> m;
	const int size_4 = 10;
	int arr_4[size_4]{};
	fill_arr(arr_4, size_4, n, m);
	cout << "�������� ������: \n";
	show_arr(arr_4, size_4);
	cout << endl;

	return 0;
}