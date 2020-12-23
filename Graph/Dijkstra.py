class Node:
    def __init__(self, key=None, w=0, d=0):
        self.key = key
        self.next = None
        self.weight = w
        self.distance = d
    def __str__(self):
        return str(self.key)

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def __len__(self):
        return self.size

    def printList(self):
        # 변경없이 사용할 것!
        v = self.head

        while (v):
            print(v.key, "->", end=" ")
            v = v.next
        print("None")
    def pushFront(self, key, w):
        new_Node = Node(key, w)
        new_Node.next = self.head
        self.head = new_Node
        self.size += 1

    def pushBack(self, key, w):
        new_Node = Node(key, w)
        if len(self) == 0:
            self.head = new_Node
        else:
            tail = self.head
            while tail.next != None:
                tail = tail.next
            tail.next = new_Node
        self.size += 1

    def popFront(self):
        if len(self) == 0:
            return None
        else:
            tmp = self.head
            key = tmp.key
            self.head = tmp.next
            self.size -= 1
            del tmp
            return key

    def popBack(self):
        if len(self) == 0:
            return None
        prev = None
        tail = self.head
        while tail.next != None:
            prev = tail
            tail = tail.next
        if len(self) == 1:
            self.head = None
        else:
            prev.next = None
        key = tail.key
        self.size -= 1
        del tail
        return key

    def search(self, key):
        v = self.head
        while v != None:
            if v.key == key:
                return v
            else:
                v = v.next
        return v

    def remove(self, x):
        prev = None
        v = self.head
        if x == None:
            return False
        if len(self) == 1:
            self.head = None
            self.size -= 1
            del v
            return True
        else:
            if v == x:
                self.head = v.next
                self.size -= 1
                return True
            else:
                while v != None:
                    prev = v
                    v = v.next
                    if v == x:
                        prev.next = v.next
                        self.size -= 1
                        del v
                        return True

    def reverse(self):
        prev = None
        current = self.head
        while current != None:
            a = current
            b = current.next
            current.next = prev
            prev = a
            current = b
        self.head = prev

    def findMax(self):
        if len(self) == 0:
            return None
        else:
            tmp = self.head
            max_key = tmp.key
            while tmp.next != None:
                tmp = tmp.next
                if max_key < tmp.key:
                    max_key = tmp.key
            return max_key

    def deleteMax(self):
        if len(self) == 0:
            return None
        else:
            max_key = self.findMax()
            self.remove(self.search(max_key))
            return max_key

    def insert(self, k, val):
        if len(self) < k:
            self.pushBack(val)
        else:
            new_Node = Node(val)
            prev = None
            v = self.head
            for i in range(k):
                prev = v
                v = v.next
            prev.next = new_Node
            new_Node.next = v
            self.size += 1

    def size(self):
        return self.size

class min_Heap:
    def __init__(self, L=[]):
        self.A = L

    def __str__(self):
        return str(self.A)

    def __len__(self):
        return len(self.A)

    def heapify_down(self, k, n):
        while 2 * k + 1 < n:
            L = 2 * k + 1
            R = 2 * k + 2
            if L < n and self.A[k].distance > self.A[L].distance:
                m = L
            else:
                m = k
            if R < n and self.A[m].distance > self.A[R].distance:
                m = R
            if m != k:
                tmp = self.A[k]
                self.A[k] = self.A[m]
                self.A[m] = tmp
                k = m
            else:
                break

    def make_heap(self):
        n = len(self.A)
        for i in range(n - 1, -1, -1):
            self.heapify_down(i, n)

    def heapify_up(self, k):
        while k > 0 and self.A[(k - 1) // 2].distance > self.A[k].distance:
            tmp = self.A[(k - 1) // 2]
            self.A[(k - 1) // 2] = self.A[k]
            self.A[k] = tmp
            k = (k - 1) // 2

    def insert(self, n):
        self.A.append(n)
        self.heapify_up(len(self.A) - 1)

    def find_min(self):
        return self.A[0]

    def delete_min(self):
        if len(self.A) == 0: return None
        key = self.A[0].key
        tmp = self.A[0]
        self.A[0] = self.A[-1]
        self.A[-1] = tmp
        self.A.pop()
        self.heapify_down(0, len(self.A))
        return key

    def decreaseKey(self, v, d):
        update_index = 0
        for update_index in range(len(self.A)):
            if self.A[update_index].key == v:
                #update
                self.A[update_index].distance = d
                break
        self.heapify_up(update_index)


def Dijkstra(G,n,m):
    visited = [False for i in range(n)] #방문 했는지 안했는지
    dist = [0] + [float('inf') for i in range(n-1)]
    #make heap
    Q = [Node(key=0,d=0)]
    for i in range(n): # N
        v = Node(key=i,d=float("inf"))
        Q.append(v)
    H = min_Heap(Q)
    while len(H): #N
        u = H.delete_min() #log N
        visited[u] = True
        initial_Node = G[u].head
        while initial_Node != None: #N
            v = initial_Node.key
            #relax(u,v)
            if visited[v] == False:
                if dist[u] + initial_Node.weight < dist[v]:
                    dist[v] = dist[u] + initial_Node.weight
                    H.decreaseKey(v, dist[v])
            initial_Node = initial_Node.next
    return dist

#그래프 생성
G = []
n = int(input()) #노드의 갯수
m = int(input()) #에지의 갯수

for i in range(n):
    tmp = SinglyLinkedList()
    G.append(tmp)
for i in range(m):
    u,v,w = input().split()
    u,v,w = int(u), int(v), int(w)
    G[u].pushFront(v, w) #인접리스트 완성

dist = Dijkstra(G, n, m)
for i in range(len(dist)):
    print(dist[i], end = " ")