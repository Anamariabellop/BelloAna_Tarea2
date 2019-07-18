#makefile
#%.png: Fourier.py 
	#python Fourier.py
Posiciones.png: euler.txt eulerdt3.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt rungek4dt2.txt rungek4dt3.txt Plots_hw2.py ODEs.cpp
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp

Velocidades.png: euler.txt eulerdt3.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt rungek4dt2.txt rungek4dt3.txt Plots_hw2.py ODEs.cpp
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp

Energias.png: euler.txt eulerdt3.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt rungek4dt2.txt rungek4dt3.txt Plots_hw2.py ODEs.cpp
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp

Energiastotal.png: euler.txt eulerdt3.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt rungek4dt2.txt rungek4dt3.txt Plots_hw2.py ODEs.cpp
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp

