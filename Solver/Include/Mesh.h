#pragma once

#include "Matrix.h"
#include "Node.h"
#include "IProcess.h"

#include <vector>

class Element;

class Mesh
{
public:
    Mesh();
    ~Mesh();

    void fromFile(const char* filePath);

    int NodeSize();
    int ElementSize();

    void DoProcess();

    int GetNodeNum();
    const std::vector<std::pair<double, double>>& GetVecNode();
    const std::vector<std::vector<int>>& GetVecTri();
    const std::vector<std::vector<int>>& GetVecEdge();


private:
    int m_num;
    std::vector<std::pair<double, double>> m_vecNodes;
    std::vector<std::vector<int>> m_vecTri;
    std::vector<std::vector<int>> m_vecEdge;
};