#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<string>
#include<fstream>
#include<tuple>

#define DELIM ' '

int part_1(std::vector<int> l1, std::vector<int> l2)
{
    std::sort(std::begin(l1), std::end(l1));
    std::sort(std::begin(l2), std::end(l2));
    unsigned int sum = 0;

    for(int i = 0; i < l1.size(); ++i)
    {
        // std::cout << l1[i] << "-" << l2[i] << " ";
        sum += std::abs(l1[i] - l2[i]);
    }

    return sum;
}

int part_2(std::vector<int> l1, std::vector<int> l2)
{
    unsigned int sum = 0;
    for(int i = 0; i < l1.size(); ++i)
    {
        int occurances = 0;
        for(int j = 0; j < l2.size(); ++j)
        {
            if(l2[j] == l1[i]) {
                ++occurances;
            }
        }

        sum += l1[i] * occurances;
    }

    return sum;
}

std::tuple<std::vector<int>, std::vector<int>> readInput()
{
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> l1, l2;

    while(std::getline(file, line))
    {
        int pos = line.find(DELIM);
        l1.push_back(std::stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
        l2.push_back(std::stoi(line));
    }

    return {l1, l2};
}

int main()
{

    auto [l1, l2] = readInput();
    std::cout << "Part 1: " << part_1(l1, l2) << std::endl;
    std::cout << "Part 2: " << part_2(l1, l2) << std::endl;
}