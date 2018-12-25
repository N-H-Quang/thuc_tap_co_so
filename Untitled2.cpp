#include<iostream >
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;
struct db
{
	string ten;
	string gioitinh;
	string sdt;
	string email;
	string diachi;
};
void nhap(db p1[10],int sl)
{
	
	ofstream f;
   f.open("d:\\db.txt");
   cin.ignore();
   
   for(int i=0;i<sl;i++)
   {
   
	cout<<"nhap ten";
	getline (std::cin,p1[i].ten);
	f<<p1[i].ten<<endl;
	cout<<"nhap dia chi";
	getline (std::cin,p1[i].diachi);
	cout<<p1[i].diachi;
 f<<p1[i].diachi<<endl;
 cout<<"nhap email";
	getline (std::cin,p1[i].email);
	cout<<p1[i].email<<endl;
 f<<p1[i].email<<endl;
 cout<<"nhap gioi tinh";
	getline (std::cin,p1[i].gioitinh);
	cout<<p1[i].gioitinh<<endl;
 f<<p1[i].gioitinh<<endl;
 cout<<"nhap so dien thoai";
	getline (std::cin,p1[i].sdt);
	cout<<p1[i].sdt<<endl;
	f<<p1[i].sdt<<endl;
}
	f.close();
}
void xuat (int sl)
{
ifstream f;
f.open("d:\\db.txt");
while(sl>0)
{
	db tam;
	f>>tam.ten;
	f>>tam.diachi;
	f>>tam.email;
	f>>tam.gioitinh;
	f>>tam.sdt;
	cout<<tam.ten<<" "<<tam.diachi<<" "<<tam.email<<" "<<tam.gioitinh<<" "<<tam.sdt;
	sl--;
}
f.close();
}
void sua(db &p1)
{
cin.ignore();
	cout<<"nhap ten";
	cin>>p1.ten;
	cout<<"nhap dia chi";
	cin>>p1.diachi;
	cout<<"nhap email";
	cin>>p1.email;
	cout<<"nhap gioi tinh";
	cin>>p1.gioitinh;
	cout<<"nhap sdt";
	cin>>p1.sdt;
	
}
void capnhat(db p1[10],int sl)
{
	ofstream f;
   f.open("d:\\db.txt");
   for(int i=0;i<sl;i++)
   {
   
   f<<p1[i].ten<<endl;
    f<<p1[i].diachi<<endl;
    	f<<p1[i].email<<endl;
    	f<<p1[i].gioitinh<<endl;
    		f<<p1[i].sdt<<endl;
    	}
    		f.close();
   
}	
void capnhatv2(db p1[10],int sl,int xoa)
{
	ofstream f;
   f.open("d:\\db.txt");
   p1[xoa].ten="deleted";
   for(int i=0;i<sl;i++)
   {
   if(p1[i].ten!="deleted")
   
{

   f<<p1[i].ten<<endl;
    f<<p1[i].diachi<<endl;
    	f<<p1[i].email<<endl;
    	f<<p1[i].gioitinh<<endl;
    		f<<p1[i].sdt<<endl;
    	}
    	}
    		f.close();
   
	
}
void tim (db p1[10],int sl,string tim1)
{
	for(int i=0;i<sl;i++)
   {
   	if(p1[i].ten.compare(tim1)==0)
   	 {
   	 	cout<<"co nguoi ten"<<tim1<<"trong ban ghi";
   	 	break;
		}
		cout<<"khong co nguoi do trong ban ghi";
}
}
int main()
{
db p1[10];
int sl;
cout<<"nhap so luong ";
cin>>sl;
nhap(p1,sl);
cin.ignore();
xuat(sl);
int vt;
cout<<"nhap vi tri ban ghi can sua";
cin>>vt;
sua(p1[vt-1]);
capnhat(p1,sl);
xuat(2);
cout<<p1[2].ten;
int xoa;
cout<<"nhap vi tri can xoa trong file";
cin>>xoa;
capnhatv2(p1,sl,xoa-1);
string tim1;
cin.ignore();
cout<<"nhap ten can tim";
getline(std::cin,tim1);
tim(p1,sl,tim1);

}
