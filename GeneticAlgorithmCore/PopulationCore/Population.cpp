//
// Created by yutong pang on 7/14/15.
//

#include "Population.h"
#include <vector>
#include <random>

using std::vector;
using std::sort;

template <class Populationtype>
Population<Populationtype>::Population(Populationtype populationstruct, unsigned int population_number)
{
    populationNumber = population_number;
    gaStruct.populationproperties = populationstruct;
    gaStruct.fitness = 0.0;
    population.assign(population_number, gaStruct);
    buffer.assign(population_number, gaStruct);
    srand(unsigned(time(NULL)));
}

template <class Populationtype>
void Population<Populationtype>::init(double rand_min, double rand_max) {
    for (GaStruct &popind:population){
        size_t populationStructSize = popind.populationproperties.size();
        for (int i = 0; i < populationStructSize; ++i) {
            popind.populationproperties[i] = doubleRand(rand_min, rand_max);
        }
        int a = 1;
    }
}

template <class Populationtype>
double Population<Populationtype>::doubleRand(double rand_min, double rand_max) {
    double randTemp = (double)rand() / RAND_MAX;
    return rand_min + randTemp * (rand_max - rand_min);
}

template <class Populationtype>
void Population<Populationtype>::sortByFitness() {
    sort(population.begin(), population.end(), [](GaStruct x, GaStruct y){ return x.fitness < y.fitness; });
}

template <class Populationtype>
void Population<Populationtype>::mate(double elitrate, double mutationrate){
    int eSize = int(populationNumber * elitrate);
    eltism(eSize);
}

template <class Populationtype>
void Population<Populationtype>::eltism(int e_size) {

}


template class Population<vector<double>>;
template class Population<vector<int>>;