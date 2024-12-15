#include "Prepare.h"
#include "OutputData.h"
#include "SolverData.h"

Prepare::Prepare(
    SolverData* pSolver,
    OutputData* pOutData)
    : IProcess(pSolver, pOutData)
    , m_pSolver(pSolver)
    , m_pOutputData(pOutData)
{

}

Prepare::~Prepare()
{

}

void Prepare::DoProcess()
{
    
}