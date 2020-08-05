#include <random>
#include "NeuralNetwork.h"
#pragma once

NeuralNetwork::NeuralNetwork(std::vector<unsigned> topology)
{
	this->topology = topology;
	initBiases();
	createLayers();
	createWeightMatrices();
}

NeuralNetwork::~NeuralNetwork()
{}

void NeuralNetwork::initBiases()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distribution(0.0, 1.0);

	for (unsigned i = 1; i < topology.size(); ++i)
	{
		std::vector<double> var;
		for (unsigned j = 0; j < topology.at(i); ++j)
			var.push_back(distribution(gen));
		this->biases.push_back(var);
	}
}

void NeuralNetwork::createLayers()
{
	for (unsigned i = 0; i < topology.size(); ++i)
		this->layers.push_back(std::make_shared<Layer>(topology.at(i)));
}

void NeuralNetwork::createWeightMatrices()
{
	for (unsigned i = 0; i < topology.size() - 1; ++i)
		this->weightMatrices.push_back(std::make_shared<Matrix>(topology.at(i), topology.at((long long)i+1)));
}

void NeuralNetwork::setInputValues(std::vector<double> input)
{
	this->inputValues = input;
	this->layers.at(0)->setInput(input);
}

void NeuralNetwork::printBiases() const
{
	for (unsigned i = 0; i < biases.size(); ++i)
	{
		for (unsigned j = 0; j < biases.at(i).size(); ++j)
			std::cout << biases.at(i).at(j) << " ";
		std::cout << std::endl;
	}
}

void NeuralNetwork::printWeightMatrices() const
{
	for (unsigned i = 0; i < weightMatrices.size(); ++i)
	{
		this->weightMatrices.at(i)->printMatrix();
		std::cout << "---------------------------" << std::endl;
	}
}

void NeuralNetwork::printLayers() const
{
	Matrix* pM = NULL;
	for (unsigned i = 0; i < layers.size(); ++i)
	{
		pM = layers.at(i)->matrixifyNeurons();
		pM->printMatrix();
		delete pM;
	}
}
