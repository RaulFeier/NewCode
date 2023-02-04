
def main():
    a, b, c, d = input().split()
    a, b, c, d = int(a), int(b), int(c), int(d)
    if a > 0 and b > 0 and c > 0 and a + b + c >= d and d >= 3:
        print("Yes\n")
    else:
        print("No\n")

if __name__ == "__main__":
    main()