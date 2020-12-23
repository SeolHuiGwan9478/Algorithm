def print_subset(x):
	print([A[i] for i in range(len(x)) if x[i]])
	
def subset_sum(k):
	global subset_sum_cnt
	v_sum = 0
	for i in range(k):
		if x[i] == 1:
			v_sum += A[i]
	if k == len(A):
		if v_sum == S:
			subset_sum_cnt += 1
			print_subset(x)
		if sum(x) == 0 and subset_sum_cnt == 0:
			print([])
	else:
		if (v_sum + A[k] <= S):
			x[k] = 1
			subset_sum(k+1)
		x[k] = 0
		subset_sum(k+1)
# code for x[k] = 1 and x[k] = 0

subset_sum_cnt = 0
# 아래 코드는 수정하지 말고 그대로 사용할 것
A = list(set(int(x) for x in input().split()))
A.sort()
S = int(input()) 
x = [0]*len(A)
subset_sum(0)