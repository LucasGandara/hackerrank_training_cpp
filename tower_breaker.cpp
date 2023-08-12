// https://www.hackerrank.com/challenges/one-week-preparation-kit-tower-breakers-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-three
#include <stdio.h>
#include <assert.h>
#include <cmath>

int greatestDivisor(int number) {
    int result = 2;
    for (int i = 2; i <= sqrt(number) ; i++)
    {
        if (number % i == 0)
        {
            result = i;
            break;
        }

        if (i == int(sqrt(number)))
        {
            return 1;
        }

    }
    return number / result;
}

int towerBreakers(int n, int m) {

	if (m == 1)
	{
		// printf("winner : 2\n");
		return 2;
	}


	int numberOfPlays = 0;
	int currentTowerSize = m;

	while (currentTowerSize > 1)
	{
		numberOfPlays++;
		currentTowerSize = greatestDivisor(currentTowerSize);
	}

	// printf("n: %d\n", n);
	// printf("m: %d\n", m);
	// printf("numberOfPlays: %d\n", numberOfPlays);

	if (numberOfPlays == 1 && n % 2 == 0)
	{
		// printf("winner : 2\n");
		return 2;
	} else if (numberOfPlays == 1 && n % 2 == 1)
	{
		// printf("winner : 1\n");
		return 1;
	}

	if (numberOfPlays % 2 == 0 && n % 2 == 0) {
		return 2;
	} else if (numberOfPlays % 2 == 0 && n % 2 != 0) {
		// printf("winner : 1\n");
		return 1;
	} else if (numberOfPlays % 2 != 0 && n % 2 == 0) {
		// printf("winner : 2\n");
		return 2;
	} else {
		return 1;
	}
}

int main(int argc, char const *argv[])
{

	// printf("greatestDivisor: %d\n", greatestDivisor(7));
	int n, m, result;

	n = 2;
    m = 6;
    result = towerBreakers(n, m);
    assert(result == 2);

	n = 2;
	m = 2;
	result = towerBreakers(n, m);
	assert(result == 2);

	n = 1;
	m = 7;
	result = towerBreakers(n, m);
	assert(result == 1);

	n = 100000;
	m = 1;
	result = towerBreakers(n, m);
	assert(result == 2);

	n = 100001;
	m = 1;
	result = towerBreakers(n, m);
	assert(result == 2);

	n = 374625;
	m = 796723;
	result = towerBreakers(n, m);
	assert(result == 1);

	n = 637702;
	m = 274784;
	result = towerBreakers(n, m);
	assert(result == 2);

}
