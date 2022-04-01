#pragma once
#include<vector>
class MathFunctions
{
public:
	static inline std::vector<long> IntegerDivibleBy3and5SmallerThan(long limit)
	{
		std::vector<long> vect;
		for (size_t i = 0; i <= limit; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
				vect.push_back(i);
		}
		return vect;
	}
};

