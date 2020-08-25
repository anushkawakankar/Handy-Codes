#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define pii pair<int,int>
#define ll unsigned long long

vector<pii> v;

ll calc( ll n ) {
  ll ans = 0;
  for( auto x : v )
  {
    if( x.second == 1 )
      ans += n/x.first;
    else
      ans -= n/x.first;
  }
  return ans;
}

int main() {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);
  int a[n];
  for( int i=0; i<n; ++i )
    scanf("%d", a+i);
  for( int j=1; j<(1<<n); ++j )
  {
    int c = -1;
    ll l = 1;
    for( int x=j, i=0; i<n; ++i, x>>=1 )
    {
      if( x&1 ) {
        c = -c;
        if( l < 10000000000000000ll )
        l = a[i]/__gcd(l,(ll)a[i]) * l;
      }
    }
    // printf("%lld %d\n", l, c);
    v.push_back({l, c});
  }
  ll m;

  for( ll l=1, r=10000000000000000ll - 1; l < r; )
  {
    m = (l+r)/2;
    // printf("%lld %lld %lld %lld\n", l, m, r, calc(m));
    if( calc(m) >= k )
      r = m;
    else
      l = m+1;
    m = (l+r)/2;
  }
  printf("%lld\n", m);
}
