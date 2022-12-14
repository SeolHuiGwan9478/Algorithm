def find_median_five(L):
	median = 0
	for i in range(3):
		max_value = L[i]
		max_index = i
		for j in range(i+1,len(L)):
			if max_value < L[j]:
				max_value = L[j]
				max_index = j
		tmp = L[i]
		L[i] = max_value
		L[max_index] = tmp
		median = max_value
	return median
			
def MoM(L, k): # L의 값 중에서 k번째로 작은 수 리턴
	if len(L) == 1: # no more recursion
		return L[0]
	i = 0
	A, B, M, medians = [], [], [], []
	while i+4 < len(L):
		medians.append(find_median_five(L[i: i+5])) #5등분씩 중앙값 구하여 medians에 append
		i = i + 5
	if i < len(L) and i+4 >= len(L): #5등분으로 나누고 남은 것
		tmp_L = L[i:len(L)]
		if len(tmp_L) <= 2:
			medians.append(tmp_L[0])
		else:
			max_value = tmp_L[0]
			max_index = 0
			for i in range(1,len(tmp_L)):
				if max_value < tmp_L[i]:
					max_value = tmp_L[i]
					max_index = i
			tmp = tmp_L[0]
			tmp_L[0] = max_value
			tmp_L[max_index] = tmp
			max_value = tmp_L[1]
			max_index = 1
			for i in range(2, len(tmp_L)):
				if max_value < tmp_L[i]:
					max_value = tmp_L[i]
			medians.append(max_value)

	mom = MoM(medians, len(medians)//2+1)
	for v in L:
		if v < mom: 
			A.append(v)
		elif v > mom:
			B.append(v)
		else:
			M.append(v)

	if k <= len(A): 
		return MoM(A, k)
	elif k > (len(A)+len(M)): 
		return MoM(B, k-len(M)-len(A))
	else: 
		return mom

# n과 k를 입력의 첫 줄에서 읽어들인다
n, k = input().split()
n, k = int(n), int(k)
# n개의 정수를 읽어들인다. (split 이용 + int로 변환)
L = input().split()
L = [int(x) for x in L]
print(MoM(L, k))