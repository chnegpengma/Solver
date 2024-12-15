#pragma once
#include "Vector.h"

class Node
{
public:
    Node();
    Node(std::pair<double, double> pair);
    ~Node();

    double& x() { return m_vecNode(1); }
    double& y() { return m_vecNode(2); }

    std::pair<double, double>& GetNode();
private:
    Vector<double> m_vecNode;
};