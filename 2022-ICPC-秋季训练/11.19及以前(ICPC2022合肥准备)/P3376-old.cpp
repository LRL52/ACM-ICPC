/*
Problem:P3376 【模板】网络最大流 复习
User:LRL
Algorithm:最大流复习
Date:2019.4.7 
*/
#define debug printf("Passing [%s] in Line %d ...\n",__FUNCTION__,__LINE__)
#define ri int 
#define ll long long
#define ci const int&
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define dwn(i,a,b) for(ri i=(a);i>=(b);--i)
#define ee(i,a) for(ri i=head[a];~i;i=e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N=10055;
const int M=100055;
const int inf=0x3f3f3f3f;
char ss[1<<21],*A=ss,*B=ss,c;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<21,stdin),A==B)?EOF:*A++;}
template<class T>void rd(T&x){
	ri f=1;c=gc();x=0;while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();};
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=gc();}x*=f;
}
//#define int long long
int ct,head[N],s,t,n,m,ans=0,cur[N],dis[N];
queue<int> q;
struct EDGE{
	int w,nxt,v;
}e[M<<1];

inline void adde(ci from,ci to,ci w){
	e[ct].w=w;//由于有^1,所以从边从0开始编号，初始head要赋值为-1 
	e[ct].v=to;
	e[ct].nxt=head[from];
	head[from]=ct++;
}

int BFS(){
	memset(dis,-1,sizeof(dis));
	dis[s]=0;q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();
		ee(i,now){
			int v=e[i].v;
			if(dis[v]==-1&&e[i].w>0){
				dis[v]=dis[now]+1;
				q.push(v);
			} 
		}
	} 
	return dis[t]!=-1;
}

int max_flow(int x,int flow){
	if(x==t)return flow;
	int tf=flow;
	for(ri &i=cur[x];~i;i=e[i].nxt){
		int v=e[i].v;
		if(dis[v]==dis[x]+1){
			int dx=max_flow(v,min(tf,e[i].w));
			e[i].w-=dx;e[i^1].w+=dx;
			tf-=dx;
			if(tf==0)break;
		}
	}
	return flow-tf;
}

//#undef int
int main()
{
    freopen("P3376_5.in", "r", stdin);
	memset(head,-1,sizeof(head)); 
	rd(n),rd(m),rd(s),rd(t);
	int x,y,z;
	rep(i,1,m){
		rd(x),rd(y),rd(z);
		adde(x,y,z);
		adde(y,x,0);//虽然是有向图，还是要建双向边，作为残量网络回路 
	}
	while(BFS()){
		rep(i,1,n)cur[i]=head[i];
		ans+=max_flow(s,inf); 
	}
	printf("%d\n",ans);
	//printf("\n内存消耗：%.3lf M",(double)sizeof(e)/(1<<20));
	return 0;
}