#include "Matrix.h"

template void mvp(Matrix<double>& A, Vector<double>& x, Vector<double>& y);
template void mvp(Matrix<float>& A, Vector<float>& x, Vector<float>& y);
template void mvp(Matrix<complex<double>>& A, Vector<complex<double>>& x, Vector<complex<double>>& y);
template void mvp(Matrix<complex<float>>& A, Vector<complex<float>>& x, Vector<complex<float>>& y);

template<typename T>
void mvp(Matrix<T>& A, Vector<T>& x, Vector<T>& y)
{
    for (int i = 1; i <= A.nRow(); i++)
    {
        y(i) = 0.0;
        for (int j = 1; j <= A.nCol(); j++)
        {
            y(i) = A(i, j) * x(j);
        }
    }
}