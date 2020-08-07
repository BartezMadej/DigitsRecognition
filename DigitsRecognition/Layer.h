#pragma once
#include "Neuron.h"
#include "Matrix.h"
#include <vector>
#include <iostream>
#include <memory>

class Layer 
{
private:
	unsigned nSize;
	std::vector<std::shared_ptr<Neuron>> neurons;
public:
	Layer(unsigned nSize);
	~Layer();
public:
	void setInput(const std::vector<double>& input);
	void setNeuronValue(unsigned index, double val);
	std::shared_ptr<Matrix> matrixifyNeurons();
	std::shared_ptr<Matrix> matrixifyActivatedVal();
	std::shared_ptr<Matrix> matrixifyDerivedVal();

};