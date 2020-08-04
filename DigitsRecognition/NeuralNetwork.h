#include <vector>
#include <memory>
#include "Layer.h"
#include "Matrix.h"
#pragma once
class NeuralNetwork
{
private:
	unsigned layersNumber;
	std::vector<double>						inputValues;
	std::vector<unsigned>					topology;
	std::vector<std::vector<double>>		biases;
	std::vector<std::shared_ptr<Layer>>		layers;
	std::vector<std::shared_ptr<Matrix>>	weightMatrices;
public:
	NeuralNetwork(std::vector<unsigned> topology);
	~NeuralNetwork();
private:
	void initBiases();
	void createLayers();
	void createWeightMatrices();
public:
	void setInputValues(std::vector<double> input);
public:
	void printBiases();
	void printWeightMatrices();
	void printLayersMatrixes();

};