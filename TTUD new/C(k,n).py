def C(k,n):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n+1):
        for j in range(min(i,k)+1):
            dp[i][j]=1 if i==j or j==0 else dp[i - 1][j - 1] + dp[i - 1][j]
    return dp[n][k]
s=input()
k,n=map(int,s.split())
print(C(k, n))