//
// Created by Katie Murphy on 4/12/22.
//
#ifndef NODE_H
#define NODE_H
class Node{

public:
    bool open = true;
    bool dij = false;
    bool bfs = false;
    bool dfs = false;
    bool obst = false;
    Node();
    Node(bool op, bool d, bool b, bool o, bool ds);


};

#endif