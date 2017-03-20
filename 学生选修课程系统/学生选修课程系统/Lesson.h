#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class TLesson
{
	friend class Student_arr;//学生课程数组
public:
	void inputLesson();//输入
	void inputLesson(ifstream&lin);//输入别名
	void printLesson();//打印课程
	void printLesson(ofstream&lout);//输出别名
private:
	int  Sno;//学号
	int  Lno;//课程代码
	char Lname[100];//课程名称
	char Lnote[100];//课程性质
	int  Ltime;//总学时
	int  Lgrade;//学分
	int  Ldata;//开课学期
	int  Lperson;//选课人数
};
void TLesson::inputLesson()
{
	cout<<"课程编号:";cin>>Lno;
	cout<<"课程名称:";cin>>Lname;
	cout<<"课程性质:";cin>>Lnote;
	cout<<"总学时:";cin>>Ltime;
	cout<<"学分:";cin>>Lgrade;
	cout<<"开课学期:";cin>>Ldata;
	cout<<"选课人数:";cin>>Lperson;
}
void TLesson::inputLesson(ifstream&lin)
{
	lin>>Lname>>Lnote>>Ltime>>Lgrade>>Ldata>>Lperson;
}
void TLesson::printLesson()
{
	cout<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
}
void TLesson::printLesson(ofstream&lout)
{
	lout<<Lno<<setw(5)<<Lname<<setw(10)<<Lnote<<setw(5)<<Ltime<<setw(5)<<Lgrade<<setw(5)<<Ldata<<setw(5)<<Lperson<<setw(5)<<endl;
}


























//#include<iostream>
//#include<fstream>
//#include<stdlib.h>
//#define MAXSIZE 100;
//using namespace std;
//class TLesson
//{
//public:
//	void Lesson();//初始化
//	void searchLesson(int Lno,char Lname[]);//查询课程
//	void insertLesson(int Lno,char Lname[],char Lnote[],int Ltime,int Lgrade,int data,int Lperson);//添加课程
//	void deletLesson();//删除课程
//	void printLesson();//打印课程
//	void reviseLesson();//修改课程信息
//private:
//	int Lno;//课程代码
//	char Lname[100];//课程名称
//	char Lnote[100];//课程性质
//	int  Ltime;//总学时
//	int  Lgrade;//学分
//	int  Ldata;//开课学期
//	int  Lperson;//选课人数
//};
//void TLesson::searchLesson(int Lno,char Lname[])//查询课程
//{}
//void TLesson::insertLesson(int Lno,char Lname[],char Lnote[],int Ltime,int Lgrade,int data,int Lperson)//添加课程
//{
//	fstream outfile;
//	outfile.open("Lesson.txt",ios::out);
//	if(!outfile)
//	{
//		cout<<"Lesson.txt cannot open!\n";
//		abort();
//	}
//	outfile<<"this is a Lesson manage system\n";
//	outfile<<"Lno\t"<<"Lname\t"<<"Lnote\t"<<"Ltime\t"<<"Lgrade\t"<<"Ldata\t"<<"Lperson\t"<<endl;
//	outfile<<Lno<<"\t"<<Lname<<"\t"<<Lnote<<"\t"<<Ltime<<"\t"<<Lgrade<<"\t"<<Ldata<<"\t"<<Lperson<<endl;
//	cout<<"Write OK!"<<endl;
//	outfile.close();
//}
//void TLesson::deletLesson()//删除课程
//{}
//void TLesson::printLesson()//打印课程
//{
//	fstream infile;
//	infile.open("Lesson.txt",ios::in);
//	if(!infile)
//	{
//		cout<<"Lesson.txt cannot open!\n";
//		abort();
//	}
//	char s[80];
//	while(!infile.eof())
//	{
//		infile.getline(s,sizeof(s));
//		cout<<s<<endl;
//	}
//	cout<<"Read OK!"<<endl;
//	infile.close();
//}
//void TLesson::reviseLesson()//修改课程信息
//{}