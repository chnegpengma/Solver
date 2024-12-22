#include "HelmholtzPrepare.h"
#include "OutputData.h"
#include "SolverData.h"
#include "Triangle.h"

HelmholtzPrepare::HelmholtzPrepare(
    SolverData* pSolver,
    OutputData* pOutData)
    : IProcess(pSolver, pOutData)
    , m_pSolver(pSolver)
    , m_pOutputData(pOutData)
{

}

HelmholtzPrepare::~HelmholtzPrepare()
{

}

void HelmholtzPrepare::DoProcess()
{
    
}