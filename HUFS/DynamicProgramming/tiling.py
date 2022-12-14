n = int(input())
A,B = [],[] #A와 B 동적테이블 생성.
A = [0]*n
B = [0]*n
case_number = 0
A[0],B[0] = 1,0
if n == 2:
	A[1],B[1] = 2,0
elif n > 2:
	A[1],B[1] = 2,0
	B[2] = 2
for i in range(2,n):
	A[i] = A[i-1] + A[i-2]
	
for j in range(3,n):
		B[j] += A[j-3]
		B[j] += B[j-3]
		B[j] += (B[j-1]-B[j-2]-B[j-3])//2
		B[j] = B[j]*2
		B[j] += B[j-1] + B[j-2]
case_number = A[n-1] + B[n-1]
print(case_number)
