#pragma once
#include "Node.h"

#include <vector>

class Mesh;
class Triangle;

class SolverData
{
public:
    SolverData();
    ~SolverData();


    std::vector<Node> GetNodes();
    std::vector<Triangle> GetTriangle();

private:
    Mesh* m_pMesh;
};
 