
def main():
    t = int(input())

    for i in range(t):
        l, r, x = map(int, input().split())
        a, b = map(int, input().split())

        if a == b:
            print(0)
        elif abs(a - b) >= x:
            print(1)
        elif r - max(a, b) >= x or min(a, b) - l >= x:
            print(2)
        elif r - b >= x and a - l >= x or r - a >= x and b - l >= x:
            print(3)
        else:
            print(-1)

if __name__ == "__main__":
    main()