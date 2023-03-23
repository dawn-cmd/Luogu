def main():
    n, m = map(int, input().split())
    p = list(map(int, input().split()))
    costs = []
    for i in range(n - 1):
        costs.append(list(map(int, input().split())))
    dif = [0 for _ in range(n)]    
    now = p[0] - 1
    for i in range(1, m):
        st = min(now, p[i] - 1)
        ed = max(now, p[i] - 1)
        dif[st] += 1
        if ed < n - 1:
            dif[ed] -= 1
        now = p[i] - 1
    ans = 0
    cnt = 0
    for i in range(n - 1):
        cnt += dif[i]
        ans += min(costs[i][0] * cnt, costs[i][2] + costs[i][1] * cnt)        
    print(ans)

if __name__ == "__main__":
    main()
