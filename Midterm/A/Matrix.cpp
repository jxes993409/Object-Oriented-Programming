#include "Matrix.h"

Matrix::Matrix()
{
	data = nullptr;
	row = 0;
	col = 0;
}

Matrix::Matrix(int _row, int _col)
{
	row = _row;
	col = _col;
	data = new double* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double [col]{0};
	}
}

Matrix::Matrix(int _row, int _col, double** arr2D)
{
	row = _row;
	col = _col;
	data = new double* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double [col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = arr2D[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& matrix)
{
	row = matrix.row;
	col = matrix.col;
	data = new double* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double [col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = matrix.data[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
	{
		delete [] data [i];
	}
	delete [] data;
	data = nullptr;
}

void Matrix::setValue(int rowIdx, int colIdx, double value)
{
	data[rowIdx][colIdx] = value;
}

double Matrix::getValue(int rowIdx, int colIdx) const
{
	return data[rowIdx][colIdx];
}

Matrix Matrix::transpose() const
{
	Matrix transMatrix(col, row);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			transMatrix.data[j][i] = data[i][j];
		}
	}
	return transMatrix;
}

void Matrix::operator =(const Matrix& matrix)
{
	if (data != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete [] data [i];
		}
		delete [] data;
		data = nullptr;
	}
	row = matrix.row;
	col = matrix.col;
	data = new double* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new double [col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = matrix.data[i][j];
		}
	}
}

Matrix& Matrix::operator +=(const Matrix& matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] += matrix.data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator -=(const Matrix& matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] -= matrix.data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator +(const Matrix& matrix)
{
	Matrix addMatrix(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			addMatrix.data[i][j] = this->data[i][j] + matrix.data[i][j];
		}
	}
	return addMatrix;
}

Matrix Matrix::operator -(const Matrix& matrix)
{
	Matrix subMatrix(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			subMatrix.data[i][j] = this->data[i][j] - matrix.data[i][j];
		}
	}
	return subMatrix;
}

Matrix Matrix::operator +() const
{
	Matrix retMatrix(*this);
	return retMatrix;
}

Matrix Matrix::operator -() const
{
	Matrix retMatrix(*this);
	for (int i = 0; i < retMatrix.row; i++)
	{
		for (int j = 0; j < retMatrix.col; j++)
		{
			retMatrix.data[i][j] = -retMatrix.data[i][j];
		}
	}
	return retMatrix;
}

bool Matrix::operator ==(const Matrix& matrix) const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != matrix.data[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator !=(const Matrix& matrix) const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != matrix.data[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

ostream& operator <<(ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		for (int j = 0; j < matrix.col; j++)
		{
			os << matrix.data[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

Matrix& Matrix::operator *=(const Matrix& matrix)
{	
	Matrix tempMatrix(*this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				data[i][j] += tempMatrix.data[i][k] * matrix.data[k][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator *=(const double value)
{	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] *= value;
		}
	}
	return *this;
}

Matrix Matrix::operator *(const Matrix& matrix) const
{
	Matrix retMatrix(row, matrix.col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < retMatrix.col; j++)
		{
			for (int k = 0; k < col; k++)
			{
				retMatrix.data[i][j] += data[i][k] * matrix.data[k][j];
			}
		}
	}
	return retMatrix;
}

Matrix Matrix::operator *(const double value) const
{
	Matrix retMatrix(*this);
	for (int i = 0; i < retMatrix.row; i++)
	{
		for (int j = 0; j < retMatrix.col; j++)
		{
			retMatrix.data[i][j] *= value;
		}
	}
	return retMatrix;
}

Matrix operator *(double value, const Matrix& matrix)
{
	Matrix retMatrix(matrix);
	for (int i = 0; i < retMatrix.row; i++)
	{
		for (int j = 0; j < retMatrix.col; j++)
		{
			retMatrix.data[i][j] *= value;
		}
	}
	return retMatrix;
}

double Matrix::determinant() const
{
	return calDet(data, row);
}

double Matrix::calDet(double** arr, int n) const
{
	if (n == 1) {return arr[0][0];}

	double det = 0;
	double** matrix = new double* [n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		matrix[i] = new double [n - 1];
	}
	
	for (int a = 0; a < n; ++a)
	{
		// create minor matrix
		for (int i = 1, minor_i = 0; i < n; ++i, ++minor_i)
		{
			for (int j = 0, minor_j = 0; j < n; ++j)
			{
				if (j == a) {continue;}
				matrix[minor_i][minor_j++] = arr[i][j];
			}
		}
		det = (a % 2 == 0) ? det + arr[0][a] * calDet(matrix, n - 1) : det - arr[0][a] * calDet(matrix, n - 1);
	}
	for (int i = 0; i < n - 1; i++)
	{
		delete [] matrix [i];
	}
	delete [] matrix;
	matrix = nullptr;
	return det;
}