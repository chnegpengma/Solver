#pragma once
#include "solver_global.h"

class SolverData;
class OutputData;

class SOLVER_EXPORT IProcess
{
public:
    IProcess(SolverData* pSolver, OutputData* pOutData) {}
    ~IProcess() {}

    virtual void DoProcess() = 0;

};
