#include "Node.h"

#include <utility>

Node::Node()
{
    m_vecNode.init(2);
}
Node::Node(std::pair<double, double> pair)
{
    m_vecNode.init(2);
    m_vecNode(1) = pair.first;
    m_vecNode(2) = pair.second;
}
Node::~Node()
{

}

std::pair<double, double>& Node::GetNode()
{
    return std::make_pair(m_vecNode(1), m_vecNode(2));
}