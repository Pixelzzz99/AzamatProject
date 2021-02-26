#pragma once
#include "Euler.hpp"
#include "TaskGenerator.hpp"
class SecondVersion : public Euler
{
private:
    int *ind;
    void dfs(int v) override;

public:
    SecondVersion(TaskGenerator *);
    ~SecondVersion() = default;

    std::vector<int> solve() override;
};
