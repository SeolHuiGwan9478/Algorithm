import heapq

def huffman(h):
    bit = 0
    cost = 0
    stack = []
    L = []
    while(len(h) != 1):
        a = heapq.heappop(h)
        b = heapq.heappop(h)
        number = a[0] + b[0]
        string = '(' + str(a[1]) + ' ' + str(b[1]) + ')'
        heapq.heappush(h, (number, string))
    final = h[0]
    for x in final[1]:
        if x == '(':
            stack.append(x)
            bit +=1
        elif x == ')':
            while(1):
                y = stack.pop()
                if y == '(':
                    break
                L.append(y)
            bit -= 1
            for i in range(len(L)):
                cost += f[int(L.pop())]*bit
        elif x == ' ':
            continue
        else:
            stack.append(x)
    print(cost)
heap = []
f = [int(i) for i in input().split()]
for i in range(len(f)):
    heapq.heappush(heap,(f[i],str(i)))

huffman(heap)
