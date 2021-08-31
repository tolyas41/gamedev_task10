#pragma once
#include <list>

class Composite
{
public:
	virtual int GetValue() const = 0;
	virtual void Add(Composite* Elem) {}
	virtual void Delete(Composite* Elem) {}
	virtual ~Composite() {}
};


class Element : public Composite
{
private:

	int Value;

public:
	virtual ~Element() {}
	Element(int init_Value = 0)
		: Value(init_Value) {}

	virtual int GetValue() const override
	{
		return Value;
	}
};


class Box : public Composite
{
private:

	std::list<Composite*> Children;

public:

	virtual ~Box() {}
	virtual void Add(Composite* Elem)
	{
		Children.push_back(Elem);
	}

	void Delete(Composite* Elem)
	{
		Children.erase(std::find(Children.begin(), Children.end(), Elem));
	}

	virtual int GetValue() const override
	{
		int Val = 0;
		for (const Composite* Elem : Children)
		{
			Val += Elem->GetValue();
		}
		return Val;
	}
};