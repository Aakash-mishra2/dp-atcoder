#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
#define vi 		vector<ll> 
#define mod 	1e10 + 7
#define inf 	10e8 + 1
#define mp 		make_pair
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define looprev(i, a, b) for(int i =(a); i>=(b); i--)

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
int dp[105][100005];
ll candies(vi &arr, ll n, ll k){
	loop(j, 0, k){
		dp[1][j] = (j > arr[1]) ? 0: 1;
	}
	loop(i,2,n) {
		loop(j, 0, k) {
		if(j == 0) { dp[i][j] = dp[i-1][j]; //cannot give any candies
			}else{
			// dp[i][j] = (mod + dp[i][j-1]%mod + dp[i-1][j]%mod - ((j-1-arr[i] >= 0) ? dp[i-1][j-1-arr[i]]%mod : 0))%mod;
			dp[i][j] = (dp[i][j-1] + dp[i-1][j] - ((j-1-arr[i] >= 0) ? dp[i-1][j-1-arr[i]] : 0));

			}
		}
	}
	return dp[n][k];
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		

		ll n, k;
		cin>>n>>k;
		memset(dp, 0, sizeof(dp));
		vi arr(n+1, 0);
		loop(i, 1, n){
			cin>>arr[i];
		}
		cout<<candies(arr, n, k);

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}