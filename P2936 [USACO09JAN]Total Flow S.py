
from collections import deque


class edge:
    """
    the class to describe an edge
    s: the start of edge
    t: the end of edge
    cap: the capacity of the edge
    res: the rest possible flow in this edge
    """
    
    def __init__(self, s: str, t: str, cap: int, res: int):
        self.s = s
        self.t = t
        self.cap = cap
        self.res = res
        self.reverse = None


def dinic(net: dict, s: str, t: str) -> int:
    """
    find the max flow of this network
    """
    ans = 0
    while True:
        # bfs to definite the depth of the net
        q = deque()
        depth = {}
        q.append(s)
        mark = {}
        depth[s] = 1
        # print("bfs start")
        while q:
            cur = q.pop()
            # print(cur, depth.get(cur), len(q))
            for e in net[cur]:
                if e.res > 0 and depth.get(e.t) is None:
                    q.append(e.t)
                    depth[e.t] = depth[cur] + 1
            if depth.get(t) is not None:
                break
                    
        # if t does not have a depth, there is no augmented path
        # print(depth, depth.get(t))
        if depth.get(t) is None:
            return ans
        
        def dfs(now: str, flow: int) -> int:
            """
            dfs to find the augmented path
            """
            # print(now, flow)
            if now == t:
                return flow
            if mark.get(now) is None:
                mark[now] = 0
            for i in enumerate(net[now][mark[now]:]):
                e = i[1]
                if (depth.get(e.t) is not None) and (depth[e.t] == depth[now] + 1) and (e.res > 0):
                    aug = dfs(e.t, (flow if flow < e.res else e.res))
                    if aug == 0:
                        continue
                    mark[now] = i[0]
                    e.res -= aug
                    e.reverse.res += aug
                    return aug
            return 0
       
        # print("dfs start")
        tmp = dfs(s, (2 ** 31 - 1))
        while tmp:
            # print(tmp)
            ans += tmp
            tmp = dfs(s, 2 ** 31 - 1)
    
    return ans
    
    
def main():
    """
    The main method of the program
    """
    numOfEdge = int(input())
    net = {}  # the network, net[s] contains all edges starts from point s
    for i in range(numOfEdge):
        dataIn = list(input().split())
        if net.get(dataIn[0]) is None:
            net[dataIn[0]] = []
        if net.get(dataIn[1]) is None:
            net[dataIn[1]] = []
        e1 = edge(dataIn[0], dataIn[1], int(dataIn[2]), int(dataIn[2]))
        e2 = edge(dataIn[1], dataIn[0], int(dataIn[2]), 0)
        e1.reverse = e2
        e2.reverse = e1
        net[dataIn[0]].append(e1)
        net[dataIn[1]].append(e2)
    print(dinic(net, "A", "Z"))


if __name__ == '__main__':
    main()
