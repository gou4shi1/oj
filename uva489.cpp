/************************************************************************
    > File Name:    UVa489.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月16日 星期三 23时04分44秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;

char puzzle[MAXN],guesses[MAXN];
bool win,lose;
int myleft,chance;

void guess(char ch)
{
    bool bad = true;
    for (int i = 0; i != strlen(puzzle); ++i)
        if (puzzle[i] == ch)
        {
            --myleft;
            puzzle[i] = ' ';
            bad = false;
        }
    if (bad)
        --chance;
    if (!chance)
        lose = true;
    if (!myleft)
        win = true;
}

int main()
{
    int rnd;
    while (scanf("%d%s%s",&rnd,puzzle,guesses) == 3 && rnd != -1)
    {
        win = lose = false;
        myleft = strlen(puzzle);
        chance = 7;
        printf("Round %d\n",rnd);
        for (int i = 0; i != strlen(guesses); ++i)
        {
            guess(guesses[i]);
            if (win || lose)
                break;
        }
        if (win)
            puts("You win.");
        else if (lose)
            puts("You lose.");
        else 
            puts("You chickened out.");
    }
    return 0;
}
