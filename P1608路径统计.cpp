#include<bits/stdc++.h>
#define LL long long
#define minn(a, b) ((a) < (b) ? (a) : (b))
#define N 2010
#define M 4000010
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

struct Edge
{
    LL to;
    LL c;
    LL next;
} edges[M];
map<pair<LL, LL>, LL> h;
LL head[N];
LL n;
LL m;
LL numEdge = 1;
LL dis[N];
LL num[N];
LL vis[N];

void addEdge(LL s, LL t, LL c)
{
    edges[++numEdge].to = t;
    edges[numEdge].c = c;
    edges[numEdge].next = head[s];
    head[s] = numEdge;
}

void dijkstra()
{
    priority_queue<pair<LL, LL>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(num, 0, sizeof(num));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    num[1] = 1;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        LL cur = tmp.second;
        if (vis[cur])
            continue;
        vis[cur] = 1;
        for (int i = head[cur]; i; i = edges[i].next)
        {
            if (dis[edges[i].to] > dis[cur] + edges[i].c)
            {
                dis[edges[i].to] = dis[cur] + edges[i].c;
                num[edges[i].to] = num[cur];
                if (!vis[edges[i].to])
                    q.push(make_pair(-dis[edges[i].to], edges[i].to));
            }
            else if (dis[edges[i].to] == dis[cur] + edges[i].c)
                num[edges[i].to] += num[cur];
        }
    }
}

int main() 
{
    n = read();
    m = read();
    LL s;
    LL t;
    LL c;
    for (int i = 0; i < m; ++i)
    {
        s = read();
        t = read();
        c = read();
        if (s == t)
            continue;
        if (!h.count(make_pair(s, t)))
            h[make_pair(s, t)] = c;
        else
            h[make_pair(s, t)] = minn(c, h[make_pair(s, t)]);
    }
    for (auto iter = h.begin(); iter != h.end(); ++iter)
        addEdge(iter->first.first, iter->first.second, iter->second);
    dijkstra();
    if (num[n] == 0)
        cout << "No answer" << endl;
    else
        cout << dis[n] << " " << num[n] << endl;
}
