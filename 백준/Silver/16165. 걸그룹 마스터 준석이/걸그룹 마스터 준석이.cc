#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, string> member;
	map<string, set<string>> team;

	int N, M;
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		string T;
		cin >> T;
		int num;
		cin >> num;
		for (int j = 0;j < num;j++) {
			string name;
			cin >> name;
			team[T].insert(name);
			member[name] = T;
		}
	}

	for (int i = 0;i < M;i++) {
		string str;
		cin >> str;
		int Q;
		cin >> Q;
		if (Q) {
			cout << member[str] << "\n";
		}
		else {
			for (string mem : team[str]) {
				cout << mem << "\n";
			}
		}
	}
}