def DFS(v): #Depth First Search
	global curr_time, n
	mark[v] = True
	pre[v] = curr_time
	curr_time += 1
	for i in range(n):
		if G[v][i] == 1 and mark[i] != True:
			DFS(i)

    result.append(v)
	post[v] = curr_time
	curr_time += 1
def DFSALL(G):
	global n
	for i in range(len(G)):
		if mark[i] != True:
			DFS(i)

def topological(G):
    global n
    #임시 s노드 추가
    for i in range(len(G)):
        G[i].append(0)
    tmp = [1]*n + [0]
    G.append(tmp)
    pre.append(0)
    post.append(0)
    mark.append(False)
    s_node = n+1
    #s노드 추가 끝.
    DFS(s_node)
     

n = int(input())
m = int(input())
mark = [False]*n
pre,post = [0]*n, [0]*n
curr_time = 1
result = []

#그래프 생성
G = []
for i in range(n):
	tmp = [0]*n
	G.append(tmp)

for i in range(m):
	e = input().split()
	f = int(e[0])
	t = int(e[1])
	G[f][t] = 1
#그래프 생성완료



for i in range(n):
    print(result[i], end=" ")