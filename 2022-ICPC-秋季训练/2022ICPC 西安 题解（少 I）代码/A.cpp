#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int inf=1039741778;

int n,m,q;
const int B=200;
vector<pii> swaps[100005];
vector<pii> queries;
int key[100005];
int cur[100005];
int pos[100005];
int tpos[100005];
int cnt;

struct HashInt
{
	int operator () (int x)
	{
		x^=(x>>13);
		return x;
	}
};

template <typename Key,typename Value,typename Hash,int N,int mod>
struct HashTable
{
	int head[mod+5];
	int nxt[N+5];
	Value val[N+5];
	Key key[N+5];
	Hash hash;
	int cnt;
	HashTable():cnt(1){}
	inline bool exist(const Key &k)
	{
		int t=hash(k)%mod;
		for(int i=head[t];i;i=nxt[i])
		{
			if(key[i]==k) return true;
		}
		return false;
	}
	inline Value& at(const Key &k)
	{
		int t=hash(k)%mod;
		for(int i=head[t];i;i=nxt[i])
		{
			if(key[i]==k) return val[i];
		}
		key[cnt]=k;
		nxt[cnt]=head[t];
		head[t]=cnt;
		assert(cnt<=N);
		return val[cnt++];
	}
	inline Value& operator [] (const Key &k)
	{
		return at(k);
	}
	inline void clear()
	{
		cnt=1;
		memset(head,0,sizeof(head));
	}
};

namespace FastIO
{
    const int MaxBufSize=1024*1024;
    char buf[MaxBufSize+5];
    int cursor=MaxBufSize;
    inline char getchar()
    {
        if(cursor==MaxBufSize)
        {
            fread(buf,1,MaxBufSize,stdin);
            cursor=0;
        }
        return buf[cursor++];
    }
    inline ll getnum()
    {
        static ll res;
        static char c;
        static int mut;
        res=0;
        c=0;
        mut=1;
        while(!isdigit(c) && c!='-') c=getchar();
        if(c=='-')
        {
            mut=-1;
            c=getchar();
        }
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res*mut;
    }
} // namespace FastIO
using FastIO::getnum;

HashTable<int,int,HashInt,400,503> M[405];
int a[B+5],b[B+5];
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("t40.in","r",stdin);
	// freopen("2.out","w",stdout);
	n=getnum();m=getnum();q=getnum();
	vector<int> v;
	for(int i=0;i<(q+B-1)/B;i++)
	{
		queries.clear();v.clear();
		for(int j=i*B;j<min(q,(i+1)*B);j++)
		{
			int type=getnum(),x=getnum(),y;
			if(type==2) queries.emplace_back(j,--x);
			else
			{
				y=getnum();
				swaps[--y].emplace_back(j,--x);
			}
		}
		memset(key,-1,sizeof(int)*n);
		iota(cur,cur+n,0);
		cnt=0;
		for(auto &o:queries)
		{
			int x=o.second;
			if(key[x]==-1) key[x]=cnt++,v.emplace_back(x);
		}
		for(int j=0;j<m;j++)
		{
			for(auto &o:swaps[j])
			{
				int &x=cur[o.second],&y=cur[o.second+1];
				swap(x,y);
				if(o.first/B!=i) continue;
				if(key[x]==-1) key[x]=cnt++,v.emplace_back(x);
				if(key[y]==-1) key[y]=cnt++,v.emplace_back(y);
			}
		}
		iota(cur,cur+n,0);
		iota(pos,pos+n,0);
		for(int j=0;j<cnt;j++) tpos[j]=pos[v[j]];
		int len=0;
		for(int j=0;j<m;j++)
		{
			for(auto &o:swaps[j])
			{
				// debug(o);
				int &x=cur[o.second],&y=cur[o.second+1];
				if(o.first/B==i)
				{
					// if(i==1) debug(pos[2]);
					for(int k=0;k<cnt;k++)
					{
						M[len][tpos[k]]=pos[v[k]];
					}
					a[len]=o.first;b[len]=o.second;
					len++;
				}
				swap(x,y);
				// if(i==1) debug(o,pos[2]);
				swap(pos[x],pos[y]);
				// if(i==1) debug(tpos[0],tpos[1],tpos[2]);
				if(o.first/B==i)
				{
					// if(i==1) debug(pos[0],pos[1],pos[2]);
					for(int k=0;k<cnt;k++)
					{
						tpos[k]=pos[v[k]];
					}
				}
			}
		}
		// debug(v,tpos[0],tpos[1],tpos[2]);
		assert(v.size()==cnt);
		for(int k=0;k<cnt;k++)
		{
			M[len][tpos[k]]=pos[v[k]];
		}
		// cout<<len<<endl;
		a[len]=inf;
		len++;
		// if(i==1)
		// {
		// 	for(auto &o:M[1]) cout<<o.first<<','<<o.second<<endl;
		// }
		// for(int j=0;j<len;j++)
		// {
		// 	cout<<a[j]<<','<<b[j]<<endl;
		// }
		// cout<<endl;
		for(auto &o:queries)
		{
			int T=o.first,pos=o.second;
			// debug(T,pos);
			for(int j=0;j<len;j++)
			{
				// debug(a[j],b[j]);
				pos=M[j][pos];
				if(a[j]<T)
				{
					if(b[j]==pos) pos=b[j]+1;
					else if(b[j]==pos-1) pos=b[j];
				}
			}
			printf("%d\n",pos+1);
			// cout<<pos+1<<endl;
		}
		for(int j=0;j<len;j++)
		{
			// cout<<M[j].size()<<endl;
			M[j].clear();
		}
	}
	return 0;
}
