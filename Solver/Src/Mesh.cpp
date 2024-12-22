#include "Mesh.h"
#include "Node.h"


Mesh::Mesh()
{

}
Mesh::~Mesh()
{

}

void Mesh::fromFile(const char* filePath)
{
    FILE* file;
    char buf[255];
    int id, num, p1, p2, p3;
    double x, y;
    fopen_s(&file, filePath, "rb");
    m_vecNodes = new double(num * 2);
    while (!feof(file))
    {
        while (strncmp(buf, "NODE", 4) != 0)
        {
            fgets(buf, 255, file);
        }
        fscanf_s(file, "%i\t%f\t%f\t", &num, &x, &y);

    }

    while (!feof(file))
    {
        while (strncmp(buf, "ELEMENT", 7) != 0)
        {
            fgets(buf, 255, file);
        }
        fscanf_s(file, "%i\t%i\t%i\t%i\t", &id, &p1, &p2, &p3);
        std::vector<int> tmp;
        tmp.push_back(p1);
        tmp.push_back(p2);
        tmp.push_back(p3);
        m_vecTri.push_back(tmp);
    }

    fclose(file);
}

int Mesh::NodeSize()
{
    return m_num;
}

int Mesh::ElementSize()
{
    return m_vecTri.size();
}

void Mesh::DoProcess()
{
    
}


int Mesh::GetNodeNum()
{
    return m_num;
}
const std::vector<std::pair<double, double>>& Mesh::GetNodeVec()
{

}
const std::vector<std::vector<int>>& Mesh::GetTri()
{
    return m_vecTri;
}