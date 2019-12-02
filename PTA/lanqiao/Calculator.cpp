#include<iostream>
#include<cmath>
#include<string>
using namespace std;
long long DCHANGE(string s, int Ary)
{
	long long t = 0,PO = 1;
	for (int i = s.length() - 1, j = 0; i >= 0; i--, j++)
	{
		if (isdigit(s[i]))
			t += (s[i] - '0')*PO;
		else
			t += (s[i] - 'A' + 10)*PO;
 
		PO = PO * Ary;
	}
	return t;
}
string RCHANGE(long long t, int k)
{
	string num;
 
	if(t==0)num="0";
	while (t)
	{
		char c;
		if (t%k < 10)
			c = t % k + '0';
		else
			c = (t % k - 10) + 'A';
 
		num = c + num;
 
		t = t / k;
	}
	return num;
}
class Calculator
{
public:
	Calculator() { Ary=10; }
	void NUM(string s) { num = s; }
	void CHANGE(int k) {
		num = RCHANGE(DCHANGE(num, Ary), k);
		Ary = k;
	}
	void ADD(string s) {
		long long sum = DCHANGE(num, Ary) + DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void SUB(string s) {
		long long sum = DCHANGE(num, Ary) - DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void MUL(string s) {
		long long sum = DCHANGE(num, Ary) * DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void DIV(string s) {
		long long sum = DCHANGE(num, Ary) / DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void MOD(string s) {
		long long sum = DCHANGE(num, Ary) % DCHANGE(s, Ary);
		num = RCHANGE(sum, Ary);
	}
	void EQUAL() { cout << num << endl; }
	void CLEAR() { num.clear();}
private:
	int Ary;	//进制
	string num;
};
int main()
{
	int N;
	cin >> N;
 
	Calculator ST;
 
	int flag;
	for(int i=0;i<N;i++)
	{
		int t;
		string s,st;
		cin >> s;
		if (s == "CLEAR")
        {
            ST.CLEAR();
            flag = 0;
        }
		else if (s == "NUM")
		{
			cin >> st;
			switch(flag)
			{
            case 0:ST.NUM(st);break;
            case 1:ST.ADD(st);break;
            case 2:ST.SUB(st);break;
            case 3:ST.MUL(st);break;
            case 4:ST.DIV(st);break;
            case 5:ST.MOD(st);break;
			}
		}
		else if (s == "CHANGE")
		{
			cin >> t;
			ST.CHANGE(t);
		}
		else if (s == "ADD")
		    flag = 1;
		else if (s == "SUB")
		    flag = 2;
		else if (s == "MUL")
            flag = 3;
		else if (s == "DIV")
            flag = 4;
		else if (s == "MOD")
			flag = 5;
		else if (s == "EQUAL")
			ST.EQUAL();
	}
	return 0;
}
