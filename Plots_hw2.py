import numpy as np
import matplotlib.pylab as plt


euler= np.genfromtxt("euler.txt")
leapfrog= np.genfromtxt("leapfrog.txt")
rungek4 = np. genfromtxt("rungek4.txt")

#euler2= np.genfromtxt("euler2.txt")
#leapfrog2= np.genfromtxt("leapfrog2.txt")
#rungek42= np. genfromtxt("rungek42.txt")

#euler3= np.genfromtxt("euler3.txt")
#leapfrog3= np.genfromtxt("leapfrog3.txt")
#rungek43= np. genfromtxt("rungek43.txt")

# x vs y  3 metodos y 3 dts.

plt.figure(figsize=(16,12))
plt.subplot(3,3,1)
plt.plot(euler[:,1],euler[:,2], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,2)
plt.plot(leapfrog[:,1],leapfrog[:,2], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,3)
plt.plot(rungek4[:,1],rungek4[:,2], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,4)
plt.plot(euler[:,1],euler[:,2], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,5)
plt.plot(leapfrog[:,1],leapfrog[:,2], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,6)
plt.plot(rungek4[:,1],rungek4[:,2], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,7)
plt.plot(euler[:,1],euler[:,2], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,8)
plt.plot(leapfrog[:,1],leapfrog[:,2], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,9)
plt.plot(rungek4[:,1],rungek4[:,2], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplots_adjust(hspace=0.5)
plt.savefig("Posiciones.png")


# vy vs vx

plt.figure(figsize=(16,12))
plt.subplot(3,3,1)
plt.plot(euler[:,4],euler[:,3], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,2)
plt.plot(leapfrog[:,4],leapfrog[:,3], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,3)
plt.plot(rungek4[:,4],rungek4[:,3], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,4)
plt.plot(euler[:,4],euler[:,3], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,5)
plt.plot(leapfrog[:,4],leapfrog[:,3], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,6)
plt.plot(rungek4[:,4],rungek4[:,3], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,7)
plt.plot(euler[:,4],euler[:,3], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,8)
plt.plot(leapfrog[:,4],leapfrog[:,3], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,9)
plt.plot(rungek4[:,4],rungek4[:,3], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: VY vs Y")

plt.subplots_adjust(hspace=0.5)
plt.savefig("Velocidades.png")




