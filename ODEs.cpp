#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
double dvxdt(double R,double tiempo, double x0, double vx0);
double dvydt(double R,double tiempo, double y0, double vy0);
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
	double M=1.0;

	// primer dt

	euler(0,20,x0,y0,vx0,vy0,0.01,10000,"euler.txt");
	leapfrog(0,20,x0,y0,vx0,vy0,0.01,10000,"leapfrog.txt");
	rungek4(0,20,x0,y0,vx0,vy0,0.01,10000,"rungek4.txt");

	//segundo dt

	euler(0,20,x0,y0,vx0,vy0,0.001,10000,"eulerdt2.txt");
	leapfrog(0,20,x0,y0,vx0,vy0,0.001,10000,"leapfrogdt2.txt");
	rungek4(0,20,x0,y0,vx0,vy0,0.001,10000,"rungek4dt2.txt");

	// tercer dt

	euler(0,20,x0,y0,vx0,vy0,0.0001,10000,"eulerdt3.txt");
	leapfrog(0,20,x0,y0,vx0,vy0,0.0001,10000,"leapfrogdt3.txt");
	rungek4(0,20,x0,y0,vx0,vy0,0.0001,10000,"rungek4dt3.txt");


	return 0;
}

double dvxdt(double R,double tiempo, double x0, double vx0){
	//double r12x= pow(((x0*x0)),0.5);
	double G=39.277;//6.674*pow(10,-11);
	double M=1.0;
	return -G*(M/(pow(R,3)))*(x0-0);
}

double dvydt(double R,double tiempo, double y0, double vy0){
	//double r12y=pow(((y0*y0)-0),0.5);
	double G=39.277;//6.674*pow(10,-11);
	double M=1.0;
	return -G*(M/(pow(R,3)))*(y0-0);
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

	double M=1.0;
	double mtierra=3.00273*pow(10,-6);
	double G=39.277;

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

	double r12x[npuntos];
	double r12y[npuntos];

	r12x[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5);
	r12y[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5); 

	double momentum[npuntos];
	momentum[0]= (r12x[0]*M*vy[0])-(r12y[0]*M*vx[0]);

	double ecinetica[npuntos];
	ecinetica[0]= 0.5*((mtierra*pow(vx[0],2))+(mtierra*pow(vy[0],2)));

	double epotencial[npuntos];
	epotencial[0]= -G*(mtierra*M)/(r12x[0]);

	double esistema[npuntos];
	esistema[0]=ecinetica[0]+epotencial[0];

	double dt= (b-a)/(npuntos-1); //dt para el linspace.

	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){ //Calculo de x, y, vx y vy.
		x[i]= x[i-1] +  (delta*dxdt(t[i-1],x[i-1],vx[i-1]));
		y[i]= y[i-1] +  (delta*dydt(t[i-1],y[i-1],vy[i-1]));
		r12x[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 
		r12y[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 
		
		vx[i]= vx[i-1] + (delta*dvxdt(r12x[i-1],t[i-1],x[i-1],vx[i-1]));
		vy[i]= vy[i-1] + (delta*dvydt(r12y[i-1],t[i-1],y[i-1],vy[i-1]));

		momentum[i]=(r12x[i]*M*vy[i])-(r12y[i]*M*vx[i]);
		ecinetica[i]=0.5*((mtierra*pow(vx[i],2))+(mtierra*pow(vy[i],2)));
		epotencial[i]= -G*(mtierra*M)/(r12x[i]);
		esistema[i]= ecinetica[i]+epotencial[i];

		}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i] << "  " <<momentum[i] <<"  "<< ecinetica[i] << "  "<< epotencial[i] << "  "<< esistema[i]<<endl;
	}
	outfile.close();
}

void leapfrog(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);

	double M=1.0;
	double mtierra=3.00273*pow(10,-6);
	double G=39.277;

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

	double r12x[npuntos];
	double r12y[npuntos];

	r12x[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5);
	r12y[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5); 

	double dt= (b-a)/(npuntos-1); //dt para el linspace.

	double momentum[npuntos];
	momentum[0]= (r12x[0]*M*vy[0])-(r12y[0]*M*vx[0]);

	double ecinetica[npuntos];
	ecinetica[0]= 0.5*((mtierra*pow(vx[0],2))+(mtierra*pow(vy[0],2)));

	double epotencial[npuntos];
	epotencial[0]= -G*(mtierra*M)/(r12x[0]);

	double esistema[npuntos];
	esistema[0]=ecinetica[0]+epotencial[0];

	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){ //Calculo de x, y, vx y vy.
		x[i]= x[i-1] +  (0.5*delta*dxdt(t[i-1],x[i-1],vx[i-1]));
		y[i]= y[i-1] +  (0.5*delta*dydt(t[i-1],y[i-1],vy[i-1]));
		r12x[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 
		r12y[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 
		
		vx[i]= vx[i-1] + (delta*dvxdt(r12x[i-1],t[i-1],x[i-1],vx[i-1]));
		vy[i]= vy[i-1] + (delta*dvydt(r12y[i-1],t[i-1],y[i-1],vy[i-1]));

		momentum[i]=(r12x[i]*M*vy[i])-(r12y[i]*M*vx[i]);
		ecinetica[i]=0.5*((mtierra*pow(vx[i],2))+(mtierra*pow(vy[i],2)));
		epotencial[i]= -G*(mtierra*M)/(r12x[i]);
		esistema[i]= ecinetica[i]+epotencial[i]; 

		}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i] << "  " <<momentum[i]<<"  "<< ecinetica[i] << "  "<< epotencial[i] << "  "<< esistema[i]<<endl;
	}

	outfile.close();
}

