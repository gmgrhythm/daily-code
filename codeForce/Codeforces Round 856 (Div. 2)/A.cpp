#include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
/*
find_by_order ->Let us assume we have a set s : {1, 5, 6, 17, 88}, then :

*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88 
order_of_key ->
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
*/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define ln "\n"
#define pb push_back
#define ppb pop_back
#define pno cout<<"No"<<ln;
#define pyes cout<<"Yes"<<ln;
// #define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
// #define int long long
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll Sinf = 1e18;
const ll inv100 = 828542813;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//-----------------------@######################@----------------------------//
#ifndef ONLINE_JUDGE
int debugval = 0;
#define debug(x) cerr << #x <<debugval++<<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//----------------------@######################@---------------------------//
ll pw(ll a, ll b){
  if(b < 0)
    return 0;
  ll ans = 1LL;
  while(b){
    if(b%2){
      ans = (ans * a),b--;
      continue;
    }
    b = b/2;
    a = (a * a);

  }
  return ans;
}
ll pww(ll a, ll b,ll md){
  ll ans = 1LL;
  while(b){
    if(b%2){
      ans = (ans%md * a%md)%md,b--;
      continue;
    }
    b = b/2;
    a = (a%md * a%md)%md;

  }
  return ans%md;
}
/* ascii value
A=65,Z=90,a=97,z=122
char('B' + 'a' - 'A');
*/
double squareRoot(double n)
{
    return pow(2, 0.5*log2(n));
}
  long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
unordered_set<ll>prime;

void primeFind(){
   vector<ll>check(5000005,0);
   for(ll i = 2; i < 5000005; i++){
     if(check[i] == 0){
      prime.insert(i);
       for(ll j = i * i ; j < 5000005; j = j + i){
              check[j] = 1;
       }
     }
   }
}


vector<vector<ll>>adj;
vector<ll>check;
vector<ll>build,lazzy;

// vector<int>par;
int cnt = 0;
void dfs(int node){
   check[node] = 1;
   build.push_back(node);
   for(auto I : adj[node]){
        if(check[I] == 0){
          dfs(I);
        }
   }
   

}
//dp(dp -> state[i,j] = ans),gready,binarySearch,recursive,
vector<ll>par;
ll find(ll node){
   if(node == par[node])
     return par[node];
   return par[node] = find(par[node]);
}
void merge(ll node1, ll node2){
   ll par1 = find(node1);
   ll par2 = find(node2);
   if(par1 == par2)
     return;
   par[par1] = par2;
}

// void buildd(ll idx, ll start, ll end){
//   if(start == end){
//      build[idx] = arr[start];
//      return;
//   }
//   ll mid = (start + end)/2;
//   buildd(idx * 2,start,mid);
//   buildd(idx * 2 + 1,mid + 1,end);
// }
// void propogate(ll idx,ll start,ll end){
//    if(start == end){
//        return;
//    }
//    lazzy[idx * 2] += lazzy[idx];
//    lazzy[idx * 2 + 1] += lazzy[idx];
//    lazzy[idx] = 0;
// }
// void update(ll idx, ll start, ll end, ll ustart, ll uend){
//     if(start > uend || end < ustart)
//        return;
//     if(start == end){
//      lazzy[idx]++;
//      return;
//     }
//     if(ustart <= start && end <= uend){
//        lazzy[idx]++;
//        return;
//     }
//     ll mid = (start + end)/2;
//     update(idx * 2,start,mid,ustart,uend);
//     update(idx * 2 + 1, mid + 1, end,ustart,uend);
// }
// void find_value(ll idx){
//    while(lazzy[idx] > 0 && build[idx] > 9){
//       ll temp = build[idx];
//       ll sum = 0;
//       while(temp > 0){
//          sum = sum + temp%10;
//          temp = temp/10;
//       }
//       build[idx] = sum;
//       lazzy[idx]--;
//    }
// }
// ll query(ll idx, ll start, ll end, ll find){
 
//   if(start == end){
//      find_value(idx);
//     return build[idx];
//   }
//   propogate(idx,start,end);
//   ll mid = (start + end)/2;
//   if(mid >= find)
//    return query(idx * 2,start,mid,find);
//   else'
//    return query(idx * 2 + 1,mid + 1,end,find);

// }

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(int i = 0; i < n; i++)
     cin>>arr[i];
  ll odd = 0,even = 0;
  for(auto I : arr){
     if(I%2)
       odd++;
     else
      even++;
  }
  if(odd%2 == 0){
     if((odd/2)%2 == 0){
       cout<<"Alice"<<ln;
       return;
     }
     cout<<"Bob"<<ln;

  }
  else{
      if((odd/2)%2){
         cout<<"Alice"<<ln;
         return;
      }
      if(even%2 == 1)
         cout<<"Alice"<<ln;
       else
        cout<<"Bob"<<ln;
  }

}
int main() {   
ios_base::sync_with_stdio(false);
cin.tie(NULL); 

#ifndef ONLINE_JUDGE

  freopen("Error.in", "w", stderr);
#endif
  // primeFind();
    int t;
    // t = 1;
    cin>>t;
    while(t--){
      solve();
    } 
}
/* -----------------END OF PROGRAM --------------------*/
/*
* stuff you should look before submission
* constraint and time limit
* int overflow
* special test case (n=0||n=1||n=2)
* don't get stuck on one approach if you get wrong answer
*/


 //  * a+b=a|b+a&b
 // * a+b=a^b+2*(a&b)

// 10 Steps to Solve Any Problems:
//0.Read question carefuly.. make sure you read  every thing which is important for solving the problem don 't hurry you can do it!! 
// 1.Read the problem completely at least two or three times (or however many makes you feel comfortable)
// 2.Identify the subject, the problem belongs to. Is it a sorting or pattern matching problem?

//   Can I use graph theory? Is it related to number theory? etc.
// 3.Try to solve the problem manually by considering 3 or 4 sample data sets.
// 4.After concentrate on optimizing the manual steps. Try to make it as simple as possible.
// 5.Write to write pseudo-code and comments besides the code from the manual steps.

//   One thing you can do is to check after every function is written. Use a good IDE with a debugger, if possible.
//   Don’t need to think much about the syntax. Just focus on the logic and steps.
// 6.Replace the comments or pseudo-code with real code.
//   Always check if the values and code are behaving as expected before moving to the new line of pseudo-code.
// 7.Then optimize the real code.
// 8.Take care of boundary conditions as well.
// 9.Get feedback from your teammates, professors, and other developers and also ask your question on Stack Overflow if possible.
//   Try to learn from others’ guidelines and what they are handling those problems. A problem may be solved in several ways.
//   So, don’t get disappointed if you can’t think like an expert.
//   You need to stick to the problem and you will gradually become better and quicker in solving problems like others.

// 10.Practice, Practice, and Practice.`
//