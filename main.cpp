#include "Prototype.h"
#include "Composite.h"
#include "Strategy.h"


int main()
{

	{
		//Prototype

		Circle a(12, 2, 2);
		std::cout << "<Circle a>";
		a.DisplayData();

		std::unique_ptr<I_Prototype> b = a.Clone();
		std::cout << "\n<Circle b>";
		b->DisplayData();
	}


	{
		//Composite

		I_Composite* a = new Element(1300);
		I_Composite* b = new Element(3);
		I_Composite* c = new Element(5);
		I_Composite* A = new Box();
		I_Composite* B = new Box();
		A->Add(a);
		A->Add(B);
		B->Add(b);
		B->Add(c);
		B->CalculateValue();
		std::cout << "\nB Value : " << B->GetValue();
		A->CalculateValue();
		std::cout << "\nA Value : " << A->GetValue();
		delete a;
		delete b;
		delete c;
		delete A;
		delete B;
	}


	{
		//Strategy

		std::vector<float> nums = { 1.f, 5.f, 2.4f, 8.2f, 2.f, 10.f };

		Addition addition;
		VectorOfNumbers a(&addition);
		a.SetNumbers(nums);
		a.PrintStrategyResult();

		Multiplication multiplication;
		a.SetStrategy(&multiplication);
		a.PrintStrategyResult();
	}

	return 0;
}