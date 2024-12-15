#pragma once
#include "solver_global.h"
#include "Element.h"
#include "Matrix.h"

class SOLVER_EXPORT 
    Triangle : public ELement
{
public:
    Triangle();
    Triangle(
        std::pair<double, double> p1,
        std::pair<double, double> p2,
        std::pair<double, double> p3);
    ~Triangle();

    double GetArea();

    double VecCoor(int row, int col);
private:
    Matrix<double> m_data;
};
