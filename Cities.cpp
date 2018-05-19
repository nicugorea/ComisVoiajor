#include "Cities.hpp"




void Cities::ReadDistances() {
	_distances.clear();
	for (int i = 0; i < C_NUMBER; i++)
	{
		vector<int> tmpVector;
		for (int j = 0; j < C_NUMBER; j++)
			tmpVector.push_back(0);
		_distances.push_back(tmpVector);
	}

	ifstream input("input.txt");
	for (int i = 0; i < C_NUMBER; i++)
	{
		for (int j = 0; j < C_NUMBER-1-i; j++)
		{
			int tmpDistance = 0;
			input >> tmpDistance;
			_distances[i][j + i + 1] = _distances[j + i + 1][i] = tmpDistance;
		}
	}

	input.close();
}

void Cities::ReadNames() {
	ifstream input("names.txt");

	_names.clear();

	for (int i = 0; i < C_NUMBER; i++)
	{
		string tmpName;
		input>>tmpName;
		_names.push_back(tmpName);
	}

	input.close();

}


void Cities::PheromoneInitialization() {
	_pheromone.clear();
	for (int i = 0; i < C_NUMBER; i++)
	{
		vector<float> tmpVector;
		for (int j = 0; j < C_NUMBER; j++)
			tmpVector.push_back(1.0f);
		_pheromone.push_back(tmpVector);
	}
}