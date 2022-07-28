#include <iostream>
#include <string>
#include <cstring>

char charSetRepetition[256];
void CountRepetitions(std::string inputString);

int main() {

	std::string inputString;
	std::string result = "";

	memset(charSetRepetition, 0, 256);

	std::cout << "Input string: " << std::endl;
	std::getline(std::cin, inputString);

	CountRepetitions(inputString);

	for (int i = 0; i < inputString.length(); i++)
	{
		int val = inputString[i];

		if (charSetRepetition[val] == 1)
		{
			result += '(';
		}
		else if (charSetRepetition[val] > 1)
		{
			result += ')';
		}
	}

	std::cout << result;

	return 0;
}

void CountRepetitions(std::string inputString)
{

	for (int i = 0; i < inputString.length(); i++)
	{
		int val = inputString[i];
		charSetRepetition[val]++;

		if (val >= 65 && val <= 90 || val >= 128 && val <= 159) //check register
		{
			charSetRepetition[val]++;
			charSetRepetition[val + 32] += 2;
		}
	}
}