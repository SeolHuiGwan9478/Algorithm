def pin(A,n):
	# code here
	count = 1 #O(1)
	std = A[0][1] #O(1)
	for i in range(1,n): #O(n)
		if std < A[i][0]: 
			count += 1
			std = A[i][1] 
	return count
# 리스트 A에 구간 n개를 저장 후, pin 함수를 불러 리턴 값을 출력한다

A = []
n = int(input())
for i in range(n): #O(n)
	tmp = [] 
	s,f = map(int, input().split())
	tmp.append(s)
	tmp.append(f)
	A.append(tmp)
A.sort(key=lambda x:x[1]) #O(nlogn)
cnt = pin(A,n) #O(1)
print(cnt)

#시작점과 끝점을 입력받은 것을 A에 2차원 배열로 저장한다. 그 후, 다차원 배열을 정렬하기 위해 labda를 이용하여 끝점을 기준으로 오름차순으로 정렬해주었다.
#그 후 강의실 배정문제와 같이 끝점이 가장 작은 것부터 기준을 잡는다. 그 끝점을 기준으로 다음 인덱스의 "시작점"을 차례대로 본다. 시작점이 기준이 되는 끝점보다 크다는 것은 한 핀으로 그것을 다 꽂을 수 없다는 것을 의미하므로 핀의 갯수를 증가시켜주고, 기준을 현재 인덱스의 끝점으로 바꿔준다. 그렇게 마지막 인덱스까지 다 확인하면 핀의 최종갯수를 pin함수에서 반환한다.
#입력 받은 것을 리스트 A에 대입하는데 O(n) 걸림. 그 후 lambda를 써서 다차원배열을 정렬하는데 걸리는 시간 O(nlogn) 걸림(참조: https://stackoverflow.com/questions/34830661/using-a-lambda-as-key-within-builtin-string-sort-hard-to-identify-big-o). 그 후 Pin함수 내부에서 for문이 n-1번 돈다.그러므로 O(n). O(n) + O(nlogn)이므로 총 시간복잡도는 O(nlogn)걸린다. 