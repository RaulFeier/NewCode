from heapq import heappush, heappop


def dij(g, s):
    dist = [int(1e9) for i in range(len(g))]
    dist[s] = 0
    pq = []
    heappush(pq, (0, s))

    while (len(pq) > 0):
        d, u = heappop(pq)
        if (d > dist[u]):
            continue
        for v, w in g[u]:
            cand = dist[u] + w
            if cand < dist[v]:
                dist[v] = cand
                heappush(pq, (dist[v], v))

    return dist


def main():
    while True:
        n, m, q, s = map(int, input().split())

        if n == 0 and m == 0 and q == 0 and s == 0:
            break

        g = [[] for i in range(n)]
        for _ in range(m):
            u, v, w = map(int, input().split())
            g[u].append((v, w))

        ans = dij(g, s)

        for _ in range(q):
            t = int(input())
            if ans[t] != int(1e9):
                print(ans[t])
            else:
                print("Impossible")

        print()


main()
