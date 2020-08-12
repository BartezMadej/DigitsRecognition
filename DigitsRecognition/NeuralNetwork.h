#pragma once
#include <vector>
#include <memory>
#include "Layer.h"
#include "Matrix.h"
#include "DataReader.h"
class NeuralNetwork
{
public:
	static double ETA;		//rate of learning
	static const unsigned BATCH_SIZE = 30;
	static const unsigned EPOCHS = 10;
private:
	unsigned layersNumber;
	std::vector<unsigned>			topology;
	std::shared_ptr<Matrix>			inputValues;
	std::vector<std::shared_ptr<Matrix>>	biases;
	std::vector<std::shared_ptr<Matrix>>	weightMatrices;
private:
	DataReader dataReader;
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
	void readData();
	void sigmoid(Matrix& z);
	Matrix feedForward();
	Matrix sigmoidPrime(const Matrix& z);
	Matrix costDerivative(const Matrix& outputActivations, int y);
	void setInputValues(std::vector<int>& input);
	void backPropagation(std::vector<Matrix>& deltaB, std::vector<Matrix>& deltaW, std::vector<int>& x, int y);
	void updateMiniBatch(std::vector<std::vector<int>> miniBatch, std::vector<int> labels);
	void SGD();
public:
	int evaluate();
};