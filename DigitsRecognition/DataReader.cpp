#include "DataReader.h"
#include <fstream>

DataReader::DataReader()
{
}

DataReader::~DataReader()
{
}

int DataReader::reverseInt(int i)
{
	unsigned char ch1, ch2, ch3, ch4;
	ch1 = i & 255;
	ch2 = (i >> 8) & 255;
	ch3 = (i >> 16) & 255;
	ch4 = (i >> 24) & 255;
	return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

void DataReader::readData(std::vector<std::vector<int>>& data, const char* pPath)
{
	std::ifstream file(pPath, std::ifstream::binary);
	if (!file.is_open())
		return;
	int magicNumber = 0;
	int imagesNumber = 0;
	int nRows = 0;
	int nCols = 0;

	file.read((char*)&magicNumber, sizeof(magicNumber));
	magicNumber = reverseInt(magicNumber);
	file.read((char*)&imagesNumber, sizeof(imagesNumber));
	imagesNumber = reverseInt(imagesNumber);
	file.read((char*)&nRows, sizeof(nRows));
	nRows = reverseInt(nRows);
	file.read((char*)&nCols, sizeof(nCols));
	nCols = reverseInt(nCols);
	data.resize(imagesNumber, std::vector<int>(IMAGE_DIM));
	for (int i = 0; i < imagesNumber - 1; ++i)
	{
		for (int j = 0; j < nRows; ++j)
		{
			for (int z = 0; z < nCols; ++z)
			{
				unsigned char temp = 0;
				file.read((char*)&temp, sizeof(temp));
				data[i][(nRows * j) + z] = (double)temp;
			}
		}
	}
	file.close();
}

void DataReader::readLabels(std::vector<int>& labels, const char* pPath)
{
	std::ifstream file(pPath, std::ifstream::binary);
	if (!file.is_open())
		return;
	int labelsNumber = 0;
	int magicNumber = 0;
	file.read((char*)&magicNumber, sizeof(int));
	magicNumber = reverseInt(magicNumber);
	file.read((char*)&labelsNumber, sizeof(int));
	labelsNumber = reverseInt(labelsNumber);
	labels.resize(labelsNumber);
	unsigned char var;
	for (int i = 0; i < labelsNumber; ++i)
	{
		file.read((char*)&var, sizeof(unsigned char));
		labels.at(i) = (int)var;
	}
	file.close();
}

void DataReader::readTestingData()
{
	readData(this->testData, "C:\\Users\\Ragnar\\Desktop\\DigitsRecognition\\t10k-images.idx3-ubyte");
	readLabels(this->testLables, "C:\\Users\\Ragnar\\Desktop\\DigitsRecognition\\t10k-labels.idx1-ubyte");
}

void DataReader::readTrainingData()
{
	readData(this->trainingData, "C:\\Users\\Ragnar\\Desktop\\DigitsRecognition\\train-images.idx3-ubyte");
	readLabels(this->trainingLabels, "C:\\Users\\Ragnar\\Desktop\\DigitsRecognition\\train-labels.idx1-ubyte");
}
