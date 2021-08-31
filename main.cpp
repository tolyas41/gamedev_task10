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

		Prototype* b = a.Clone();
		std::cout << "\n<Circle b>";
		b->DisplayData();
		delete b;
	}


	{
		//Composite

		Composite* a = new Element(1300);
		Composite* b = new Element(3);
		Composite* c = new Element(5);
		Composite* A = new Box();
		Composite* B = new Box();
		A->Add(a);
		A->Add(B);
		B->Add(b);
		B->Add(c);
		std::cout << "\nB Value : " << B->GetValue();
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

		VectorOfNumbers* a = new VectorOfNumbers(new Addition);
		a->SetNumbers(nums);
		a->PrintStrategyResult();

		a->SetStrategy(new Multiplication);
		a->PrintStrategyResult();
		delete a;
	}

	return 0;
}