#include "SecondVersion.hpp"

SecondVersion::SecondVersion(TaskGenerator *newTask)
{
    resizeArraysAndVectors(newTask);
    setGraph(newTask->get_count_vertex(), newTask->get_count_edges(), newTask->getGraph());
}

std::vector<int> SecondVersion::solve()
{
    get_new_edges();
    dfs(1);
    return euler;
}

void SecondVersion::resizeArraysAndVectors(TaskGenerator *task)
{
    const int MAX_COUNT_VERTEX = 5e5+10;
    count_vertex = task->get_count_vertex();
    count_edges = task->get_count_edges();
    ind.resize(MAX_COUNT_VERTEX);
    deg.resize(MAX_COUNT_VERTEX);
    edges.resize(MAX_COUNT_VERTEX);
    used.resize(MAX_COUNT_VERTEX);
}

void SecondVersion::dfs(int v)
{
   for(;ind[v] < edges[v].size(); ind[v]++)
   {
       Edge e = edges[v][ind[v]];
       if(!used[e.index])
       {
           used[e.index] = 1;
           dfs(e.u);
       }
   }
   euler.push_back(v);
}