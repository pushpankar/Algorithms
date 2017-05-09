#include <iostream>
#include <vector>

using namespace std;

vector<int> left_rotate(vector<int> a, int n, int k);

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int a_i = 0; a_i < n; a_i++){
		cin >> a[a_i];
	}
	vector<int> output = left_rotate(a, n, k);
	for(int i = 0; i < n; i++){
		cout << output[i] << " ";
	}
	cout << endl;
	return 0;
}

vector<int> left_rotate(vector<int> a, int n, int k){
	vector<int> temp(k);
	for(int i = 0; i < k; i++){
		temp[i] = a[i];
	}
	for(int i = 0; i < n-k; i++){
		a[i] = a[i+k];
	}
	for(int i = 0; i < k; i++){
		a[n-k+i] = temp[i];
	}
	return a;
}
