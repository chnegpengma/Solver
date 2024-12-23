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
    const std::vector<std::vector<int>>& matTri = pMesh->GetVecTri();
    int num = pMesh->GetNodeNum();
    const std::vector<std::pair<double, double>>& vecNode = pMesh->GetVecNode();
    for (int i = 0; i < matTri.size(); ++i)
    {
        std::vector<int> tri = matTri[i];
        Triangle oTri(vecNode[tri[0]], vecNode[tri[1]], vecNode[tri[2]]);
        Matrix<double> matBase = oTri.GetBaseMat();
        double a1 = matBase(1, 1);
        double b1 = matBase(1, 2);
        double c1 = matBase(1, 3);
        double a2 = matBase(2, 1);
        double b2 = matBase(2, 2);
        double c2 = matBase(2, 3);
        double a3 = matBase(3, 1);
        double b3 = matBase(3, 2);
        double c3 = matBase(3, 3);

        Matrix<double> matK(3, 3);
        matK(1, 1) = (b1 * b1 + c1 * c1) / (4 * oTri.GetArea());
        matK(1, 2) = (b1 * b2 + c1 * c2) / (4 * oTri.GetArea());
        matK(1, 3) = (b1 * b3 + c1 * c3) / (4 * oTri.GetArea());
        matK(2, 1) = matK(1, 2);
        matK(2, 2) = (b2 * b2 + c2 * c2) / (4 * oTri.GetArea());
        matK(2, 3) = (b2 * b3 + c2 * c3) / (4 * oTri.GetArea());
        matK(3, 1) = matK(1, 3);
        matK(3, 2) = matK(2, 3);
        matK(3, 3) = (b3 * b3 + c3 * c3) / (4 * oTri.GetArea());


    }
}