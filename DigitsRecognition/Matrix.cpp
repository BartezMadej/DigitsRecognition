#include "Matrix.h"
#include <iostream>
#include <random>
Matrix::Matrix(unsigned nRows, unsigned nCols, bool initRandom)
{
	this->nRows = nRows;
	this->nCols = nCols;
	if (initRandom)
		initializeMatrix();
	else
		zerosMatrix();

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
	{
		std::vector<double> var;
		for (unsigned j = 0; j < nCols; ++j)
			var.push_back(0.0);
		weights.push_back(var);
	}
}

std::shared_ptr<Matrix> Matrix::transposeMatrix()
{
	std::shared_ptr<Matrix>pTrans = std::make_shared<Matrix>(this->nCols, this->nRows, false);
	for (unsigned i = 0; i < nCols; ++i)
		for (unsigned j = 0; j < nRows; ++j)
			pTrans->setValue(i, j, this->getValue(j, i));
	return pTrans;
}

std::shared_ptr<Matrix> Matrix::operator*(const std::shared_ptr<Matrix> mat)
{
	if (this->nCols != mat->getNumRows())
		throw std::logic_error("Matrix operator*");
	std::shared_ptr<Matrix> res = std::make_shared<Matrix>(this->getNumRows(), mat->getNumCols(),false);
	for (unsigned i = 0; i < nRows; ++i)
	{
		for (unsigned j = 0; j < mat->getNumCols(); ++j)
		{
			for (unsigned z = 0; z < mat->getNumRows(); ++z)
				res->setValue(i, j, res->getValue(i, j) + (this->getValue(i, z) * mat->getValue(z, j)));
		}
	}
	return res;
}

std::shared_ptr<Matrix> Matrix::operator+(const std::shared_ptr<Matrix> add)
{
	std::shared_ptr<Matrix> res = std::make_shared<Matrix>(this->getNumRows(), add->getNumCols(), false);
	for (unsigned i = 0; i < this->getNumRows(); ++i)
		for (unsigned j = 0; j < this->getNumCols(); ++j)
			res->setValue(i, j, this->getValue(i,j) + add->getValue(i, j));
	return res;
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
