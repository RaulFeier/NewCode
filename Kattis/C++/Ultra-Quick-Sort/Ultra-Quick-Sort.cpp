#include <iostream>
#include <vector>

using namespace std;
using i64 = long long;

i64 count;

i64 array1[500005];
i64 array2[500005];

void mergesort(i64 *array, i64 len, i64 offset)
{
    if (len > 1)
    {
        i64 *first = array1 + offset;
        
        if (first == array)
        {    
            first = array2 + offset;
        }
        for (int i = 0; i < len; ++i)
        {
            first[i] = array[i];
        }

        i64 firstLength = len / 2;
        i64 secondStart = firstLength, secondLength = len - secondStart;
        i64 *second = first + secondStart;
        
        mergesort(first, firstLength, offset);
        mergesort(second, secondLength, offset + secondStart);
        
        i64 i = 0, j = 0;
        i64 pos = 0;
        
        i64 currentCost = count;
        
        while (i < firstLength && j < secondLength)
        {
            if (first[i] < second[j])
                array[pos++] = first[i++];
            else
            {
                array[pos++] = second[j++];
                count += firstLength - i;
            }
        }
        
        for (; i < firstLength; ++i, ++pos)
        {
            array[pos] = first[i];
        }
        for (; j < secondLength; ++j, ++pos)
        {
            array[pos] = second[j];
        }
    }
}

int main()
{
    i64 N;
    
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> array1[i];
        
        mergesort(array1, N, 0);
        
        cout << count << '\n';
        return 0;        
    }    
}