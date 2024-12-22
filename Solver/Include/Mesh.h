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
    double* GetNodes();
    const std::vector<std::pair<double, double>>& GetNodeVec();
    const std::vector<std::vector<int>>& GetTri();
private:
    double& NodeX(int id);
    double& NodeY(int id);
    std::pair<double, double> Node(int id);


private:
    int m_num;
    const std::vector<std::pair<double, double>>& m_vecNodes;
    std::vector<std::vector<int>> m_vecTri;
    Matrix<double> m_matElem;
};