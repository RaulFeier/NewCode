def multiply(a, b):
    return a * b

def adun(a, b):
    return a + b

def main():
    a = int(input())
    c = input()
    b = int(input())
    if c == "*":
        print(multiply(a, b))
    else:
        print(adun(a, b))

if __name__ == "__main__":
    main()