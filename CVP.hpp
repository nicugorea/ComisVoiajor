#pragma once
#include "includes.hpp"

class CVP
{
public:
	void CreatePath();

	int GetNextCity(int currentCity, vector<float> pheromone, vector<int> distances);

private:
	vector<int> _path;

};

