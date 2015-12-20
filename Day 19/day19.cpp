#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	ifstream f("input");

	vector<pair<string, string>> dict;

	string line;
	while (getline(f, line), line != "") {
		string from, dummy, to;
		istringstream ss(line);
		ss >> from >> dummy >> to;
		dict.emplace_back(move(from), move(to));
	}

	string molecule;
	f >> molecule;

	unordered_set<string> found;

	for (const auto& p : dict) {
		string::size_type pos = 0;
		while ((pos = molecule.find(p.first, pos)) != string::npos) {
			string replaced = molecule;
			replaced.replace(pos, p.first.length(), p.second);
			found.insert(move(replaced));
			pos++;
		}
	}

	cout << found.size() << endl;

	auto steps = 0;

	while (molecule != "e") {
		decltype(dict)::iterator best_it;
		string::size_type best_pos = 0;

		for (auto it = dict.begin(); it != dict.end(); ++it) {
			auto pos = molecule.rfind(it->second);
			if (pos != string::npos && pos >= best_pos) {
				best_pos = pos;
				best_it = it;
			}
		}

		molecule.replace(best_pos, best_it->second.length(), best_it->first);
		steps++;
	}

	cout << steps << endl;
}