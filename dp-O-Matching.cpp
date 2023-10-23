#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

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
	ll dp[22][1<<22];
	ll matching(vector<vector<int>> &compat, int i, int mask, int n){
		if(i == n+1){
			if(mask == 0) return 1;
			return 0;
		}
		if(dp[i][mask] != -1) return dp[i][mask];
		ll ans = 0;
		loop(women, 0, n-1){
			bool available = (((1<<i)&(mask)) == 0) ? 0 : 1;
			if(available and compat[i][w+1] == 1){
				ans = ((ans%mod) + (matching(compat, i+1, mask^(1<<w), n)%mod))%mod;
			}
		}
		return dp[i][mask] = ans;
	}	
		
int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		int n;
		cin>>n;
		vector<vector<int>> compat(n+1, vector<int>(n+1));
		memset(dp, -1, sizeof(dp));
		loop(i, 1, n){
			loop(j, 1, n) {
				cin>>compat[i][j];
			}
		}

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}