#include <iostream>

class SlowerMath
{
public:
	int checkperfect(int num)
	{
		int i = 1;
		while (i != num / i)
		{
			i++;
			if (i > num)
			{
				return NULL;
				break;
			}
		}
		if (i == num / i)
		{
			return i;
		}
	}

	int findsmallerperfect(int num)
	{
		while (checkperfect(num) == NULL)
		{
			num--;
			int smallerperfect = checkperfect(num);
			if (checkperfect(num) != NULL)
			{
				return smallerperfect;
			}
		}
	}

	float sqrt(int num, int digits)
	{
		if (checkperfect(num) == NULL)
		{
			int i = 1;
			int smallerperfect = findsmallerperfect(num);
			float sqrt = smallerperfect + i * pow(10, -digits);
			while (sqrt * sqrt < num)
			{
				i++;
				sqrt = smallerperfect + i * pow(10, -digits);
				std::cout << sqrt << std::endl;

			}
			if (sqrt * sqrt > num)
			{
				return sqrt - pow(10, -digits);
				std::cout << sqrt << std::endl;

			}
		}
		else if (checkperfect(num) != NULL)
		{
			return checkperfect(num);
		}
	}
};