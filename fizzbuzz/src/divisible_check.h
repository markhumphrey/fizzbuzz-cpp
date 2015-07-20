#pragma once

#include <ostream>
#include <string>
#include <utility>
#include <vector>

class DivisibleCheck {
public:
	DivisibleCheck();
	~DivisibleCheck();

	void doCheck(int start, int end, std::ostream &stream) const;
	void addDivisor(int divisor, const std::string &message);
	void clearDivisors();

private:
	std::vector<std::pair<int, std::string> > m_divisors;

};

