//
// Created by yutong pang on 6/27/15.
//

#include <gmock/gmock.h>
#include "StructureCore/Structure.h"
using namespace testing;

class StructureTEST: public Test{
public:
    Structure structure;
};

TEST_F(StructureTEST, structureCanInitPermittivity){
    ASSERT_THAT(structure.getPermittivity().size(), STRUCTURE_SIZE);
}
TEST_F(StructureTEST, structureCanInitLoss){
    ASSERT_THAT(structure.getLoss().size(), STRUCTURE_SIZE);
}

TEST_F(StructureTEST, StructureTWOlayerRefractiveIndexConstructor){
    Structure structure1(9.0, 4.0);
    ASSERT_THAT(structure1.getPermittivity1(), 9.0);
    ASSERT_THAT(structure1.getpermittivity2(), 4.0);
}

