#include "LaplacePrepare.h"
#include "SolverData.h"
#include "OutputData.h"
#include "Triangle.h"
#include "Mesh.h"

LaplacePrepare::LaplacePrepare(
    SolverData* pSolver,
    OutputData* pOutData)
    : IProcess(pSolver, pOutData)
    , m_pSolver(pSolver)
    , m_pOutputData(pOutData)
{

}

LaplacePrepare::~LaplacePrepare()
{
}

void LaplacePrepare::DoProcess()
{
    if (!m_pSolver)
    {
        return;
    }
    auto pMesh = m_pSolver->GetMeshPtr();
    if (!pMesh)
    {
        return;
    }
    const std::vector<std::vector<int>>& matTri = pMesh->GetTri();
    int num = pMesh->GetNodeNum();
    double* pNode = pMesh->GetNodes();
    for (int i = 0; i < matTri.size(); ++i)
    {
        std::vector<int> tri = matTri[i];
        Triangle oTri(Node(tri[0]), tri[1], tri[2]);
        double a1 = oTri.VecCoor(2, 1) * oTri.VecCoor(3, 2) - oTri.VecCoor(3, 1) * oTri.VecCoor(2, 2);
        double b1 = oTri.VecCoor(2, 2) - oTri.VecCoor(3, 2);
        double c1 = oTri.VecCoor(3, 1) - oTri.VecCoor(2, 1);
        double a2 = oTri.VecCoor(3, 1) * oTri.VecCoor(1, 2) - oTri.VecCoor(1, 1) * oTri.VecCoor(3, 2);
        double b2 = oTri.VecCoor(3, 2) - oTri.VecCoor(1, 2);
        double c2 = oTri.VecCoor(1, 1) - oTri.VecCoor(3, 1);
        double a3 = oTri.VecCoor(1, 1) * oTri.VecCoor(2, 2) - oTri.VecCoor(2, 1) * oTri.VecCoor(1, 2);
        double b3 = oTri.VecCoor(1, 2) - oTri.VecCoor(2, 2);
        double c3 = oTri.VecCoor(2, 1) - oTri.VecCoor(1, 1);
        std::vector<double> aiVec;
        std::vector<double> ajVec;
        std::vector<double> amVec;

    }
}