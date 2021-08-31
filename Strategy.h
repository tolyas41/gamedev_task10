#pragma once
#include <vector>
#include <string>

class Strategy
{
public:
	virtual ~Strategy() {}
	virtual float Operation(const std::vector<float> Numbers) = 0;
	virtual std::string GetName() const = 0;
};


class VectorOfNumbers
{
private:

	Strategy* CurrentStrategy;
	std::vector<float> Numbers;

public:

	VectorOfNumbers(Strategy* init_CurrentStrategy = nullptr) 
		: CurrentStrategy(init_CurrentStrategy) {}
	~VectorOfNumbers()
	{
		delete this->CurrentStrategy;
	}

	void SetStrategy(Strategy* strategy)
	{
		delete this->CurrentStrategy;
		CurrentStrategy = strategy;
	}

	void SetNumbers(std::vector<float> numbers)
	{
		Numbers = numbers;
	}

	void PrintStrategyResult() const
	{
		std::cout << "\nResult for " << CurrentStrategy->GetName() << " is : " << CurrentStrategy->Operation(Numbers) << std::endl;
	}
};


class Addition : public Strategy
{
private:

	std::string Name = "Addition";

public:

	virtual ~Addition() {}

	virtual float Operation(const std::vector<float> Numbers) override
	{
		float Result = 0;
		for (float n : Numbers)
		{
			Result += n;
		}
		return Result;
	}

	virtual std::string GetName() const
	{
		return Name;
	}
};

class Multiplication : public Strategy
{
private:

	std::string Name = "Multiplication";

public:

	virtual ~Multiplication() {}

	virtual float Operation(const std::vector<float> Numbers) override
	{
		float Result = Numbers.at(0);
		for (float n : Numbers)
		{
			Result *= n;
		}
		return Result;
	}

	virtual std::string GetName() const
	{
		return Name;
	}
};

