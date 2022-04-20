//
// Created by Katie Murphy on 4/12/22.
//
//#pragma once
#include "Node.h"

Node::Node(){
}

Node::Node(bool op, bool d, bool b, bool o, bool ds){
    open = op;
    dij = d;
    bfs = b;
    obst = o;
    dfs = ds;
}