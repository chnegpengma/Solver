#include "ComFun.h"
#include "Node.h"

namespace Algorithm
{
    void ComFun::SwapNode(Node& node1, Node& node2)
    {
        if (node1.y() > node2.y())
        {
            Node tmpNode = node2;
            node2 = node1;
            node1 = tmpNode;
        }
        else
        {
            if (node1.x() > node2.x())
            {
                Node tmpNode = node2;
                node2 = node1;
                node1 = tmpNode;
            }
        }
    }
}