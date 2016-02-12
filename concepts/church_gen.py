#!/usr/bin/python
print "#define _C0(f,z) (z)"
for i in range(1, 100):
    r = "(z)"
    for j in range(0,i):
        r = "f(" + r + ")" 
    print "#define _C" + str(i) + "(f,z) " + r

print "#define TO_CHURCH(i, f, z) _C##i(f, z)"
