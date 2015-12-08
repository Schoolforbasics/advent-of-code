#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
	ifstream f("input");

	cout << accumulate(istream_iterator<char>(f), {}, 0, [](auto sum, auto c) {
		return sum + (c == '(') - (c == ')');
	}) << endl;
}
