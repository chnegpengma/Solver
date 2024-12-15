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
private:
    double& NodeX(int id);
    double& NodeY(int id);
    std::pair<double, double> Node(int id);


private:
    int m_num;
    double* m_vecNodes = nullptr;
    std::vector<std::vector<int>> m_vecTri;
    Matrix<double> m_matElem;
};