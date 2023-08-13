// https://www.hackerrank.com/challenges/one-week-preparation-kit-caesar-cipher-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-three
#include <string>
#include <stdio.h>
#include <assert.h>
#include <cctype>

std::string caesarCipher(std::string s, int k) {
	std::string result;
	for (int i = 0; i < s.length(); i++)
	{
		if(isalnum(s[i]))
		{
			char c = s[i] + k;
			if (c > 'z')
			{
				c -= 26;
			}
		result.insert(result.end(), c);
		} else {
			result.insert(result.end(), s[i]);
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{

	std::string input1 = "abcdefghijklmnopqrstuvwxyz";
	std::string actual = caesarCipher(input1, 2).c_str();
	std::string expected1 = "cdefghijklmnopqrstuvwxyzab";

	printf("Actual: %s\n", actual.c_str());
	printf("Expected: %s\n", expected1.c_str());
	assert(actual == expected1);

	std::string input2 = "There's-a-starman-waiting-in-the-sky";
	std::string actual2 = caesarCipher(input2, 3);
	std::string expected2 = "Wkhuh'v-d-vwdupdq-zdlwlqj-lq-wkh-vnb";

	printf("\nActual: %s\n", actual2.c_str());
	printf("Expected: %s\n", expected2.c_str());
	assert(actual2 == expected2);
}
