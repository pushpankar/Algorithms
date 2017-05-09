#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
  unordered_map<string, int> mag_map, note_map;
  for(vector<string>::iterator it = magazine.begin(); it != magazine.end(); it++){
    mag_map[*it]++;
  }
  for(vector<string>::iterator it = ransom.begin(); it != ransom.end(); it++){
    note_map[*it]++;
  }
  for(unordered_map<string, int>::iterator it = note_map.begin(); it != note_map.end(); it++){
    unordered_map<string, int>::iterator it2 = mag_map.find(it->first);
    if(it2 == mag_map.end() || (it2->second - it->second < 0)){
      return false;
    }
  }
  return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
