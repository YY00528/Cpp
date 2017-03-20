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
	void inputLesson1(ifstream&lin);//输入别名引用
	void printLesson();//打印课程
	void printLesson2();//c调用
	void printLesson1(ofstream&lout);//输出别名引用
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
	//cout<<"选课人数:";cin>>Lperson;
}
void TLesson::inputLesson1(ifstream&lin)//输入别名引用
{
	lin>>Lname>>Lnote>>Ltime>>Lgrade>>Ldata;//>>Lperson
}
void TLesson::printLesson()
{
	cout<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
}
void TLesson::printLesson2()
{
	cout<<setw(10)<<Sno<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<endl;
}
void TLesson::printLesson1(ofstream&lout)//输出别名引用
{
	lout<<Lno<<setw(10)<<Lname<<setw(10)<<Lnote<<setw(5)<<Ltime<<setw(5)<<Lgrade<<setw(5)<<Ldata<<setw(5)<<Lperson<<setw(5)<<endl;
}
class TStudent
{
	friend class Student_arr;//学生课程数组
public:
	void inputStudent();//输入
	void inputStudent1(ifstream&lin);//输入别名引用
	void printStudent();//打印学生信息
	void printStudent1(ofstream&lout);//输出别名引用
private:
	int Snum;//学号
	char Sname[20];//姓名
	char Ssex[2];//性别
	int  Sage;//年龄
	char dept[20];//系别
	int  classno;//班级
	char phonenum[20];//联系方式
};
void TStudent::inputStudent()
{
	cout<<"学号:";cin>>Snum;
	cout<<"姓名:";cin>>Sname;
	cout<<"性别:";cin>>Ssex;
	cout<<"年龄:";cin>>Sage;
	cout<<"系别:";cin>>dept;
	cout<<"班级:";cin>>classno;
	cout<<"联系方式:";cin>>phonenum;
}
void TStudent::inputStudent1(ifstream&lin)
{
	lin>>Snum>>Sname>>Ssex>>Sage>>dept>>classno>>phonenum;
}
void TStudent::printStudent()
{
	cout<<setw(10)<<Snum<<setw(10)<<Sname<<setw(12)<<Ssex<<setw(10)<<Sage<<setw(10)<<dept<<setw(10)<<classno<<setw(10)<<phonenum<<endl;
}
void TStudent::printStudent1(ofstream&lout)
{
	lout<<Snum<<" "<<Sname<<" "<<Ssex<<" "<<Sage<<" "<<dept<<" "<<classno<<" "<<phonenum<<" "<<endl;
}
class Student_arr//类数组
{
	friend class TStudent;
	friend class TLesson;
public:
	Student_arr()
	{
		int i=0;
		LS=0;
		lin.open("Student.txt",ios::in);
		pb=new TStudent[30];//定义学生数组
		//while(!lin.eof())
		for(i=0;i<0;i++)
		{
			//lin.getline((pb+i),sizeof(pb));
			//i++;
			//LS++;
			lin>>(pb+i)->Snum;
			if((pb+i)->Snum==-1)
				break;
			else{
				(pb+i)->inputStudent1(lin);
				LS++;
			}
		}
		lin.close();
	}
	Student_arr(int a)
	{
		int i;
		L=0;
		lin.open("Lesson.txt",ios::in);
		p=new TLesson[30];//定义课程数组
		for(i=0;i<0;i++)
		{
			lin>>(p+i)->Lno;
			if((p+i)->Lno==-1)
				break;
			else{
				(p+i)->inputLesson1(lin);
				L++;
			}
		}
		lin.close();
	}
	Student_arr(int a,int b)
	{
		int i;
		L=0;
		lin.open("S_Lesson.txt",ios::in);
		p=new TLesson[30];//定义学生选课课程数组
		for(i=0;i<0;i++)
		{
			lin>>(p+i)->Sno;
			if((p+i)->Sno==-1)
				break;
			else{
				lin>>(p+i)->Lno;
				(p+i)->inputLesson1(lin);
				L++;
			}
		}
		lin.close();
	}
	void Print();//输出学生数组
	void Print1();//输出课程数组
	void Print2();//输出选课数组
	void lessonInsert();//录入课程信息
	void studentInsert();//录入学生信息
	void search_by_grade();//按学分查询
	void search_by_Lname();//按课程名查询
	TLesson search_by_Lno();//按课程号查询
	void search_sdudent_by_Snum();//按学号查询学生
	void search_sdudent_by_Sname();//按姓名查询学生
	void search_by_Sno(Student_arr&c);////按学生查询所选修的课程
	int  total_grade(int i);//计算某学生的总学分 
	void  choose(Student_arr&a,Student_arr&b,Student_arr&c);//实现选课功能
	void deleteLesson(Student_arr&c);//删除课程记录
	void deleteStudent(Student_arr&b,Student_arr&c);//删除学生记录
	void reviseLesson();//修改课程记录
	void reviseLesson(int);//修改课程记录
	void reviseStudent();//修改学生记录
	int  GetLS()//获取学生数
		{return LS;}
	int  GetL()//获取课程数
		{return L;}
	void sdudent_save();//保存student文件
	void Lesson_save();//保存lesson文件
	void S_L_save();//保存选课信息文件
private:
		int L,LS;//长度
		ifstream lin;//输入流
		ofstream lout;//输出流
		TLesson  *p;//课程数组地址
		TStudent *pb;//学生数组地址
};
void Student_arr::Print()//输出学生数组
{
	int i;
	//cout<<setw(10)<<Snum<<setw(10)<<Sname<<setw(12)<<Ssex<<setw(10)<<Sage<<setw(10)<<dept<<setw(10)<<classno<<setw(10)<<phonenum<<endl;
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(12)<<"性别"<<setw(10)<<"年龄"<<setw(10)<<"系别"<<setw(10)<<"班级"<<setw(10)<<"联系方式"<<endl;
	for(i=0;i<LS;i++)
		(pb+i)->printStudent();
}
void Student_arr::Print1()//输出课程数组
{
	int i;
	//cout<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
	cout<<setw(10)<<"课程代码"<<setw(10)<<"课程名称"<<setw(12)<<"课程性质"<<setw(10)<<"总学时"<<setw(10)<<"学分"<<setw(10)<<"开课学期"<<setw(10)<<"选修人数"<<endl;
	for(i=0;i<L;i++)
		(p+i)->printLesson();
}
void Student_arr::Print2()//输出选课数组
{
	int i;
	cout<<setw(10)<<"选课学生"<<setw(10)<<"课程代码"<<setw(10)<<"课程名称"<<setw(12)<<"课程性质"<<setw(10)<<"总学时"<<setw(10)<<"学分"<<setw(10)<<"开课学期"<<endl;
	for(i=0;i<L;i++)
		(p+i)->printLesson2();
}
void Student_arr::lessonInsert()//录入课程信息
{
	int i=0,flag=0;
	(p+L)->inputLesson();//调用信息录入，并将录入的信息加在数组末尾
	(p+L)->Lperson=0;
	for(i=0;i<L;i++)
	if(((p+i)->Lno==((p+L)->Lno))||(strcmp((p+i)->Lname,((p+L)->Lname))==0)){
		(p+i)->printLesson();
		flag=1;
	}
	if(flag!=1){
		L++;
		cout<<"添加成功！！\n";
	}
	else if(1==flag)
		cout<<"已存在所添加的课程,添加失败！！\n";
}
void Student_arr::studentInsert()//录入学生信息
{
	int i=0,flag=0;
	(pb+LS)->inputStudent();//调用信息录入，并将录入的信息加在数组末尾
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==((pb+LS)->Snum)){
			(pb+i)->printStudent();
			flag=1;
		}
	if(flag!=1){
		LS++;
		cout<<"添加成功！！\n";
	}
	else if(1==flag)
		cout<<"已存在所添加的学生,添加失败！！\n";
}
void Student_arr::search_by_grade()//按学分查询课程
{
	int k,i;
	cout<<"请输入学分值：";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lgrade==k){
			(p+i)->printLesson();
			return;
		}
	cout<<"未找到！！！"<<endl;
}
void Student_arr::search_by_Lname()//按课程名查询
{
	int i;
	char k[20];
	cout<<"请输入课程名：";
	cin>>k;
	for(i=0;i<L;i++)
		if(strcmp((p+i)->Lname,k)==0){
			(p+i)->printLesson();
			return;
		}
	cout<<"未找到！！！"<<endl;
}
TLesson Student_arr::search_by_Lno()//按课程号查询
{
	int k,i;
	cout<<"请输入课程号：";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+i)->printLesson();
			return *(p+i);
		}
	cout<<"未找到！！！"<<endl;
}
void Student_arr::search_by_Sno(Student_arr&c)//按学生查询所选修的课程
{
	int k,i;
	TLesson *b=c.p;
	cout<<"请输入你想查询的学生的学号：";
	cin>>k;
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(12)<<"性别"<<setw(10)<<"年龄"<<setw(10)<<"系别"<<setw(10)<<"班级"<<setw(10)<<"联系方式"<<endl;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+i)->printStudent();
		}
	cout<<setw(10)<<"选课学生"<<setw(10)<<"课程代码"<<setw(10)<<"课程名称"<<setw(12)<<"课程性质"<<setw(10)<<"总学时"<<setw(10)<<"学分"<<setw(10)<<"开课学期"<<endl;
	for(i=0;i<c.L;i++)
		if((b+i)->Sno==k){
			(b+i)->printLesson2();
		}
}
void Student_arr::search_sdudent_by_Snum()//按学号查询学生
{
	int k,i;
	cout<<"请输入你想查询的学号：";
	cin>>k;
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(12)<<"性别"<<setw(10)<<"年龄"<<setw(10)<<"系别"<<setw(10)<<"班级"<<setw(10)<<"联系方式"<<endl;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+i)->printStudent();
			return;
		}
	cout<<"未找到！！！"<<endl;
}
void Student_arr::search_sdudent_by_Sname()//按姓名查询学生
{
	int i;
	char k[20];
	cout<<"请输入你想查询的学生姓名：";
	cin>>k;
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(12)<<"性别"<<setw(10)<<"年龄"<<setw(10)<<"系别"<<setw(10)<<"班级"<<setw(10)<<"联系方式"<<endl;
	for(i=0;i<LS;i++)
		if(strcmp((pb+i)->Sname,k)==0){
			(pb+i)->printStudent();
			return;
		}
	cout<<"未找到！！！"<<endl;
}
int Student_arr::total_grade(int i)//计算某学生的总学分
{
	int k,j=0;
	for(k=0;k<L;k++)
		if(p[k].Sno==i)
			j=j+p[k].Lgrade;
	return j;
}
void  Student_arr::choose(Student_arr&a,Student_arr&b,Student_arr&c)//选课功能实现
{
	int i,k,j,fflag=0,m;
	char flag='y';
	TLesson l1;
	cout<<"请输入你的学号：";
	cin>>j;
	for(i=0;i<=a.LS;i++)
	if((a.pb+i)->Snum==j){
		fflag=1;
	}
	if(0==fflag){
		cout<<"学号输入有误！！！\n";
		return ;
	}
	while(flag=='y'||flag=='Y')
	{
		cout<<"课程列表：\n";
		b.Print1();
		l1=b.search_by_Lno();//选课
		l1.Sno=j;//将学号填入数据
		i=0;
		do{
			if(((c.p+i)->Lno==l1.Lno)&&((c.p+i)->Sno==l1.Sno))
				{
					cout<<"你已选修过此课程，请重新选择其他课程\n";
					return;
				}
			i++;
		}while(i<=c.L);
		c.p[L]=l1;//将节点填入课程链表
		L++;
		k=total_grade(j);
		cout<<"当前学分为"<<k<<endl;;
		cout<<"继续选课请输入y，否则输入n：";
		cin>>flag;
		if('y'!=flag&&'Y'!=flag&&'n'!=flag&&'N'!=flag)return;
		b.reviseLesson(l1.Lno);
	}
	return ;
}
void Student_arr::deleteLesson(Student_arr&c)//删除课程记录
{
	int k,i,j,m,flag=0;
	cout<<"请输入你想删除的课程号：";
	cin>>k;
	for(i=0;i<L;i++){
		if((p+i)->Lno==k){
			for(j=i;j<L-1;j++)
			{
				*(p+j)=*(p+j+1);
			}
			L--;
			for(j=0;j<=c.L+1;j++)
			{
				if(((c.p+j)->Lno)==k)
				{
					for(m=0;m<c.L+1;m++)
					{
						*(c.p+j+m)=*(c.p+j+m+1);
					}
					c.L--;
				}
			}
			for(j=0;j<=c.L+1;j++)
			{
				if(((c.p+j)->Lno)==k)
				{
					for(m=0;m<c.L+1;m++)
					{
						*(c.p+j+m)=*(c.p+j+m+1);
					}
					c.L--;
				}
			}
			flag=1;
		}
	}
	if(1==flag){
		cout<<"删除成功！！\n";
		return ;
	}
	else if(0==flag)
		cout<<"记录为空！！\n";
}
void Student_arr::deleteStudent(Student_arr&b,Student_arr&c)//删除学生记录
{
	int k,i,j,m,n;
	cout<<"请输入你想删除学生记录的学号：";
	cin>>k;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			for(j=i;j<LS-1;j++)
			{
				*(pb+j)=*(pb+j+1);
			}
			LS--;
			for(j=0;j<=c.L;j++)
			{
				if((c.p+j)->Sno==k)
				{
					for(n=0;n<b.L;n++)
						if(((b.p+n)->Lno)==((c.p+i)->Lno)){
							(b.p+n)->Lperson--;
						}
					for(m=0;m<c.L;m++)
					{
						*(c.p+m)=*(c.p+m+1);
					}
					j=0;
					c.L--;
				}
			}
			for(j=0;j<=c.L;j++)
			{
				if((c.p+j)->Sno==k)
				{
					for(n=0;n<b.L;n++)
						if(((b.p+n)->Lno)==((c.p+i)->Lno)){
							(b.p+n)->Lperson--;
						}
					for(m=0;m<c.L;m++)
					{
						*(c.p+m)=*(c.p+m+1);
					}
					j=0;
					c.L--;
				}
			}
			cout<<"删除成功！！\n";
			return;
		}
	cout<<"记录为空！！\n";
}
void Student_arr::reviseLesson()//修改课程记录
{
	int k,i,j,flag=0;
	cout<<"请输入你想修改的课程号：";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+L)->inputLesson();
			for(j=0;j<L;j++)
			if(((p+j)->Lno==((p+L)->Lno))||(strcmp((p+j)->Lname,((p+L)->Lname))==0)){
				(p+j)->printLesson();
				flag=1;
			}
			if(flag!=1){
				*(p+i)=*(p+L);
				cout<<"修改成功！！\n";
			}
			else if(1==flag)
				cout<<"已存在所修改的课程,修改失败！！\n\n";
			return ;
		}
	cout<<"记录为空！！\n";
}
void Student_arr::reviseLesson(int k)//修改课程选修人数
{
	int i;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+i)->Lperson++;
			return ;
		}
}
void Student_arr::reviseStudent()//修改学生记录
{
	int k,i,j,flag=0;
	cout<<"请输入你想修改学生记录的学号：";
	cin>>k;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+LS)->inputStudent();
			for(j=0;j<LS;j++)
				if((pb+j)->Snum==((pb+LS)->Snum)){
					(pb+j)->printStudent();
					flag=1;
				}
			if(flag!=1){
				*(pb+i)=*(pb+LS);
				cout<<"修改成功！！\n";
			}
			else if(1==flag)
				cout<<"已存在所修改的学生信息,修改失败！！\n";
			return;
		}
	cout<<"记录为空！！\n";
}
void Student_arr::sdudent_save()//保存student文件
{
	int i,k=-1;
	lout.open("student.txt",ios::out);
	if(!lout)
	{
		cout<<"student.txt cannot open!\n";
		abort();
	}
	lout<<"//student文件\n";
	for(i=0;i<LS;i++)
		(pb+i)->printStudent1(lout);
	lout<<k;
	lout.close();
}
void Student_arr::Lesson_save()//保存lesson文件
{
	int i,k=-1;
	lout.open("lesson.txt",ios::out);
	if(!lout)
	{
		cout<<"lesson.txt cannot open!\n";
		abort();
	}
	lout<<"//lesson文件\n";
	for(i=0;i<L;i++)
		(p+i)->printLesson1(lout);
	lout<<k;
	lout.close();
}
void Student_arr::S_L_save()//保存选课信息文件
{
	int i,k=-1;
	lout.open("S_L.txt",ios::out);
	if(!lout)
	{
		cout<<"S_L.txt cannot open!\n";
		abort();
	}
	
	for(i=0;i<L;i++){
		lout<<(p+i)->Sno<<" ";
		(p+i)->printLesson1(lout);
	}
	lout<<k;
	lout.close();
}
int main ()
{
	Student_arr a,b(1),c(1,2);
	int i,j,k=1;
	cout<<"-------------------------学生选修课程管理系统-------------------------"<<endl;
	for(;k==1;)
	{
		cout<<"1.编辑功能\n";
		cout<<"2.查询功能\n";
		cout<<"3.显示功能\n";
		cout<<"4.编辑功能\n";
		cout<<"5.删除功能\n";
		cout<<"6.选课功能\n";
		cout<<"7.统计功能\n";
		cout<<"8.退出系统\n";
		cout<<"请选择：";
		cin>>i;
		switch (i)
		{
		case 1:cout<<"---------------------编辑功能---------------------\n";
			cout<<"1.添加课程信息\n2.添加学生信息\n";
			   cout<<"请选择：";
			   cin>>j;
			   if(1==j){
					   cout<<"添加课程信息\n";
					   b.lessonInsert();
			   }
			   else if(2==j){
					   cout<<"添加学生信息\n";
					   a.studentInsert();
			   }
			   else
				   cout<<"输入有误！！！";
			   break;
		case 2:cout<<"---------------------查询功能-----------------------\n";
			   cout<<"1.课程信息查询\n2.学生信息查询\n";
			   cout<<"请选择：";
			   cin>>j;
			   if(1==j){
					   cout<<"1.按学分查询\n2.按课程名查询\n3.按课程号查询\n4.按学生查询所选修的课程\n";
					   cout<<"请选择：";
					   cin>>j;
					   if(j==1){
						   cout<<"按学分查询\n";
						   b.search_by_grade();
					   }
					   else if(j==2){
						   cout<<"按课程名查询\n";
					       b.search_by_Lname();
					   }
					   else if(j==3){
						   cout<<"按课程号查询\n";
						   b.search_by_Lno();
					   }
					   else if(j==4){
						   cout<<"按学生查询所选修的课程\n";
						   a.search_by_Sno(c);
					   }
					   else
						   cout<<"输入有误！！！";
					   }
			   else if(2==j){
					   cout<<"1.按学号查询\n2.按姓名查询\n";
					   cout<<"请选择：";
					   cin>>j;
					   if(1==j){
								cout<<"按学号查询学生信息\n";
								a.search_sdudent_by_Snum();
					   }
					   else if(2==j){
								cout<<"按姓名查询\n";
								a.search_sdudent_by_Sname();
					   }
			   }
			   else
				   cout<<"输入有误！！！";
			   break;
		case 3:cout<<"---------------------显示功能-----------------------\n";
			   cout<<"1.显示所有课程信息\n2.显示所有学生信息\n3.显示所有选课信息\n4.显示所有信息\n";
			   cout<<"请选择：";
			   cin>>j;
			   if(1==j){
					   b.Print1();
			   }
			   else if(2==j){
					   a.Print();
			   }
			   else if(3==j){
					   c.Print2();
			   }
			   else if(4==j){
				       b.Print1();
					   a.Print();
					   c.Print2();
			   }
			   else
				   cout<<"输入有误！！！";
			   break;
		case 4:cout<<"---------------------编辑功能-----------------------\n";
			   cout<<"1.修改课程信息\n2.修改学生信息\n";
			   cout<<"请选择：";
			   cin>>j;
			   if(1==j){
					   b.reviseLesson();
			   }
			   else if(2==j){
					   a.reviseStudent();
			   }
			   else
				   cout<<"输入有误！！！";
			   break;
		case 5:cout<<"---------------------删除功能-----------------------\n";
			   cout<<"1.删除课程信息\n2.删除学生信息\n";
			   cout<<"请选择：";
			   cin>>j;
			   if(1==j){
					   b.deleteLesson(c);
			   }
			   else if(2==j){
					   a.deleteStudent(b,c);
			   }
			   else
				   cout<<"输入有误！！！";
			   break;
		case 6:c.choose(a,b,c);
			   break;
		case 7:cout<<"---------------------统计功能-----------------------\n";
			   cout<<"当前学生人数："<<a.GetLS()<<endl;
			   cout<<"当前课程数："<<b.GetL()<<endl;
			   b.Print1();
			   break;
		case 8:k=0;break;
		default:cout<<"输入有误！！\n";
		}
	}
	a.sdudent_save();
	b.Lesson_save();
	c.S_L_save();
	return 0;
}