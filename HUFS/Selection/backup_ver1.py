def reconstruct(B):
	n = len(B)
	A = [0] * n
	for i in range(n):
		A[i] += B[i]
		for j in range(i):
			if A[j] >= A[i]:
				A[j] += 1
	return A	
B = [int(x) for x in input().split()]
A = reconstruct(B)
print(A)

# 1. 본인이 작성한 알고리즘의 수행시간을 간략히 분석해보자
# 
# 2. 수행시간 T(n)을 Big-O료 표기해보자
# 