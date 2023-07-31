// https://www.hackerrank.com/challenges/one-week-preparation-kit-lonely-integer/problem?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D%5B%5D=preparation-kits&playlist_slugs%5B%5D%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D%5B%5D=one-week-day-two

#include <unordered_map>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <algorithm>

bool isValueOne(const std::pair<int, int> &pair)
{
    return pair.second == 1;
}

int lonelyinteger(std::vector<int> a)
{
    std::unordered_map<int, int> map;
    for (int value : a)
    {
        map[value]++;
    }
    std::unordered_map<int, int>::iterator it = std::find_if(map.begin(), map.end(), isValueOne);

    return it->first;
}

int main(int argc, char const *argv[])
{
    std::vector<int> a = {1, 2, 3, 4, 3, 2, 1};
    int retult = lonelyinteger(a);

    assert(retult == 4);
}
