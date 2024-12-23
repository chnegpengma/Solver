#pragma once
#include "solver_global.h"
#include "IProcess.h"

class PoissonPrepare : public IProcess
{
public:
    PoissonPrepare(
        SolverData* pSolver,
        OutputData* pOutData);
    ~PoissonPrepare();

    void DoProcess() override;

private:
    SolverData* m_pSolver = nullptr;
    OutputData* m_pOutputData = nullptr;
};

