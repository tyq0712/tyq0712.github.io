#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
#define _ 2000005
char sps[10] = { '$', '%', '^', '&', '*' };
struct SuffixAutomaton {
  int tr[_][26], las=1, tot=1, len[_], fail[_], end[_];
  void insert(char ch) {
  int p=las, q, cur=las=++tot; len[cur]=len[p]+1; end[cur]=1;
  while(p && !tr[p][ch]) { tr[p][ch]=cur; p=fail[p]; }
  if(!p) fail[cur]=1;
  else {
    q=tr[p][ch];
    if(len[q]==len[p]+1) fail[cur]=q;
    else {
      int nw=++tot; len[nw]=len[p]+1; fail[nw]=fail[q]; memcpy(tr[nw], tr[q], sizeof(tr[nw]));
      while(p && tr[p][ch]==q) { tr[p][ch]=nw; p=fail[p]; }
      fail[cur]=fail[q]=nw;
    }
  }
}
  void build(char* str) {f(i,1,strlen(str+1)) insert(str[i]-'a');}
} sam;
char s[200510]; int n, nl=1;
int main() {
  rd(n); 
  f(i,1,n) {
    scanf("%s", s[i]+nl);
    s[strlen(s+1)+1]=sps[i];
    nl = strlen(s+1)+1;
  }
  return 0;
}