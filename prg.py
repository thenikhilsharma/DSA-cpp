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

def solution(n, i):
    if n == 1:
        return i
    return solution(n-1, i+1)

for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    big = a[0]
    a.pop(0)
    add = sum(a)
    ans = add
    for i in a:
        ans += solution(i, 0)
    print(ans)