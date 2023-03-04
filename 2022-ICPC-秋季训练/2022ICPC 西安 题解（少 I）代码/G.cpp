#include <bits/stdc++.h>
using namespace std;

int n;
string s[100005];
set<string> S;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n,[](const string &a,const string &b){
		return a.size()<b.size();
	});
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(s[i].size()==1 || (S.count(s[i].substr(0,s[i].size()-1)) && S.count(s[i].substr(1))))
		{
			S.insert(s[i]);
			res=max(res,(int)s[i].size());
		}
	}
	cout<<res<<endl;
	return 0;
}
