import numpy as np
import matplotlib.pyplot as plt
import math

P0 = (0,.1)
P1 = (.2,0)
P2 = (.6,.16)
P3 = (1,.3)

def B(t):

    coords=[0,0]
    for i in [0,1]:
        coords[i] = pow((1-t),3) * P0[i] + 3*t*pow((1-t),2) * P1[i] + 3*pow(t,2)*(1-t) * P2[i] + pow(t,3) * P3[i]
    return coords

def dB(t):
    coords=[0,0]
    for i in [0,1]:
        coords[i] = -3*pow((1-t),2) * P0[i] + (9*pow(t,2)-12*t+3) * P1[i] + (6*t-9*pow(t,2)) * P2[i] + 3*pow(t,2) * P3[i]
    return coords

n = 100

x = np.array([])
y = np.array([])
dx= np.array([])
dy= np.array([])

for i in range(n):

    t = 1. * i / n
    coords = B(t)
    x = np.append(x, coords[0])
    y = np.append(y, coords[1])

    dcoords = dB(t)
    dx = np.append(dx,dB(t)[0])
    dy = np.append(dy,dB(t)[1])

# invert the procedure now: given x find t such that B(t) = (x,y)
xbar = 0.756

t = 1
nIter = 20
eps = 0.001
for i in range(nIter):
    dt= - ( B(t)[0] - xbar) / dB(t)[0]
    print("dt= ", dt)
    if(abs(dt)<eps):
        print("Newton converged in ", i, " iterations")
        break
    t = t + dt

print("Solution : ", B(t))

# Prepare the curve for xbar, ybar
xrange = np.array([0,1])
yrange = np.array([np.amin(y),np.amax(y)])
xbar = np.array([xbar,xbar])
ybar = np.array([B(t)[1],B(t)[1]])

fig, ax = plt.subplots()
bezier, = ax.plot(x, y, label="Bezier")
reversex, = ax.plot(xbar,yrange,label="xBar")
reversey, = ax.plot(xrange,ybar,label="yBar")
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.legend()
plt.show()
