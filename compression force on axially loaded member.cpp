#include<iostream>
#include<cmath>
#include <iomanip>
#include<algorithm>
using namespace std;

int main(){
	float b1, b2, t, L, fy;
	cout<<"b1 = ";
	cin>>b1;
	cout<<"b2 = ";
	cin>>b2;
	cout<<"t = ";
	cin>>t;
	cout<<"L = ";
	cin>>L;
	cout<<"fy = ";
	cin>>fy;
	cout<<"write Given, "<<endl;
	cout<<"Pd = Ae*fcd"<<endl;
	
	cout<<"Lambda = Non dimensional effective slenderness ratio = root(fy/fcc)"<<endl;
	cout<<"fcc = Eulers bucling stress = pi^2*E/(KL/rmin)^2"<<endl;
	cout<<"From steel table for ..."<<endl;
	float Ae, K, rmin;
	cout<<"Ae = ";
	cin>>Ae;
	cout<<"rmin = ";
	cin>>rmin;
	cout<<"K = ";
	cin>>K;
	float fcc = M_PI*M_PI*2*pow(10, 5)/pow((K*L/rmin), 2);
	cout<<"fcc = "<<fcc<<endl<<endl;
	float Lambda = pow(fy/fcc, 0.5);
	cout<<"Lambda = root("<<fy<<"/"<<fcc<<")"<<endl;
	cout<<"Lambda = "<<Lambda<<endl<<endl;

	float fi, alpha;
	cout<<"fi = 0.5*(1 + alpha*(Lambda - 0.2) + (Lambda^2)"<<endl;
	cout<<"alpha = Bucling class page 44"<<endl;
	cout<<"alpha = ";
	cin>>alpha;
	fi =  0.5*(1 + alpha*(Lambda - 0.2) + (pow(Lambda, 2)));
	cout<<"fi = 0.5*(1 + "<<alpha<<"*("<<Lambda<<" - 0.2) + ("<<Lambda<<"^2)"<<endl;
	cout<<"fi = "<<fi<<endl<<endl;
	
	float fcd = (fy/1.1)/(fi + pow((fi*fi - Lambda*Lambda), 0.5));
	cout<<"fcd = (fy/1.1)/(fi + pow((fi*fi - Lambda*Lambda), 0.5))"<<endl;
	cout<<"fcd = "<<fcd<<"KN/mm2"<<endl<<endl;
	
	float Pd = Ae*fcd;
	cout<<"Pd = Ac*fcd"<<endl;
	cout<<"Pd = "<<Ae<<"*"<<fcd<<endl;
	cout<<"Pd = "<<Pd<<"N"<<endl<<endl;
	cout<<"Pd = "<<Pd/1000<<"kN"<<endl<<endl;
	
	
}
