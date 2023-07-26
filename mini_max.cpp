#include <stdio.h>
#include <vector>
#include <algorithm>

int print_uint128(__int128_t max)
{
    if (max == 0)
        return printf("0\n");

    char str[40] = {0};              // log10(1 << 128) + '\0'
    char *s = str + sizeof(str) - 1; // start at the end
    while (max != 0)
    {
        if (s == str)
            return -1; // never happens

        *--s = "0123456789"[max % 10]; // save last digit
        max /= 10;                     // drop it
    }
    return printf("%s", s);
}

int main(int argc, char const *argv[])
{
    // std::vector<long long int> v{396285104, 573261094, 759641832, 819230764, 364801279};
    std::vector<long long int> v{793810624, 895642170, 685903712, 623789054, 468592370};
    std::sort(v.begin(), v.end());
    __int128_t min = 0;
    __int128_t max = 0;
    int arr_size = v.size();
    long long int partialSum = 0;

    for (int i = 1; i < arr_size - 1; i++)
    {
        partialSum += v[i];
    }
    min = v[0] + partialSum;
    max = v[arr_size - 1] + partialSum;

    print_uint128(min);
    printf(" ");
    print_uint128(max);
}
