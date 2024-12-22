#pragma once
#include<complex>
#include "Vector.h"

using namespace std;

template <typename T>
class Matrix
{
public:
    Matrix()
    {
        m_nCol = 0;
        m_nRow = 0;
    }

    Matrix(int r, int c) {
        m_nRow = r;
        m_nCol = c;
        m_data = new T[r * c];
        for (int i = 0; i < r * c; i++){
            m_data[i] = 0;
        }
    }

    Matrix(const Matrix<T>& mat){
        m_nRow = mat.m_nRow;
        m_nCol = mat.m_nCol;
        for (int i = 0; i < m_nRow * m_nCol; i++) {
            m_data[i] = mat.m_data[i];
        }
    }

    ~Matrix() {
        if (m_nRow * m_nCol > 0)
        {
            delete m_data;
            m_nRow = 0;
            m_nCol = 0;
        }
    }
    void init(int r) {
        m_nRow = r;
        m_nCol = r;
        m_data = new T[r * r];
        for (int i = 0; i < r * r; i++) {
            m_data[i] = 0;
        }
    }
    void init(int r, int c) {
        m_nRow = r;
        m_nCol = c;
        m_data = new T[r * c];
        for (int i = 0; i < r * c; i++) {
            m_data[i] = 0;
        }
    }

    void clear(){
        if (m_nRow * m_nCol > 0)
        {
            delete m_data;
            m_nRow = 0;
            m_nCol = 0;
        }
    }

    int& nRow() { return m_nRow; }
    int& nCol() { return m_nCol; }

    T& operator[](int i) const { return m_data[i]; }
    T& operator()(int i, int j) const { return m_data[i - 1 + (j - 1) * m_nRow]; }
    
    template <typename E>
    Matrix<T>& operator=(const E& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] = vec;
        }
        return *this;
    }

    Matrix<T>& operator=(const Matrix<T>& vec) {
        for (int i = 0; i < m_nRow*m_nCol; i++)
        {
            m_data[i] = vec.m_data[i];
        }
        return *this;
    }

    template <typename E>
    Matrix<T>& operator+=(const E& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] += vec;
        }
        return *this;
    }

    Matrix<T>& operator+=(const Matrix<T>& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] += vec.m_data[i];
        }
        return *this;
    }

    template <typename E>
    Matrix<T>& operator-=(const E& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] += vec;
        }
        return *this;
    }

    Matrix<T>& operator-=(const Matrix<T>& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] += vec.m_data[i];
        }
        return *this;
    }

    template <typename E>
    Matrix<T>& operator*=(const E& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] *= vec;
        }
        return *this;
    }

    Matrix<T>& operator*=(const Matrix<T>& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] *= vec.m_data[i];
        }
        return *this;
    }

    template <typename E>
    Matrix<T>& operator/=(const E& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] /= vec;
        }
        return *this;
    }

    Matrix<T>& operator/=(const Matrix<T>& vec) {
        for (int i = 0; i < m_nRow * m_nCol; i++)
        {
            m_data[i] /= vec.m_data[i];
        }
        return *this;
    }

    template <typename E>
    friend Matrix operator+(const Matrix& mat, E& val) {
        Matrix<T>v(mat.m_nRow * mat.m_nCol);
        for (int i = 0; i < mat.m_nRow*m_nCol; i++)
        {
            v.m_data[i] = val + mat.m_data[i];
        }
        return *this;
    }
 
    friend Matrix operator+(const Matrix<T>& mat1, const Matrix<T>& mat2) {
        Matrix<T>v(mat1.m_nRow * mat1.m_nCol);
        for (int i = 0; i < mat1.m_nRow * mat1.m_nCol; i++)
        {
            v.m_data[i] = mat1.m_data[i] + mat2.m_data[i];
        }
        return *this;
    }
    template <typename E>
    friend Matrix operator-(const Matrix<T>& mat, E& val) {
        Matrix<T>v(mat.m_nRow*mat.m_nCol);
        for (int i = 0; i < mat.m_nRow * mat.m_nCol; i++)
        {
            v.m_data[i] = mat.m_data[i] - val;
        }
        return *this;
    }
    friend Matrix operator-(const Matrix<T>& mat1, const Matrix<T>& mat2) {
        Matrix<T>v(mat1.m_nRow * mat1.m_nCol);
        for (int i = 0; i < mat1.m_nRow * mat1.m_nCol; i++)
        {
            v.m_data[i] = mat1.m_data[i] * mat2.m_data[i];
        }
        return *this;
    }
    template <typename E>
    friend Matrix operator*(const Matrix<T>& mat, E& val) {
        Matrix<T>v(mat.m_nRow * mat.m_nCol);
        for (int i = 0; i < mat.m_nRow * mat.m_nCol; i++)
        {
            v.m_data[i] = mat.m_data[i] * val;
        }
        return *this;
    }

    friend Matrix operator*(const Matrix<T>& mat1, const Matrix<T>& mat2) {
        Matrix<T>v(mat1.m_nRow * mat1.m_nCol);
        for (int i = 0; i < mat1.m_nRow * mat1.m_nCol; i++)
        {
            v.m_data[i] = mat1.m_data[i] * mat2.m_data[i];
        }
        return *this;
    }
    template <typename E>
    friend Matrix operator/(const Matrix<T>& mat, E& val) {
        Matrix<T>v(mat.m_nRow * mat.m_nCol);
        for (int i = 0; i < mat.m_nRow * mat.m_nCol; i++)
        {
            v.m_data[i] = mat.m_data[i] / val;
        }
        return *this;
    }
    friend Matrix operator/(const Matrix<T>& mat1, const Matrix<T>& mat2) {
        Matrix<T>v(mat1.m_nRow * mat1.m_nCol);
        for (int i = 0; i < mat1.m_nRow * mat1.m_nCol; i++)
        {
            v.m_data[i] = mat1.m_data[i] / mat2.m_data[i];
        }
        return *this;
    }
 

protected:
    int m_nCol;
    int m_nRow;
    T* m_data;

private:

};

//matrix vector product
template<typename T>
void mvp(Matrix<T>& A, Vector<T>& x, Vector<T>& y);
