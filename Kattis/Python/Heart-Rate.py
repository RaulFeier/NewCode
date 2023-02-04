def main():
    n = int(input())
    for i in range(n):
        b, p = input().split()
        b = int(b)
        p = float(p)

        ans = 60 * (b / p)
        t = 60 / p

        short_ans = '%.4f'%ans
        short_t = '%.4f'%t

        print(ans - t, ans, ans + t)

main()