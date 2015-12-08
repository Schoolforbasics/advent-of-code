#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

int main() {
	ifstream f("input");

	cout << accumulate(istream_iterator<string>(f), {}, 0, [](auto sum, auto str) {
		istringstream ss(str);
		string dimension;

		getline(ss, dimension, 'x');
		auto l = stoi(dimension);

		getline(ss, dimension, 'x');
		auto w = stoi(dimension);

		getline(ss, dimension, 'x');
		auto h = stoi(dimension);

		auto sideA = l*w;
		auto sideB = w*h;
		auto sideC = h*l;

		auto smallest = min({ sideA, sideB, sideC });

		return sum + 2 * sideA + 2 * sideB + 2 * sideC + smallest;
	}) << endl;
}
