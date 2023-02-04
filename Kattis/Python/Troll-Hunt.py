
import math

def main():
    b, k, g = input().split()
    b, k = int(b), int(k)
    g = float(g)

    b -= 1

    crt = math.floor(k / g)

    d = math.ceil(float(b) / crt)
    print(d)

if __name__ == '__main__':
    main()