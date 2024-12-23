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
        double x1 = vecNode[0].first;
        double y1 = vecNode[0].second;
        double x2 = vecNode[1].first;
        double y2 = vecNode[1].second;
        double x3 = vecNode[2].first;
        double y3 = vecNode[2].second;

        std::pair<double, double> p2 = vecNode[1];
        std::pair<double, double> p3 = vecNode[2];


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

        Matrix<double> matH(3, 3);
        matH(1, 1) = (a1 * a1 + (x1 * x1 + x2 * y2 + x3 * y3) * b1 * b1 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * b1 * c1 + (y1 * y1 + y2 * y2 + y3 * y3) * c1 * c1 / 12);
        matH(1, 2) = (a1 * a2 + (x1 * x1 + x2 * y2 + x3 * y3) * b1 * b2 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b1 * c2 + b2 * c1) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c1 * c2 / 12);
        matH(1, 3) = (a1 * a3 + (x1 * x1 + x2 * y2 + x3 * y3) * b1 * b3 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b1 * c3 + b3 * c1) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c1 * c3 / 12);
        matH(2, 1) = (a2 * a1 + (x1 * x1 + x2 * y2 + x3 * y3) * b2 * b1 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b2 * c1 + b1 * c2) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c2 * c1 / 12);
        matH(2, 2) = (a2 * a2 + (x1 * x1 + x2 * y2 + x3 * y3) * b2 * b2 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * b2 * c2 / 6 + (y1 * y1 + y2 * y2 + y3 * y3) * c2 * c2 / 12);
        matH(2, 3) = (a2 * a1 + (x1 * x1 + x2 * y2 + x3 * y3) * b2 * b1 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b2 * c1 + b1 * c2) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c1 * c2 / 12);
        matH(3, 1) = (a3 * a1 + (x1 * x1 + x2 * y2 + x3 * y3) * b3 * b1 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b3 * c1 + b1 * c3) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c1 * c3 / 12);
        matH(3, 2) = (a3 * a2 + (x1 * x1 + x2 * y2 + x3 * y3) * b3 * b2 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * (b3 * c2 + b2 * c3) / 12 + (y1 * y1 + y2 * y2 + y3 * y3) * c3 * c2 / 12);
        matH(3, 3) = (a3 * a3 + (x1 * x1 + x2 * y2 + x3 * y3) * b3 * b3 / 12
            + (x1 * y1 + x2 * y2 + x3 * y3) * b3 * c3 / 6 + (y1 * y1 + y2 * y2 + y3 * y3) * c3 * c3 / 12);


    }
}