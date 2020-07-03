#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define vpii             vector<pii>
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
string make_beautiful(string x , int k){for(int i = k; i<x.size();i++){ x[i]=x[i-k];}return x;
}
 
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

bool comparator(pii a , pii b)
{

	if(a.first == b.first)
	{
		if(a.second < b.second) return true;
	    else 
		return false;
	}

	else if(a.first > b.first) return true;
    else return false;

}

void solve()
{
	int n,k;
	cin>>n>>k;

    vi a(n);
    
    loop(i,0,n) cin>>a[i];

    vpii store(30);

    for(int i=0;i<30;i++)
    {
    	store[i].first = 0;
    	store[i].second = i;
    }

    for(int i=0 ;i < n ; i++)
    {
    	for(int j=0; j < 30 ; j++)
    	{
    		 if(a[i] & (1<<j))
    		 	store[j].first += (1<<j);
    	}
    }

    sort(store.begin(), store.end() , comparator);
    
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans += (1<<(store[i].second));
    }

    cout<<ans<<endl;
}

int32_t main()
{
	c_s();
	io
 	multipletest
	solve();
}
s