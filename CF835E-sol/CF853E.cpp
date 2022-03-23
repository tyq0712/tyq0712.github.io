#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back 
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
int n; ll x, y, ans[10]; vector<int> Set;
int main() {
  cin >> n >> x >> y;
  f(i,0,9) {
    vector<int> query;
    f(j,1,n) if((j>>i)&1) query.pb(j);
    if(query.empty()) continue;
    cout<<"? "<<query.size()<<" "; for_each(query.begin(), query.end(), [](const int& x){cout << x << ' ';}); cout << endl;
    cin >> ans[i]; ll expans = (query.size()&1)*x;
    if(ans[i] == expans) ans[i]=0;
    else ans[i]=1;
  }
  f(i,0,9) if(ans[i]) { f(j,1,n) if((j>>i)&1) Set.pb(j); break; }
  // for_each(Set.begin(), Set.end(), [](const int& x){cout << x << ' ';}); cout << endl;
  while(Set.size()>1) {
    vector<int> query, unquery; for(int i=0; i<Set.size(); ++i) if(i<Set.size()/2) query.pb(Set[i]); else unquery.pb(Set[i]);
    // cerr << "query.size = " << query.size() << endl;
    cout<<"? "<<query.size()<<" "; for_each(query.begin(), query.end(), [](const int& x){cout << x << ' ';}); cout << endl;
    ll ans; cin >> ans; ll expans = (query.size()&1)*x;
    if(ans == expans) std::swap(unquery, Set);
    else std::swap(query, Set);
  }
  int ans0=Set[0], ans1=Set[0];
  f(i,0,9) ans1 ^= (ans[i]*(1<<i));
  // cerr <<"ans "; f(i,0,9) cout << ans[i] << " \n"[i==9];
  if(ans1<ans0) std::swap(ans0, ans1);
  cout << "! " << ans0 << ' ' << ans1 << endl;
  return 0;
}