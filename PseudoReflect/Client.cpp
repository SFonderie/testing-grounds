#include <iostream>

#include "FunctionRegistry.h"

//Start Execution
int main()
{
	FunctionRegistry<int, int, int> registry;

	registry.Add([](int a, int b) { return a * b; }, "Multiply");

	std::cout << "15 x 10 = " << registry.Evaluate("Multiply", 15, 10) << std::endl;

	//Default.
	return 0;
}
