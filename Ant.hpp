#pragma once
#include "includes.hpp"

class Ant
{
public:
	int GetVisitedDistance(const vector<vector<int>> & distances);
	void AddPheromone(vector<vector<float>> & pheromone, vector<vector<int>> distances);

	void ToVisitListInitialization();
	void VisitedListInitialization();

	void DeleteFromToVisit(int city) { _toVisit.erase(city); }
	void DeleteFromVisited(int city) { _visitedCities.erase(city); }

	bool HaveCityToVisit() { return !_toVisit.empty(); }

	void unordered_setCurrentCity(int city) { _currentCity = city; }
	void unordered_setNextCity(int city) { _nextCity = city; }

	int GetCurrentCity() { return _currentCity; }
	int GetNextCity() { return _nextCity; }

	void AddCityToVisited(int city) { _visitedCities.insert(city); }

private:
	int _currentCity;
	int _nextCity;
	unordered_set<int> _visitedCities;
	unordered_set<int> _toVisit;
};

