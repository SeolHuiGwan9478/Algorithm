def DFS(v): #Depth First Search
	global curr_time, n
	mark[v] = True
	pre[v] = curr_time
	curr_time += 1
	for i in range(n):
		if G[v][i] == 1 and mark[i] != True:
			DFS(i)
	post[v] = curr_time
	curr_time += 1

def DFSALL(G):
	global n
	for i in range(len(G)):
		if mark[i] != True:
			DFS(i)

n = int(input())
m = int(input())
mark = [False]*n
pre,post = [0]*n, [0]*n
curr_time = 1
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

DFSALL(G)