def gcd(a,b):
    if b == 0:
        return a;
    else:
        return gcd(b,a%b)

def power(a,p,mod):
    res= 1
    for i in range(int(p)):
        res = res*a
        res = res%mod
    return res

#main

p = 656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693
q = 204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945177811
n = p*q
phi = (p-1)*(q-1)

can_e = 2
e = 2
while( can_e < phi ):
    c_gcd = gcd(can_e,phi)
    if c_gcd == 1:
        e = can_e
        break
    can_e += 1

print("E ",e)

i = 1
d = 1
while(True):
    j = (phi*i)+1
    if( j%e == 0 ):
        d = j//e
        break
    i += 1

print("D",d)

msg = 60
print("MSG ",msg)

cipher= pow(msg, e, n)
print("Cipher ",cipher)

decrypted = pow(cipher,d,n)
print("decypted ",decrypted)

        

        