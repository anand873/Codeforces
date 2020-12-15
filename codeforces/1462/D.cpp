//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

void testcase()
{
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	int sum = 0;
	for(auto a:A) sum += a;

	set<int> D;
	for(int i=1;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			if(i <= n) D.insert(i);
			if(sum/i <= n) D.insert(sum/i);
		}
	}
	int ans = n-1;
	for(auto d:D)
	{
		int val = sum/d;
		bool can=true;
		int curr=0;
		for(int i=0;i<n;i++)
		{
			curr+=A[i];
			if(curr==val) curr=0;
			else if(curr>val) can=false;
		}
		if(can) ans = min(ans,n-d);
	}
	cout<<ans<<endl;
}

int main()
{
	test()
	{
		testcase();
	}
}	