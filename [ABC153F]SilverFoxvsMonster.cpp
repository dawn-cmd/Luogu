#include<bits/stdc++.h>
#define LL long long
#define N 200010
using namespace std;

LL read()
{
    LL x = 0;
    LL w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return (LL)(x * w);
}

inline void write(LL x)
{
    static LL sta[35];
    LL top = 0;
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    do
    {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

LL n;
LL d;
LL a;
struct enemy
{
    LL hp;
    LL loc;
} enemies[N];

LL dif[N];

inline bool cmp(enemy a, enemy b)
{
    return a.loc < b.loc;
}

inline LL getLast(LL loc, LL l, LL r)
{
    if (l > r)
        return l - 1;
    LL mid = (l + r) / 2;
    if (enemies[mid].loc <= loc)
        l = mid + 1;
    else
        r = mid - 1;
    return getLast(loc, l, r);
}

int main() {
    n = read();
    d = read();
    a = read();
    LL loc;
    LL hp;
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        enemies[i].loc = read();
        enemies[i].hp = read();
    }
    sort(enemies, enemies + n, cmp);
    for (int i = 1; i < n; ++i)
        dif[i] = enemies[i].hp - enemies[i - 1].hp;
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            enemies[i].hp = enemies[i - 1].hp + dif[i];
        if (enemies[i].hp <= 0)
            continue;
        LL numBomb = enemies[i].hp / a + (enemies[i].hp % a != 0);
        ans += numBomb;
        enemies[i].hp -= numBomb * a;
        dif[i] -= numBomb * a;
        LL id = getLast(enemies[i].loc + 2 * d, i, n - 1);
        dif[id + 1] += numBomb * a;
    }
    write(ans);
}
