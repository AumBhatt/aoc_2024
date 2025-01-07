#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<string>

int solution(std::vector<std::vector<int>> reports)
{
    int unsafe_reports = 0;

    for(int i = 0; i < reports.size(); ++i)
    {
        
        std::vector<int> levels = reports[i];

        int dir = 0;

        for(int j = 0; j < levels.size(); ++j)
        {

            if(j + 1 >= levels.size())
            {
                break;
            }

            int cur = levels[j], next = levels[j + 1];
            int diff = cur - next;

            if(diff == 0)
            {
                ++unsafe_reports;
                break;
            }

            if(j == 0)
            {
                dir = int(diff / std::abs(diff));
            }

            if(std::abs(diff) < 1 || std::abs(diff) > 3 || dir != int(diff/std::abs(diff)))
            {
                ++unsafe_reports;
                break;
            }
            

        }


    }

    return reports.size() - unsafe_reports;
}

std::vector<std::vector<int>> readInput()
{
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::vector<int>> reports;

    while(std::getline(file, line))
    {
        std::vector<int> levels;

        while(int space = line.find(" ") != std::string::npos)
        {
            unsigned int data_point = std::stroi(
                line.substr(0, space)
            );
            line.erase(0, space + 1);
            levels.push_back(data_point);

        }
            std::cout << line << "\n";

        levels.push_back(std::stroi(line.substr(0, line.find("\n"))));

        reports.push_back(levels);
        
    }

    return reports;
}

int main()
{
    // std::vector<std::vector<int>> i = {{7, 6, 4, 2, 1},{1, 2, 7, 8, 9},{9, 7, 6, 2, 1},{1, 3, 2, 4, 5},{8, 6, 4, 4, 1},{1, 3, 6, 7, 9}};


    std::vector<std::vector<int>> input = readInput();
    // std::cout << solution(input) << std::endl;


    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = 0; j < input[i].size(); ++j)
        {
            std::cout << " " << input[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}