#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	ifstream f("input");
	vector<int> containers;
	copy(istream_iterator<int>(f), {}, back_inserter(containers));

	auto combinations_found = 0;
	auto minimum_containers = INT_MAX;
	for (auto com = 0; com < (1 << containers.size()); com++) {
		auto liters = 0;
		auto containers_count = 0;
		for (auto i = 0; i < containers.size(); i++) {
			if (com & (1 << i)) {
				liters += containers[i];
				containers_count++;
			}
		}
		if (liters == 150) {
			combinations_found++;
			if (containers_count < minimum_containers) {
				minimum_containers = containers_count;
			}
		}
	}

	cout << combinations_found << endl;
	cout << minimum_containers << endl;
}