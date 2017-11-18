#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

const short N = 5;
class Matrix
{
private:
	int matrix[N][N];
	int i, j;
	int * products;
public:
	void InputMatrix();
	void WriteMatrix();
	void Sort();
	void ChooseMinimumsOfColumns();
	void WriteMinimums();
	void ProductOfMinimums();
};

void Matrix::InputMatrix()
{
	cout << "vpushit matruciu:" << endl;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << '[' << i + 1 << "][" << j + 1 << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::WriteMatrix()
{
	for (i = 0; i < N; i++, cout << endl)
	{
		for (j = 0; j < N; j++)
		{
			printf("%4d ", matrix[i][j]);
		}
	}
}

void Matrix::Sort()
{
	int temp, previousItem;
	for (i = 0; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			temp = matrix[i][j];
			previousItem = j - 1;
			while (previousItem >= 0 && matrix[i][previousItem] > temp)
			{
				matrix[i][previousItem + 1] = matrix[i][previousItem];
				matrix[i][previousItem] = temp;
				previousItem--;
			}
		}
	}
}

void Matrix::ChooseMinimumsOfColumns()
{
	products = new int[4];
	for (j = 0; j < N; j++)
	{
		int min = matrix[0][j];
		for (i = 0; i < N; i++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j];
		}
		products[j] = min;
	}
}

void Matrix::WriteMinimums()
{
	cout << "\nminimalni elementu:" << endl;

	for (i = 0; i < N; i++)
	{
		cout << products[i] << ' ';
	}
	cout << endl << endl;
}


void Matrix::ProductOfMinimums() {
	int product = 1;

	for (i = 0; i < N; i++)
	{
		product *= products[i];
	}
	cout << "dobutok: " << product << endl << endl;
}

int main(void) {
	Matrix M;

	M.InputMatrix();
	cout << "\n stara matrucia:" << endl;
	M.WriteMatrix();
	M.Sort();
	cout << "\n vidsortova matrucia:" << endl;
	M.WriteMatrix();
	M.ChooseMinimumsOfColumns();
	M.WriteMinimums();
	M.ProductOfMinimums();

	system("pause");
	return 0;
}