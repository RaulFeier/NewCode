import math

def nrDiv(a, b):
    l = []
    ok = False
    for i in range(a, b + 1):
        if math.sqrt(i).is_integer():
            continue
        else:
            m = math.sqrt(i)
            m = int(m)
            x = m 
            y = m + 1
            if x * y == i:
                l.append(i)
    
    return len(l)

print(nrDiv(10, 40))