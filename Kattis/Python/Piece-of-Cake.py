
def main():
    n, v, h = input().split()
    n, v , h = int(n), int(v), int(h)

    print(max(v, n - v) * max(h, n - h) * 4, end='\n')

if __name__ == '__main__':
    main()