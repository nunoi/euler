#!/usr/bin/python

num = 2 ** 1000
print num

res = 0
s = str(num)
for i in range(0, len(s)):
    res = res + int(s[i])

print "\n" + str(res)

