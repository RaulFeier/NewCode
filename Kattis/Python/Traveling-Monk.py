a,d = [int(x) for x in input().split()]
asc = []
desc = []

for x in range(a):
    asc.append([float(x) for x in input().split()])

for x in range(d):
    desc.append([float(x) for x in input().split()])

total_distance = 0
total_time = 0
for x in asc:
    total_distance += x[0]
    total_time += x[1]

def asct(asc,time):
    completed_time = 0
    distance = 0
    for segment in asc:
        if completed_time < time and segment[1]+completed_time < time:
            distance += (segment[0])
            completed_time += segment[1]
        else:
            distance += (segment[0]/segment[1] * (time-completed_time))
            return distance
    return distance

def desct(desc, time):
    completed_time = 0
    distance = 0
    for segment in desc:
        if completed_time < time and segment[1] + completed_time < time:
            distance += (segment[0])
            completed_time += segment[1]
        else:
            distance += (segment[0]/segment[1] * (time-completed_time))
            return total_distance - distance
    return total_distance - distance



def ans():
    mid = 0
    max = total_time
    min = 0
    while mid != (max+min)/2:
        mid = (max + min) / 2
        asc_distance = asct(asc, mid)
        desc_distance = desct(desc,mid)

        if asc_distance == desc_distance:
            max = mid
        elif asc_distance < desc_distance:
            min = mid
        elif asc_distance > desc_distance:
            max = mid
    return '%.5f'%mid


print (ans())