
def main():

    arr = [1, 1, 2, 2, 2, 8]
    
    n = [int(x) for x in input().split()]
    
    for i in range(6):
        print(arr[i] - n[i], end=' ')

    print(end='\n')

if __name__ == '__main__':
    main()