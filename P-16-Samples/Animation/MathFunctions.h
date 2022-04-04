#pragma once
#pragma once
#include<vector>
#include<string>
class MathFunctions
{
public:
	static inline std::vector<long> IntegerDivibleBy3and5SmallerThan(long limit)
	{
		std::vector<long> vect;
		for (long i = 0; i <= limit; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
				vect.push_back(i);
		}
		return vect;
	}

	static inline long greaterCommonDivisorFrom(long, long)
	{

	}
	static inline long leastCommonMultipleFrom(long, long)
	{

	}

	static inline std::vector<long> largestPrimeSmallerThan(long)
	{

	}

	static inline std::vector<long> sexyPrimePairSmallerThan(long)
	{

	}

	static inline std::vector<long> abundantNumberSmallerThan(long)
	{

	}

	static inline std::vector<long> amicalNumbersSmallerThan(long)
	{

	}

	static inline std::vector<long> armstrongNumbersSmallerThan(long)
	{

	}

	static inline std::vector<long> primeFactorsOfNumber(long)
	{

	}


	//+grayCode();
	std::string toRoman(long)
	{

	}

	std::string largestCollatzSequence(long)
	{

	}

	constexpr double getPi()
	{
		return 22 / 7;
	}

	bool validateISBN(int)
	{

	}

private:
	std::vector<long> m_numbers;
};

