
def main():
    a = []

    for i in range(6):
        b = input()
        b = int(b)
        a.append(b)
    
    a.sort(reverse = True)
    print(a)

if __name__ == "__main__":
    main()