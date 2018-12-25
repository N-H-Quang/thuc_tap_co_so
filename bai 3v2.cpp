#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <fstream>
#include<vector>
using namespace std;
struct nguoichoi
{
	string ten;
	int diem=0;
};
int trochoi(nguoichoi &n1, int de)
{
	string traloi;
	string b;
	ifstream doc;
	switch (de)
	{
	
	case 1:
    doc.open("D:\\quang.txt");
    break;
    case 2 :
      doc.open("D:\\quang01.txt");
      break;
   }
    int dem=0;
    do
    {
	if(dem <=1 )
   {
    for (int i=0;i<=3;i++)
    {
	
    getline (doc,b) ;
    cout<<b<<endl;
   }
   getline (doc,b) ;
   cin>>traloi;
   
   
   
if(b.compare(traloi)==0)
{

cout<<"tra loi dung"<<endl;
n1.diem++;
}
else
{
	cout<<"tra loi sai"<<endl;
	break;
}
dem++;
}
else
{
	break;
}
}while(1!=0);
cout<<n1.diem;

 
    doc.close();
    return n1.diem;
}
vector <nguoichoi>nt;
int main()
{
	ofstream ghi;
    ghi.open("d://a.txt");
	char ct='y';
	while (ct=='y')
	{
		nguoichoi c;
	cin.sync();
	cout<<"Nhap ten cua ban :  "<<endl;
	getline(std::cin,c.ten);
	 cout<<"xin chao ban "<<c.ten<<" game do vui!!!"<<endl;
	 cout<<"ban muon chon de may"<<endl;
	  int de;
	cin>>de;
	trochoi (c,de);
	 	nt.push_back(c);
	 	ghi<<c.ten<<endl;
    ghi<<c.diem<<endl;
    cout<<"ban muon choi nua ko";
    ct=getch();
	}
	cout<<"ds diem cao";
	for(int i=0;i<nt.size();i++)
	{
		cout<<nt[i].ten <<"        ";
		cout<<nt[i].diem;
		
	}
	
}
