//Author: AnandRaj uux
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
	int curr_t = 0;
	int curr_x = 0;
	vpll C(n+2);
	C[0].first = 0;
	C[0].second = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>C[i].first>>C[i].second;
	}
	C[n+1].first = INF;

	int active = 1;
	vpll T(n+1);
	T[1].first = 0;
	if(C[1].second<0) T[1].second = max(C[1].second,-C[2].first+C[1].first);
	else T[1].second = min(C[1].second,C[2].first-C[1].first);

	for(int i=2;i<=n;i++)
	{
		if(C[active].second==T[i-1].second)
		{
			active = i;
		}
		T[i].first = T[i-1].second;
		if(C[active].second<T[i-1].second) T[i].second = max(C[active].second,T[i-1].second-C[i+1].first+C[i].first);
		else T[i].second = min(C[active].second,T[i-1].second+C[i+1].first-C[i].first);
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		// prinp(T[i]);
		if(T[i].first>T[i].second) swap(T[i].first,T[i].second);
		if(C[i].second>=T[i].first&&C[i].second<=T[i].second) ans++;
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