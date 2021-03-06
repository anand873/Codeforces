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

int main()
{
	fastio
	
	int n;
	cin>>n;
	vi A(n+1);
	take(A,1,n);
	vi I(n+1);
	for(int i=1;i<=n;i++) I[A[i]] = i;
	vi W(n+1);
	W[n] = 0;
	for(int i=n-1;i>0;i--)
	{
		bool good = false;
		int st = I[i];
		for(int in=st+i;in<=n;in+=i)
		{
			if(A[in]>i&&W[A[in]]==0) 
			{
				good = true;
			}
		}
		for(int in=st-i;in>0;in-=i)
		{
			if(A[in]>i&&W[A[in]]==0) 
			{
				good = true;
			}
		}
		if(good) W[i] = 1;
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		if(W[A[i]]==1) s += 'A';
		else s += 'B';
	}
	cout<<s<<endl;
}	