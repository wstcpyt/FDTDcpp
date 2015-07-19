//
// Created by yutong pang on 7/14/15.
//

#ifndef FDTDCPP_GENETICALGORITHM_H
#define FDTDCPP_GENETICALGORITHM_H

#include <vector>
using std::vector;

template <class Populationtype>
class Population {
    struct GaStruct
    {
        Populationtype populationproperties;
        double fitness;
    };
    unsigned int populationproperitessize;
    GaStruct gaStruct;
    typedef vector<GaStruct> GaVector;
    unsigned int populationNumber;
    GaVector population;
    GaVector buffer;
    double randomMin, randMax;
public:
    GaVector *populationP, *bufferP;
    Population(Populationtype population_properties, unsigned int population_number);

    const GaStruct &getGaStruct() const {
        return gaStruct;
    }

    unsigned int getPopulationNumber() const {
        return populationNumber;
    }


    unsigned int getPopulationproperitessize() const {
        return populationproperitessize;
    }

    void init(double rand_min, double rand_max);
    void sortByFitness();
    void mate(double elitrate, double mutationrate);

private:
    double doubleRand(double rand_min, double rand_max);
    void eltism(int e_size);
    void mutate(GaStruct &mutatemember);
    void swap();
};

#endif //FDTDCPP_GENETICALGORITHM_H
