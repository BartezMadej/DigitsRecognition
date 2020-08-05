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

void Layer::setInput(const std::vector<double>& input)
{
	if (input.size() != neurons.size())
		throw std::out_of_range("void::Layer setInput()");
	for (unsigned i = 0; i < input.size(); ++i)
		this->neurons.at(i)->setValue(input.at(i));
}

void Layer::setNeuronValue(unsigned index, double val)
{
	this->neurons.at(index)->setValue(val);
}

Matrix* Layer::matrixifyNeurons()
{
	Matrix* pVals = new Matrix(1, (unsigned)neurons.size());
	for (unsigned i = 0; i < neurons.size(); ++i)
		pVals->setValue(0, i, neurons.at(i)->getValue());
	return pVals;
}

Matrix* Layer::matrixifyActivatedVal()
{
	Matrix* pResult = new Matrix(1, this->neurons.size());
	for (unsigned i = 0; i < this->neurons.size(); ++i)
		pResult->setValue(0,i,neurons.at(i)->getActivatedVal());
	return pResult;
}

Matrix* Layer::matrixifyDerivedVal()
{
	Matrix* pResult = new Matrix(1, this->neurons.size());
	for (unsigned i = 0; i < this->neurons.size(); ++i)
		pResult->setValue(0, i, neurons.at(0)->getDerivedVal());
	return pResult;
}
