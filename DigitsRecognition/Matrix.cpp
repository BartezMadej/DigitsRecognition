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

Matrix* Matrix::transposeMatrix()
{
	Matrix* pTrans = new Matrix(this->nCols,this->nRows);
	for (unsigned i = 0; i < nCols; ++i)
		for (unsigned j = 0; j < nRows; ++j)
			pTrans->setValue(i, j, this->getValue(j, i));
	return pTrans;
}

void Matrix::printMatrix()
{
	for (unsigned i = 0; i < nRows; ++i)
	{
		for (unsigned j = 0; j < nCols; ++j)
			std::cout << weights.at(i).at(j) << "\t";
		std::cout << std::endl;
	}
}
