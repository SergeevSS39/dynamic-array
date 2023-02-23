#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;
enum Color {
	Black = 0, Blue, Green, Cyan, Red,
	Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan,
	LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void arrayFill(double* array, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		array[i] = -10 + rand() % 20 + (1 + rand() % 99 / 100.0);
	}
}
void printArr(double* array, int  length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}
template<typename Sample>
void copyArr(Sample* destination, Sample* sourse, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		destination[i] = sourse[i];
	}

}

int main()

{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//ДЗ
//Описать массив типа double.Размер указывает пользователь.Заполнить его случайными значениями.
//Работу с массивом реализовать функциями.
//1.Создать массив, состоящий только из дробных частей тех элементов, 
//целая часть которых чётная и пложительная.

	int length, count = 0;//count для ограничения массива по количеству элементов, согласно нужным нам значениям
	cout << "Enter a length for this array: " << endl;
	cin >> length;
	double* array = new double[length];
	arrayFill(array, length);
	printArr(array, length);
	cout << endl;
	double* array2 = new double[length];
	//copyArr(array, array2, length);
	for (size_t i = 0; i < length; i++)
	{
		if ((int)array[i] % 2 == 0 && (int)array[i] > 0)
		{
			array2[i] = array[i];
			count++;
		}
		else
			array2[i] = 0;
	}
	delete[]array;

	array = new double[length];
	double min;
	int position;
	for (size_t i = 0; i < length; i++)//сортировка массива, чтобы сдвинуть в одну сторону нужные значения
	{
		min = array2[i];
		position = i;
		for (size_t j = 0; j < length; j++)
		{
			if (array2[j] < min)
			{
				min = array2[j];
				position = j;
			}
		}
		swap(array2[i], array2[position]);
	}
	copyArr(array, array2, length);
	length = count;
	cout << endl;
	delete[]array2;
	for (size_t i = 0; i < length; i++)
	{
		cout << array[i] - (int)array[i] << "\t";
	}




	return 0;
}