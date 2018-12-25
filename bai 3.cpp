#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <fstream>
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
int main()
{
  
    nguoichoi n1[100];
    cout<<"co may nguoi choi";
    int n;
    cin>>n;
    ofstream ghi;
    ghi.open("d://a.txt");
    for(int i=0;i<n;i++)
    {
	
    int de;
    cin.ignore();  
    cout<<"Nhap ten cua ban :  "<<endl;
    getline(std::cin,n1[i].ten);
    cout<<"xin chao ban "<<n1[i].ten<<" game do vui!!!"<<endl;
	cout<<"ban muon chon de may"<<endl;
	cin>>de;
	trochoi (n1[i],de);
    ghi<<n1[i].ten<<endl;
    ghi<<n1[i].diem<<endl;
}
    ghi.close();
    
	
}
