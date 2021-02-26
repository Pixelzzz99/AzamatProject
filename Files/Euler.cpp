#include "Euler.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdlib>

void Euler::get_new_edges()
{
    std::vector<int> vertex;
    for (int i = 1; i <= count_vertex; i++)
        if (deg[i] % 2)
            vertex.push_back(i);

    for (int i = 0; i < vertex.size(); i += 2)
    {
        int u = vertex[i];
        int v = vertex[i + 1];
        count_edges++;
        edges[u].push_back({v, count_edges});
        edges[v].push_back({u, count_edges});
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= count_vertex; i++)
    {
        if (deg[i] % 2)
        {
            std::cout << "Error : you have vertex with odd deg" << std::endl;
            assert(true);
            return;
        }
    }
}

void Euler::setGraph(int n, int m, std::vector<std::pair<int, int>> matrix)
{
    count_vertex = n;
    count_edges = m;
    for (int i = 1; i <= count_edges; i++)
    {
        int u = matrix[i].first;
        int v = matrix[i].second;
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
        deg[v]++;
        deg[u]++;
    }
}
