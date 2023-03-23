
from collections import deque
from typing import List

INF = 2 ** 31 - 1


class edge:
    """
    class to implement an edge in the network
    """
    
    def __init__(self, s: int, t: int, res: int):
        self.s = s
        self.t = t
        self.res = res
        self.reverse = None
        self.isReverse = None


def Dinic(net: List[List[edge]], s: int, t: int, checkReverse: bool) -> int:
    """
    find the maxflow of the network
    """
    ans = 0
    while True:
        q = deque()
        depth = [0] * (t - s + 10)
        mark = [0] * (t - s + 10)
        q.append(s)
        depth[s] = 1
        # bfs to definite depth of the net
        while q:
            cur = q.popleft()
            for e in net[cur]:
                if checkReverse and e.isReverse:
                    continue
                if depth[e.t] == 0 and e.res > 0:
                    depth[e.t] = depth[cur] + 1
                    q.append(e.t)
            if depth[t] != 0:
                break
        
        if depth[t] == 0:
            return ans
        
        def dfs(now: int, flow: int) -> int:
            """
            dfs to find augment path and update flow
            """
            if now == t:
                return flow
            for i in range(mark[now], len(net[now])):
                e = net[now][i]
                if checkReverse and e.isReverse:
                    continue
                if depth[e.t] != depth[now] + 1 or e.res <= 0:
                    continue
                flowAdd = dfs(e.t, (flow if flow < e.res else e.res))
                if flowAdd == 0:
                    continue
                mark[now] = i
                e.res -= flowAdd
                e.reverse.res += flowAdd
                return flowAdd
            return 0
        
        tmp = dfs(s, INF)
        while tmp:
            ans += tmp
            tmp = dfs(s, INF)
    return ans


def main():
    """
    main method of this program
    """
    lenOfStr, numOfRequest, g = map(int, input().split())
    bitList = list(map(int, input().split()))
    v = list(map(int, input().split()))
    # first element is source, last element is end,
    # [1, lenOfStr] are points, [lenOfStr, lenOfStr + numOfRequest] are requests
    net = [list() for _ in range(lenOfStr + numOfRequest + 2)]
    
    def addEdge(s: int, t: int, res: int):
        """
        add an edge and its reverse edge in the net
        """
        e1 = edge(s, t, res)
        e2 = edge(t, s, 0)
        e1.reverse = e2
        e2.reverse = e1
        e1.isReverse = False
        e2.isReverse = True
        net[s].append(e1)
        net[t].append(e2)
    
    st = 0
    ed = lenOfStr + numOfRequest + 1
    #  connect "0" from source point, and "1" to end point
    for i, c in enumerate(v):
        if bitList[i] == 0:
            addEdge(st, i + 1, c)
        else:
            addEdge(i + 1, ed, c)
    
    ans = 0
    for i in range(numOfRequest):
        dataIn = list(map(int, input().split()))
        ans += dataIn[1]
        if dataIn[0] == 0:
            addEdge(st, lenOfStr + i + 1, dataIn[1] + (g if dataIn[-1] == 1 else 0))
            for j in range(dataIn[2]):
                addEdge(lenOfStr + i + 1, dataIn[j + 3], INF)
        else:
            addEdge(lenOfStr + i + 1, ed, dataIn[1] + (g if dataIn[-1] == 1 else 0))
            for j in range(dataIn[2]):
                addEdge(dataIn[j + 3], lenOfStr + i + 1, INF)
    
    ans -= Dinic(net, st, ed, True)
    ans -= Dinic(net, st, ed, False)
    print(ans)


if __name__ == '__main__':
    main()
