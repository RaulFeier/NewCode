


def checker(n = int()):

    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    
    return s

def main():

    a = int(input())
    b = int(input())
    x = int(input())
    

    n = a
    m = b

    while checker(n) != x:
        n += 1
    
    while checker(m) != x:
        m -= 1

    print(n, m, sep = '\n')

if __name__ == '__main__':
    main()