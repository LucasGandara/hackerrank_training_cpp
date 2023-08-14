// https://www.hackerrank.com/challenges/one-week-preparation-kit-caesar-cipher-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-three
#include <string>
#include <stdio.h>
#include <assert.h>
#include <cctype>

std::string caesarCipher(const std::string& s, int k) {
	std::string result = "";
	for (int i = 0; i < s.length(); i++)
	{
		if(isalnum(s[i]))
		{
			if (isupper(s[i]))
			{
				result += 'A' + (s[i] - 'A' + k) % 26;
			} else if (islower(s[i]))
			{
				result += 'a' + (s[i] - 'a' + k) % 26;
			} else // Is numeric value
			{
				result += s[i];
			}



		} else {
			result += s[i];
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

	std::string input3 = "Hello_World!";
	std::string actual3 = caesarCipher(input3, 4);
	std::string expected3 = "Lipps_Asvph!";

	printf("\nActual: %s\n", actual3.c_str());
	printf("Expected: %s\n", expected3.c_str());
	assert(actual3 == expected3);

	std::string input4 = "Ciphering.";
	std::string actual4 = caesarCipher(input4, 26);
	std::string expected4 = "Ciphering.";

	printf("\nActual: %s\n", actual4.c_str());
	printf("Expected: %s\n", input4.c_str());
	assert(actual4 == expected4);

	std::string input5 = "DNFjxo?b5h*5<LWbgs6?V5{3M].1hG)pv1VWq4(!][DZ3G)riSJ.CmUj9]7Gzl?VyeJ2dIPEW4GYW*scT8(vhu9wCr]q!7eyaoy.";
	std::string actual5 = caesarCipher(input5, 45);
	std::string expected5 = "WGYcqh?u5a*5<EPuzl6?O5{3F].1aZ)io1OPj4(!][WS3Z)kbLC.VfNc9]7Zse?OrxC2wBIXP4ZRP*lvM8(oan9pVk]j!7xrthr.";

	printf("\nString to cipher: %s\n", input5.c_str());
	printf("Actual:           %s\n", actual5.c_str());
	printf("Expected:         %s\n", expected5.c_str());
	assert(actual5 == expected5);
}
