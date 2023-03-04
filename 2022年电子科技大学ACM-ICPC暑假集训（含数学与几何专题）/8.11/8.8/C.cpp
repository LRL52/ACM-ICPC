#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const double eps=1e-12;
const double INF=2000093000.443;
double SQR(double x){return x*x;}
int sgn(double x){
    if(-eps<x&&x<eps)return 0;
    else if(x<=-eps)return -1;
    else return 1;
}
struct point{
    int x,y,h;
    point(int _x,int _y,int _h){
        x=_x;
        y=_y;
        h=_h;
    }
    /*
    double dis_t(point B){
        return sqrt((x-B.x)*(x-B.x)+(y-B.y)*(y-B.y));
    }
    */
};
double dis[54][54][54],mp[64][64];
queue<point>q;
int n;
int h[54];
void work(int rik,int con,int hei,double val){
    //cout<<rik<<" "<<con<<" "<<hei<<" "<<val<<" "<<dis[rik][con][hei]<<endl;
    if(dis[rik][con][hei]>val){
        dis[rik][con][hei]=val;
        q.push(point(rik,con,hei));
    }
}
int w33ha(){
    scanf("%d",&n);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            for(int k=0;k<=51;k++){
                dis[i][j][k]=INF;
            }
        }
    }
    while(!q.empty())q.pop();
    for(int i=0;i<=n;i++)scanf("%d",&h[i]);
    dis[0][n][0]=0;
    q.push(point(0,n,0));
    while(!q.empty()){
        point now=q.front();q.pop();
        int r,c,hi;
        r=now.x;c=now.y;hi=now.h;
        if(r>0&&hi==h[r]){
            work(r-1,c,hi,(h[r]==h[r-1])+dis[r][c][hi]);
        }
        if(c>0&&hi==h[c]){
            work(r,c-1,hi,(h[c]==h[c-1])+dis[r][c][hi]);
        }
        if(r<n&&hi==h[r+1]){
            work(r+1,c,hi,(h[r]==h[r+1])+dis[r][c][hi]);
        }
        if(c<n&&hi==h[c+1]){
            work(r,c+1,hi,(h[c]==h[c+1])+dis[r][c][hi]);
        }
        if(c<n&&r<n){
            if(min(h[r],h[r+1])<=hi-1&&max(h[r],h[r+1])>=hi-1&&min(h[c],h[c+1])<=hi-1&&max(h[c],h[c+1])>=hi-1){
                work(r,c,hi-1,dis[r][c][hi]+mp[h[r]][h[r+1]]+mp[h[c]][h[c+1]]);
            }
            if(min(h[r],h[r+1])<=hi+1&&max(h[r],h[r+1])>=hi+1&&min(h[c],h[c+1])<=hi+1&&max(h[c],h[c+1])>=hi+1){
                work(r,c,hi+1,dis[r][c][hi]+mp[h[r]][h[r+1]]+mp[h[c]][h[c+1]]);
            }
        }
    }
    printf("%.15f\n",dis[n][0][0]);
    return 0;
}
void prework(){
    for(int i=0;i<=60;i++){
        for(int j=0;j<=60;j++){
            if(i!=j){
                mp[i][j]=sqrt(SQR(i-j)+1)/(1.0*abs(i-j));
            }
        }
    }
}
int main(){
    prework();
    int T;scanf("%d",&T);
    while(T--)w33ha();
    return 0;
}
