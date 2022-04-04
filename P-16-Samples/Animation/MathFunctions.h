#pragma once
#pragma once
#include<vector>
#include<string>
#include<numeric>
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

	static inline size_t greaterCommonDivisorFrom(size_t a, size_t b)
	{
		//return std::gcd(a, b);
		return b == 0 ? a : greaterCommonDivisorFrom(b, a%b);
	}
	static inline size_t leastCommonMultipleFrom(size_t a, size_t b)
	{
		int temp = greaterCommonDivisorFrom(a, b);
		return temp ? (a*(b / temp)) : 0;
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

};

