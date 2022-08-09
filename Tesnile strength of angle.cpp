#include<iostream>
#include<cmath>
#include <iomanip>
#include<algorithm>
using namespace std;

int main(){
	float fu, fub, fy, d, d0, t_main, t_cover, L1, L2, n;
	cout<<"fu = "<<flush;
	cin>>fu;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<"d = "<<flush;
	cin>>d;
	cout<<"d0 = "<<flush;
	cin>>d0;
	cout<<"Thickness of main plate, t = "<<flush;
	cin>>t_main;
	cout<<"Thickness of cover plate, tc = "<<flush;
	cin>>t_cover;
	cout<<"Width of cover plate, L1 = "<<flush;
	cin>>L1;
	cout<<"Length of cover plate, L2 = "<<flush;
	cin>>L2;
	cout<<"n = ";
	cin>>n;
	
	cout<<endl;
	cout<<"1. Shear strength due to yielding"<<endl;
	float t = min(t_main, t_cover);
	float Ag = ((L1 - (t_cover/2)) + (L2 - (t_cover/2)))*t_cover;
	float Ym0 = 1.1;
	float Tdg = fy*Ag/Ym0;
	cout<<"Tdg = fy*Ag/Yma"<<endl;
	cout<<"Ag = ((L1 - (t/2)) + (L2 - (t/2)))*t"<<" = "<<Ag<<" and Ym0 = "<<Ym0<<endl;
	cout<<"Tdg = "<<fy<<"*"<<Ag<<"/"<<Ym0<<endl;
	cout<<"Tdg = "<<fixed<<setprecision(2)<<Tdg<<"N"<<endl;
	cout<<"Tdg = "<<fixed<<setprecision(2)<<Tdg/pow(10,3)<<"kN"<<endl<<endl;
	
	cout<<"2. Strength of Rupture"<<endl;
	float Anc = (L1 - (t_cover/2) - (n*d0))*t_cover, Ym1 = 1.25;
	float Ago = (L2 - (t_cover/2))*t_cover;
	float W, bs, Lc;
	cout<<"W = ";
	cin>>W;
	cout<<"bs = ";
	cin>>bs;
	cout<<"Lc = ";
	cin>>Lc;
	float B = 1.4 - 0.076*((W/t_cover)*(fy/fu)*(bs/Lc));
	float Tdn = (0.9*fu*Anc/Ym1) + (B*Ago*fy/Ym0);
	cout<<"Tdn = (0.9*fu*Anc/Ym1) + (B*Ago*fy/Ym0)"<<endl;
	cout<<"Anc = ("<<L1<<" - "<<"("<<t_cover<<"/2) - ("<<n<<"*"<<d0<<"))*"<<t_cover<<" = "<<Anc<<endl;
	cout<<"Ago = ("<<L2<<" - ("<<t_cover<<"/2))*"<<t_cover<<" = "<<Ago<<endl;
	cout<<"B = 1.4 - 0.076*((W/t)*(fy/fu)*(bs/Lc))"<<endl;
	cout<<"B = 1.4 - 0.076*(("<<W<<"/"<<t_cover<<")*("<<fy<<"/"<<fu<<")*("<<bs<<"/"<<Lc<<"))"<<endl;
	cout<<"B = "<<B<<endl;
	cout<<"B >= 0.7 and B <= ((fu*Ym0)/(fy*Ym1)) = "<<((fu*Ym0)/(fy*Ym1))<<endl;
	cout<<"Tdn = ("<<0.9<<"*"<<fu<<"*"<<Anc<<"/"<<Ym1<<") + ("<<B<<"*"<<Ago<<"*"<<fy<<"/"<<Ym0<<")"<<endl;
	cout<<"Tdn = "<<fixed<<setprecision(2)<<Tdn<<"N"<<endl;
	cout<<"Tdn = "<<fixed<<setprecision(2)<<Tdn/pow(10,3)<<"kN"<<endl<<endl;
	cout<<"Block shear strength"<<endl;
	float Avg, Avn, Atn, Atg;
	cout<<"Avg = ";
	cin>>Avg;
	cout<<"Avn = ";
	cin>>Avn;
	cout<<"Atg = ";
	cin>>Atg;
	cout<<"Atn = ";
	cin>>Atn;
	
	float Tdb1 = ((Avg*fy)/(pow(3, 0.5)*Ym0)) + ((0.9*Atn*fu)/(Ym1));
	float Tdb2 = ((0.9*Avn*fu)/(pow(3, 0.5)*Ym1)) + ((Atg*fy)/(Ym0));
	cout<<"Tdb1 = ((Avg*fy)/(pow(3, 0.5))*Ym0)) + ((0.9*Atn*fu)/(Ym1))"<<endl;
	cout<<"Tdb1 = (("<<Avg<<"*"<<fy<<")/(pow(3, 0.5))*"<<Ym0<<")) + ((0.9*"<<Atn<<"*"<<fu<<")/("<<Ym1<<"))"<<endl;
	cout<<"Tdb1 = "<<fixed<<setprecision(2)<<Tdb1<<"N"<<endl;
	cout<<"Tdb1 = "<<fixed<<setprecision(2)<<Tdb1/pow(10, 3)<<"kN"<<endl<<endl;
	cout<<"Tdb2 = ((0.9*Avn*fu)/(pow(3, 0.5)*Ym1)) + ((Atg*fy)/(Ym0))"<<endl;
	cout<<"Tdb2 = ((0.9*"<<Avn<<"*"<<fu<<")/(pow(3, 0.5)*"<<Ym1<<")) + (("<<Atg<<"*"<<fy<<")/("<<Ym0<<"))"<<endl;
	cout<<"Tdb2 = "<<fixed<<setprecision(2)<<Tdb2<<"N"<<endl;
	cout<<"Tdb2 = "<<fixed<<setprecision(2)<<Tdb2/pow(10, 3)<<"KN"<<endl;
	float Tdb = min(Tdb1, Tdb2);
	cout<<"Block shear strength = "<<Tdb/pow(10, 3)<<"kN"<<endl<<endl;
	
	cout<<"Design tensile strength of plate = "<<min(Tdg, min(Tdn, Tdb))/pow(10, 3)<<"KN"<<endl;
}
	
