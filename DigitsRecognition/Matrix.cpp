#include "Matrix.h"
#include <random>
Matrix::Matrix(unsigned nRows, unsigned nCols)
{
	this->nRows = nRows;
	this->nCols = nCols;
	initializeMatrix();
}

Matrix::~Matrix()
{
	weights.clear();
}

void Matrix::initializeMatrix()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distribution(0.0, 1.0);
	for (unsigned i = 0; i < nRows; ++i)
	{
		std::vector<double> var;
		for (unsigned j = 0; j < nCols; ++j)
			var.push_back(distribution(gen));
		weights.push_back(var);
	}
}

void Matrix::zerosMatrix()
{
	for (unsigned i = 0; i < nRows; ++i)
		for (unsigned j = 0; j < nCols; ++j)
			this->weights[i][j] = 0.0;
	
}

Matrix* Matrix::transposeMatrix()
{
	Matrix* pTrans = new Matrix(this->nCols,this->nRows);
	for (unsigned i = 0; i < nCols; ++i)
		for (unsigned j = 0; j < nRows; ++j)
			pTrans->setValue(i, j, this->getValue(j, i));
	return pTrans;
}

Matrix& Matrix::operator*(const Matrix& mat)
{
	Matrix* pResult = new Matrix(this->getNumRows(), mat.getNumCols());
	pResult->zerosMatrix();
	for (unsigned i = 0; i < nRows; ++i)
	{
		for (unsigned j = 0; j < mat.getNumCols(); ++j)
		{
			for (unsigned z = 0; z < mat.getNumRows(); ++z)
				pResult->setValue(i, j, pResult->getValue(i, j) + (this->getValue(i, z) * mat.getValue(z, j)));
		}
	}
	return *pResult;
}

void Matrix::printMatrix() const
{
	for (unsigned i = 0; i < nRows; ++i)
	{
		for (unsigned j = 0; j < nCols; ++j)
			std::cout << weights.at(i).at(j) << "\t";
		std::cout << std::endl;
	}
}
