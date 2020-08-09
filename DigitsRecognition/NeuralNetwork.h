#pragma once
#include <vector>
#include <memory>
#include "Layer.h"
#include "Matrix.h"
class NeuralNetwork
{
private:
	unsigned layersNumber;
	std::vector<unsigned>			topology;
	std::shared_ptr<Matrix>			inputValues;
	std::vector<std::shared_ptr<Matrix>>	biases;
	std::vector<std::shared_ptr<Matrix>>	weightMatrices;
public:
	NeuralNetwork(std::vector<unsigned> topology);
	~NeuralNetwork();
private:
	void initBiases();
	void createWeightMatrices();
public:
	void printInput() const;
	void printBiases() const;
	void printWeightMatrices() const;
public:
	void setInputValues(std::vector<double>& input);
	Matrix feedForward();
	void backPropagation(std::vector<Matrix>& deltaB, std::vector<Matrix>& deltaW, std::vector<double>& x, int y);
	void sigmoid(Matrix& z);
	Matrix sigmoidPrime(const Matrix& z);
	Matrix costDerivative(const Matrix& outputActivations, int y);
};