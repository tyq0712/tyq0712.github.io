#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int maxn=1e3+10;
int a[maxn];
int head[maxn],to[maxn],nxt[maxn],tot;
void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
const int mod=1e9+7;
int qpow(int a,int b=mod)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int son[202][202];
int dep[404];
int f[404][10];
vector<int>v[202];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		f[v][0]=x;
		dfs(v,x);
	}
}
int lca(int x,int y)
{	
	if(dep[x]<dep[y])swap(x,y);
	down(i,9,0)
	{
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	
	if(x==y)return x;
	down(i,9,0)
	{
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}

	return f[x][0];
}
int dp[202][202];
signed main()
{
	up(i,1,200)dp[0][i]=1;
	up(i,1,200)up(j,1,200)dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod*qpow(2,mod-2)%mod;
	n=read();
	up(i,1,n-1)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	int ans=0;
	up(i,1,n)
	{
		int sum=0;
		memset(f,0,sizeof(f));
		memset(dep,0,sizeof(dep));
		dfs(i,0);
		up(j,1,9)
		{
			up(k,1,n)f[k][j]=f[f[k][j-1]][j-1];
		}
		up(j,1,n)
		{
			up(k,1,n)
			{
				if(j>=k)continue;
				int nw=lca(j,k);
				int f1=dep[j]-dep[nw];
				int f2=dep[k]-dep[nw];
				sum+=dp[f2][f1];
				sum%=mod;
			}
		}
		ans+=sum;
		ans%=mod;
	}
	cout<<ans*qpow(n,mod-2)%mod;
}
