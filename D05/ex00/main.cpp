
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Bureaucrat.hpp"

#define xassert(exp, msg) \
	{ \
		bool ___ok = (exp); \
		if (___ok) \
			std::cout << "\e[92mPASSED\e[39m: " << msg << std::endl; \
		if (!___ok) { \
			std::cout << "\e[91mFAILED\e[39m: " << msg << "    (line: " << __LINE__ << ")" << std::endl; \
			exit(1); \
		} \
	}

int
main(void)
{
	try {
		Bureaucrat("Caren", 0);
	} catch (std::exception & e) {
		std::cout << 
	}
	//std::string msg;

	//try
	//{
	//	msg = "normal: 1";

	//	Bureaucrat("hello", 1);
	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "normal: 100";

	//	Bureaucrat("hello", 150);
	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "normal: 150";

	//	Bureaucrat("hello", 150);
	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "slightly off: 0";

	//	Bureaucrat("hello", 0);
	//	xassert(false, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too high", msg);
	//}

	//try
	//{
	//	msg = "slightly off: 151";

	//	Bureaucrat("hello", 151);
	//	xassert(false, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too low", msg);
	//}

	//try
	//{
	//	msg = "negative number: -5";

	//	Bureaucrat("hello", -5);
	//	xassert(false, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too high", msg);
	//}

	//try
	//{
	//	msg = "big number: 12588";

	//	Bureaucrat("hello", 12588);
	//	xassert(false, "big number: 12588");
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too low", msg);
	//}

	//try
	//{
	//	msg = "normal, gradeUp 2 -> 1";

	//	Bureaucrat x("hello", 2);
	//	x.gradeUp();

	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "off, gradeUp 1 -> 0";

	//	Bureaucrat x("hello", 1);
	//	x.gradeUp();

	//	xassert(false, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too high", msg);
	//}

	//try
	//{
	//	msg = "normal, gradeDown 149 -> 150";

	//	Bureaucrat x("hello", 149);
	//	x.gradeDown();

	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "off, gradeDown 150 -> 151";

	//	Bureaucrat x("hello", 150);
	//	x.gradeDown();

	//	xassert(false, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(e.what() == "Grade is too low", msg);
	//}

	//try
	//{
	//	msg = "loop, gradeUp 150 -> ... -> 1";

	//	Bureaucrat x("hello", 150);

	//	for (int i = 0; i < 149; ++i)
	//	{
	//		x.gradeUp();
	//	}

	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "loop, gradeDown 1 -> ... -> 150";

	//	Bureaucrat x("hello", 1);

	//	for (int i = 0; i < 149; ++i)
	//	{
	//		x.gradeDown();
	//	}

	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "loop, gradeUp 150 -> ... -> 1, gradeDown 1 -> ... -> 150";

	//	Bureaucrat x("hello", 150);

	//	for (int i = 0; i < 149; ++i)
	//	{
	//		x.gradeUp();
	//	}

	//	for (int i = 0; i < 149; ++i)
	//	{
	//		x.gradeDown();
	//	}

	//	xassert(true, msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "<< overload: 1";

	//	std::stringstream ss;
	//	ss << Bureaucrat("the boss", 1);

	//	xassert(ss.str() == "the boss, bureaucrat grade 1", msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	//try
	//{
	//	msg = "<< overload: 150";

	//	std::stringstream ss;
	//	ss << Bureaucrat("the intern", 150);

	//	xassert(ss.str() == "the intern, bureaucrat grade 150", msg);
	//}
	//catch (std::exception &e)
	//{
	//	xassert(false, msg);
	//}

	return (EXIT_SUCCESS);
}