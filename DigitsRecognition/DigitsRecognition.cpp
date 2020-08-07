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
	std::vector<unsigned> topology = {2,3,2 };
	std::vector<double> input = { 0.3,0.2 };
	NeuralNetwork* pNetwork = new NeuralNetwork(topology);
	pNetwork->setInputValues(input);
	pNetwork->printWeightMatrices();






	std::vector<std::shared_ptr<Matrix>> deltaNablaB;
	std::vector<std::shared_ptr<Matrix>> deltaNablaW;
	pNetwork->backPropagation(deltaNablaB, deltaNablaW, input, 1);	delete pNetwork;
	return 0;
}