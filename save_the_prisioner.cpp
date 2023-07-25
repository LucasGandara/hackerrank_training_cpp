// https://www.hackerrank.com/challenges/save-the-prisoner/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

int saveThePrisoner(int numberOfChairs, int numberOfCandys, int offset)
{
  int index = offset - 1;
  for (int i = 0; i < numberOfCandys; i++)
  {
    index++;
    if (index > numberOfChairs)
    {
      index = index - numberOfChairs;
    }
  }
  return index;
}

int saveThePrisoner2(int numberOfChairs, int numberOfCandys, int offset)
{
  if (numberOfCandys < numberOfChairs)
  {
    return saveThePrisoner(numberOfChairs, numberOfCandys, offset);
  }
  return saveThePrisoner(numberOfChairs, numberOfCandys - numberOfChairs, offset);
}

std::vector<std::string> split(const std::string &str)
{
  std::vector<std::string> tokens;
  std::string::size_type start = 0;
  std::string::size_type end = 0;

  while ((end = str.find(' ', start)) != std::string::npos)
  {
    tokens.push_back(str.substr(start, end - start));
    int test = std::stoi(tokens[0]);
    start = end + 1;
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

int main(int argc, char const *argv[])
{

  int chairs;
  int candys;
  int offset;

  std::string currentFilePath(__FILE__);
  std::string currentDirectory = currentFilePath.substr(0, currentFilePath.find_last_of("/\\"));

  std::ifstream inputFile(currentDirectory + "/save_the_prisioner.txt", std::ios::in);

  int numberOfExamples = 0;

  if (inputFile.is_open())
  {
    // #TODO: Read line length to define buffer size
    char line[30];
    std::vector<std::string> example;
    inputFile.getline(line, 30);
    numberOfExamples = std::stoi(line);

    while (inputFile.good())
    {
      inputFile.getline(line, 30);
      example = split(line);
      chairs = std::stoi(example[0]);
      candys = std::stoi(example[1]);
      offset = std::stoi(example[2]);
      std::cout << "chairs: " << chairs << "\n";
      std::cout << "candys: " << candys << "\n";
      std::cout << "offset: " << offset << "\n";
    }
  }

  std::chrono::steady_clock::time_point begin = std::chrono::high_resolution_clock::now();
  const int savedPrisioner = saveThePrisoner(chairs, candys, offset);
  std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();

  std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("Time measured for saveThePrisoner: %.3f seconds.\n", elapsed.count() * 1e-9);

  begin = std::chrono::high_resolution_clock::now();
  const int savedPrisioner2 = saveThePrisoner2(chairs, candys, offset);
  end = std::chrono::high_resolution_clock::now();

  elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("Time measured for saveThePrisoner2: %.3f seconds.\n", elapsed.count() * 1e-9);

  std::cout << "savedPrisioner 1: " << savedPrisioner << "\n";
  std::cout << "savedPrisioner 2: " << savedPrisioner2 << "\n";
}
