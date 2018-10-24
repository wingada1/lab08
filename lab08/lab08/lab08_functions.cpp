#include "lab08_functions.h"
#include<stdexcept>
using std::range_error;
#include<iostream>
using std::cout; using std::cin; using std::endl;
using namespace std;

long collatz_next(long n) {
	if (n < 1)
		throw range_error("Number should be positive (1 or greater)!");
	long num = n;
	if ((n % 2) == 0) {
		num = num / 2;
	}
	else {
		num = (num * 3) + 1;
	}
	return num;
}

string Collatz_to_string(const Collatz & p) {
	string str = to_string(p.first) + ": ";
	vector<long> v = p.second;
	str += to_string(v[0]);
	for (int i = 1; i < v.size(); i++)
		str += "," + to_string(v[i]);
	return str;
}

string sequence_in_map_to_string(map<long, vector<long>>& m, long number) {
	map<long, vector<long>>::iterator it = m.find(number);
	if (it != m.end())
		return Collatz_to_string(*it);
	else
		return "";
}

vector<long> collatz_sequence(map<long, vector<long>>& m, long number) {
	vector<long> r;
	long n = number;
	while (number != 1) {
		const bool is_in = m.find(number) != m.end();
		if (is_in == 1) {
			for (int i = 0; i < m.at(number).size(); i++)
				r.push_back(m.at(number)[i]);
			long sz = m.at(number).size();
			number = m.at(number)[sz];
		}
		else {
			number = collatz_next(number);
			r.push_back(number);
		}
	}
	m[n] = r;
	return r;
}

void collatz_range(map<long, vector<long>>& m, long low, long high)
{
}
