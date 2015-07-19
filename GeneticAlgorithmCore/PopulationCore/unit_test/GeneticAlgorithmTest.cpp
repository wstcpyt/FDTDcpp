//
// Created by yutong pang on 7/14/15.
//
#include <gmock/gmock.h>
#include "PopulationCore/Population.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace testing;
using std::vector;
using std::cout;


class GeneticAlgorithmTest: public Test{
public:
    vector<double> populationproperties = {0.0, 1.0, 2.0};
    unsigned int populationNumber = 10;
    Population<vector<double>> population = Population<vector<double>>::Population(populationproperties, populationNumber);
};
TEST_F(GeneticAlgorithmTest, PopulationConstructor){
    ASSERT_THAT(population.getGaStruct().fitness, 0);
    ASSERT_THAT(population.getGaStruct().populationproperties[0], 0.0);
    ASSERT_THAT(population.getGaStruct().populationproperties[1], 1.0);
    ASSERT_THAT(population.getGaStruct().populationproperties[2], 2.0);
    ASSERT_THAT(population.getPopulationNumber(), 10);
    ASSERT_THAT(population.buffer.size(), populationNumber);
    ASSERT_THAT(population.population.size(), populationNumber);
}

TEST_F(GeneticAlgorithmTest, PopulationInit){
    double rand_min = 1.0;
    double rand_max = 4.0;
    population.init(rand_min, rand_max);
    ASSERT_THAT(population.population.size(), populationNumber);
    ASSERT_THAT(population.population[0].populationproperties[0], Ge(rand_min));
    ASSERT_THAT(population.population[0].populationproperties[0], Le(rand_max));
}

TEST_F(GeneticAlgorithmTest, sortByFitness){
    population.init(1.0, 5.0);
    for (auto &popind:population.population){
       popind.fitness = popind.populationproperties[0];
    }
    population.sortByFitness();
    ASSERT_THAT(population.population[0].fitness, Le(population.population[1].fitness));
    ASSERT_THAT(population.population[1].fitness, Le(population.population[2].fitness));
}