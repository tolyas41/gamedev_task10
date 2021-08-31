#pragma once
#include <iostream>

class Prototype
{
public:

	virtual Prototype* Clone() const = 0;
	virtual void DisplayData() const = 0;
};


class Circle : public Prototype
{
private:

	int Radius;
	float PivotX;
	float PivotY;

public:

	Circle(int init_Radius = 0, float init_PivotX = 0, float init_PivotY = 0)
		: Radius(init_Radius), PivotX(init_PivotX), PivotY(init_PivotY) {}
	Circle(const Circle& Source)
	{
		this->Radius = Source.Radius;
		this->PivotX = Source.PivotX;
		this->PivotY = Source.PivotY;
	}

	virtual Prototype* Clone() const override
	{
		return new Circle(*this);
	}

	virtual void DisplayData() const override
	{
		std::cout << "\nRadius : " << Radius;
		std::cout << "\nPivotX : " << PivotX;
		std::cout << "\nPivotY : " << PivotY << std::endl;
	}
};