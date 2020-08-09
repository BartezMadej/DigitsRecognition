#pragma once
#include <vector>
#include <iostream>
class Matrix
{
private:
	unsigned nRows;
	unsigned nCols;
	std::vector<std::vector<double>> weights;
public:
	Matrix(unsigned nRows, unsigned nCols, bool initRandom);
	~Matrix();
public:
	unsigned getNumRows() const					{ return nRows; }
	unsigned getNumCols() const					{ return nCols; }
	double getValue(unsigned nRow, unsigned nCol) const		{ return weights.at(nRow).at(nCol); }
	void setValue(unsigned nRow, unsigned nCol, double value)	{ weights.at(nRow).at(nCol) = value; }
public:
	void printMatrix() const;
	void zerosMatrix();
	void initializeMatrix();
	Matrix transposeMatrix();
	Matrix operator*(const Matrix mat);
	Matrix operator+(const Matrix add);
};