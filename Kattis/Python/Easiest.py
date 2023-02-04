
def checker(n = int()):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    
    return s


def main():

    n = int(input())
    while n > 0:
        a = 11
        while checker(n) != checker(n * a):
            a += 1
        
        print(a)
        n = int(input())

if __name__ == '__main__':
    main()
