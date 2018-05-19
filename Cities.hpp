#pragma once
#include "includes.hpp"
class Cities
{
public:
	void ReadDistances();
	void ReadNames();
	void PheromoneInitialization();

	void unordered_setPheromone(vector<vector<float>> pheromone) { _pheromone = pheromone; }

	vector<vector<int>> GetDistances()	{ return _distances; }
	vector<vector<float>>GetPheromone() { return _pheromone; }
	vector<string>		GetNames() { return _names; }

private:
	vector<vector<int>> _distances;
	vector<vector<float>> _pheromone;
	vector<string> _names;
};

