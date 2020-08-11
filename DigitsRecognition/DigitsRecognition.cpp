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
	/*std::vector<unsigned> topology = {3,2,1 };
	std::vector<double> input = { 233, 33, 233 };
	NeuralNetwork* pNetwork = new NeuralNetwork(topology);
	pNetwork->setInputValues(input);
	pNetwork->printWeightMatrices();
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=\n";


	std::vector<Matrix> deltaNablaB;
	std::vector<Matrix> deltaNablaW;
	pNetwork->backPropagation(deltaNablaB, deltaNablaW, input, 2);
	delete pNetwork;*/
	DataReader reader;
	//reader.readTrainingLabels();
	reader.readTrainingData();
	return 0;
}