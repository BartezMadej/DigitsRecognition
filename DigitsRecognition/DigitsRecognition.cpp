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
	std::vector<unsigned> topology = { 3,3,2 };
	NeuralNetwork* pNetwork = new NeuralNetwork(topology);
	//pNetwork->printWeightMatrices();
	//pNetwork->printBiases();
	//pNetwork->printLayers();
	delete pNetwork;
	return 0;
}
