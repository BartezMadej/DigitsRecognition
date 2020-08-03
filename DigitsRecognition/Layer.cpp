#include "Layer.h"
#include <random>
Layer::Layer(unsigned nSize)
{
	this->nSize = nSize;
	for (unsigned i = 0; i < nSize; ++i)
		this->neurons.push_back(std::make_shared<Neuron>(0.0));
	
}

Layer::~Layer()
{
}
