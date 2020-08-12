#pragma once
#include <vector>
class DataReader
{
public:
	static const unsigned IMAGE_DIM = 784;
private:
	std::vector<int> testLables;		
	std::vector<int> trainingLabels;
	std::vector<std::vector<int>> testData;		// data use to check corectness
	std::vector<std::vector<int>> trainingData;	// data used to teach nueral network
public:
	DataReader();
	~DataReader();
private:
	int reverseInt(int i);
	void readLabels(std::vector<int>& labels, const char* pPath);
	void readData(std::vector<std::vector<int>>& data, const char* pPath);
public:
	void readTestingData();
	void readTrainingData();
/*FRIEND ZONE*/
	friend class NeuralNetwork;
};