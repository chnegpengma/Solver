#pragma once
#include "IProcess.h"

class LaplacePrepare : public IProcess
{
public:
    LaplacePrepare(
        SolverData* pSolver,
        OutputData* pOutData);
    ~LaplacePrepare();

    void DoProcess()override;
private:
    SolverData* m_pSolver = nullptr;
    OutputData* m_pOutputData = nullptr;
};

