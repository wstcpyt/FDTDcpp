//
// Created by yutong pang on 7/14/15.
//

#include "GeneticAlgorithm.h"
#include <iostream>					// for cout etc.
#include <algorithm>				// for sort algorithm
#include <time.h>					// for random seed
#include <math.h>					// for abs()
#include "constant.h"
#include "FieldCore/EMField.h"
#include "FrequencyDomainCore/FrequencyDomain.h"
#include "VisualCore/LineChart.h"
#include "VisualCore/ColorMap.h"
using namespace std;

bool fitness_sort(ga_struct x, ga_struct y)
{ return (x.fitness < y.fitness); }

inline void sort_by_fitness(ga_vector &population)
{ sort(population.begin(), population.end(), fitness_sort); }

inline void swap(ga_vector *&population,
                 ga_vector *&buffer)
{ ga_vector *temp = population; population = buffer; buffer = temp; }

GeneticAlgorithm::GeneticAlgorithm() {
}

void GeneticAlgorithm::runenvolotion() {
    srand(unsigned(time(NULL)));

    ga_vector pop_alpha, pop_beta;
    ga_vector *population, *buffer;
    init_population(pop_alpha, pop_beta);
    population = &pop_alpha;
    buffer = &pop_beta;

    for (int i=0; i<GA_MAXITER; i++){
        calc_fitness(*population);
        sort_by_fitness(*population);
        print_best(*population);
        mate(*population, *buffer);
        swap(population, buffer);
    }
}

void GeneticAlgorithm::init_population(ga_vector &population, ga_vector &buffer) {
    for (int i=0;  i < GA_POPSIZE; i++) {
        ga_struct structure;
        structure.fitness = 0;
        structure.imp = {rand() % 16, rand() %16};
        population.push_back(structure);
    }
    buffer.resize(GA_POPSIZE);
}

void GeneticAlgorithm::calc_fitness(ga_vector &population) {
    for (int i = 0; i < GA_POPSIZE; i++){
        Boundary boundary;
        vector<vector<double>> waterFallVector(STRUCTURE_SIZE, vector<double >(MAXTIME));
        Structure structure(population[i].imp[0], population[i].imp[1]);
        EMField emField(structure);
        for (int time = 0; time < MAXTIME; time++){
            emField.updateMagneticField();
            boundary.addMagneticTFSF(time, 50, emField);
            boundary.addElectricTFSF(time, 50, emField);
            emField.updateElectricField();
            boundary.addElectricFirstABC(emField);
            int gridpoint;
            for (gridpoint=0; gridpoint < STRUCTURE_SIZE; gridpoint++){
                waterFallVector[gridpoint][time] = emField.getEz()[gridpoint];
            }
        }
        vector<double> structurefield(STRUCTURE_SIZE, 0);
        for (int i =0; i < STRUCTURE_SIZE; i++){
            FrequencyDomain frequencyDomain(waterFallVector[i]);
            auto intensity = frequencyDomain.fftrealToIntensity();
            structurefield[i] = intensity[5];
        }
        population[i].fitness = structurefield[40];
        LineChart lineChart;
        //lineChart.drawchart(structurefield, 1);
    }
}



void GeneticAlgorithm::print_best(ga_vector &gav) {
    { cout << "Best: " << gav[0].imp[0] <<  " " << gav[0].imp[1]  << " (" << gav[0].fitness << ")" << endl; }
}

void GeneticAlgorithm::mate(ga_vector &population, ga_vector &buffer) {
    int esize = GA_POPSIZE * GA_ELITRATE, i1, i2;
    elitism(population, buffer, esize);
    // Mate the rest
    for (int i=esize; i< GA_POPSIZE; i++){
        i1 = rand() % (GA_POPSIZE / 2);
        i2 = rand() % (GA_POPSIZE / 2);
        buffer[i].imp[0] = population[i1].imp[0];
        buffer[i].imp[1] = population[i2].imp[1];
        if (rand() < GA_MUTATION) mutate(buffer[i]);
    }

}

void GeneticAlgorithm::elitism(ga_vector &population, ga_vector &buffer, int esize) {
    for (int i=0; i<esize; i++) {
        buffer[i].imp = population[i].imp;
        buffer[i].fitness = population[i].fitness;
    }
}


void GeneticAlgorithm::mutate(ga_struct &member) {
    int impposition = rand() % 1;
    member.imp[impposition] = rand() % 16;
}