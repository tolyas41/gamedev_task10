#pragma once
#include <iostream>
#include <memory>

class I_Prototype
{
public:

	virtual std::unique_ptr<I_Prototype> Clone() const = 0;
	virtual void DisplayData() const = 0;
	virtual ~I_Prototype() {}
};


class Circle : public I_Prototype
{
private:

	int Radius;
	float PivotX;
	float PivotY;

public:

	virtual ~Circle() {}

	Circle(int init_Radius = 0, float init_PivotX = 0, float init_PivotY = 0)
		: Radius(init_Radius), PivotX(init_PivotX), PivotY(init_PivotY) {}

	Circle(const Circle& Source)
	{
		Radius = Source.Radius;
		PivotX = Source.PivotX;
		PivotY = Source.PivotY;
	}

	Circle& operator=(const Circle& Source)
	{
		Radius = Source.Radius;
		PivotX = Source.PivotX;
		PivotY = Source.PivotY;
		return *this;
	}

	virtual std::unique_ptr<I_Prototype> Clone() const override
	{
		return std::make_unique<Circle>(*this);
	}

	virtual void DisplayData() const override
	{
		std::cout << "\nRadius : " << Radius;
		std::cout << "\nPivotX : " << PivotX;
		std::cout << "\nPivotY : " << PivotY << std::endl;
	}
};