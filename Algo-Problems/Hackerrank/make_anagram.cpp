#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

int numbers_needed(string a, string b);

int main(){
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << numbers_needed(a, b) << endl;
	return 0;
}

int numbers_needed(string a, string b){
	unordered_map<char, int> a_map, b_map;
	for(string::iterator it = a.begin(); it != a.end(); it++){
		a_map[*it]++;
	}
	for(string::iterator it = b.begin(); it != b.end(); it++){
		b_map[*it]++;
	}

	int count = 0;
	for(unordered_map<char, int>::iterator it = a_map.begin(); it != a_map.end(); it++){
		unordered_map<char, int>::iterator it2 = b_map.find(it->first);
		if(it2 == b_map.end()){
			count += it->second;
			continue;
		}
		count += abs(it->second - it2->second);
	}
	for(unordered_map<char, int>::iterator it = b_map.begin(); it != b_map.end(); it++){
		unordered_map<char, int>::iterator it2 = a_map.find(it->first);
		if(it2 == b_map.end()){
			count += it->second;
		}
	}
	return count;
}
