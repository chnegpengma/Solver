#pragma once
#include "IProcess.h"

class HelmholtzPrepare : public IProcess
{
public:
    HelmholtzPrepare(
        SolverData* pSolver,
        OutputData* pOutData);
    ~HelmholtzPrepare();

    void DoProcess() override;

private:
    SolverData* m_pSolver = nullptr;
    OutputData* m_pOutputData = nullptr;
};
