#include "HelmholtzPrepare.h"
#include "OutputData.h"
#include "SolverData.h"
#include "Triangle.h"
#include "Mesh.h"

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
    double kx, ky;
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
        Matrix<double> mat(3, 3);

        mat(1, 1) = (kx * b1 * b1 + ky * c1 * c1) / (4 * oTri.GetArea());
        mat(1, 2) = (kx * b1 * b2 + ky * c1 * c2) / (4 * oTri.GetArea());
        mat(1, 3) = (kx * b1 * b3 + ky * c1 * c3) / (4 * oTri.GetArea());
        mat(2, 1) = mat(1, 2);
        mat(2, 2) = (kx * b2 * b2 + ky * c2 * c2) / (4 * oTri.GetArea());
        mat(2, 3) = (kx * b2 * b3 + ky * c2 * c3) / (4 * oTri.GetArea());
        mat(3, 1) = mat(1, 3);
        mat(3, 2) = (kx * b2 * b2 + ky * c1 * c2) / (4 * oTri.GetArea());
        mat(3, 3) = (kx * b1 * b2 + ky * c1 * c2) / (4 * oTri.GetArea());


        std::vector<Matrix<double>> 

    }
}