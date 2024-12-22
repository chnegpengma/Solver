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
    Triangle(const Triangle& oTri);
    ~Triangle();

    double GetArea() override;
    Matrix<double> GetBaseMat() override;

    double Vec(int row, int col) const;
private:
    Matrix<double> m_data;
};
