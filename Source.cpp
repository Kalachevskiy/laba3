#include <fstream>
#include <iostream>
#include <conio.h>
#define N 5 // размерность матрицы
//Дана матрица A(5x5). Определить массив X из 5 элементов, каждый
//из которых равен среднему арифметическому наибольшего и наименьшего
//из элементов соответствующего столбца матрицы

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // Русская локаль

	// Работа с открытием файла
	ifstream file; // Создаем объект ifstream (считывание файла)
	string fileName; // Переменная хранящее название файла
	cout << "Введите имя файла откуда взять матрицу: ";
	cin >> fileName;
	file.open(fileName);
	while (!file.is_open())
	{
		cout << "\nОшибка при открытии файла" << '\n';
		cout << "Введите имя файла: ";
		cin >> fileName;
		file.open(fileName);
	}
	float matrix[N][N]; // Матрица
	float arr[N]; // Результрующий массив
	int i, j;
	// Работа со считыванием файла в массив
	cout << "\nИсходная матрица: \n";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout.width(5);
			file >> matrix[i][j]; // Считываем элемент в файле в матрицу
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}

	file.close(); // Закрываем файл
	// Далее уже сам алгоритм 
	float maxEl, minEl; // Максимум и минимум по столбцу
	int column = 0; // Тут у нас просто номер столбца, нужно для инициализации макс/мин
	for (i = 0; i < N; i++)
	{
		maxEl = matrix[i][column];
		minEl = matrix[i][column];
		for (j = 0; j < N; j++)
		{
			// Тут индекс j, i чтоб бежать по столбцам, а не по строкам
			if (matrix[j][i] > maxEl) maxEl = matrix[j][i]; // По выходу из цикла мы нашли максимальное
			if (matrix[j][i] < minEl) minEl = matrix[j][i]; // И минимальное
		}
		column++; // Сдвигаем столбец
		cout << "Максимум в столбце " << i << " - " << maxEl << " миниум: " << minEl << endl;
		arr[i] = (minEl + maxEl) / 2; // Добавляем по соответствующему индексу в массив элемент

	}
	// Вывод ответа (ср.арифметического)
	ofstream file2; // Создаём объект ofstream (считывание файла)
	cout << "\nВведите имя файла куда ввести исходный массив: " << endl;
	cin >> fileName;
	file2.open(fileName); // Тут нет цикла проверки имени файла, т.к ofstream сам создаст файл если такой не найден
	cout << "Ответ: " << endl;
	for (i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
		file2 << arr[i] << " ";
	}
	file2.close();
}

