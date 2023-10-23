#include<bits/stdc++.h>
using namespace std;
//MCM, //LPS, //CODECHEF HARRY POTTER

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
#define vi vector<ll>
#define inf 10e8 + 1
#define mp make_pair
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define revloop(i, a, b) for(int i =(b); i>=(b); i--)

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
	int dp[405][405];
	int sum[405][405];

ll slimes(vi& arr,int i, int j){
	if( i == j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	ll mincost = inf;
	loop(k, i, j-1){
		mincost = min({ 
			mincost, slimes(arr, i, k) + slimes(arr, k+1, j) + sum[i][j] });
	} 
	return dp[i][j] = mincost;
}
int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		ll n, k;
		cin>>n;
		vi a(n+1, 0);
		loop(i, 1, n){ cin>> a[i]; }

		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		loop(i, 1, n){
			loop(j, i, n){
				sum[i][j] = a[j] + ((i==j) ? 0 : sum[i][j-1]);
			}
		}
		cout<<slimes(a, 1, n);

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}