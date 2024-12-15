#include "Triangle.h"
#include "Vector.h"

Triangle::Triangle()
    : ELement(ELement::Type::Triangle)
{
    m_data.init(3, 2);
}

Triangle::Triangle(
    std::pair<double, double> p1,
    std::pair<double, double> p2,
    std::pair<double, double> p3)
    :ELement(ELement::Type::Triangle)
{
    m_data.init(3, 2);
    m_data(1, 1) = p1.first;
    m_data(1, 2) = p1.second;
    m_data(2, 1) = p2.first;
    m_data(2, 2) = p2.second;
    m_data(3, 1) = p3.first;
    m_data(3, 2) = p3.second;
}

Triangle::~Triangle()
{

}

double Triangle::GetArea()
{
    Vector<double> ab(2);
    Vector<double> ac(2);
    ab(1) = m_data(2, 1) - m_data(1, 1);
    ab(2) = m_data(2, 2) - m_data(1, 2);
    ac(1) = m_data(3, 1) - m_data(1, 1);
    ac(2) = m_data(3, 2) - m_data(1, 2);

    return ab(1) * ac(2) - ab(2) * ac(1);
}

double Triangle::VecCoor(int row, int col)
{
    return m_data(row, col);
}