#include "FirstVersion.hpp"

FirstVersion::FirstVersion(TaskGenerator *newTask)
{
    resizeArraysAndVectors(newTask);
    setGraph(newTask->get_count_vertex(), newTask->get_count_edges(), newTask->getGraph());
}

void FirstVersion::resizeArraysAndVectors(TaskGenerator *task)
{
    const int MAX_COUNT_VERTEX = 5e5+10;
    count_vertex = task->get_count_vertex();
    count_edges = task->get_count_edges();
    deg.resize(MAX_COUNT_VERTEX);
    edges.resize(MAX_COUNT_VERTEX);
    used.resize(MAX_COUNT_VERTEX);
}

std::vector<int> FirstVersion::solve()
{
    get_new_edges();
    dfs(1);
    return euler;
}

void FirstVersion::dfs(int v)
{
    for (int i = 0; i < edges[v].size(); i++)
    {
        Edge e = edges[v][i];
        if (!used[e.index])
        {
            used[e.index] = 1;
            dfs(e.u);
        }
    }
    euler.push_back(v);
}