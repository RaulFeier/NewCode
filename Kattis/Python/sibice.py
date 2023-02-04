import math
from tokenize import Double


def main():
    n, w ,h = input().split()
    n = int(n)
    w = int(w)
    h = int(h)
    d = math.sqrt(w**2 + h**2)
    
    for i in range(n):
        x = int(input())
        if x <= d:
            print("DA\n")
        else:
            print("NE\n")

if __name__ == "__main__":
    main()