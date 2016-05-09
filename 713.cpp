#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
string r(string x) {
		string t;
		bool flag = 1;
		for (int i = 0; i < x.size(); i++) {
			if (x[x.size() - 1 - i] == '0'&&flag) continue;
			else flag = 0;
			t =t+ x[x.size() - 1 - i];
		}
		return t;
}
string add(string az, string bz){
	int flag=0;
	string ans;
	int m = az.size(), n =bz.size();
	int a[205] = { 0 }, b[250] = { 0 };
	for (int i = 0; i < az.size(); i++) a[i] = az[az.size() -1-i] - '0';
	for (int i = 0; i < bz.size(); i++) b[i] = bz[bz.size()-1-i] - '0';
	int k = (m > n ? m : n);
	for (int i = 0; i<k; i++) {
		a[i] = a[i] + b[i];
		if (a[i] > 9) {
			if (i == k - 1) flag++;
			a[i] -= 10;
			a[i + 1]++;
		}
		flag++;
	}
	for (int i = 0; i < flag; i++) {
		string t;
		stringstream ss;
		ss << a[flag - 1 - i];
		ss >> t;
		ans = ans + t;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	while (n--){
		string a, b;
		cin >> a >> b;
		string na= r(a),nb= r(b);
		string added = add(na , nb);
		string ans = r(added);
		cout << ans << endl;
	}
	//system("PAUSE");
	return 0;
}