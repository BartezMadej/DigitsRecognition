#pragma once
#include <vector>
#include <memory>
#include "Layer.h"
#include "Matrix.h"
class NeuralNetwork
{
private:
	unsigned layersNumber;
	std::vector<unsigned>					topology;
	std::shared_ptr<Matrix>					inputValues;
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
	std::shared_ptr<Matrix> feedForward();
	void backPropagation(std::vector<std::shared_ptr<Matrix>>& deltaNablaB,
		std::vector<std::shared_ptr<Matrix>>& deltaNablaW, std::vector<double>& x, int y);
	void sigmoid(std::shared_ptr<Matrix>& z);
	std::shared_ptr<Matrix> sigmoidPrime(std::shared_ptr<Matrix>& z);
	std::shared_ptr<Matrix> costDerivative(std::shared_ptr<Matrix>& outputActivations, int y);
};