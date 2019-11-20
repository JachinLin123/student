#include <iostream>
#include <map>
using namespace std; 
map<int, int> ans;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	int n, m;
	cin>> n>> m;	 
	for(int i = 0; i < n; i++){
		int num = 0, x; 
		for(int j = 0; j < m; j++) {
			cin>> x;
			num = (num<<1)+x;
		}
		ans[num]++;
	}
	int sum =0,maxn = (1<<m)-1, mid = maxn/2;
	for(map<int, int>::iterator it = ans.begin(); it != ans.end() ; it++){
		int x = it->first;
		if(mid < x) break;  
		int num = x^maxn;
		sum += ans[num]*it->second;
	}
	cout<< sum << '\n';
	return 0;
}
