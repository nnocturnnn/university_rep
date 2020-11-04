import scipy.optimize as opt
import math
from scipy.optimize import fsolve


def toFixed(numObj, digits=0):
    return f"{numObj:.{digits}f}"


    
def newtonn(variables) :
    (x,y) = variables

    first_eq = math.tan(x*y)-x**2
    second_eq = 0.7*x**2+2*y*y-1
    return [first_eq, second_eq]

solution = opt.fsolve(newtonn, (0.1,1))
q = str(solution[0])
print(q[0:7])
print(format(solution[1],'.4f'))

# это 1 код


def double_solve(f1,f2,x0,y0):
    func = lambda x: [f1(x[0], x[1]), f2(x[0], x[1])]
    return fsolve(func,[x0,y0])

def n_solve(functions,variables):
    func = lambda x: [ f(*x) for f in functions]
    return fsolve(func, variables)

f1 = lambda x,y : math.tan(x*y)-x**2
f2 = lambda x,y : 0.7*x**2+2*y*y-1

res = double_solve(f1,f2,0.1,1)
print(res)
