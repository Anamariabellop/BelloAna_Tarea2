#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
double dvxdt(double tiempo, double x0, double vx0);
double dvydt(double tiempo, double y0, double vy0);
double dydt(double tiempo, double x0, double vx0);
double dxdt(double tiempo, double y0, double vy0);
void euler(double a, double b,double xinicial, double yinicial, double vxini, double vyini, double delta, int npuntos, string filename);
void leapfrog(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename);

//void euler(double xinicial, double yinicial, double delta, int npuntos, string filename);

int main()
{
	double x0= 0.1163; //UA
	double y0=0.9772;  //UA
	double vx0= -6.35; //UA/yr
	double vy0= 0.606; //UA/yr
	double M=1.98*pow(10,30);
	euler(1,100,x0,y0,vx0,vy0,0.1,100,"euler.txt");
	leapfrog(1,100,x0,y0,vx0,vy0,0.1,100,"leapfrog.txt");

	return 0;
}

double dvxdt(double tiempo, double x0, double vx0){
	double r12x= pow(((x0*x0)-0),0.5);
	double G=6.674*pow(10,-11);
	double M=1.98*pow(10,30);
	return -G*(M/(pow(r12x,3)))*(x0-0);
}

double dvydt(double tiempo, double y0, double vy0){
	double r12y=pow(((y0*y0)-0),0.5);
	double G=6.674*pow(10,-11);
	double M=1.98*pow(10,30);
	return -G*(M/(pow(r12y,3)))*(y0-0);
}

double dydt(double tiempo, double x0, double vx0){
	return vx0;
}

double dxdt(double tiempo, double y0, double vy0){
	return vy0;
}

void euler(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);

	//Arreglos.
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

	double dt= (b-a)/(npuntos-1); //dt para el linspace.


	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){ //Calculo de x, y, vx y vy.
		x[i]= x[i-1] +  (delta*dxdt(t[i-1],x[i-1],vx[i-1]));
		y[i]= y[i-1] +  (delta*dydt(t[i-1],y[i-1],vy[i-1]));
		vx[i]= vx[i-1] + (delta*dvxdt(t[i-1],x[i-1],vx[i-1]));
		vy[i]= vy[i-1] + (delta*dvydt(t[i-1],y[i-1],vy[i-1]));
		}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i] << endl;
	}
	outfile.close();
}

void leapfrog(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);

	//Arreglos.
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

	double dt= (b-a)/(npuntos-1); //dt para el linspace.


	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){ //Calculo de x, y, vx y vy.
		x[i]= x[i-1] +  (0.5*delta*dxdt(t[i-1],x[i-1],vx[i-1]));
		y[i]= y[i-1] +  (0.5*delta*dydt(t[i-1],y[i-1],vy[i-1]));
		vx[i]= vx[i-1] + (delta*dvxdt(t[i-1],x[i-1],vx[i-1]));
		vy[i]= vy[i-1] + (delta*dvydt(t[i-1],y[i-1],vy[i-1]));
		}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i] << endl;
	}

	outfile.close();
}