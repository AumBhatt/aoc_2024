#include<iostream>
#include<cstdlib>

int solution(int reports[6][5])
{
    int safe_reports = 0;

    int reports_len = sizeof(reports)/sizeof(int);

    for(int i = 0; i < reports_len; ++i)
    {
        
        int *levels = reports[i];
        int levels_len = sizeof(levels)/sizeof(int);

        int dir = 0;

        for(int j = 0; j < levels_len; ++j)
        {

            if(j + 1 >= levels_len)
            {
                break;
            }

            int cur = levels[j], next = levels[j + 1];
            int diff = cur - next;

            if(j == 0)
            {
                dir = int(diff / std::abs(diff));
            }

            if(std::abs(diff) >= 1 && std::abs(diff) <= 3 && dir == int(diff/std::abs(diff)))
            {
                ++safe_reports;
            }

        }

    }

    return safe_reports;
}

int main()
{
    int i[6][5] = {{7, 6, 4, 2, 1},{1, 2, 7, 8, 9},{9, 7, 6, 2, 1},{1, 3, 2, 4, 5},{8, 6, 4, 4, 1},{1, 3, 6, 7, 9}};


    std::cout << solution(i) << std::endl;
    return 0;
}