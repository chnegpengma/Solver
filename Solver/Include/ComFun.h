#pragma once
#include "solver_global.h"

class Node;

namespace Algorithm
{
    class SOLVER_EXPORT ComFun
    {
    public:
        ComFun() {}
        ~ComFun() {}

        static void SwapNode(Node& node1, Node& Node2);


    };
}
