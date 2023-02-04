
def main():
    a, b = input().split()
    a = int(a)
    b = int(b)
    c = 0
    d = 0

    while a:
        c *= 10
        c += a % 10
        a //= 10
    
    while b:
        d *= 10
        d += b % 10
        b //= 10
    
    if(c > d):
        print(c, end = "\n")
    else:
        print(d, end = "\n")

if __name__ == '__main__':
    main()