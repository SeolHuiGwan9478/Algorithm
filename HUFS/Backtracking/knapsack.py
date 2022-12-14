def knapsack(i,size):
	global MaxProfit
	s,p = 0,0
	if i >= N or size <= 0:
		return
	for k in range(i):
		if x[k] == 1:
			s += S[k] #p(v) 계산
			p += P[k] #s(v) 계산
	if S[i] <= size:
		B = frac_knapsack(i+1, size-S[i])
		if MaxProfit < (p + P[i] + B):
			x[i] = 1
			MaxProfit = max(MaxProfit, p + P[i])
			knapsack(i+1,size-S[i])
	B = frac_knapsack(i+1,size)
	if MaxProfit < p + B:
		x[i] = 0
		knapsack(i+1,size)
	
def frac_knapsack(i, size):
	if size <= 0:
		return 0
	s,p = 0,0
	for k in range(i,N):
		if s + S[k] <= size:
			p += P[k]
			s += S[k]
		else:
			p += (size-s) * (P[k]/S[k])
			s = size
			break
	return p

K = int(input()) #가방 용량
N = int(input()) #아이템 갯수
S = [int(k) for k in input().split()] #아이템별 크기
P = [int(k) for k in input().split()] #아이템별 가치
x = [0] * N
sp = [0] * N #가성비만 넣어둔 리스트
for k in range(N): #가성비 넣어줌.
	sp[k] = P[k]/S[k]
sp.sort(reverse=True) #가성비를 내림차순으로 정렬
for i in range(N):
	for j in range(i,N):
		if (P[j]/S[j]) == sp[i]: #가성비 리스트를 보면서 S,P도 똑같이 정렬
			S[i],S[j] = S[j],S[i]
			P[i],P[j] = P[j],P[i]
			break

MaxProfit = 0 #최종 출력값
knapsack(0,K) #냅색 함수 호출
print(MaxProfit)