#pragma once
#include "Euler.hpp"
#include "TaskGenerator.hpp"
class SecondVersion : public Euler
{
private:
    std::vector<int> ind;
    void dfs(int v) override;
    void resizeArraysAndVectors(TaskGenerator *);
public:
    SecondVersion(TaskGenerator *);
    ~SecondVersion() = default;

    std::vector<int> solve() override;
};
