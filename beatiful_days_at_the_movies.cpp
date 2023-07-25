// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?h_r=next-challenge&h_v=zen
#include <iostream>
#include <string>

int calculateBeautifulDays(int i, int j, int k)
{
  int beautifulDays = 0;

  for (int index = i; index <= j; index++)
  {
    std::string strNumber = std::to_string(index);
    std::reverse(strNumber.begin(), strNumber.end());
    const int reversed = std::stoi(strNumber);
    if ((index - reversed) % k == 0)
    {
      beautifulDays++;
    }
  }

  return beautifulDays;
}

int main(int argc, char const *argv[])
{
  int initialDay = 20;
  int finalDay = 23;
  int k = 6;

  int beautifulDays = calculateBeautifulDays(initialDay, finalDay, k);
  std::cout << "Beautiful days: " << beautifulDays << "\n";
}
