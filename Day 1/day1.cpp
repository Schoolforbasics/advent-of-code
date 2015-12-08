#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
	ifstream f("input");

	cout << accumulate(istream_iterator<char>(f), {}, 0, [pos = 1, found = false](auto sum, auto c) mutable {
		sum += (c == '(') - (c == ')');
		if (sum == -1 && !found) {
			found = true;
			cout << pos << endl;
		}
		pos++;
		return sum;
	}) << endl;
}
