#include <math.h>
#pragma once
class Neuron
{
private:
	 double value;
	 double activatedVal;
	 double derivedVal;
public:
	 Neuron(double value);
	 ~Neuron();
public:
	double getValue()							{ return this->value; }
	double getActivatedVal()					{ return this->activatedVal; };
	double getDerivedVal()						{ return this->derivedVal; }
	void setValue(double value);
	void setActivatedVal(double activatedVal)   { this->activatedVal = activatedVal; }
	void setDerivedVal(double derivedVal)		{ this->derivedVal = derivedVal; }
public:
	void activateNeuron();
	void deriveNeuron();
}; 