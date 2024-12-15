#pragma once
#include "IProcess.h"

class Prepare : public IProcess
{
public:
    Prepare(
        SolverData* pSolver,
        OutputData* pOutData);
    ~Prepare();

    void DoProcess() override;

private:
    SolverData* m_pSolver = nullptr;
    OutputData* m_pOutputData = nullptr;
};
