#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define setbits(x)       __builtint_popcountll(x) //return no. of set bits in x
#define zerobits(x)      __buitlin_ctzll(x)       // return no. of zeroes after first set bit
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define multipletest     int t;cin>>t;while(t--) 
bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}
 
void c_s()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	   freopen("input1.txt","r",stdin);
	   freopen("output1.txt","w",stdout);
	#endif
}

long long binpow(long long a, long long b) {long long res = 1; while (b > 0) { if (b & 1) res = res * a;a = a * a;b >>= 1;}return res;}
 
// for GCD -> __gcd(a,b);
 
int LCM(int x , int y) { return (x * y)/__gcd(x,y); }
 
const int mod = 100000;
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

void insert(stack<int>st , int x)
{
	if(st.size() == 0)
	{
		st.push(x);
		return;
	}
    int y = st.top();
    st.pop();
	insert(st,x);
	st.push(y);
}


void reverse(stack<int>st)
{
	if(st.size() == 0) return;

	int x = st.top();
	st.pop();

	reverse(st);

	insert(st,x);
}

void solve()
{	
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	reverse(st);

	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
}

int32_t main()
{
	c_s();
	io
 	multipletest
	solve();
}

