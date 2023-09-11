#include <fstream>
#include <iostream>
#include <conio.h>
#define N 5 // ����������� �������
//���� ������� A(5x5). ���������� ������ X �� 5 ���������, ������
//�� ������� ����� �������� ��������������� ����������� � �����������
//�� ��������� ���������������� ������� �������

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // ������� ������

	// ������ � ��������� �����
	ifstream file; // ������� ������ ifstream (���������� �����)
	string fileName; // ���������� �������� �������� �����
	cout << "������� ��� ����� ������ ����� �������: ";
	cin >> fileName;
	file.open(fileName);
	while (!file.is_open())
	{
		cout << "\n������ ��� �������� �����" << '\n';
		cout << "������� ��� �����: ";
		cin >> fileName;
		file.open(fileName);
	}
	float matrix[N][N]; // �������
	float arr[N]; // ������������� ������
	int i, j;
	// ������ �� ����������� ����� � ������
	cout << "\n�������� �������: \n";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout.width(5);
			file >> matrix[i][j]; // ��������� ������� � ����� � �������
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}

	file.close(); // ��������� ����
	// ����� ��� ��� �������� 
	float maxEl, minEl; // �������� � ������� �� �������
	int column = 0; // ��� � ��� ������ ����� �������, ����� ��� ������������� ����/���
	for (i = 0; i < N; i++)
	{
		maxEl = matrix[i][column];
		minEl = matrix[i][column];
		for (j = 0; j < N; j++)
		{
			// ��� ������ j, i ���� ������ �� ��������, � �� �� �������
			if (matrix[j][i] > maxEl) maxEl = matrix[j][i]; // �� ������ �� ����� �� ����� ������������
			if (matrix[j][i] < minEl) minEl = matrix[j][i]; // � �����������
		}
		column++; // �������� �������
		cout << "�������� � ������� " << i << " - " << maxEl << " ������: " << minEl << endl;
		arr[i] = (minEl + maxEl) / 2; // ��������� �� ���������������� ������� � ������ �������

	}
	// ����� ������ (��.���������������)
	ofstream file2; // ������ ������ ofstream (���������� �����)
	cout << "\n������� ��� ����� ���� ������ �������� ������: " << endl;
	cin >> fileName;
	file2.open(fileName); // ��� ��� ����� �������� ����� �����, �.� ofstream ��� ������� ���� ���� ����� �� ������
	cout << "�����: " << endl;
	for (i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
		file2 << arr[i] << " ";
	}
	file2.close();
}

