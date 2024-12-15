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
private:
    Type m_nType;
};
