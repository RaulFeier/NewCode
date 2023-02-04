def sum(v):
    sum = 0
    for i in v:
        sum += i
    return sum

def max1(a, b):
    if a > b:
        return a
    else:
        return b

def max(v):
    max = 0
    for i in v:
        max = max1(max, i)
    return max
    

def main():
    tc = int(input())

    for i in range(tc):
        m, s = map(int, input().split())
        v = [int(x) for x in input().split()]
        s += sum(v)

        sm = 0
        cnt = 0
        for j in range(1, s + 1):
            if sm >= s:
                break
            sm += j
            cnt = j
        
        if sm != s or max(v) > cnt or cnt <= m:
            print("NO")
        else:
            print("YES")
    
if __name__ == "__main__":
    main()