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

struct DSU
{
	vi weight,parent;
	void init(int n)
	{
		weight.resize(n+1);
		parent.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			parent[i]=i;
			weight[i]=1;
		}
	}
	int find_set(int a)
	{
		if(parent[a]==a) return a;
		else return parent[a]=find_set(parent[a]);
	}
	bool union_set(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if(a!=b)
		{
			if(weight[a]>weight[b]) swap(a,b);
			parent[a] = b;
			weight[b] += weight[a];
			return true;
		}
		return false;
	}
};

void test_case()
{
	int n,m;
	cin>>n>>m;
	DSU T;
	T.init(n);
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==y) continue;
		ans++;
		if(!T.union_set(x,y)) ans++;
	}
	cout<<ans<<"\n";
}

int main()
{
	fastio
	test()
	{
		test_case();
	}
}	