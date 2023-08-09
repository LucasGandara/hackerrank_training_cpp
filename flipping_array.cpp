// https://medium.com/@mlgerardvla/hackerrank-flipping-the-matrix-javascript-7f945220ca1b
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
int flippingMatrix(std::vector<std::vector<int>> matrix, int input_n)
{
    int n = matrix.size() / 2;
    int total = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int max = 0;
            max = std::max(matrix[row][col], max);
            max = std::max(matrix[row][2 * n - col - 1], max);
            max = std::max(matrix[2 * n - row - 1][col], max);
            max = std::max(matrix[2 * n - row - 1][2 * n - col - 1], max);
            total += max;
        }
    }

    printf("Total %d: %d\n", input_n, total);
    return total;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> input2 = {
        {112, 42, 83, 119},
        {56, 125, 56, 49},
        {15, 78, 101, 43},
        {62, 98, 114, 108}};

    int expected1 = flippingMatrix(input1, 1);
    int expected2 = flippingMatrix(input2, 2);
    assert(expected1 == 4);
    assert(expected2 == 414);
}
