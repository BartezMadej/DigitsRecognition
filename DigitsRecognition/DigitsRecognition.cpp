// DigitsRecognition.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <vector>
#include <iostream>
#include "Neuron.h"
#include "Matrix.h"
#include "Layer.h"
#include "NeuralNetwork.h"
int main()
{
	std::vector<unsigned> topology = {3,202,12,12,12 };
	std::vector<double> input = { 0.2, 0.3, 0.2 };
	NeuralNetwork* pNetwork = new NeuralNetwork(topology);
	pNetwork->setInputValues(input);
	//pNetwork->printWeightMatrices();
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=\n";


	std::vector<Matrix> deltaNablaB;
	std::vector<Matrix> deltaNablaW;
	pNetwork->backPropagation(deltaNablaB, deltaNablaW, input, 2);
	delete pNetwork;
	return 0;
}