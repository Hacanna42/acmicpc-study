# 백준: 두 수 비교하기
# https://www.acmicpc.net/problem/1330
# 2023-11-07

temp = input().split(" ")
a = int(temp[0])
b = int(temp[1])
if a > b:
    print(">")
elif a < b:
    print("<")
else:
    print("==")
