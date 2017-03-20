#include<iostream>

using namespace std;

double getcircumference(double radius)
{
	double c;
	c=2*3.14*radius;
	return c;
}

int main()
{
	double radius;
	cout<<"ÇëÊäÈë°ë¾¶£º";
	cin>>radius;
	double c;
	c=getcircumference(radius);
	cout<<"ÖÜ³¤="<<c<<"cm"<<endl;
	return 0;
}
