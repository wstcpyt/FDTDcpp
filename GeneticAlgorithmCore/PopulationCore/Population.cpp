//
// Created by yutong pang on 7/14/15.
//

#include "Population.h"
#include <vector>
#include <random>

using std::vector;
using std::sort;

template <class Populationtype>
Population<Populationtype>::Population(Populationtype population_properties, unsigned int population_number)
{
    populationNumber = population_number;
    gaStruct.populationproperties = population_properties;
    gaStruct.fitness = 0.0;
    population.assign(population_number, gaStruct);
    buffer.assign(population_number, gaStruct);
    populationP = &population;
    populationproperitessize = population_properties.size();
    bufferP = &buffer;
    randMax = 0.0;
    randomMin = 0.0;
    srand(unsigned(time(NULL)));
}

template <class Populationtype>
void Population<Populationtype>::init(double rand_min, double rand_max) {
    for (GaStruct &popind:*populationP){
        size_t populationStructSize = popind.populationproperties.size();
        for (int i = 0; i < populationStructSize; ++i) {
            popind.populationproperties[i] = doubleRand(rand_min, rand_max);
        }
        int a = 1;
    }
}

template <class Populationtype>
double Population<Populationtype>::doubleRand(double rand_min, double rand_max) {
    randomMin = rand_min;
    randMax = rand_max;
    double randTemp = (double)rand() / RAND_MAX;
    return rand_min + randTemp * (rand_max - rand_min);
}

template <class Populationtype>
void Population<Populationtype>::sortByFitness() {
    sort((*populationP).begin(), (*populationP).end(), [](GaStruct x, GaStruct y){ return x.fitness < y.fitness; });
}

template <class Populationtype>
void Population<Populationtype>::mate(double elitrate, double mutationrate){
    int eSize = int(populationNumber * elitrate), i1, i2, crossposition;
    eltism(eSize);
    // Mate the rest
    for (int i = eSize; i < populationNumber; i++){
        i1 = rand()%(populationNumber / 2);
        i2 = rand()%(populationNumber / 2);
        crossposition = rand() % populationproperitessize;
        for (int j = 0; j < populationproperitessize; j++){
            if (j< crossposition){
                (*bufferP)[i].populationproperties[j] = (*populationP)[i1].populationproperties[j];
            }
            else{
                (*bufferP)[i].populationproperties[j] = (*populationP)[i2].populationproperties[j];
            }
        }
        if (rand() < int(mutationrate * RAND_MAX)){
            mutate((*bufferP)[i]);
        }
    }
    swap();
}

template <class Populationtype>
void Population<Populationtype>::eltism(int e_size) {
    for (int i = 0; i < e_size; i++){
        (*bufferP)[i].populationproperties = (*populationP)[i].populationproperties;
        (*bufferP)[i].fitness = (*populationP)[i].fitness;
    }
}

template <class Populationtype>
void Population<Populationtype>::mutate(GaStruct &mutatemember) {
    int mutateposition = rand()%populationproperitessize;
    mutatemember.populationproperties[mutateposition] = doubleRand(randomMin, randMax);
}

template <class Populationtype>
void Population<Populationtype>::swap() {
    GaVector *temp = populationP; populationP = bufferP; bufferP = temp;
}

template class Population<vector<double>>;
template class Population<vector<int>>;