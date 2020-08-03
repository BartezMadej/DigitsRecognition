#include "Neuron.h"

Neuron::Neuron(double value)
{
	this->value = value;
	activateNeuron();
	deriveNeuron();
}

Neuron::~Neuron()
{}

void Neuron::setValue(double value)
{
	this->value = value;
	activateNeuron();
	deriveNeuron();
}

void Neuron::activateNeuron()
{
	this->activatedVal = 1 / (1 + exp(-value));	
}

void Neuron::deriveNeuron()
{
	this->derivedVal = activatedVal * (1 - activatedVal);
}
