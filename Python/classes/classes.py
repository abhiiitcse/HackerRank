import math
class Complex(object):
    def __init__(self,real,imag):
        self.real = real
        self.imag = imag
    def __add__(self,no):
        r = self.real + no.real
        i = self.imag + no.imag
        return Complex(r,i)
    def __sub__(self,no):
        r = self.real - no.real
        i = self.imag - no.imag
        return Complex(r,i)
    def __mul__(self,no):
        r = self.real*no.real - self.imag*no.imag
        i = self.real*no.imag + self.imag*no.real
        return Complex(r,i)
    def __div__(self,no):
        x = float(no.real**2 + no.imag**2)
        y = self * Complex(no.real,-no.imag)
        r = y.real/x
        i = y.imag/x
        return Complex(r,i)
    def mod(self):
        r = math.sqrt(self.real**2+self.imag**2)
        return Complex(r,0)
    def __str__(self):
        if self.imag == 0:
            result = "%.2f+0.00i"%(self.real)
        elif self.real == 0:
            if self.imag >= 0:
                result = "0.00+%.2fi"%(self.imag)
            else:
                result = "0.00-%.2fi"%(abs(self.imag))
            
        elif self.imag >= 0:
            result = "%.2f+%.2fi"%(self.real,self.imag)
        else:
            result = "%.2f-%.2fi"%(self.real,abs(self.imag))
        return result

def run():
    c = map(float,raw_input().strip().split())
    d = map(float,raw_input().strip().split())
    C1 = Complex(*c)
    C2 = Complex(*d)
    print "\n".join(map(str,[C1+C2,C1-C2,C1*C2,C1/C2,C1.mod(),C2.mod()]))

if __name__=="__main__":
    run()
