#include "Neuron.h"
#include <vector>
#include <iostream>
#include <memory>

#pragma once
class Layer {
private:
	unsigned nSize;
	std::vector<std::shared_ptr<Neuron>> neurons;
public:
	Layer(unsigned nSize);
	~Layer();
public:
	void printBiases();


};