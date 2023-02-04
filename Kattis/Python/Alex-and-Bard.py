
def main():
    k, a, b = input().split()
    k, a, b = int(k), int(a), int(b)

    if(k % (a + b) < a):
        print("Barb\n")
    else:
        print("Alex\n")

if __name__ == '__main__':
    main()