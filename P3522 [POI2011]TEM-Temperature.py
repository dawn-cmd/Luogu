def main():
    n = int(input())
    t = [list(map(int, input().split())) for _ in range(n)]
    now = t[0][0]
    cnt = 1
    ans = 1
    for i in range(1, n):
        if t[i][1] < now:
            ans = max(ans, cnt)
            cnt = 1
            now = t[i][0]
        else:
            now = max(t[i][0], now)
            cnt += 1
    ans = max(ans, cnt)
    print(ans)

if __name__ == "__main__":
    main()
