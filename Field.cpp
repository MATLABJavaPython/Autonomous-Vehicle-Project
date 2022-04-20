#include "Field.h"

//Field constructor, initializes the size and start and target locations
Field::Field() {
    max = 319;
    min = 0;
    from = pair<int, int>(300, 30);
    to = pair<int, int>(30, 256);
    get<3>(V[from.first][from.second]) = pair<int, int>(301, 30);
}

//Clears the field and paths
void Field::Clear() {
    obstacles.clear();
    dijkPath.clear();
    breadthPath.clear();
    depthPathMaybeLaterlol.clear();
    for (int i = 0; i < 320; i++){
        for (int j = 0; j < 320; j++){
            get<0>(V[i][j]) = false;
        }
    }
}

//Loads in a blank field
void Field::LoadBlankField() {
    Clear();
    from = pair<int, int>(300, 30);
    to = pair<int, int>(30, 256);
    get<3>(V[from.first][from.second]) = pair<int, int>(301, 30);
}

//Loads in predefined field number 3
void Field::LoadPDF1() {
    Clear();
    AddObst(159, 159, 200, 200);
    from = pair<int, int>(300, 30);
    to = pair<int, int>(30, 256);
    get<3>(V[from.first][from.second]) = pair<int, int>(301, 30);
}

//Loads in predefined field number 2
void Field::LoadPDF2() {
    Clear();
    for (int i = 10; i <= 310; i += 50){
        for (int j = 10; j <= 310; j += 50){
            AddObst(i, j, 15, 15);
        }
    }
    from = pair<int, int>(300, 30);
    to = pair<int, int>(30, 256);
    get<3>(V[from.first][from.second]) = pair<int, int>(301, 30);
}

