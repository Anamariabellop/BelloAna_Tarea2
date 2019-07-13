#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

//void euler(double xinicial, double yinicial, double delta, int npuntos, string filename);

int main()
{
	double x0= 0.1163; //UA
	double y0=0.9772;  //UA
	double vx0= -6.35; // UA/yr
	double vy0= 0.606; //UA/yr
	double M=1.98*pow(10,30);
	return 0;
}

double dvxdt(double tiempo, double x0, double vx0){
	double r12x;
	double r2x;
	double r1x;
	double G=6.674*pow(10,-11);
	double M=1.98*pow(10,30);
	return -G*(M/(pow(r12x,3)))*(r2x-r1x);
}

double dvydt(double tiempo, double y0, double vy0){
	double r12y;
	double r2y;
	double r1y;
	double G=6.674*pow(10,-11);
	double M=1.98*pow(10,30);
	return -G*(M/(pow(r12y,3)))*(r2y-r1y);
}

double dydt(double tiempo, double x0, double vx0){
	return vx0;
}

double dxdt(double tiempo, double y0, double vy0){
	return vy0;
}

void euler(double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);


	double t[npuntos];
	t[0]=0.0;

	double x[npuntos];
	x[0]=xinicial;

	double y[npuntos];
	y[0]=yinicial;

	double vx[npuntos];
	vx[0]=vxini;

	double vy[npuntos];
	vy[0]=vyini;

	double dt= (b-a)/(npuntos-1);


	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i]+dt;
	}

	for(int i=1; i<npuntos; i++){

		x[i]= x[i-1] + (delta*dxdt(t[i],x[i-1],vx[i-1]));
		y[i]= y[i-1] + (delta*dydt(t[i],y[i-1],vy[i-1]));
		vx[i]= vx[i-1] +(delta*dvxdt(t[i],x[i-1],vx[i-1]));
		vy[i]= vy[i-1] +(delta*dvydt(t[i],y[i-1],vy[i-1]));

		outfile << x[i-1] << "   " << y[i-1]<< "   " << vx[i-1] << "   " << vy[i-1] << endl;
	}




}