
def main():
    x = int(input())
    
    res = x

    while res > 9:
        crt = res
        res = 1
        
        while crt > 0:
            if crt % 10 != 0:
                res *= crt % 10
            crt //= 10
        
    print(res, end="\n")

if __name__ == '__main__':
    main()
