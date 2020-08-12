// DigitsRecognition.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <vector>
#include <iostream>
#include "Neuron.h"
#include "Matrix.h"
#include "Layer.h"
#include "NeuralNetwork.h"
#include <iostream>
#include <fstream>
#include "DataReader.h"
int main()
{
	std::vector<unsigned> topology = { 784, 30, 10 };
	NeuralNetwork* pNetwork = new NeuralNetwork(topology);
	pNetwork->readData();
	pNetwork->SGD();
	delete pNetwork;
	return 0;
}