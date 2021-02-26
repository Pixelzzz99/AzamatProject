#include "FirstVersion.hpp"

FirstVersion::FirstVersion(TaskGenerator *newTask)
{
    /*
    const int MAX_COUNT_VERTEX = 1e5 + 10;
    int count_vertex, count_edges;
    int deg[MAX_COUNT_VERTEX];
    vector <edge> edges[MAX_COUNT_VERTEX];
    int ind[MAX_COUNT_VERTEX], used[MAX_COUNT_VERTEX];
    vector <int> euler;
    */
    setGraph(newTask->get_count_vertex(), newTask->get_count_edges(), newTask->getGraph());
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