void rungek4(double a, double b,double xinicial, double yinicial,double vxini, double vyini, double delta, int npuntos, string filename){
	ofstream outfile;
	outfile.open(filename);

	double M=1.0;
	double mtierra=3.00273*pow(10,-6);
	double G=39.277;

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

	double r12x[npuntos];
	double r12y[npuntos];

	r12x[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5);
	r12y[0]= pow(((x[0]*x[0])+(y[0]*y[0])),0.5); 

	double momentum[npuntos];
	momentum[0]= (r12x[0]*M*vy[0])-(r12y[0]*M*vx[0]);

	double ecinetica[npuntos];
	ecinetica[0]= 0.5*((mtierra*pow(vx[0],2))+(mtierra*pow(vy[0],2)));

	double epotencial[npuntos];
	epotencial[0]= -G*(mtierra*M)/(r12x[0]);

	double esistema[npuntos];
	esistema[0]=ecinetica[0]+epotencial[0];

	for(int i=1; i<npuntos; i++){ //Linspace para el tiempo.
		t[i]= t[i-1]+dt;
	}

	for(int i=1; i<npuntos; i++){ //Calculo k para calcular de x, y, vx y vy.

		k1x= delta*dxdt(t[i-1],x[i-1],vx[i-1]);
		k1y= delta*dydt(t[i-1],y[i-1],vy[i-1]);
		k1vx= delta*dvxdt(r12x[i-1],t[i-1],x[i-1],vx[i-1]);
		k1vy= delta*dvydt(r12y[i-1],t[i-1],y[i-1],vy[i-1]);

		k2x= delta*dxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k1x), vx[i-1]+(0.5*k1vx));
		k2y= delta*dydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k1y), vy[i-1]+(0.5*k1vy));
		k2vx= delta*dvxdt(r12x[i-1],t[i-1]+(0.5*delta), x[i-1]+(0.5*k1x), vx[i-1]+(0.5*k1vx));
		k2vy= delta*dvydt(r12y[i-1],t[i-1]+(0.5*delta), y[i-1]+(0.5*k1y), vy[i-1]+(0.5*k1vy));

		k3x= delta*dxdt(t[i-1]+(0.5*delta), x[i-1]+(0.5*k2x), vx[i-1]+(0.5*k2vx));
		k3y= delta*dydt(t[i-1]+(0.5*delta), y[i-1]+(0.5*k2y), vy[i-1]+(0.5*k2vy));
		k3vx= delta*dvxdt(r12x[i-1],t[i-1]+(0.5*delta), x[i-1]+(0.5*k2x), vx[i-1]+(0.5*k2vx));
		k3vy= delta*dvydt(r12y[i-1],t[i-1]+(0.5*delta), y[i-1]+(0.5*k2y), vy[i-1]+(0.5*k2vy));

		k4x= delta*dxdt(t[i-1]+delta,x[i-1]+k3x,vx[i-1]+k3vx);
		k4y= delta*dydt(t[i-1]+delta,y[i-1]+k3y,vy[i-1]+k3vy);
		k4vx= delta*dvxdt(r12x[i-1],t[i-1]+delta,x[i-1]+k3x,vx[i-1]+k3vx);
		k4vy= delta*dvydt(r12y[i-1],t[i-1]+delta,y[i-1]+k3y,vy[i-1]+k3vy);

		promediox= (1.0/6.0)*(k1x+(2.0*k2x)+(2.0*k3x)+k4x);
		promedioy= (1.0/6.0)*(k1y+(2.0*k2y)+(2.0*k3y)+k4y);
		promediovx= (1.0/6.0)*(k1vx+(2.0*k2vx)+(2.0*k3vx)+k4vx);
		promediovy= (1.0/6.0)*(k1vy+(2.0*k2vy)+(2.0*k3vy)+k4vy);

		x[i]= x[i-1]+promediox;
		y[i]= y[i-1]+promedioy;
		r12x[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 
		r12y[i]=pow(((x[i]*x[i])+(y[i]*y[i])),0.5); 

		vx[i]= vx[i-1]+promediovx;
		vy[i]= vy[i-1]+promediovy;

		momentum[i]=(r12x[i]*M*vy[i])-(r12y[i]*M*vx[i]);

		ecinetica[i]=0.5*((mtierra*pow(vx[i],2))+(mtierra*pow(vy[i],2)));
		epotencial[i]= -G*(mtierra*M)/(r12x[i]);
		esistema[i]= ecinetica[i]+epotencial[i];
	}

	for(int i=0; i<npuntos; i++){
		outfile << t[i] <<"  " << x[i] << "   " << y[i]<< "   " << vx[i] << "   " << vy[i]<< "  " <<momentum[i]<<"  "<< ecinetica[i] << "  "<< epotencial[i] << "  "<< esistema[i]<<endl;
	}

	outfile.close();
}