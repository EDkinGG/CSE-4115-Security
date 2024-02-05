def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)

def power1(a,p,mod):
    res = 1
    for i in range(p):
        res = res*a
        res = res%mod
    return res

def power(x, y, p):
    # Initialize result
    res = 1
    while (y > 0):
        # If y is odd, multiply x with result
        if ((y & 1) != 0):
            res = res * x
        # y must be even now
        y = y >> 1  # y = y/2
        x = x * x  # Change x to x^2
    return res % p

#main
p = 656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693
q = 204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945177811

n = p*q
phi = (p-1)*(q-1)

can_e = 2
e = 2
while(can_e < phi):
    c_gcd = gcd(can_e,phi)
    if( c_gcd == 1 ):
        e = can_e
        break
    can_e += 1
    

k = 1
d = 1 
while(True):
    j = (k*phi)+1
    if( j%e == 0 ):
        d = j//e
        break
    k += 1
    
msg = 606
print("MSG ",msg)

#signing 
s = pow(msg,d,n)
print("Signing ",s)

#verification
v = pow(s,e,n)
print("Verification ",v)

if(v == msg ):
    print("Verified")
else:
    print("Not verified")