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

		string s1, s2;
		cin>>s1>>s2;
		int n = s1.size(), m = s2.size();

		vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
		vector<char> ans;
		loop(i, 1, n){
			loop(j, 1, m){
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					// ans.push_back(s1[i-1]); prints wrong
				}else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}

		int result = dp[n][m];
		cout<<result<<endl;
		//can use optimization of space to O(m) but not if you print string.
		string str(result,' ');
		int i = n, j=m;
		while(i>0 and j>0) {
			if(s1[i-1] == s2[j-1]){
				str[result - 1] = s1[i-1];
				i--; j--; result--;
			} else if(dp[i-1][j] > dp[i][j-1]){
				//goto up direction 
				i--;
			} else { j--; }
		}
		cout<<str;

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}