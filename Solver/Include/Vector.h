#pragma once

#include "solver_global.h"
#include <complex>

using namespace std;

template <typename T>
class SOLVER_EXPORT Vector
{
public:
    Vector()
    {
        m_num = 0;
    }
    Vector(int n)
    {
        m_num = n;
        m_data = new T[n];
        for (int i = 0; i < n; i++)
        {
            m_data[i] = 0.0;
        }
    }
    Vector(const Vector<T>& vec)
    {
        m_num = vec.m_num;
        T* m_data = new T[m_num];
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] = vec[i];
        }
    }
    ~Vector()
    {
        if (m_num > 0)
        {
            delete[] m_data;
            m_num = 0;
        }
    }
    void clear()
    {
        if (m_num > 0)
        {
            delete[] m_data;
            m_num = 0;
        }
    }

    void init(int n)
    {
        m_num = n;
        m_data = new T[n];
        for (int i = 0; i < n; i++)
        {
            m_data[i] = 0.0;
        }
    }
    int& size() { return m_num; }
    double norm()
    {
        double res = 0;
        for (int i = 0; i < m_num; ++i)
        {
            res += m_data[i] * m_data[i];
        }
        res = std::pow(res, 0.5);
        return res;
    }

    T& operator[](int i) const { return m_data[i]; }
    T& operator()(int i) const { return m_data[i - 1]; }
    template<typename E>
    Vector<T>& operator=(const E& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] = vec;
        }
        return *this;
    }

    Vector<T>& operator=(const Vector<T>& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] = vec.m_data[i];
        }
        return *this;
    }

    template<typename E>
    Vector<T>& operator+=(const E& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] += vec;
        }
        return *this;
    }

    Vector<T>& operator+=(const Vector<T>& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] += vec.m_data[i];
        }
        return *this;
    }

    template<typename E>
    Vector<T>& operator-=(const E& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] -= vec;
        }
        return *this;
    }

    Vector<T>& operator-=(const Vector<T>& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] -= vec.m_data[i];
        }
        return *this;
    }

    template<typename E>
    Vector<T>& operator*=(const E& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] *= vec;
        }
        return *this;
    }

    Vector<T>& operator*=(const Vector<T>& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] *= vec.m_data[i];
        }
        return *this;
    }

    template<typename E>
    Vector<T>& operator/=(const E& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] /= vec;
        }
        return *this;
    }
    Vector<T>& operator/=(const Vector<T>& vec) {
        for (int i = 0; i < m_num; i++)
        {
            m_data[i] /= vec.m_data[i];
        }
        return *this;
    }
    template<typename E>
    friend Vector operator+(const Vector<T>& vec, E& val) {
        Vector<T>v(vec.m_num);
        for (int i = i; i < vec.m_num; i++)
        {
            v.m_data[i] = vec.m_data[i] + val;
        }
        return *this;
    }
    friend Vector operator+(const Vector<T>& vec1, const Vector<T>& vec2) {
        Vector<T>v(vec1.m_num);
        for (int i = i; i < vec1.m_num; i++)
        {
            v.m_data[i] = vec1.m_data[i] + vec2.m_data[i];
        }
        return *this;
    }
    template <typename E>
    friend Vector operator-(const Vector<T>& vec, E& val) {
        Vector<T>v(vec.m_num);
        for (int i = i; i < vec.m_num; i++)
        {
            v.m_data[i] = vec.m_data[i] - val;
        }
        return *this;
    }
    friend Vector operator-(const Vector<T>& vec1, const Vector<T>& vec2) {
        Vector<T>v(vec1.m_num);
        for (int i = i; i < vec1.m_num; i++)
        {
            v.m_data[i] = vec1.m_data[i] - vec2.m_data[i];
        }
        return *this;
    }
    template <typename E>
    friend Vector operator*(const Vector<T>& vec, E&val) {
        Vector<T>v(vec.m_num);
        for (int i = i; i < vec.m_num; i++)
        {
            v.m_data[i] = vec.m_data[i] * val;
        }
        return *this;
    }
    friend Vector operator*(const Vector<T>& vec1, const Vector<T>& vec2) {
        Vector<T>v(vec1.m_num);
        for (int i = i; i < vec1.m_num; i++)
        {
            v.m_data[i] = vec1.m_data[i] * vec2.m_data[i];
        }
        return *this;
    }
    template<typename E>
    friend Vector operator/(const Vector<T>& vec, E& val) {
        Vector<T>v(vec.m_num);
        for (int i = i; i < vec.m_num; i++)
        {
            v.m_data[i] = vec.m_data[i] / val;
        }
        return *this;
    }
    friend Vector operator/(const Vector<T>& vec1, const Vector<T>& vec2) {
        Vector<T>v(vec1.m_num);
        for (int i = i; i < vec1.m_num; i++)
        {
            v.m_data[i] = vec1.m_data[i] / vec2.m_data[i];
        }
        return *this;
    }
private:
    int m_num;
    T* m_data;
};

template<typename T>
T dot_product(int n, T* vec1, T* vec2);

template<typename T>
T dot_product(Vector<T>& vec1, Vector<T>& vec2);

//
template<typename T>
Vector<T> cross_product(Vector<T>&vec1, Vector<T>& vec2);
