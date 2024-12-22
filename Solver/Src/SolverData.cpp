#include "SolverData.h"
#include "Mesh.h"

SolverData::SolverData()
{
    m_pMesh = new Mesh;
}

SolverData::~SolverData()
{
    if (m_pMesh)
    {
        delete m_pMesh;
        m_pMesh = nullptr;
    }
}

Mesh* SolverData::GetMeshPtr()
{
    return m_pMesh;
}