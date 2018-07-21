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

typedef struct Hotel_
{
    int startDay;
    int endDay;
    int price;
}Hotel;

bool compare(Hotel &hotel1, Hotel &hotel2);

int main()
{
    FILE *in = fopen("input.txt","r");

    int startDay, endDay, price;

    deque<Hotel> result;
    vector<Hotel> input;

    while(fscanf(in, "%d %d %d", &startDay, &endDay, &price) == 3)
    {
        Hotel hotel = {startDay, endDay, price};
        input.push_back(hotel);
    }

    sort(input.begin(), input.end(), compare);

    while(!input.empty())
    {
        Hotel hotel = input.back();
        input.pop_back();
        if(result.empty())
        {
            result.push_back(hotel);
        }else if(result.back().price == hotel.price)
        {
            result.back().endDay = hotel.endDay;
        }else if(result.back().endDay < hotel.startDay)
        {
            result.push_back(hotel);
        }else
        {
            result.back().endDay = hotel.startDay - 1;
            result.push_back(hotel);
        }
    }

    for(unsigned int i = 0; i < result.size(); i++)
    {
        if(i == 0)
        {
            printf("[%d, %d, %d]", result[i].startDay, result[i].endDay, result[i].price);
        }else
        {
            printf(",[%d, %d, %d]", result[i].startDay, result[i].endDay, result[i].price);
        }
    }

    return 0;
}

bool compare(Hotel &hotel1, Hotel &hotel2)
{
    return hotel1.startDay > hotel2.startDay;

}
