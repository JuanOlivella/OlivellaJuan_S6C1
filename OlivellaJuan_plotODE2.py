import numpy as np
import matplotlib.pylab as plt

datos1=np.genfromtxt("datosNoFriccionFuerza.dat")

x1 = datos1[:,0]

y1 = datos1[:,1]

y2 = datos1[:,2]

plt.figure()
plt.plot(x1,y1)
plt.title("Solucion con el metodo de RK4 sin friccion ni fuerza externa")
plt.xlabel("$t$")
plt.ylabel("$ theta (t)$")
plt.savefig("SolucionNoFriccionNoFuerza.pdf")


