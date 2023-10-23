#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
#define mod 1e10 + 7
#define inf 10e8 + 1
#define mp make_pair
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
int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		int h, w;
		cin>>h>>w;


		vector<vector<char>> grid(h+1, vector<char>(w+1));
		loop(i, 1, h){
			string s;
			cin>>s;
			loop(j, 1, w){
				grid[i][j] = s[j-1];
			}
		}
		vector<vector<ll>> dp(h+1, vector<ll>(w+1)); //to allow 1 based indexing.
		dp[h][w] = 1;
		looprev(i, h, 1){
			looprev(j, w, 1){
				if(i==h and j==w) { continue; }
				if(grid[i][j] == '#') { dp[i][j] = 0; continue;}
				dp[i][j] = (((i==h)?0:dp[i+1][j])+ ((j==w)?0:dp[i][j+1]));
			}
		}
		loop(i, 1, h){
			loop(j, 1, w){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<dp[1][1];
		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}