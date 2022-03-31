#include "main.hpp"

void	test_empty(void)
{
	std::cout << std::endl;
	std::cout << ">> test empty function" << std::endl;
	std::cout << std::endl;

	LIB::stack<std::string>		animals;

	display_stack("animals", animals);
	std::cout << "animals.empty() = " << animals.empty() <<
		std::endl << std::endl;

	animals.push("zebra");
	animals.push("goat");

	display_stack("animals", animals);
	std::cout << "animals.empty() = " << animals.empty() << std::endl;
	std::cout << std::endl;
}

void	test_size(void)
{
	std::cout << std::endl;
	std::cout << ">> test size function" << std::endl;
	std::cout << std::endl;

	LIB::stack<std::string>		animals;

	display_stack("animals", animals);

	std::cout << "animals.size() = " << animals.size() <<
		std::endl << std::endl;

	animals.push("tiger");
	animals.push("snake");

	display_stack("animals", animals);

	std::cout << "animals.size() = " << animals.size() << std::endl;
	std::cout << std::endl;
}

void	test_top(void)
{
	LIB::stack<std::string>		animals;

	std::cout << std::endl;
	std::cout << ">> test top" << std::endl;
	std::cout << std::endl;

	animals.push("bear");
	animals.push("lion");

	display_stack("animals", animals);

	std::cout << "animals.top() = " << animals.top()
		<< std::endl << std::endl;
}

void	test_push(void)
{
	std::cout << std::endl;
	std::cout << ">> test push function" << std::endl;
	std::cout << std::endl;

	LIB::stack<std::string>		animals;

	display_stack("animals", animals);

	std::cout << "animals.push(\"giraffe\")" << std::endl;
	std::cout << "animals.push(\"hippopotamus\")" << std::endl << std::endl;
	animals.push("giraffe");
	animals.push("hippopotamus");

	display_stack("animals", animals);
}

void	test_pop(void)
{
	std::cout << std::endl;
	std::cout << ">> test pop function" << std::endl;
	std::cout << std::endl;

	LIB::stack<std::string>		animals;

	animals.push("bird");
	animals.push("cat");

	display_stack("animals", animals);

	animals.pop();
	std::cout << "animals.pop()" << std::endl << std::endl;
	display_stack("animals", animals);
}

void	test_stack_member_functions(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test member functions ------------>"
	<< std::endl << std::endl;

	std::cout << "********************************************" << std::endl;
	test_empty();
	std::cout << "********************************************" << std::endl;
	test_size();
	std::cout << "********************************************" << std::endl;
	test_top();
	std::cout << "********************************************" << std::endl;
	test_push();
	std::cout << "********************************************" << std::endl;
	test_pop();
	std::cout << "********************************************" << std::endl;
}
