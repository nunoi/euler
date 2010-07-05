#!/usr/bin/python

import sys

nletters = {
    0:0,
    1:3,
    2:3,
    3:5,
    4:4,
    5:4,
    6:3,
    7:5,
    8:5,
    9:4,
    10:3,
    11:6,
    12:6,
    13:8,
    14:8,
    15:7,
    16:7,
    17:9,
    18:8,
    19:8,
    20:6,
    30:6,
    40:5,
    50:5,
    60:5,
    70:7,
    80:6,
    90:6,
    100:10,
    200:10,
    300:12,
    400:11,
    500:11,
    600:10,
    700:12,
    800:12,
    900:11,
    1000:11}

def get_nletters(n):
    print "n: " + str(n)
    if n <= 20:
        return nletters[n]
    elif n < 100:
        if n % 10 == 0:
            return nletters[n]
        return nletters[(n / 10)*10] + nletters[n % 10]
    elif n < 1000:
        if n % 100 == 0:
            return nletters[n]
        elif (n % 100) < 20:
            return nletters[(n / 100)*100] + nletters[n % 100] + 3
        elif (n % 100) % 10 == 0:
            return nletters[(n / 100)*100] + nletters[n % 100] + 3
        return nletters[(n / 100)*100] + nletters[((n % 100) / 10)*10] + \
                nletters[(n % 100) % 10] + 3
    else:
        return nletters[n]


if len(sys.argv) == 2:
    print get_nletters(int(sys.argv[1]))
else:
    total = 0
    for i in range(1,1001):
        total = total + get_nletters(i)
    print total

