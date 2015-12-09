#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	ifstream f("input");
	unordered_map<string, unordered_map<string, int>> distances;

	string line;
	while (getline(f, line)) {
		istringstream ss(line);

		string location1, eat, location2;
		int distance;
		
		ss >> location1 >> eat >> location2 >> eat >> distance;

		distances[location1][location2] = distance;
		distances[location2][location1] = distance;
	}

	vector<string> v(distances.size());
	transform(begin(distances), end(distances), begin(v), [](const auto &kv) {
		return kv.first;
	});

	sort(begin(v), end(v));

	auto best_distance = INT_MAX;
	auto worst_distance = 0;

	do {
		auto distance = inner_product(begin(v) + 1, end(v), begin(v), 0, std::plus<int>{}, [&](auto city1, auto city2) {
			return distances[city1][city2];
		});
		if (distance > worst_distance) {
			worst_distance = distance;
		}
		else if (distance < best_distance) {
			best_distance = distance;
		}
	} while (next_permutation(begin(v), end(v)));

	cout << best_distance << endl;
	cout << worst_distance << endl;
}