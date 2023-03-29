def unluckiest_starship(l, r):
    l_str = str(l)
    r_str = str(r)
    if len(l_str) != len(r_str):
        return 10 ** (len(l_str)) - 1
    else:
        unluckiness = int(max(l_str)) - int(min(l_str))
        for i in range(len(l_str)):
            for j in range(i + 1, len(l_str)):
                temp = int(l_str[:i] + l_str[j] + l_str[i+1:j] + l_str[i] + l_str[j+1:])
                if temp <= r:
                    unluckiness = min(unluckiness, int(max(str(temp))) - int(min(str(temp))))
        return l if unluckiness == 0 else temp

t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    print(unluckiest_starship(l, r))
