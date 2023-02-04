import math

def main():
    while True:
        r, m, c = (float(x) for x in input().split())
        if r == 0:
            break
        else:
            print(math.pi * r ** 2, (2 * r) ** 2 * c / m)

if __name__ == '__main__':
    main()