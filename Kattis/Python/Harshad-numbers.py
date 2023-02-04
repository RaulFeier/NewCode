
def main():
    a = input()

    for i in range(int(a), 1000000000 + 1):
        
        a = str(i)
        r = a
        n1 = int(a)
        arr = []
        sum = 0

        for j in range(len(a)):
            
            n = int(a[j])
            sum += n
        
        if i % sum == 0:
            break
    
    print(i)

if __name__ == '__main__':
    main()
