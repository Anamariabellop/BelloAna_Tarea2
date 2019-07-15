import numpy as np
import matplotlib.pylab as plt
from scipy import fftpack
from scipy.fftpack import fft, fftfreq,fft2
from matplotlib.colors import LogNorm


#Almacene los datos de las imagenes cara_02_grisesMF.png y de cara_03_grisesMF.png.

feliz= plt.imread("cara_03_grisesMF.png")
triste= plt.imread("cara_02_grisesMF.png")

#Haga filtros para realizar la imagen hibrida.
#Haga graficas de las transformadas de fourier, de los filtros, etc. (Ilustren proceso de realización).


#Transformada Fourier 2D.

Transformadaf= fft2(feliz)
Transformadat= fft2(triste)

freqfeliz= np.fft.fftshift(feliz)
freqtriste= np.fft.fftshift(triste)

plt.figure(figsize=(10,8))
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


#Haga una imagen hibrida tal que cuando se observe de cerca, se vea a la persona seria y cuando se observe de lejos se vea a la persona sonriendo.
