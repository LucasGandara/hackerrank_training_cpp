// https://www.hackerrank.com/challenges/strange-advertising/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <iostream>

int viralAdvertising(int n)
{
  int likes = 0;
  int recipients = 5;

  for (int i = 1; i < n + 1; i++)
  {
    likes = likes + recipients / 2;
    recipients = recipients / 2 * 3;
  }

  return likes;
}

int main(int argc, char const *argv[])
{
  const int n = 5;
  int result = viralAdvertising(n);

  std::cout << result << std::endl;
}
