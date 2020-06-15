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

void generate_subset(int start , int a[] , int n , vi &v)
{   
	int sum;
	for(int i=0 ; i < (1<<n) ; i++)
	{   
		sum = 0;
		for(int j=0 ; j<n ; j++)
		{
            if(i &  (1<<j) )
            	sum += a[j + start];
		}

		v.p_b(sum);
	}
}

void solve()
{
   int N,A,B;
   cin>>N>>A>>B;
   int a[N];
   loop(i,0,N) cin>>a[i];
   
   vi left,right;
   vector<int>::iterator low,high;

   generate_subset(0 , a , N/2 , left);    
   generate_subset(N/2 , a , N & 1 ? N/2+1 : N/2 , right);   	 
   sort(right.begin() , right.end());
   
   int ans = 0;
   for(int i=0;i<left.size();i++)
    {
        low=lower_bound(right.begin(),right.end(),A-left[i]);
        high=upper_bound(right.begin(),right.end(),B-left[i]);
        ans+=(high-right.begin())-(low-right.begin());
    }
    cout<<ans<<endl;
}

int32_t main()
{
	c_s();
	io
 	// multipletest
	solve();
}

