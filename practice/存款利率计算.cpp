#include<iostream>
#include<stdlib.h> 
#include<cmath>
using namespace std;
int main ()
{
	double money,year,rate,sum;
	int flag=1;
	cout<<"欢迎使用利率计算器^0^"<<endl; 
	while(flag!=0)
	{
		cout<<"请输入存款金额："<<endl;
		cin>>money;
		cout<<"请输入存款年限："<<endl;
		cin>>year;
		cout<<"请输入当前年利率："<<endl;
		cin>>rate;
		sum=money*(pow((1+rate),year));
		cout<<"本息为："<<sum<<endl;
		cout<<"需要继续请输入1，否则输入0  ^0^ " <<endl;
		cin>>flag;
		system("cls");
	}
	system("cls");
	cout<<endl;
	cout<<"谢谢使用，再见！"<<endl; 
	return 0;
}
