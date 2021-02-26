#pragma once 
#include "Euler.hpp"
#include "TaskGenerator.hpp"

class FirstVersion : public Euler 
{
private:
    void dfs(int v) override;
    void resizeArraysAndVectors(TaskGenerator *);
public:
    FirstVersion(TaskGenerator *);
    
    ~FirstVersion() = default;

    std::vector<int> solve() override;
};
