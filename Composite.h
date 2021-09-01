#pragma once
#include <list>

class I_Composite
{
protected:
	int Value;
public:
	virtual void CalculateValue() = 0;
	virtual int GetValue() const = 0;
	virtual void Add(I_Composite* Elem) {}
	virtual void Delete(I_Composite* Elem) {}
};


class Element : public I_Composite
{
public:

	Element(int init_Value = 0) 
	{
		Value = init_Value;
	}

	virtual int GetValue() const override
	{
		return Value;
	}

	virtual void CalculateValue() {}
};


class Box : public I_Composite
{
private:

	std::list<I_Composite*> Children;

public:

	virtual void Add(I_Composite* Elem)
	{
		Children.push_back(Elem);
	}

	void Delete(I_Composite* Elem)
	{
		Children.erase(std::find(Children.begin(), Children.end(), Elem));
	}

	virtual void CalculateValue() 
	{
		int Val = 0;
		for (I_Composite* Elem : Children)
		{
			Elem->CalculateValue();
			Val += Elem->GetValue();
		}
		Value = Val;
	}

	virtual int GetValue() const override
	{
		return Value;
	}

};