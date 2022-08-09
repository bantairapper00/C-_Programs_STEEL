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
	cout<<"From steel table for ..."<<endl;
	float Ae, rvv;
	cout<<"Ae = ";
	cin>>Ae;
	cout<<"rvv = ";
	cin>>rvv;
	cout<<"From table 12 page 48"<<endl;

	float E = 2*pow(10,5), e = pow(250/fy, 0.5);
	float Lambdavv = (L/rvv)/(e*pow(M_PI*M_PI*E/250, 0.5));

	cout<<"Lambda(vv) = (L/rvv)/(absalen*root(M_PI*M_PI*E/250))"<<endl;
	cout<<"E = 2*10^5 and absalen = root(250/fy) = "<<e<<endl;
	cout<<"Lambda(vv) = ("<<L<<"/"<<rvv<<")/("<<e<<"*root((pi^2 * 2*10^5)/250)"<<endl;
	cout<<"Lambda(vv) = "<<Lambdavv<<endl<<endl;
	
	float Lambdafi = ((b1 + b2)/(2*t))/(e*pow(M_PI*M_PI*E/250, 0.5));
	cout<<"Lambdafi = ((b1 + b2)/(2*t))/(absalen*pow(M_PI*M_PI*E/250, 0.5))"<<endl;
	cout<<"Lambda(fi) = (("<<b1<<"+"<<b2<<")/2*"<<t<<")/("<<e<<"*root((pi^2 * 2*10^5)/250)"<<endl;
	cout<<"Lambda(fi) = "<<Lambdafi<<endl<<endl;
	
	cout<<"From table 12 page 48"<<endl;
	float k1, k2, k3;
	cout<<"k1 = ";
	cin>>k1;
	cout<<"k2 = ";
	cin>>k2;
	cout<<"k3 = ";
	cin>>k3;
	cout<<"Lambda(e) = root(k1 + k2*lambda(vv)^2 +k3*lambda(fi)^2)"<<endl;
	float Lambdae = pow((k1 + (k2*pow(Lambdavv, 2)) + (k3*pow(Lambdafi, 2))), 0.5);
	cout<<"Lambda(e) = root("<<k1<<" + "<<k2<<"*"<<Lambdavv<<"^2 + "<<k3<<"*"<<Lambdafi<<"^2)"<<endl;
	cout<<"lambda(e) = "<<Lambdae<<endl<<endl;
	
	float fi, alpha;
	
	cout<<"fi = 0.5*(1 + alpha*(Lambda(e) - 0.2) + (Lambda(e)^2)"<<endl;
	cout<<"alpha = Bucling class page 44"<<endl;
	cout<<"alpha = ";
	cin>>alpha;
	fi =  0.5*(1 + alpha*(Lambdae - 0.2) + (pow(Lambdae, 2)));
	cout<<"fi = 0.5*(1 + "<<alpha<<"*("<<Lambdae<<" - 0.2) + ("<<Lambdae<<"^2)"<<endl;
	cout<<"fi = "<<fi<<endl<<endl;
	
	float fcd = (fy/1.1)/(fi + pow((fi*fi - Lambdae*Lambdae), 0.5));
	cout<<"fcd = (fy/1.1)/(fi + pow((fi*fi - Lambdae*Lambdae), 0.5))"<<endl;
	cout<<"fcd = "<<fcd<<"KN/mm2"<<endl<<endl;
	
	float Pd = Ae*fcd;
	cout<<"Pd = Ac*fcd"<<endl;
	cout<<"Pd = "<<Ae<<"*"<<fcd<<endl;
	cout<<"Pd = "<<Pd<<"N"<<endl<<endl;
	cout<<"Pd = "<<Pd/1000<<"kN"<<endl<<endl;
	
	
}
