// https : // www.hackerrank.com/challenges/one-week-preparation-kit-zig-zag-sequence/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-three
#include <iostream>
#include <vector>
#include <algorithm>

void findZigZagSequence(std::vector<int> a, int n)
{
    std::sort(a.begin(), a.end());
    // int mid = (n + 1) / 2;
    int mid = ((n + 1) / 2) - 1;;
    std::swap(a[mid], a[n-1]);

    int st = mid + 1;
    // int ed = n - 1;
    int ed = n - 2;
    while (st <= ed)
    {
        std::swap(a[st], a[ed]);
        st = st + 1;
        // ed = ed + 1;
        ed = ed - 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << a[i];
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> input1 = {1, 2, 3, 4, 5, 6, 7};
    int n = input1.size();

    findZigZagSequence(input1, n);

    return 0;
}
