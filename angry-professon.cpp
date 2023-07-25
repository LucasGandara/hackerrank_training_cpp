#include <iostream>
#include <vector>
#include <string>

std::string angryProfessor(int k, std::vector<int> a)
{
	int lates = 0;
	int earlys = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] <= 0)
		{
			earlys++;
		}
		else
		{
			lates++;
		}
	}
	if (earlys >= k)
	{
		return "NO";
	}
	return "YES";
}

int main()
{
	int k = 3;
	std::vector<int> a = {-1, -3, 4, 2};
	std::string result = angryProfessor(k, a);
	std::cout << result << "\n";

	k = 2;
	a = {0, -1, 2, 1};
	result = angryProfessor(k, a);
	std::cout << result << "\n";
}
