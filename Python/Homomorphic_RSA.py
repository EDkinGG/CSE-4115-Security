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

p = 101
q = 103
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

msg1 = 10
msg2 = 15

Msg_Combined_cipher = pow(msg1*msg2,e,n)

cipher1 = pow(msg1,e,n)
cipher2 = pow(msg2,e,n)

Cipher_Combined = (cipher1*cipher2) % n

Decrypted_Combined = pow(Msg_Combined_cipher,d,n)
Decrypted_Combined_Cipher = pow(Cipher_Combined,d,n)


print(Decrypted_Combined)
print(Decrypted_Combined_Cipher)



        

        