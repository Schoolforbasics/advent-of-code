#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

using namespace std;

int main() {
	ifstream f("input");

	struct {
		int paper;
		int ribbon;
	} feet{};

	for_each(istream_iterator<string>(f), {}, [&](auto str) {
		istringstream ss(str);
		string dimension;

		getline(ss, dimension, 'x');
		auto l = stoi(dimension);

		getline(ss, dimension, 'x');
		auto w = stoi(dimension);

		getline(ss, dimension, 'x');
		auto h = stoi(dimension);

		auto areaA = l*w;
		auto areaB = w*h;
		auto areaC = h*l;

		auto smallestArea = min({ areaA, areaB, areaC });

		feet.paper += 2 * areaA + 2 * areaB + 2 * areaC + smallestArea;

		auto perA = 2 * (l + w);
		auto perB = 2 * (w + h);
		auto perC = 2 * (h + l);

		auto smallestPer = min({ perA, perB, perC });

		feet.ribbon += smallestPer + l*w*h;
	});

	cout << feet.paper << endl;
	cout << feet.ribbon << endl;
}
