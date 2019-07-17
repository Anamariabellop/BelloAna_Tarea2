import numpy as np
import matplotlib.pylab as plt
from scipy import fftpack
from scipy.fftpack import fft, fftfreq,fft2
from matplotlib.colors import LogNorm
#from PIL import Image, ImageFilter
#import cv2
from scipy import ndimage,misc


#Almacene los datos de las imagenes cara_02_grisesMF.png y de cara_03_grisesMF.png.

feliz= plt.imread("cara_03_grisesMF.png")
triste= plt.imread("cara_02_grisesMF.png")

#Haga filtros para realizar la imagen hibrida.
#Haga graficas de las transformadas de fourier, de los filtros, etc. (Ilustren proceso de realización).


#Transformada Fourier 2D.

Transformadaf= fft2(feliz)
Transformadat= fft2(triste)

#print(Transformadaf)
print("   ")
#print(Transformadat)

freqfeliz= np.fft.fftshift(feliz)
freqtriste= np.fft.fftshift(triste)
#print(np.shape(freqfeliz))
#Shape es de 254, 170.
#print(freqfeliz)

plt.figure(figsize=(10,10))
plt.subplot(2,1,1)
plt.plot(freqfeliz,Transformadaf, color= 'c')
plt.xlabel("freq(Hz)")
plt.ylabel("Tfd")
plt.grid()
plt.title("Transformada 2D Cara feliz")

plt.subplot(2,1,2)
plt.plot(freqtriste,Transformadaf, color= 'm')
plt.xlabel("freq(Hz)")
plt.ylabel("Tfd")
plt.title("Transformada 2D Cara Triste")
plt.subplots_adjust(hspace=0.5)
plt.grid()
plt.savefig("Transformadas.png")

plt.figure(figsize=(10,8))
plt.subplot(1,2,1)
plt.imshow(np.abs(Transformadaf), norm= LogNorm())
plt.xlabel("freq(Hz)")
plt.ylabel("Tfd")
plt.colorbar()
plt.grid()
plt.title("Transformada 2D Cara feliz")

plt.subplot(1,2,2)
plt.imshow(np.abs(Transformadaf), norm= LogNorm())
plt.xlabel("freq(Hz)")
plt.ylabel("Tfd")
plt.colorbar()
plt.title("Transformada 2D Cara Triste")
plt.subplots_adjust(hspace=0.5)
plt.grid()
plt.savefig("Transformadas2.png")

#Filtros de imagen.

m=np.shape(freqfeliz)[0]
n=np.shape(freqfeliz)[1]
#print(m,n)

#Maximo y minimo de imagen feliz.
maximo=np.max(freqfeliz)
minimo=np.min(freqfeliz)
promedio=np.mean(freqfeliz)

#Filtro pasa bajos para feliz

Transformadaf2=np.copy(Transformadaf)
Transformadaf3=np.copy(Transformadat)

for i in range(m):
	for j in range(n):

		if(freqfeliz[i][j]<promedio):
			Transformadaf2[i][j]=0
		else:
			Transformadaf2[i][j]=Transformadaf2[i][j]



plt.figure()
plt.imshow(np.abs(Transformadaf2), norm= LogNorm())
plt.savefig("prueba")

#Maximo y minimo de imagen triste.

maximot=np.max(freqtriste)
minimot=np.min(freqtriste)
promediot=np.mean(freqtriste)

for i in range(m):
	for j in range(n):

		if(freqtriste[i][j]>promediot):
			Transformadaf3[i][j]=0
		else:
			Transformadaf3[i][j]=Transformadaf3[i][j]

plt.figure()
plt.imshow(np.abs(Transformadaf3), norm= LogNorm())
plt.savefig("prueba2")


#Filtro gaussiano para realizar hibrido.

#f(x)= ae^-((x-b)^2/2c^2) Modelo.

#gauss= np.exp(-(x**2)/(sigma**2))

#kernel= cv2.getGaussianKernel(np.shape(feliz)[0],sigma=1)




#Haga una imagen hibrida tal que cuando se observe de cerca, se vea a la persona seria y cuando se observe de lejos se vea a la persona sonriendo.
