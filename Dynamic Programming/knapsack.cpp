#include<bits/stdc++.h>
using namespace std;

int main ()
{
    long long int n, sum;
    cin >> n >> sum;
    long long int value[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    int dp[sum + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = value[i]; j <= sum; j++) {
            dp[j] += dp[j - value[i]];
        }
    }
    cout << dp[sum] << endl;
    return 0;
}

