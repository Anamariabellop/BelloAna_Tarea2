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
void rungek4(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename);

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
	rungek4(1,100,x0,y0,vx0,vy0,0.1,100,"rungek4.txt");

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

double dxdt(double tiempo, double x0, double vx0){
	return vx0;
}

double dydt(double tiempo, double y0, double vy0){
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

void rungek4(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){
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
	double k1x,k2x,k3x,k4x;
	double k1y,k2y,k3y,k4y;
	double k1vx, k2vx, k3vx, k4vx;
	double k1vy, k2vy, k3vy, k4vy;
	double promediox,promedioy,promediovx,promediovy;

	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){

		k1x= delta*dxdt(t[i-1],x[i-1],vx[i-1]);
		k1y= delta*dydt(t[i-1],y[i-1],vy[i-1]);
		k1vx= delta*dvxdt(t[i-1],x[i-1],vx[i-1]);
		k1vy= delta*dvydt(t[i-1],y[i-1],vy[i-1]);

		k2x= delta*dxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k1x), vx[i-1]+(0.5*k1vx));
		k2y= delta*dydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k1y), vy[i-1]+(0.5*k1vy));
		k2vx= delta*dvxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k1x), vx[i-1]+(0.5*k1vx));
		k2vy= delta*dvydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k1y), vy[i-1]+(0.5*k1vy));

		k3x= delta*dxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k2x), vx[i-1]+(0.5*k2vx));
		k3y= delta*dydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k2y), vy[i-1]+(0.5*k2vy));
		k3vx= delta*dvxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k2x), vx[i-1]+(0.5*k1vx));
		k3vy= delta*dvydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k2y), vy[i-1]+(0.5*k2vy));

		k4x= delta*dxdt(t[i-1]+delta,x[i-1]+k3x,vx[i-1]+k3vx);
		k4y= delta*dydt(t[i-1]+delta,y[i-1]+k3y,vy[i-1]+k3vy);
		k4vx= delta*dvxdt(t[i-1]+delta,x[i-1]+k3x,vx[i-1]+k3vx);
		k4vy= delta*dvydt(t[i-1]+delta,y[i-1]+k3y,vy[i-1]+k3vy);

		promediox= (1.0/6.0)*(k1x+(2.0*k2x)+(2.0*k3x)+k4x);
		promedioy= (1.0/6.0)*(k1y+(2.0*k2y)+(2.0*k3y)+k4y);
		promediovx= (1.0/6.0)*(k1vx+(2.0*k2vx)+(2.0*k3vx)+k4vx);
		promediovy= (1.0/6.0)*(k1vy+(2.0*k2vy)+(2.0*k3vy)+k4vy);

		x[i]= x[i-1]+promediox;
		y[i]= y[i-1]+promedioy;
		vx[i]= vx[i-1]+promediovx;
		vy[i]= vy[i-1]+promediovy;
	}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i] << endl;
	}

	outfile.close();
}