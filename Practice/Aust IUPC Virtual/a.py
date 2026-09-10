import sys

sys.set_int_max_str_digits(10000)
s = input()
arr = s.split(" ")
n, p, q = int(arr[0]), int(arr[1]), int(arr[2])
sum = 0

for i in range(n):
    x = int(input())
    sum += x

sm = str(sum)

ans = ""
for i in range(p - 1, q):
    ans = ans + sm[i]

print(int(ans))
print(int(ans) % 3)
