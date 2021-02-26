#include "SecondVersion.hpp"

SecondVersion::SecondVersion(TaskGenerator *newTask)
{
    setGraph(newTask->get_count_vertex(), newTask->get_count_edges(), newTask->getGraph());
}

std::vector<int> SecondVersion::solve()
{
    get_new_edges();
    dfs(1);
    return euler;
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