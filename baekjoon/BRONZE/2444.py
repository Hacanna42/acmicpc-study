n = int(input())

for i in range(n):
    print((n-i)*" "+(i*2-1)*"*")
for i in range(n):
    print(i*" "+((n-i)*2-1)*"*")
