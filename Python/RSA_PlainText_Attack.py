def power(x, y, mod):
    # Initialize result
    res = 1
    while (y > 0):
        # If y is odd, multiply x with result
        if ((y & 1) != 0):
            res = (res * x)%mod
        # y must be even now
        y = y >> 1  # y = y/2
        x = (x * x)%mod  # Change x to x^2
    return res % mod


#main

e = 29
n = 17*19
msg = 50
print("Msg ",msg)
cipher = power(msg,e,n)
print("Cipher ",cipher)

d = 2
while(True):
    new_msg = power(cipher,d,n)
    if(new_msg == msg ):
        print("new_msg ",new_msg)
        print("Private key: ",d)
        break
    d += 1
    
