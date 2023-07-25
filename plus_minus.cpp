#include <stdio.h>
#include <vector>

void plusMinus(std::vector<int> arr)
{
    float negatives = 0;
    float positives = 0;
    float zeros = 0;
    float arrLength = arr.size();

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
        {
            negatives++;
        }
        else if (arr[i] > 0)
        {
            positives++;
        }
        else
        {
            zeros++;
        }
    }
    printf("%6f\n", positives / arrLength);
    printf("%6f\n", negatives / arrLength);
    printf("%6f\n", zeros / arrLength);
}

int main(int argc, char const *argv[])
{
    std::vector<int> input{-4, 3, -9, 0, 4, 1};

    plusMinus(input);
}
