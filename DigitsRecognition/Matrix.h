#include <vector>
#include <iostream>
#pragma once
class Matrix
{
private:
	unsigned nRows;
	unsigned nCols;
	std::vector<std::vector<double>> weights;
public:
	Matrix(unsigned nRows, unsigned nCols);
	~Matrix();
public:
	unsigned getNumRows()										{ return nRows; }
	unsigned getNumCols()										{ return nCols; }
	double getValue(unsigned nRow, unsigned nCol)				{ return weights.at(nRow).at(nCol); }
	void setValue(unsigned nRow, unsigned nCol, double value)	{ weights.at(nRow).at(nCol) = value; }
public:
	void initializeMatrix();
	Matrix* transposeMatrix();
	void printMatrix();
};