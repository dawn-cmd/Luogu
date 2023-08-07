def main():
    n = int(input())
    king_l, king_r = map(int, input().split())
    hands = []
    for i in range(n):
        tmp = list(map(int, input().split()))
        hands.append(tmp)
    hands.sort(key=lambda a: a[0] * a[1])
    cur_l = king_l
    res = -1
    for i in range(n):
        res = max(res, cur_l // hands[i][1])
        cur_l *= hands[i][0]
    print(res)


if __name__ == "__main__":
    main()
