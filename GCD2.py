def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)
t=int(input())
for i in range(t):
    a,b=(input()).split(' ')
    print(gcd(int(a),int(b)));
