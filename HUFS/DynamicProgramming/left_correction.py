W = int(input())
words = input().split()
# code below
n = len(words)
DP = [[float('inf')]*n for i in range(n)] #DP table 생성 시작
best_p = [float('inf')]*n
best_p[n-1] = DP[n-1][n-1]

for i in range(n):
	DP[i][i] = len(words[i])
for i in range(n):
	for j in range(i + 1,n):
		if (DP[i][j-1] + len(words[j]) + 1) <= W:
			DP[i][j] = DP[i][j-1] + len(words[j]) + 1
		else:
			break
for i in range(n):
	for j in range(i,n):
		if DP[i][j] != float('inf'):
			DP[i][j] = (W-DP[i][j])**3
		else:
			break
#DP table 생성 완료

for i in range(n-1,-1,-1):
	best_p[i] = DP[i][n-1]
	for j in range(n-1,i,-1):
		if DP[i][j-1] == float('inf'):
			continue
		if (best_p[i] > best_p[j] + DP[i][j-1]):
			best_p[i] = best_p[j] + DP[i][j-1]

print(best_p[i])