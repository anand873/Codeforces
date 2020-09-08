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
	int n;
	cin>>n;
	vi A(n+1);
	vector<int> In;
	for(int i=0;i<n;i++)
	{
		In.push_back(i+1);
	}
	while(In.size()>1)
	{
		vi Temp;
		for(int i=0;i<In.size()-1;i+=2)
		{
			cout<<"? "<<In[i]<<" "<<In[i+1]<<endl;
			int left;
			cin>>left;
			cout<<"? "<<In[i+1]<<" "<<In[i]<<endl;
			int right;
			cin>>right;
			if(left<right)
			{
				A[In[i+1]] = right;
				Temp.push_back(In[i]);
			}
			else
			{
				A[In[i]] = left;
				Temp.push_back(In[i+1]);
			}
		}
		if(In.size()%2) Temp.push_back(In.back());
		In = Temp;
	}

	set<int> S;
	for(int i=0;i<n;i++) S.insert(i+1);
	for(int i=1;i<=n;i++)
	{
		if(S.count(A[i])) S.erase(A[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(A[i]==0) A[i] = * (S.begin());
	}
	cout<<"!";
	for(int i=1;i<=n;i++) cout<<" "<<A[i];
	cout<<endl;

}	