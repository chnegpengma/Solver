#include "Triangle.h"
#include "Vector.h"

Triangle::Triangle()
    : ELement(ELement::Type::Triangle)
{
    m_data.init(3, 2);
}

Triangle::Triangle(
    const std::pair<double, double>& p1,
    const std::pair<double, double>& p2,
    const std::pair<double, double>& p3)
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

Triangle::Triangle(const Triangle& oTri)
    : ELement(ELement::Type::Triangle)
{
    m_data.init(3, 2);
    m_data(1, 1) = oTri.Vec(1, 1);
    m_data(1, 2) = oTri.Vec(1, 2);
    m_data(2, 1) = oTri.Vec(2, 1);
    m_data(2, 2) = oTri.Vec(2, 2);
    m_data(3, 1) = oTri.Vec(3, 1);
    m_data(3, 2) = oTri.Vec(3, 2);
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

Matrix<double> Triangle::GetBaseMat()
{
    Matrix<double> mat(3, 3);
    mat(1, 1) = Vec(2, 1) * Vec(3, 2) - Vec(3, 1) * Vec(2, 2);
    mat(1, 2) = Vec(2, 2) - Vec(3, 2);
    mat(1, 3) = Vec(3, 1) - Vec(2, 1);
    mat(2, 1) = Vec(3, 1) * Vec(1, 2) - Vec(1, 1) * Vec(3, 2);
    mat(2, 2) = Vec(3, 2) - Vec(1, 2);
    mat(2, 3) = Vec(1, 1) - Vec(3, 1);
    mat(3, 1) = Vec(1, 1) * Vec(2, 2) - Vec(2, 1) * Vec(1, 2);
    mat(3, 2) = Vec(1, 2) - Vec(2, 2);
    mat(3, 3) = Vec(2, 1) - Vec(1, 1);
    return mat;
}

double Triangle::Vec(int row, int col) const
{
    return m_data(row, col);
}

