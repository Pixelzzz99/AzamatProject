#include "TaskGenerator.hpp"

TaskGenerator::TaskGenerator(int n)
{
    n_count_vertex = n;
    generateGraph();
}

int TaskGenerator::get_count_vertex()
{
    return n_count_vertex;
}

int TaskGenerator::get_count_edges()
{
    return m_count_edges;
}

std::vector<std::pair<int, int>> TaskGenerator::getGraph()
{
    return graph;
}

int TaskGenerator::Randomize(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void TaskGenerator::generateGraph()
{
    std::vector<int> v = {1};
    int id_v = 2;
    int count_d = n_count_vertex - 1;
    while (count_d > 0)
    {
        int position = Randomize(0, v.size() - 1);
        int now_v = v[position];
        v.push_back(id_v);
        graph.push_back({now_v, id_v});
        mp[{now_v, id_v}] = mp[{id_v, now_v}] = 1;
        id_v++;
        count_d--;
    }

    m_count_edges = n_count_vertex - 1;
    int it = Randomize(0, 5 * n_count_vertex);
    while (it--)
    {
        int pos1 = Randomize(0, v.size() - 1);
        int pos2 = Randomize(0, v.size() - 1);
        if (pos1 == pos2)
            continue;
        int v1 = v[pos1], v2 = v[pos2];
        if (mp.count({v1, v2}))
            continue;
        mp[{v1, v2}] = mp[{v2, v1}] = 1;
        graph.push_back({v1, v2});
        m_count_edges++;
    }
}