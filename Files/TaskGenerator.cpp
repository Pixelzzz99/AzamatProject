#include "TaskGenerator.hpp"

TaskGenerator::TaskGenerator(int n)
{
    n_count_vertex = n;
    graph = generateGraph(n_count_vertex);
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