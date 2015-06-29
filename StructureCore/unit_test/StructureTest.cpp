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

