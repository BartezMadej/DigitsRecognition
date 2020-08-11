#include <random>
#include "NeuralNetwork.h"
#pragma once

NeuralNetwork::NeuralNetwork(std::vector<unsigned> topology)
{
	this->topology = topology;
	initBiases();
	createWeightMatrices();
}

NeuralNetwork::~NeuralNetwork()
{}

void NeuralNetwork::initBiases()
{
	std::shared_ptr<Matrix> var;
	for (unsigned i = 1; i < topology.size(); ++i)
	{
		var = std::make_shared<Matrix>(topology.at(i), 1,true);
		this->biases.push_back(var);
	}
}

void NeuralNetwork::createWeightMatrices()
{
	for (unsigned i = 0; i < topology.size() - 1; ++i)
		this->weightMatrices.push_back(std::make_shared<Matrix>(topology.at((long long)i+1), topology.at(i), true));
}


void NeuralNetwork::printBiases() const
{
	for (auto mtx : biases)
	{
		mtx->printMatrix();
		std::cout << "---------------------------" << std::endl;
	}
}

void NeuralNetwork::printInput() const
{
	for (unsigned i = 0; i < inputValues->getNumRows(); ++i)
		std::cout << inputValues->getValue(i, 0) << " ";
}

void NeuralNetwork::printWeightMatrices() const
{
	for (auto mtx : this->weightMatrices)
	{
		mtx->printMatrix();
		std::cout << "---------------------------" << std::endl;
	}
}

void NeuralNetwork::setInputValues(std::vector<int>& input)
{
	inputValues = std::make_shared<Matrix>((unsigned)input.size(), 1, false);
	for (unsigned i = 0; i < input.size(); ++i)
	{
		inputValues->setValue(i, 0, input.at(i)/255);
	}
}
Matrix NeuralNetwork::feedForward()
{
	Matrix act = *inputValues;
	for (unsigned i = 0; i < topology.size() - 1; ++i)
	{
		act = (*weightMatrices.at(i) * act) + *biases.at(i);
		sigmoid(act);
	}
	return act;
}


void NeuralNetwork::backPropagation(std::vector<Matrix>& deltaB, std::vector<Matrix>& deltaW, std::vector<int>& x, int y)
{
	this->setInputValues(x);
	Matrix activation = *(this->inputValues);
	std::vector<Matrix> activations; // store activations layer by layer
	activations.push_back(activation);
	
	std::vector<Matrix> zs; // store signal before activation layer by layer
	Matrix z(0, 0, false);
	
	for (unsigned i = 0; i < topology.size() - 1; ++i)
	{
		z = *(this->weightMatrices.at(i)) * activation;
		zs.push_back(z);
		sigmoid(z);
		activation = z;
		activations.push_back(activation);
	}
	
	//Last layer error
	Matrix var1 = costDerivative(activations.back(), y);
	Matrix var2 = sigmoidPrime(zs.back());
	Matrix delta (var1.getNumRows(), 1u, false);
	for (unsigned j = 0; j < var1.getNumRows(); ++j)
		delta.setValue(j, 0, var1.getValue(j, 0u) * var2.getValue(j, 0u));
	deltaB.insert(deltaB.begin(), delta);
	deltaW.insert(deltaW.begin(), delta * activations.at(activations.size()-2).transposeMatrix());

	//back propagation
	Matrix sp(0u, 0u, false);
	for (unsigned i = (unsigned)topology.size()-2; i > 0; --i)
	{
		z = zs.at(i-1);
		sp = sigmoidPrime(z);
		var1 = this->weightMatrices.at(i)->transposeMatrix() * delta;
		delta = Matrix(var1.getNumRows(), 1, false);
		for (unsigned j = 0; j < var1.getNumRows(); ++j)
			delta.setValue(j, 0, var1.getValue(j, 0u) * sp.getValue(j, 0u));
		deltaB.insert(deltaB.begin(), delta);
		deltaW.insert(deltaW.begin(), delta *  activations.at(i-1).transposeMatrix());
	}
	  
}
void NeuralNetwork::sigmoid(Matrix& z)
{
	for (unsigned i = 0; i < z.getNumRows(); ++i)
		for (unsigned j = 0; j < z.getNumCols(); ++j)
			z.setValue(i, j, 1/(1+exp(-z.getValue(i, j))));
}

Matrix NeuralNetwork::sigmoidPrime(const Matrix& z)
{
	Matrix result = z;
	for (unsigned i = 0; i < result.getNumRows(); ++i)
		for (unsigned j = 0; j < result.getNumCols(); ++j)
			result.setValue(i, j, result.getValue(i, j) * (1 - result.getValue(i, j)));
	return result;
}

Matrix NeuralNetwork::costDerivative(const Matrix& outputActivations, int y)
{
	Matrix result(outputActivations.getNumRows(), outputActivations.getNumCols(),false);
	for (unsigned i = 0; i < result.getNumRows(); ++i)
		for (unsigned j = 0; j < result.getNumCols(); ++j)
			result.setValue(i, j, outputActivations.getValue(i, j) - y );
	return result;
}
