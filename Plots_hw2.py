import numpy as np
import matplotlib.pylab as plt


euler= np.genfromtxt("euler.txt")
leapfrog= np.genfromtxt("leapfrog.txt")
rungek4 = np. genfromtxt("rungek4.txt")

euler2= np.genfromtxt("eulerdt2.txt")
leapfrog2= np.genfromtxt("leapfrogdt2.txt")
rungek42= np. genfromtxt("rungek4dt2.txt")

euler3= np.genfromtxt("eulerdt3.txt")
leapfrog3= np.genfromtxt("leapfrogdt3.txt")
rungek43= np. genfromtxt("rungek4dt3.txt")

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
plt.plot(euler2[:,1],euler2[:,2], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,5)
plt.plot(leapfrog2[:,1],leapfrog2[:,2], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,6)
plt.plot(rungek42[:,1],rungek42[:,2], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,7)
plt.plot(euler3[:,1],euler3[:,2], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,8)
plt.plot(leapfrog3[:,1],leapfrog3[:,2], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,9)
plt.plot(rungek43[:,1],rungek43[:,2], color= 'm')
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
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("Euler: Vx vs Vy")

plt.subplot(3,3,2)
plt.plot(leapfrog[:,4],leapfrog[:,3], color= 'c')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("leapfrog: Vx vs Vy")

plt.subplot(3,3,3)
plt.plot(rungek4[:,4],rungek4[:,3], color= 'm')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("RK4: Vx vs Vy")

plt.subplot(3,3,4)
plt.plot(euler2[:,4],euler2[:,3], color= 'g')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("Euler: Vx vs Vy")

plt.subplot(3,3,5)
plt.plot(leapfrog2[:,4],leapfrog2[:,3], color= 'c')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("leapfrog: Vx vs Vy")

plt.subplot(3,3,6)
plt.plot(rungek42[:,4],rungek42[:,3], color= 'm')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("RK4: Vx vs Vy")

plt.subplot(3,3,7)
plt.plot(euler3[:,4],euler3[:,3], color= 'g')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("Euler: Vx vs Vy")

plt.subplot(3,3,8)
plt.plot(leapfrog3[:,4],leapfrog3[:,3], color= 'c')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("leapfrog: Vx vs Vy")

plt.subplot(3,3,9)
plt.plot(rungek43[:,4],rungek43[:,3], color= 'm')
plt.xlabel("Vx")
plt.ylabel("Vy")
plt.grid()
plt.title("RK4: Vx vs Vy")

plt.subplots_adjust(hspace=0.5)
plt.savefig("Velocidades.png")

#momentun angular

plt.figure(figsize=(16,12))
plt.subplot(3,3,1)
plt.plot(euler[:,0],euler[:,5], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,2)
plt.plot(leapfrog[:,0],leapfrog[:,5], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,3)
plt.plot(rungek4[:,0],rungek4[:,5], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,4)
plt.plot(euler2[:,0],euler2[:,5], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,5)
plt.plot(leapfrog2[:,0],leapfrog2[:,5], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,6)
plt.plot(rungek42[:,0],rungek42[:,5], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,7)
plt.plot(euler3[:,0],euler3[:,5], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,8)
plt.plot(leapfrog3[:,0],leapfrog3[:,5], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,9)
plt.plot(rungek43[:,0],rungek43[:,5], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: VY vs Y")

plt.subplots_adjust(hspace=0.5)
plt.savefig("Momentums.png")

# energia del sistema 

"""plt.figure(figsize=(16,12))
plt.subplot(3,3,1)
plt.plot(euler[:,0],euler[:,6], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,2)
plt.plot(leapfrog[:,0],leapfrog[:,6], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,3)
plt.plot(rungek4[:,0],rungek4[:,6], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,4)
plt.plot(euler[:,0],euler[:,6], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,5)
plt.plot(leapfrog[:,0],leapfrog[:,6], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,6)
plt.plot(rungek4[:,0],rungek4[:,6], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: X vs Y")

plt.subplot(3,3,7)
plt.plot(euler[:,0],euler[:,6], color= 'g')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("Euler: X vs Y")

plt.subplot(3,3,8)
plt.plot(leapfrog[:,0],leapfrog[:,6], color= 'c')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("leapfrog: X vs Y")

plt.subplot(3,3,9)
plt.plot(rungek4[:,0],rungek4[:,6], color= 'm')
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.title("RK4: VY vs Y")

plt.subplots_adjust(hspace=0.5)
plt.savefig("Energias.png")"""




