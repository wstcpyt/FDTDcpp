//
// Created by yutong pang on 7/14/15.
//

#ifndef FDTDCPP_GENETICALGORITHM_H
#define FDTDCPP_GENETICALGORITHM_H

#include <vector>
#include "BoundaryCore/Boundary.h"
#define GA_POPSIZE 100
#define GA_MAXITER 10
#define GA_ELITRATE 0.10f
#define GA_MUTATION	RAND_MAX * GA_MUTATIONRATE
#define GA_MUTATIONRATE 0.25f
#define GA_TARGET_SIZE 2

using namespace std;
typedef vector<double > imp_vector;

struct ga_struct
{
    imp_vector imp {1.0,1.0};
    double fitness;
};

typedef vector<ga_struct> ga_vector;// for brevity

class GeneticAlgorithm{
public:
    GeneticAlgorithm();
    void runenvolotion();

private:
    void init_population(ga_vector &population,
                         ga_vector &buffer );
    void calc_fitness(ga_vector &population);
    inline void print_best(ga_vector &gav);
    void mate(ga_vector &population, ga_vector &buffer);
    void elitism(ga_vector &population,
                 ga_vector &buffer, int esize );
    void mutate(ga_struct &member);
    double fRand(double fMin, double fMax);

};
#endif //FDTDCPP_GENETICALGORITHM_H
