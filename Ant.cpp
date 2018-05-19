#include "Ant.hpp"
#include "Cities.hpp"

int Ant::GetVisitedDistance(const vector<vector<int>> & distances) {
	int tmpDistance = 0;
	for (int i = 1; i < _visitedCities.size(); i++)
		tmpDistance += distances[_currentCity][i];
	return tmpDistance;
}


void Ant::AddPheromone(vector<vector<float>> & pheromone, vector<vector<int>> distances) {

	for (int i = 0; i < pheromone.size(); i++)
	{
		pheromone[_currentCity][i] += 1.0f / (float)distances[_currentCity][i];
		pheromone[_currentCity][i] *= EVAPORATION_COEFICIENT;
	}
}

void Ant::ToVisitListInitialization() {
	for (int i = 0; i < C_NUMBER; i++)
		_toVisit.insert(i);
}

void Ant::VisitedListInitialization() {
	_visitedCities.clear();
}