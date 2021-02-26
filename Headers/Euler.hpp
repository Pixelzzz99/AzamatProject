#pragma once
#include <vector>
#include "Edge.hpp"

class Euler
{
protected:
    int count_vertex;
    int count_edges;
    int* deg;
    std::vector<std::vector<Edge>> edges;
    int* used;
    std::vector<int> euler;
    void get_new_edges();
    virtual void dfs(int v) = 0;
    void setGraph(int n, int m, std::vector<std::pair<int, int>> matrix);
public:
    ~Euler() = default;

    virtual std::vector<int> solve() = 0;
};
