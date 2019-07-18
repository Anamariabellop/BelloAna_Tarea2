#makefile
FFT.pdf FFtIm.pdf ImProceso.pdf ImHybrid.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf Enertotal_met_dt.pdf: Fourier.py Plots_hw2.py euler.txt eulerdt2.txt eulerdt3.txt leapfrog.txt leapfrogdt2.txt leapfrogdt3.txt rungek4.txt
	python Fourier.py
	python Plots_hw2.py
%.txt: a.out
	./a.out
a.out: ODEs.cpp
	g++ ODEs.cpp