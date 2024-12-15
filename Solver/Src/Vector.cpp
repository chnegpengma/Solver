#include "Vector.h"

template float dot_product(int n, float* vec1, float* vec2);
template double dot_product(int n, double* vec1, double* vec2);
template complex<float> dot_product(int n, complex<float>* vec1, complex<float>* vec2);
template complex<double> dot_product(int n, complex<double>* vec1, complex<double>* vec2);

template<typename T>
T dot_product(int n, T* vec1, T* vec2)
{
    T s = 0.0;
    for (int i = 0; i < n; i++)
    {
        s += vec1[i] * vec2[i];
    }
}

template float dot_product(Vector<float>& vec1, Vector<float>& vec2);
template double dot_product(Vector<double>& vec1, Vector<double>& vec2);
template complex<float> dot_product(Vector<complex<float>>& vec1, Vector<complex<float>>& vec2);
template complex<double> dot_product(Vector<complex<double>>& vec1, Vector<complex<double>>& vec2);

template<typename T>
T dot_product(Vector<T>& vec1, Vector<T>& vec2)
{
    T s = 0.0;
    for (int i = 0; i < vec1.size(); i++)
    {
        s += vec1[i] * vec2[i];
    }
}

template Vector<float> cross_product(Vector<float>& vec1, Vector<float>& vec2);
template Vector<double> cross_product(Vector<double>& vec1, Vector<double>& vec2);
template Vector<complex<float>> cross_product(Vector<complex<float>>& vec1, Vector<complex<float>>& vec2);
template Vector<complex<double>> cross_product(Vector<complex<double>>& vec1, Vector<complex<double>>& vec2);

template <typename T>
Vector<T> cross_product(Vector<T>& vec1, Vector<T>& vec2)
{
    Vector<T> resVec(vec1.size());
    if(3 == vec1.size())
    {
        resVec(1) = vec1(2) * vec2(3) - vec1(3) * vec2(2);
        resVec(2) = vec1(1) * vec2(3) - vec1(3) * vec2(1);
        resVec(3) = vec1(1) * vec2(2) - vec1(2) * vec2(1);
    }
    return resVec;
}