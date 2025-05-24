def firstandlastoccurence(arr, key, s, e):
  m = (s + e) // 2;
  global ans
  if (arr[m] == key):
    ans.append(m)
    firstandlastoccurence(arr, key, s, m - 1)
    firstandlastoccurence(arr, key, m + 1, e)
  elif (arr[m] < key):
    firstandlastoccurence(arr, key, m + 1, e)
  else:
    firstandlastoccurence(arr, key, s, m - 1)

arr = [1, 2, 3, 3, 5];
key = 3
ans = []
firstandlastoccurence(arr, 3, 0, 4)
print(min(ans), max(ans))