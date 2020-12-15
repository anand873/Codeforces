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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

struct PnC
{
	int n;
	vl F,I;
	void init(int n)
	{
		F.resize(n+1);
		I.resize(n+1);
		F[0]=I[0]=1;
		for(int i=1;i<=n;i++)
		{
			F[i]=(F[i-1]*i)%MOD;
			I[i]=powN(F[i],MOD-2);
		}
	}
	ll nCr(int n,int r)
	{
		if(r>n) return 0;
		return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
	}
};

PnC P;
void testcase()
{
	int n,m,k;
	cin>>n;//>>m>>k;
	m = 3;
	k = 2;
	vi A(n);
	take(A,0,n);
	sort(all(A));
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		int low = i+m-1,high = n-1;
		int upto = -1; 
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			// cerr<<mid<<" "<<A[mid]-A[i]<<endl;
			if(A[mid]-A[i]<=k)
			{
				upto = mid;
				low = mid+1;
			}
			else high = mid-1;
		}
		if(upto==-1) continue;
		else
		{
			ans += (ll)(upto-i)*(upto-i-1)/2;
			// ans%=MOD;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	P.init(MAX);
	test()
	{
		testcase();
	}
}	