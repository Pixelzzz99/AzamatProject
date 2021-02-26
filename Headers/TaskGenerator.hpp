#pragma once
#include <vector>
#include <utility>
#include <map>
class TaskGenerator
{
private:
    int n_count_vertex;
    int m_count_edges;
    std::vector<std::pair<int, int>> graph;
    std::map<std::pair<int,int>, bool> mp;

    void generateGraph();
    int Randomize(int min, int max);
public:
    int get_count_vertex();
    int get_count_edges();
    std::vector<std::pair<int, int>> getGraph();
    TaskGenerator(int n);
    ~TaskGenerator() = default;
};
