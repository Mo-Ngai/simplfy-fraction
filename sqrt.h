#include <iostream>

class Math
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

	float sqrt(int num, int digits)//2
	{
		if (checkperfect(num) == NULL)// --> NULL
		{
			int d = 1;
			int i = 1;
			int smallerperfect = findsmallerperfect(num);
			float sqrt = smallerperfect + i * pow(10, -d);
			float sqrtans = 0;
			while (d <= digits)
			{
				while (sqrt * sqrt < num)
				{
					if (d == 1)
					{
						i++;
						sqrt = smallerperfect + i * pow(10, -d);
						std::cout << sqrt << std::endl;
					}
					else
					{
						i++;
						sqrt = sqrtans + i * pow(10, -d);
						std::cout << sqrt << std::endl;

					}
				}
				if (sqrt * sqrt > num)
				{
					sqrt -= pow(10, -d);
					sqrtans = sqrt;
					d++;
					i = 0;
					std::cout << sqrt << std::endl;
				}
			}
			return sqrtans;
		}
		else if (checkperfect(num) != NULL)
		{
			return checkperfect(num);
		}
	}

};