//Loads in predefined field number 3
void Field::LoadPDF3() {
    Clear();
    vector<pair<int, int>> obst;
    int x = 134;
    int y = 134;
    int radius = 50;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 184;
    y = 184;
    radius = 50;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    AddObst(134, 84, 25, 120);
    AddObst(184, 234, 25, 120);

    AddObst(74, 50, 25, 100);
    AddObst(194, 50, 25, 100);
    AddObst(124, 270, 25, 100);
    AddObst(244, 270, 25, 100);

    x = 134;
    y = 24;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 184;
    y = 294;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 74;
    y = 100;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 194;
    y = 100;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 124;
    y = 220;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
    x = 244;
    y = 220;
    radius = 12;
    for (int i = x-radius; i < x+radius; i++){
        for (int j = y-radius; j < y+radius; j++){
            if ((i-x)*(i-x)+(j-y)*(j-y) <= radius*radius){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);

    from = pair<int, int>(300, 30);
    to = pair<int, int>(30, 256);
    get<3>(V[from.first][from.second]) = pair<int, int>(301, 30);
}

//Adds a rectangular obstacle to the field
void Field::AddObst(int x, int y, int xSize, int ySize) {
    vector<pair<int, int>> obst;
    for (int i = x-xSize/2; i < x+xSize/2; i++){
        for (int j = y-ySize/2; j < y+ySize/2; j++){
            if (CheckValid(i,j)){
                obst.emplace_back(pair<int, int>(i,j));
                get<0>(V[i][j]) = true;
            }
        }
    }
    obstacles.push_back(obst);
}

//Calculates all paths, and times how long each takes to be calculated
void Field::FindPaths() {
    auto start = high_resolution_clock::now();
    FindDijk();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    dijkTime = duration.count();
    cout << "Time taken by Dijkstra: " << dijkTime << " microseconds" << endl;
    cout << "Dijkstra distance: ";
    if (get<2>(V[to.first][to.second]) != 100000000){
        dijkLength = get<2>(V[to.first][to.second]);
        cout << dijkLength << endl;
    }
    else
        cout << "Invalid. Target unreachable" << endl;

    start = high_resolution_clock::now();
    FindBreadth();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    breadthTime = duration.count();
    cout << "Time taken by Breadth: " << breadthTime << " microseconds" << endl;
    cout << "Breadth distance: ";
    if (get<2>(V[to.first][to.second]) != 100000000){
        breadthLength = get<2>(V[to.first][to.second]);
        cout << breadthLength << endl;
    }
    else
        cout << "Invalid. Target unreachable" << endl;

    start = high_resolution_clock::now();
    FindDepth();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    depthTime = duration.count();
    cout << "Time taken by Depth: " << depthTime << " microseconds" << endl;
    cout << "Depth distance: ";
    if (get<2>(V[to.first][to.second]) != 100000000){
        depthLength = get<2>(V[to.first][to.second]);
        cout << depthLength << endl;
    }
    else
        cout << "Invalid. Target unreachable" << endl;
}

//Finds the shortest path using Dijkstra's algorithm
void Field::FindDijk() {
#define visited 1
#define distance 2
#define parent 3
#define node pair<int, int>
#define x first
#define y second

    priority_queue<pair<int, node>> PQ;
    for (int i = 0; i < 320; i++){
        for (int j = 0; j < 320; j++){
            if (pair<int, int>(i,j) != from){
                get<visited>(V[i][j]) = false;
                get<distance>(V[i][j]) = 100000000;
                get<parent>(V[i][j]) = from;
            }
        }
    }
    PQ.push(pair<int, node>(0, from));
    node vert = PQ.top().second;
    get<distance>(V[vert.x][vert.y]) = 0;

    while(!PQ.empty()){
        vert = PQ.top().second;
        if (vert == to)
            break;
        PQ.pop();
        get<visited>(V[vert.x][vert.y]) = true;
        vector<node> adj = GetAdj(vert);
        for (int i = 0; i < adj.size(); i++){
            int weight = GetWeight(vert, adj[i]);
            if (get<distance>(V[vert.x][vert.y]) + weight < get<distance>(V[adj[i].x][adj[i].y])){
                get<distance>(V[adj[i].x][adj[i].y]) = weight + get<distance>(V[vert.x][vert.y]);
                get<parent>(V[adj[i].x][adj[i].y]) = vert;
            }
            PQ.push(pair<int, node>(-get<distance>(V[adj[i].first][adj[i].second]), adj[i]));
        }
        while(!PQ.empty() && get<visited>(V[PQ.top().second.x][PQ.top().second.y]) == true){
            PQ.pop();
        }
    }

    vert = get<parent>(V[to.x][to.y]);
    dijkPath.clear();
    while(vert != from){
        dijkPath.push_back(vert);
        vert = get<parent>(V[vert.x][vert.y]);
    }

#undef visited
#undef distance
#undef parent
#undef node
#undef x
#undef y
}

//Finds a path using breadth first search
void Field::FindBreadth() {
#define visited 1
#define distance 2
#define parent 3
#define node pair<int, int>
#define x first
#define y second

    for (int i = 0; i < 320; i++){
        for (int j = 0; j < 320; j++){
            if (pair<int, int>(i,j) != from){
                get<visited>(V[i][j]) = false;
                get<distance>(V[i][j]) = 100000000;
                get<parent>(V[i][j]) = from;
            }
        }
    }
    queue<node> vertices;
    get<visited>(V[from.x][from.y]) = true;
    vertices.push(from);
    node vert;
    while(!vertices.empty()){
        vert = vertices.front();
        if (vert == to)
            break;
        vertices.pop();
        vector<node> adj = GetAdj(vert);

        for (int i = 0; i < adj.size(); i++){
            if (get<visited>(V[adj[i].x][adj[i].y]) == false){
                get<visited>(V[adj[i].x][adj[i].y]) = true;
                get<parent>(V[adj[i].x][adj[i].y]) = vert;
                get<distance>(V[adj[i].x][adj[i].y]) = GetWeight(vert, adj[i]) + get<distance>(V[vert.x][vert.y]);
                vertices.push(adj[i]);
            }
        }
    }

    vert = get<parent>(V[to.x][to.y]);
    breadthPath.clear();
    while(vert != from){
        breadthPath.push_back(vert);
        vert = get<parent>(V[vert.x][vert.y]);
    }
#undef visited
#undef distance
#undef parent
#undef node
#undef x
#undef y
}

//Finds a (very inefficient) path using depth first search
void Field::FindDepth() {
#define visited 1
#define distance 2
#define parent 3
#define node pair<int, int>
#define x first
#define y second

    for (int i = 0; i < 320; i++){
        for (int j = 0; j < 320; j++){
            if (pair<int, int>(i,j) != from){
                get<visited>(V[i][j]) = false;
                get<distance>(V[i][j]) = 100000000;
                get<parent>(V[i][j]) = from;
            }
        }
    }
    stack<node> vertices;
    get<visited>(V[from.x][from.y]) = true;
    vertices.push(from);
    node vert;
    while(!vertices.empty()){
        vert = vertices.top();
        if (vert == to)
            break;
        vertices.pop();
        vector<node> adj = GetAdj(vert);

        for (int i = 0; i < adj.size(); i++){
            if (get<visited>(V[adj[i].x][adj[i].y]) == false){
                get<visited>(V[adj[i].x][adj[i].y]) = true;
                get<parent>(V[adj[i].x][adj[i].y]) = vert;
                get<distance>(V[adj[i].x][adj[i].y]) = GetWeight(vert, adj[i]) + get<distance>(V[vert.x][vert.y]);
                vertices.push(adj[i]);
            }
        }
    }

    vert = get<parent>(V[to.x][to.y]);
    depthPathMaybeLaterlol.clear();
    while(vert != from){
        depthPathMaybeLaterlol.push_back(vert);
        vert = get<parent>(V[vert.x][vert.y]);
    }
#undef visited
#undef distance
#undef parent
#undef node
#undef x
#undef y
}

//Returns the shuffled valid adjacent nodes
vector<pair<int, int>> Field::GetAdj(pair<int, int> node) {
    int i = node.first;
    int j = node.second;
    vector<pair<int, int>> adjacent;
    if (CheckValid(i-1,j) && !get<0>(V[i-1][j]))
        adjacent.emplace_back(i-1,j);
    if (CheckValid(i+1,j) && !get<0>(V[i+1][j]))
        adjacent.emplace_back(i+1,j);
    if (CheckValid(i,j-1) && !get<0>(V[i][j-1]))
        adjacent.emplace_back(i,j-1);
    if (CheckValid(i,j+1) && !get<0>(V[i][j+1]))
        adjacent.emplace_back(i,j+1);
    shuffle(adjacent.begin(), adjacent.end(), std::mt19937(std::random_device()()));
    return adjacent;
}

//Checks whether or not a node is accessible (valid)
bool Field::CheckValid(int i, int j) const{
    if (!(i < min || i > max || j < min || j > max))
        if (!get<0>(V[i][j])){
            return true;
        }
    return false;
}

//Determines the weight of an edge based on how much of a turn would be needed to reach it
int Field::GetWeight(pair<int, int> start, pair<int, int> end) {
    int cdx = start.first - get<3>(V[start.first][start.second]).first;
    int cdy = start.second - get<3>(V[start.first][start.second]).second;
    int ndx = end.first - start.first;
    int ndy = end.second - start.second;
    if (ndx == cdx && ndy == cdy)
        return 1;
    else if (ndx == -1*cdx || ndy == -1*cdy)
        return 3;
    else
        return 2;
}