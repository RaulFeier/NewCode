n, k, m = map(int, input().split())

dp = [[[0 for s in range(k)] for j in range(k)] for i in range(n+1)]
for j in range(k):
    dp[1][j][j] = 1

for i in range(2, n+1):
    for j in range(k):
        for s in range(k):
            for d in range(k):
                dp[i][j][(s+d)%k] += dp[i-1][d][s]
                dp[i][j][(s+d)%k] %= m

ans = 0
for j in range(k):
    ans += dp[n][j][0]
    ans %= m

print(ans)
