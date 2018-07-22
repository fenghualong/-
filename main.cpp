#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    FILE *in = stdin;//fopen("input.txt","r");

    int startDay, endDay, price;

    int *priceTable = new int[50000];

    while(fscanf(in, "%d %d %d", &startDay, &endDay, &price) == 3)
    {
        for(int i = startDay; i <= endDay && i < 50000; i++)
            priceTable[i] = price;
    }

    int index = 0;
    bool isFirst = true;
    while(index < 50000)
    {
        price = 0;
        while(index < 50000 && priceTable[index] == 0)
            index++;

        startDay = index;
        price = priceTable[index];

        while(index < 50000 && priceTable[index] == price)
            index++;

        endDay = index-1;

        if(isFirst)
        {
            printf("[%d, %d, %d]", startDay, endDay, price);
            isFirst = false;
        }else if(price != 0)
        {
            printf(",[%d, %d, %d]", startDay, endDay, price);
        }
    }

    delete[] priceTable;
    return 0;
}
