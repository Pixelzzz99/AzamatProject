#include <iostream>
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include "TaskGenerator.hpp"
#include <ctime>
#include <fstream>

TaskGenerator *task = new TaskGenerator(1000);
void FirstTest()
{
    std::cout << task->get_count_vertex() << std::endl;
    FirstVersion *first = new FirstVersion(task);
    unsigned int time_start = clock();
    std::vector<int> result = first->solve();
    double time = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    for (auto element : result)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Time: " << time << std::endl;
    delete first;
}

void SecondTest()
{
    std::cout << task->get_count_vertex() << std::endl;
    SecondVersion *second = new SecondVersion(task);
    unsigned int time_start = clock();
    std::vector<int> result = second->solve();
    double time = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    for (auto element : result)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Time: " << time << std::endl;
    delete second;
}

void ExcelTable()
{
    std::ofstream myTable;
    myTable.open("D:\\Projects\\AzamatProject\\Table\\MyTable.csv");
    if (myTable.is_open())
    {
        myTable << "N ; "
                << "Result FIrst ;"
                << "Result Second ;"
                << "Time First ;"
                << "Time Second ;" << std::endl;
        int step = 500;
        for (int i = 1000; i < 500000; i += step)
        {
            TaskGenerator *task2 = new TaskGenerator(i);
            std::vector<int> result2;
            double timeSecond;
            if (i < 5000)
            {
                SecondVersion *second = new SecondVersion(task2);
                unsigned int time_start = clock();
                result2 = second->solve();
                timeSecond = (double)(clock() - time_start) / CLOCKS_PER_SEC;
            }
            else
            {
                step = 10000;
            }

            std::cout << task2->get_count_vertex() << std::endl;
            FirstVersion *first = new FirstVersion(task2);
            unsigned int time_start = clock();
            std::vector<int> result1 = first->solve();
            double timeFirst = (double)(clock() - time_start) / CLOCKS_PER_SEC;
            myTable << i << ";" << result2.size() << ";" << result1.size() << ";" << timeSecond << ";" << timeFirst << std::endl;
        }
    }
}

int main()
{
    //FirstTest();
    //SecondTest();
    //delete task;
    ExcelTable();
    system("pause>nul");
    return 0;
}