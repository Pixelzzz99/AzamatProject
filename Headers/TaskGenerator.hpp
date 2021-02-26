#pragma once
#include <vector>
#include <utility>

class TaskGenerator
{
private:
    int n_count_vertex;
    int m_count_edges;
    std::vector<std::pair<int, int>> graph;

    std::vector<std::pair<int, int>> generateGraph(int n);
    int Randomize(int min, int max);
public:
    int get_count_vertex();
    int get_count_edges();
    std::vector<std::pair<int, int>> getGraph();
    TaskGenerator(int n);
    ~TaskGenerator() = default;
};
