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
}