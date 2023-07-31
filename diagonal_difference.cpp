// https://www.hackerrank.com/challenges/one-week-preparation-kit-diagonal-difference/problem?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D%5B%5D=preparation-kits&playlist_slugs%5B%5D%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D%5B%5D=one-week-day-two
#include <stdio.h>
#include <vector>
#include <math.h>

int diagonalDifference(std::vector<std::vector<int>> arr)
{
    int main_diagonal = 0;
    int reverse_diagonal = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        main_diagonal += arr[i][i];
        reverse_diagonal += arr[i][arr.size() - i - 1];
    }
    return abs(main_diagonal - reverse_diagonal);
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> arr = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};

    printf("%d", diagonalDifference(arr));
}
