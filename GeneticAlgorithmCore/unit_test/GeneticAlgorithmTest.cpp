//
// Created by yutong pang on 7/14/15.
//
#include <gmock/gmock.h>
#include "GeneticAlgorithmCore/GeneticAlgorithm.h"
using namespace testing;
class GeneticAlgorithmTest: public Test{
public:
    GeneticAlgorithm geneticAlgorithm;

};
TEST_F(GeneticAlgorithmTest, constructor){
    geneticAlgorithm.runenvolotion();
}