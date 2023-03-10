def Colats(n):
    n = int(n)
    if n == 1:
        return 1
    
    if n % 2 == 0:
        return n + Colats(n / 2)
    else:
        return n + Colats(n * 3 + 1)

def main():
    n = int(input())
    print(Colats(n))

if __name__ == "__main__":
    main()