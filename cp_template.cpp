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

void solve()
{
	int n,m;
	cin>>n>>m;

	vi a(n);
	set<int>st;

	loop(i,0,n){ 
	  cin>>a[i];
	  st.insert(a[i]);
	}
    
    sort(a.begin(), a.end());
    
    int cnt =0;
    int prev = m;

    for(int i=n-1;i>=0;i--)
    {
    	if(a[i] == m) continue;

    	if(a[i] < m)
    	{
    		if( prev - a[i] >= 2) break;
    		else prev = a[i];
    	}
        
        cnt++;
    }
    
cout<<cnt<<endl;

}

int32_t main()
{
	c_s();
	io
 	multipletest
	solve();
}

