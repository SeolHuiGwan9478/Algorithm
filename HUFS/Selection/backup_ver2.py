def reconstruct(S, L):
	n = len(S)
	A = [S[i] + (n-1-i-L[i]) for i in range(n)]
	return A
	
# S와 L을 차례로 읽어들임
S = [int(x) for x in input().split()]
L = [int(x) for x in input().split()]
A = reconstruct(S, L)
print(A)

# 1. 본인이 작성한 알고리즘의 수행시간을 간략히 분석해보자
# 
# 2. 수행시간 T(n)을 Big-O료 표기해보자
# 