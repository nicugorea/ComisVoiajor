#include "CVP.hpp"
#include "Ant.hpp"
#include "Cities.hpp"

void CVP::CreatePath() {


	Cities cities;
	cities.ReadDistances();
	cities.ReadNames();
	cities.PheromoneInitialization();

	vector<int> pathResults;
	Ant ants[5];

	for (auto& ant : ants)
		ant.unordered_setCurrentCity(rand() % C_NUMBER);


	for (int iterator = 0; iterator < ITERATIONS; iterator++)
	{
		int shortestDistance = INT_MAX;
		vector<vector<float>> pheromoneArray = cities.GetPheromone();
		vector<vector<int>> distancesArray = cities.GetDistances();
		for (auto& ant : ants) {
			ant.ToVisitListInitialization();
			ant.VisitedListInitialization();
			ant.unordered_setCurrentCity(ant.GetCurrentCity());
			ant.AddCityToVisited(ant.GetCurrentCity());
			ant.DeleteFromToVisit(ant.GetCurrentCity());

			while (ant.HaveCityToVisit())
			{
				int pickedCity =
					GetNextCity(ant.GetCurrentCity(),
						pheromoneArray[ant.GetCurrentCity()],
						distancesArray[ant.GetCurrentCity()]);
				ant.AddCityToVisited(pickedCity);
				ant.DeleteFromToVisit(pickedCity);
				ant.unordered_setCurrentCity(pickedCity);
			}
			ant.AddPheromone(pheromoneArray, distancesArray);
			cities.unordered_setPheromone(pheromoneArray);
			//pathResults.push_back(ant.GetVisitedDistance(distancesArray));
			if (ant.GetVisitedDistance(distancesArray) < shortestDistance)
				shortestDistance = ant.GetVisitedDistance(distancesArray);
		}
		cout << "\nShortest distance at iteration " << iterator << " is : " << shortestDistance;


	}

	/*
	for (int i = 0; i < pathResults.size(); i++)
	{
		if (i % 5 == 0) cout << "Iteratia " << i / 5 << "\n";
		cout << "Furnica " << i%5 << " a parcurs " << pathResults[i] << " \n";
	}
	*/
}


int CVP::GetNextCity(int currentCity, vector<float> pheromone, vector<int> distances) {


	float probabilitiesSum = 0.0f;
	float monteCarloSum = 0.0f;
	vector<float> probabilities;
	vector<float> monteCarloProbabilities;

	for (int i = 0; i < C_NUMBER; i++)
		probabilitiesSum += pow(pheromone[i], C_ALPHA) * pow((float)distances[i], C_BETA);

	for (int i = 0; i < C_NUMBER; i++)
	{
		float tmpProbability = pow(pheromone[i], C_ALPHA) / probabilitiesSum;
		probabilities.push_back(tmpProbability);
	}

	for (auto& p : probabilities)
		monteCarloSum += p;

	for (int i = 0; i < probabilities.size(); i++) {
		float tmpSum = 0.0f;
		for (int j = 0; j <= i; j++)
			tmpSum += probabilities[i];
		monteCarloProbabilities.push_back(tmpSum / monteCarloSum);
	}

	int nextCity = 0;
	float randomNumber = (float)(rand() % 100) / 100;

	while (monteCarloProbabilities[nextCity] < randomNumber)
		nextCity++;

	return nextCity;
}
