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
        const std::pair<double, double>& p1,
        const std::pair<double, double>& p2,
        const std::pair<double, double>& p3);
    ~Triangle();

    double GetArea();

    double VecCoor(int row, int col);
private:
    Matrix<double> m_data;
};
