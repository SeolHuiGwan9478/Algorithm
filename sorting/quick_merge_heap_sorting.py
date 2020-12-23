import random, timeit
##
## 여기에 세 가지 정렬함수를 위한 코드를...
##
#inserton 함수 그리고 quick_sort,insertion_sort 같이 쓴 함수
'''
def insertion_sort(A,first,last):
	for i in range(first+1,last+1):
		j = i-1
		while A[i] < A[j] and j >= first:
			j -= 1
		A.insert(j+1,A[i])
		del A[i+1]           

def quick_sort_combo(A,first,last):
	if (last-first+1) > 9 and (last-first+1) < 41:
		insertion_sort(A,first,last)
		return
	if first >= last:
		return
	p = A[first]
	left,right = first+1,last
	while left <= right:
		while left <= last and A[left] <p:
			left += 1
		while right > first and A[right] > p:
			right -= 1
		if left <= right:
			A[left],A[right] = A[right],A[left]
			left += 1
			right -= 1
	A[first],A[right] = A[right],A[first]
	quick_sort_combo(A,first,right-1)
	quick_sort_combo(A,left,last)
'''
def quick_sort(A,first,last):
	global Qc, Qs
	if first >= last:
		return
	p = A[first]
	left, right = first+1, last
	while left <= right:
		while left <= last and A[left] < p:
			left += 1
			Qc += 1
		while right > first and A[right] > p:
			right -= 1
			Qc += 1
		if left <= right:
			A[left],A[right] = A[right],A[left]
			Qs += 1
			left += 1
			right -= 1
	A[first], A[right] = A[right], A[first]
	Qs += 1
	quick_sort(A, first, right-1)
	quick_sort(A, left, last)
#merge_sort와 insertion 함수 같이 쓴 것
'''
def merge_sort_combo(A,first,last):
	B = []
	if (last-first+1) >= 10 and (last-first+1) <= 40:
		insertion_sort(A,first,last)
		return
	if first >= last:
		return
	m = (first+last)//2
	i,j = first,m+1
	merge_sort_combo(A,first,m)
	merge_sort_combo(A,m+1,last)
	while i <= m and j <= last:
		if A[i] < A[j]:
			B.append(A[i])
			i += 1
		else:
			B.append(A[j])
			j += 1
	for x in range(i, m+1):
		B.append(A[x])
	for x in range(j,last+1):
		B.append(A[x])
	for x in range(first, last+1):
		A[x] = B[x-first]
'''
def merge_sort(A,first,last):
	global Mc
	global Ms
	if first >= last:
		return
	m = (first+last)//2
	merge_sort(A,first,m)
	merge_sort(A,m+1,last)
	B = []
	i,j = first, m+1
	while i <= m and j <= last:
		Mc += 1
		if A[i] <= A[j]:
			B.append(A[i])
			i += 1
		else:
			B.append(A[j])
			j += 1
	for i in range(i, m+1):
		B.append(A[i])
	for j in range(j, last+1):
		B.append(A[j])
	for k in range(first, last +1):
		A[k] = B[k-first]
	Ms += 2*(last-first+1)
		
def heap_sort(A):
	global Hs
	global Hc
	n = len(A)
	make_heap(A)
	for i in range(n-1,-1,-1):
		A[0],A[i] = A[i],A[0]
		Hs += 1
		n -= 1
		heapify_down(A,0,n)

def make_heap(A):
	n = len(A)
	for k in range(n-1,-1,-1):
		heapify_down(A,k,n)

def heapify_down(A,k,n):
	global Hs
	global Hc
	while 2*k+1 < n:
		L,R = 2*k+1,2*k+2
		if L < n and A[k] < A[L]:
			m = L
			Hc += 1
		else:
			m = k
			Hc += 1
		if R < n and A[m] < A[R]:
			m = R
			Hc += 1
		if m != k:
			A[k],A[m] = A[m],A[k]
			k = m
			Hs += 1
		else:
			break

# 아래 코드는 바꾸지 말 것!
# 직접 실행해보면, 어떤 값이 출력되는지 알 수 있음
#

def check_sorted(A):
	for i in range(n-1):
		if A[i] > A[i+1]: return False
	return True

#
# Qc는 quick sort에서 리스트의 두 수를 비교한 횟수 저장
# Qs는 quick sort에서 두 수를 교환(swap)한 횟수 저장
# Mc, Ms는 merge sort에서 비교, 교환(또는 이동) 횟수 저장
# Hc, Hs는 heap sort에서 비교, 교환(또는 이동) 횟수 저장
#
Qc, Qs, Mc, Ms, Hc, Hs = 0, 0, 0, 0, 0, 0
n = int(input())
random.seed()
A = []
for i in range(n):
	A.append(random.randint(-1000,1000))
B = A[:]
C = A[:]
#D = A[:]
print("")
print("Quick sort:")
print("time =", timeit.timeit("quick_sort(A, 0, n-1)", globals=globals(), number=1))
print("  comparisons = {:10d}, swaps = {:10d}\n".format(Qc, Qs))
print("Merge sort:")
print("time =", timeit.timeit("merge_sort(B, 0, n-1)", globals=globals(), number=1))
print("  comparisons = {:10d}, swaps = {:10d}\n".format(Mc, Ms))
print("Heap sort:")
print("time =", timeit.timeit("heap_sort(C)", globals=globals(), number=1))
print("  comparisons = {:10d}, swaps = {:10d}\n".format(Hc, Hs))
#print("time =", timeit.timeit("merge_sort_combo(D,0,n-1)", globals=globals(),number=1))
# 진짜 정렬되었는지 check한다. 정렬이 되지 않았다면, assert 함수가 fail됨!
assert(check_sorted(A))
assert(check_sorted(B))
assert(check_sorted(C))
