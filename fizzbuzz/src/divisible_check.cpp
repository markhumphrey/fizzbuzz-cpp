#include "divisible_check.h"
#include <iostream>

using namespace std;

DivisibleCheck::DivisibleCheck() {
}

DivisibleCheck::~DivisibleCheck() {
}

void DivisibleCheck::doCheck(int start, int end, std::ostream &stream) const {
	for (int i = start; i <= end; ++i) {
		bool isDiv = false;
		for (size_t j = 0; j < m_divisors.size(); ++j) {
			if (i % m_divisors[j].first == 0) {
				stream << m_divisors[j].second;
				isDiv = true;
			}
		}
		if (!isDiv) {
			stream << i;
		}
		stream << endl;
	}
}

void DivisibleCheck::addDivisor(int divisor, const std::string &message) {
	if (divisor != 0) {
		m_divisors.push_back(pair<int, string>(divisor, message));
	}
}

void DivisibleCheck::clearDivisors() {
	m_divisors.clear();
}

