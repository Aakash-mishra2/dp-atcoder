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
		


int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		int n, w;
		cin>>n>>w;
		//SPACE OPTIMIZATION : TWO 1D ARRAYS
		// vector<vector<int>> dp(n+1, vector(int)(w+1, 0));
		// int wt[n], val[n];
		// 	loop(i, 0,n){ cin>> wt[i] >> val[i]; }

		// 	loop(i,1,n){
		// 		loop(j,1,w){
		// 			if( wt[i] > j) dp[i][j] = dp[i-1][j];
		// 			else{
		// 				dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wt[i]]);
		// 			}
		// 		}
		// 	}

			vi dp1(w+1, 0);
			vi dp2(w+1, 0);
			int wt[n], val[n];
			loop(i, 0,n){ cin>> wt[i] >> val[i]; }

			loop(i, 0, n-1){
				loop(j, 1, w){
					if( wt[i] > j) dp2[j] = dp1[j];
					else{
						dp2[j] = max(dp2[j], dp1[j], val[i] + dp1[j-wt[i]]);
					}
				}
				dp2.swap(dp1);
				dp2.clear();
			}
			cout<<dp1[w];

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}