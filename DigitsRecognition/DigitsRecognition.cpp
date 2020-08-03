// DigitsRecognition.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Neuron.h"
int main()
{
	Neuron* n1 = new Neuron(0.5);
	std::cout<<"Neuron value:\t"<<n1->getValue()<< std::endl;
	std::cout<<"Activated value:\t"<<n1->getActivatedVal()<< std::endl;
	std::cout<<"Derived value:\t"<<n1->getDerivedVal()<< std::endl;
	return 0;
}
