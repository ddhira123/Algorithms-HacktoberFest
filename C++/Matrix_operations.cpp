/* This code perform add, sub, multiply, transpose of a matrix, sum of diagonal and check the condition for Upper,lower, or Diagonal matrix */

#include <iostream>
using namespace std;
class matrix
{
private:
	int mat1[30][30], r, c, i, j, r1, c1, mat2[30][30], sum, sub, x, fu, fl, fd, mat3[30][30], k, add;

public:
	void m1();
	void m2();
	void addition();
	void subtraction();
	void transpose();
	void tri();
	void multi();
	void dia();
};

void matrix::m1()
{
	cout << "ENTER THE NO. OF ROWS AND COLUMNS OF MAT1=";
	cin >> r >> c;

	cout << "ENTER THE ELEMENTS OF MATRIX1=\n";

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> mat1[i][j];
		}
	}
	cout << "\n";
	cout << "MATRIX1=\n";

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cout << mat1[i][j];
			cout << "\t";
		}
		cout << "\n";
	}
}

void matrix::m2()
{

	cout << "ENTER THE NO. OF ROWS  AND COLUMN OF MAT2=";
	cin >> r1 >> c1;

	cout << "ENTER THE ELEMENTS OF MATRIX2=\n";

	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			cin >> mat2[i][j];
		}
	}
	cout << "\n";
	cout << "MATRIX2=\n";
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			cout << mat2[i][j];
			cout << "\t";
		}
		cout << "\n";
	}
}

void matrix::addition()
{
	cout << "ADDITION OF THE 2 MATRICES IS=\n";
	sum = 0;
	if (r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				sum = mat1[i][j] + mat2[i][j];
				cout << sum << "\t";
			}
			cout << "\n";
		}
	}

	else
	{
		cout << "INVAID MATRICES!!";
	}
}

void matrix::subtraction()
{
	cout << "SUBTRACTION OF THE 2 MATRICES IS=\n";
	sub = 0;
	if (r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				sub = mat1[i][j] - mat2[i][j];
				cout << sub << "\t";
			}
			cout << "\n";
		}
	}

	else
	{
		cout << "INVAID MATRICES!!";
	}
}

void matrix::transpose()
{
	cout << "TRANSPOSE OF THE MATRICES IS=\n";
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{

			cout << mat1[j][i] << "\t";
		}
		cout << "\n";
	}
}

void matrix::tri()
{
	cout << "CHECKING FOR MATRIX 1:";
	fu = 0;
	fl = 0;
	fd = 0;
	int x = r;

	if (r == c)
	{

		for (i = 0; i < x; i++)
		{
			for (j = 0; j < x; j++)
			{
				if (i > j)
				{
					if (mat1[i][j] == 0)
						fu++;
				}
				if (i < j)
				{
					if (mat1[i][j] == 0)
						fl++;
				}
				if (i == j)
				{
					if (mat1[i][j] != 0)
						fd++;
				}
			}
		}

		if (fu == (x * (x - 1)) / 2)
			cout << "\n IT'S A UPPER TRIANGULAR MATRIX.\n";

		else if (fl == (x * (x - 1)) / 2)
			cout << "\n IT'S A LOWER TRIANGULAR MATRIX.\n";

		else if (fu == (x * (x - 1)) / 2 && fl == (x * (x - 1)) / 2 && (fd == x))
			cout << "\n IT'S A DIAGONAL MATRIX.\n";
		else
			cout << "NOT UPPER,LOWER,DIAGONAL MATRIX. \n";
	}
	else
	{
		cout << "INVALID MATRIX! \n";
	}
}

void matrix::multi()
{
	cout << "MULTIPICATION OF 2 MATRICES IS=\n";
	k = 0;

	if (r1 == c)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c1; j++)
			{
				mat3[i][j] = 0;
				for (k = 0; k < r1; k++)
				{
					mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
				}
				cout << mat3[i][j] << "\t";
			}
			cout << "\n";
		}
	}

	else
	{
		cout << "INVALID MATRIX! \n";
	}
}

void matrix::dia()
{
	add = 0;
	cout << "SUM OF DIAGONAL IS= \n";

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (i == j)
				add = add + mat1[i][j];
		}
	}
	cout << add;
}

int main()
{
	matrix m;
	m.m1();
	m.m2();
	m.addition();
	m.subtraction();
	m.transpose();
	m.tri();
	m.multi();
	m.dia();

	return 0;
}
