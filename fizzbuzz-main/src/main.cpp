#include <iostream>
#include <string>

#include "divisible_check.h"

using namespace std;

void runFizzBuzz(const string &multiple3Msg, const string &multiple5Msg) {
	DivisibleCheck divCheck;
	divCheck.addDivisor(3, multiple3Msg);
	divCheck.addDivisor(5, multiple5Msg);
	divCheck.doCheck(1, 100, std::cout);
}

int main(int argc, char* argv[]) {
	//runFizzBuzz("Fizz", "Buzz");
	runFizzBuzz("Crackle", "Pop");
	return 0;
}

