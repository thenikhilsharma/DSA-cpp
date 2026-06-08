#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vec = {'a', 'b', 'c', 'd', 'e'};
	int count = vec.count('c');
	int target = 'c';
	int find = target + 1;
	int i = 0;
	while (find < vec[i]) {
		i++;
	}
	cout << vec[i];
	return 0;
}