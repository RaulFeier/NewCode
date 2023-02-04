
from itertools import count


def main():
    n = int(input())

    a = input().split()
    a = [int(i) for i in a]

    count = 0
    for i in range(n):
        if a[i] < 0:
            count += 1
    
    print(count, end="\n")

if __name__ == "__main__":
    main()