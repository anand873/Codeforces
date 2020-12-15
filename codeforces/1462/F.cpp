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

bool cmp(pair<pii,int> A,pair<pii,int> B)
{
	if(A.first.second==B.first.second) return A.first.first<B.first.first;
	else return A.first.second<B.first.second;
}

void testcase()
{
	int n;
	cin>>n;
	vector<pair<pii,int>> LR(n);
	for(int i=0;i<n;i++)
	{
		cin>>LR[i].first.first>>LR[i].first.second;
		LR[i].second=i;
	}
	sort(all(LR));
	vi dpL(n),dpR(n);
	
	multiset<int> EP;
	EP.insert(LR[0].first.second);
	for(int i=1;i<n;i++)
	{
		dpL[LR[i].second] = dpL[LR[i-1].second];
		while(!EP.empty()&&*(EP.begin())<LR[i].first.first)
		{
			dpL[LR[i].second]++;
			EP.erase(EP.find(*EP.begin()));
		}
		EP.insert(LR[i].first.second);
	}
	sort(all(LR),cmp);
	multiset<int> SP;
	SP.insert(LR[n-1].first.first);
	for(int i=n-2;i>=0;i--)
	{
		dpR[LR[i].second] = dpR[LR[i+1].second];
		while(!SP.empty()&&*(SP.rbegin())>LR[i].first.second)
		{
			dpR[LR[i].second]++;
			SP.erase(SP.find(*SP.rbegin()));
		}
		SP.insert(LR[i].first.first);
	}	
	// prinv(dpL);
	// prinv(dpR);
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans = max(ans , n - (dpL[i]+dpR[i]));
	}
	cout<<n - ans<<endl;
}

int main()
{
	test()
	{
		testcase();
	}
}	