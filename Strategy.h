#pragma once
#include <vector>
#include <string>


class I_Strategy
{
protected:

	std::string Name;

public:

	virtual float DoOperation(const std::vector<float> Numbers) = 0;

	std::string GetName() const
	{
		return Name;
	}
};


class VectorOfNumbers
{
private:

	I_Strategy* CurrentStrategy;
	std::vector<float> Numbers;

public:

	VectorOfNumbers(I_Strategy* init_CurrentStrategy)
	{
		CurrentStrategy = init_CurrentStrategy;
	}

	void SetStrategy(I_Strategy* strategy)
	{
		CurrentStrategy = strategy;
	}

	void SetNumbers(std::vector<float> numbers)
	{
		Numbers = numbers;
	}

	void PrintStrategyResult() const
	{
		std::cout << "\nResult for " << CurrentStrategy->GetName() << " is : " << CurrentStrategy->DoOperation(Numbers) << std::endl;
	}
};


class Addition : public I_Strategy
{
public:

	Addition()
	{
		Name = "Addition";
	}

	virtual float DoOperation(const std::vector<float> Numbers) override
	{
		float Result = 0;
		for (float n : Numbers)
		{
			Result += n;
		}
		return Result;
	}
};

class Multiplication : public I_Strategy
{
public:

	Multiplication()
	{
		Name = "Multiplication";
	}

	virtual float DoOperation(const std::vector<float> Numbers) override
	{
		float Result = Numbers.at(0);
		for (float n : Numbers)
		{
			Result *= n;
		}
		return Result;
	}

};

