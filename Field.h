#include<string>
#include<vector>
#include<stdexcept>
#include<iostream>
//#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#include<queue>
#include<stack>
#include<chrono>
#include<random>
#include<algorithm>
#pragma once
using namespace std;
using namespace std::chrono;

class Field
{
private:
    int max;
    int min;
    tuple<bool, bool, int, pair<int, int>> V[320][320];
    void FindDijk();
    void FindBreadth();
    void FindDepth();
    vector<pair<int, int>> GetAdj(pair<int, int> node);
    bool CheckValid(int i, int j) const;
    int GetWeight(pair<int, int> start, pair<int, int> end);
public:
    vector<vector<pair<int, int>>> obstacles;
    vector<pair<int, int>> dijkPath;
    vector<pair<int, int>> breadthPath;
    vector<pair<int, int>> depthPathMaybeLaterlol;
    pair<int, int> from;
    pair<int, int> to;
    int dijkLength;
    int breadthLength;
    int depthLength;
    int dijkTime;
    int breadthTime;
    int depthTime;

    Field();
    void Clear();
    void LoadBlankField();
    void LoadPDF1();
    void LoadPDF2();
    void LoadPDF3();
    void AddObst(int x, int y, int xSize, int ySize);
    void FindPaths();
};