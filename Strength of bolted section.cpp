#include<iostream>
#include<cmath>
#include <iomanip>
#include<algorithm>
using namespace std;

int main(){
	float fu, fub, d, d0, t_main, t_cover, n;
	cout<<"fu = "<<flush;
	cin>>fu;
	cout<<"fub = "<<flush;
	cin>>fub;
	cout<<"d = "<<flush;
	cin>>d;
	cout<<"d0 = "<<flush;
	cin>>d0;
	cout<<"Thickness of main plate, t = "<<flush;
	cin>>t_main;
	cout<<"Thickness of cover plate, tc = "<<flush;
	cin>>t_cover;
	cout<<"n = "<<flush;
	cin>>n;
	
	cout<<"1. Strength in shear/ shear capacity of bolt"<<endl;
	float Vdsb;
	cout<<"Vdsb = Vnsb/Ymb"<<endl;
	cout<<"Vnsb = fub(Nn*Anb + Ns*Asb)/(root(3))"<<endl;
	cout<<"Ymb = 1.25"<<endl;
	float Nn, Anb, Ns, Asb;
	Asb = (M_PI*pow(d, 2))/4;
	cout<<"Asb = (pi/4)* d^2 = "<<Asb<<endl;
	Anb = (0.78*M_PI*pow(d, 2))/4;
	cout<<"Anb = 0.78*(pi/4)* d^2 = "<<Anb<<endl;
	cout<<"Nn = "<<flush;
	cin>>Nn;
	cout<<"Ns = "<<flush;
	cin>>Ns;
	cout<<"Vdsb = "<<n<<"*"<<fub<<"*("<<Nn<<"*"<<Anb<<"+"<<Ns<<"*"<<Asb<<")/(root(3)*1.25)"<<endl;
	Vdsb = (n*fub*(Nn*Anb + Ns*Asb))/(pow(3, 0.5)*1.25);
	cout<<"Vdsb ="<<Vdsb<<"N"<<endl;
	cout<<"Vdsb ="<<Vdsb/1000<<"kN"<<endl;
	Vdsb = Vdsb/1000;
	
	cout<<endl<<"2. Bearing capacity of bolt"<<endl;
	float Vdpb,t,Kb,e,p;
	cout<<"Vdpb = Vnpb/Ymb"<<endl;
	cout<<"Vnpb = 2.5*Kb*d*t*fu"<<endl;
	cout<<"Kb = min(e/3d0, ((p/3d0)-0.25), fub/fu, 1)"<<endl;
	cout<<"Minimum end distance, e = 1.5*d0"<<endl;
	cout<<"e = ";
	cin>>e;
	cout<<"Minimum pitch p = 2.5*d"<<endl;
	cout<<"p = ";
	cin>>p;
	float d_ =1;
	float c = fub/fu;
	float b = (p/(3*d0))-0.25;
	float a = e/(3*d0);
	Kb = min(a, min(b , min(c, d_)));
	cout<<"Kb is smaller of("<<e/(3*d0)<<" , "<<(p/(3*d0))-0.25<<" , "<<fub/fu<<" , "<<"1"<<endl;
	cout<<"Kb = "<<Kb<<endl;
	cout<<"t = ";
	cin>>t;
	Vdpb = (2.5*Kb*d*t*fu/1.25)*n;
	cout<<"Vdpb = (2.5*"<<Kb<<"*"<<d<<"*"<<t<<"*"<<fu<<"/1.25)*"<<n<<endl;
	cout<<"Vdpb = "<<Vdpb<<"N"<<endl;
	cout<<"Vdpb = "<<Vdpb/1000<<"kN"<<endl<<endl;
	Vdpb = Vdpb/1000;
	
	cout<<"Strength of bolt = min(Vdsb, Vdpb)"<<endl;
	cout<<"Strenght of bolt = "<<min(Vdsb, Vdpb)<<"KN"<<endl<<endl;
	
	cout<<"3. Tensile strength of plate"<<endl;
	cout<<"Tdn = 0.9*An*fu/Ymb"<<endl;
	float An;
	cout<<"An = ";
	cin>>An;
	float Tdn = 0.9*An*fu/1.25;
	cout<<"Tdn = 0.9*"<<An<<"*"<<fu<<"/1.25"<<endl;
	cout<<"Tdn = "<<Tdn<<"N"<<endl;
	cout<<"Tdn = "<<Tdn/1000<<"KN"<<endl<<endl;
	Tdn = Tdn/1000;
	
	cout<<"Design strength of connection is smallest of shear, bear and tension"<<endl;
	cout<<"Vdc = "<<min(Vdsb, min(Vdpb, Tdn))<<endl<<endl;
	
	cout<<"Design strength of solid plate, Tsp = 0.9*Ag*fu/Ymb"<<endl;
	float Ag;
	cout<<"Ag = ";
	cin>>Ag;
	float Tsp = 0.9*Ag*fu/1.25;
	cout<<"Tsp = 0.9*"<<Ag<<"*"<<fu<<"/1.25"<<endl;
	cout<<"Tsp = "<<Tsp<<"N"<<endl;
	cout<<"Tsp = "<<Tsp/1000<<"KN"<<endl<<endl;
	Tsp = Tsp/1000;
	
	cout<<"For efficiency of connection(n) = Design strength of connection(Vdc)/Design strenght of solid plate(Tsp)"<<endl;
	cout<<"n = ("<<min(Vdsb, min(Vdpb, Tdn))<<"/"<<Tsp<<")*100"<<endl;
	float ne = min(Vdsb, min(Vdpb, Tdn))*100/Tsp;
	cout<<"n = "<<ne<<endl;
	
	
	
}
