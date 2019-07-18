#makefile
#Imagenes.png prueba.png prueba2.png Tinv.png Transformadas.png Transformadas2.png hibrida.png hibridasinruido.png: Fourier.py euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt
	#python Fourier.py
#Energias.png Energiastotal.png Momentums.png Posiciones.png Velocidades.png: Plots_hw2.py euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt rungek4dt2.txt rungek4dt3.txt
	#python Plots_hw2.py
#euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt: a.out
	#./a.out
#a.out: ODEs.cpp
	#g++ ODEs.cpp

#Imagenes.png prueba.png prueba2.png Tinv.png Transformadas.png Transformadas2.png hibrida.png hibridasinruido.png Energias.png Energiastotal.png Momentums.png Posiciones.png Velocidades.png: Fourier.py Plots_hw2.py euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt
	#python Fourier.py
	#python Plots_hw2.py
#euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt: a.out
#%.txt:a.out
	#./a.out
#a.out: ODEs.cpp
	#g++ ODEs.cpp


FFT.pdf FFtIm.pdf ImProceso.pdf ImHybrid.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf Enertotal_met_dt.pdf: Fourier.py Plots_hw2.py euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt
	python Fourier.py
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp