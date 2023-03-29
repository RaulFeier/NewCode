
def main():
    n, c, p = input().split()
    n = int(n)
    c = int(c)
    p = int(p)

    words = []

    for _ in range(n):
        word, tag = input().split()
        words.append((word, tag))

t = int(input())

for i in range(t):
    main()