#include "Mesh.h"
#include "Node.h"
#include "Triangle.h"

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
    for (int i = 0; i < m_vecTri.size(); ++i)
    {
        std::vector<int> tri = m_vecTri[i];
        Triangle oTri(Node(tri[0]), Node(tri[0]), Node(tri[0]));
        double ai = oTri.VecCoor(2, 1) * oTri.VecCoor(3, 2) - oTri.VecCoor(3, 1) * oTri.VecCoor(2, 2);
        double bi = oTri.VecCoor(2, 2) - oTri.VecCoor(3, 2);
        double ci = oTri.VecCoor(3, 1) - oTri.VecCoor(2, 1);
        double aj = oTri.VecCoor(3, 1) * oTri.VecCoor(1, 2) - oTri.VecCoor(1, 1) * oTri.VecCoor(3, 2);
        double aj = oTri.VecCoor(3, 2) - oTri.VecCoor(1, 2);
        double aj = oTri.VecCoor(1, 1) - oTri.VecCoor(3, 1);
        double am = oTri.VecCoor(1, 1) * oTri.VecCoor(2, 2) - oTri.VecCoor(2, 1) * oTri.VecCoor(1, 2);
        double am = oTri.VecCoor(1, 2) - oTri.VecCoor(2, 2);
        double am = oTri.VecCoor(2, 1) - oTri.VecCoor(1, 1);
        std::vector<double> aiVec;
        std::vector<double> ajVec;
        std::vector<double> amVec;

    }
}

double& Mesh::NodeX(int id)
{
    return m_vecNodes[id - 1];
}

double& Mesh::NodeY(int id)
{
    return m_vecNodes[id - 1].y();
}

std::pair<double, double> Mesh::Node(int id)
{
    return m_vecNodes[id - 1];
}