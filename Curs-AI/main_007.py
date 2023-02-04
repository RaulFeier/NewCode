
def main():
    w = input()
    ln = input().split()
    ln = [x for x in ln]

    for i in ln:
        if w in i:
            print(i)

if __name__ == "__main__":
    main()