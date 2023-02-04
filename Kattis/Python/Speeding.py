
def main():

    a = 0
    a = int(a)
    n = int(input())

    t2, d2 = 1e9, 1e9
    t2, d2 = int(t2), int(d2)

    for i in range(n):

        t1, d1 = input().split()
        t1, d1 = int(t1), int(d1)

        if ((d1 - d2) / (t1 - t2)) > a:
            a = (d1 - d2) / (t1 - t2)
            a = int(a)
        
        t2, d2 = t1, d1
    
    print(a)

if __name__ == '__main__':
    main()