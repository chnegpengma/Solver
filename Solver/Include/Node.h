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

    const std::pair<double, double>& GetNode();

    Node& operator=(Node node);
private:
    Vector<double> m_vecNode;
};

