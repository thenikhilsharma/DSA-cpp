'''n, q = map(int, input().split())
parent_array = []
for i in range(n):
    array = list(map(int, input().split()))
    array = array[1::]
    parent_array.append(array)
for i in range(q):
    array_num, element = map(int, input().split())
    array_element = parent_array[array_num][element]
    print(array_element)'''

for _ in range(int(input())):
    n, m = list(map(int, input().split()))
    # print(n, m)
    i = 1
    z = n
    while True:
        if (z <= m):
            ans = n*i
            z = ans
            i += 1
            # print(ans, z, i)
        else: break
    # print(ans)
    '''if (ans - m) < (n*(i+1) - m):
        prev = n*(i-1)
        # print(prev)
    elif (ans - m) > (n*(i+1) - m):
        prev = n*(i+1)
        # print(prev)'''
    if m == 1:
        print(abs(m-n))
    else:
        if m%n != 0:
            remaining = abs(m - (n * (i-1)))
        else: remaining = 0
        next_remaining = n - remaining
        print(next_remaining) if (next_remaining < remaining) else print(remaining)