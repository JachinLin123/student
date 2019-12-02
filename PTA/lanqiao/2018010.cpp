#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, k;
long long ans = 1;
int l_neg = -1, l_pos = -1, r_neg = -1, r_pos = -1;
const int M = 1000000009;
 
bool cmp(int a, int b)
{
	return abs(a) < abs(b);
}
 
int calc(vector<int> a)
{
	long long temp = 1;
	for(int i = n - k; i < n; i++)
		temp = (temp * a[i]) % M;
	return temp;
}
 
bool v_cmp(vector<int> a, vector<int> b)
{
	int sum1 = 0, sum2 = 0;
	for(int i = n - k; i < n; i++){
		sum1 += abs(a[i]);
		sum2 += abs(b[i]);
	}
	return sum1 > sum2;
}
 
int main() {
	cin >> n >> k;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);
 
	for(int i = n - k; i < n; i++){
		ans = (ans * a[i]) % M;
		if(r_pos == -1 && a[i] > 0) r_pos = i;
		if(r_neg == -1 && a[i] < 0) r_neg = i;
	}
	for(int i = n - k - 1; i >= 0; i--){
		if(l_pos == -1 && a[i] > 0) l_pos = i;
		if(l_neg == -1 && a[i] < 0) l_neg = i;
	}
	
	if(ans < 0 && n != k){
		if(r_pos == -1){
			if(l_pos == -1){
				ans = 1;
				for(int i = 0; i < k; i++)
					ans = (ans * a[i]) % M;
			}
			else {
				swap(a[l_pos], a[r_neg]);
				ans = calc(a);
			}
		}
		else {
			if(l_neg == -1){
				swap(a[l_pos], a[r_neg]);
				ans = calc(a);
			}
			else if(l_pos == -1){
				swap(a[l_neg], a[r_pos]);
				ans = calc(a);
			}
			else {
				vector<int> c1 = a;
				vector<int> c2 = a;
				swap(c1[l_neg], c1[r_pos]);
				swap(c2[l_pos], c2[r_neg]);
				ans = v_cmp(c1, c2) == true? calc(c1): calc(c2);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
