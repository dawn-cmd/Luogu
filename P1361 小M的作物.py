
from typing import List
from collections import deque

INF = 2 ** 31 - 1


class edge:
    """
    a class to implement an edge
    """
    def __init__(self, to: int, res: int):
        self.to = to
        self.res = res
        self.back = None
        

def Dinic(net: List[List[edge]], s: int, t: int):
    """
    find the maxflow of the network
    """
    
    depth = [0] * len(net)
    mark = [0] * len(net)
    q = deque()
    
    def bfs() -> bool:
        """
        find restflow net and define depth
        """
        q.clear()
        q.append(s)
        for i in range(len(depth)):
            depth[i] = 0
        depth[s] = 1
        while q:
            cur = q.popleft()
            for e in net[cur]:
                if e.res <= 0 or depth[e.to] != 0:
                    continue
                depth[e.to] = depth[cur] + 1
                q.append(e.to)
            if depth[t] != 0:
                return True
        return depth[t] != 0

    def dfs(cur: int, flow: int) -> int:
        """
        find an augment path and update flow
        """
        if cur == t:
            return flow
        for i in range(mark[cur], len(net[cur])):
            e = net[cur][i]
            if e.res <= 0 or depth[e.to] != depth[cur] + 1:
                continue
            aug = dfs(e.to, min(flow, e.res))
            if aug == 0:
                continue
            mark[cur] = i
            e.res -= aug
            e.back.res += aug
            return aug
        return 0

    ans = 0
    while bfs():
        tmp = dfs(s, INF)
        while tmp:
            ans += tmp
            tmp = dfs(s, INF)
        for _ in range(len(mark)):
            mark[_] = 0
    return ans
    

def main():
    """
    main method of this program
    """
    n = int(input())
    addUp = 0
    net = [list() for _ in range(n + 2)]
    
    def addEdge(st: int, ed: int, res: int):
        """
        add an edge in net and its back edge
        """
        e1 = edge(ed, res)
        e2 = edge(st, 0)
        e1.back = e2
        e2.back = e1
        net[st].append(e1)
        net[ed].append(e2)
    
    s = 0
    t = 1
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    addUp += sum(a) + sum(b)
    for i in range(n):
        id = i + 2
        addEdge(s, id, b[i])
        addEdge(id, t, a[i])
    
    m = int(input())
    net += [list() for _ in range(m * 2 + 1)]
    for i in range(m):
        dataIn = list(map(int, input().split()))
        id1 = n + 2 + i * 2
        id2 = n + 2 + i * 2 + 1
        addEdge(s, id1, dataIn[2])
        addEdge(id2, t, dataIn[1])
        addUp += dataIn[1] + dataIn[2]
        for j in range(3, len(dataIn)):
            addEdge(id1, dataIn[j] + 1, INF)
            addEdge(dataIn[j] + 1, id2, INF)
            
    print(addUp - Dinic(net, s, t))
    

if __name__ == '__main__':
    main()
