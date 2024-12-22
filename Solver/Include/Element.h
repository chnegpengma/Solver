#pragma once
class ELement
{
public:
    enum Type
    {
        Unknown,
        Triangle
    };
public:
    ELement(Type nType)
    : m_nType(nType)
    {

    }
    ~ELement()
    {

    }


    virtual double GetArea() = 0;
    virtual Matrix<double> GetBaseMat() = 0;
private:
    Type m_nType;
};
