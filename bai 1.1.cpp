#include<iostream >
#include<string.h>
#include<fstream>
#include<vector>
#include<conio.h>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct 
{
	char ten[50];
	char gioitinh[5];
	char sdt[11];
	char email[30];
	char diachi[50];
}danhba;
vector<danhba>db;
void docfile()
{
	db.clear();
	FILE *f;
	f=fopen("d:\\danhba.dat","rb");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			danhba c;
			fread(&c,sizeof(c),1,f);
			db.push_back(c);
		}	
			fclose(f);
	db.pop_back();
	}
	
}
void ghifile()
{
		danhba tam;
		int size=db.size();
		FILE *f;
	f=fopen("d:\\danhba.dat","wb");
	for(int i=0;i<size;i++)
	{
		tam=db[i];
		fwrite(&tam,sizeof(tam),1,f);
	}
	fclose(f);
}
void themmoi(danhba c)
{
	db.push_back(c);
		ghifile();	

}
void indanhba(danhba c)
{
	cout<<"so dien thoai "<<c.sdt<<endl;
	cout<<"ten "<<c.ten<<endl;
	cout<<"diachi "<<c.diachi<<endl;
	cout<<"email "<<c.email<<endl;
	cout<<"gioi tinh "<<c.gioitinh<<endl;
	cout<<"............................."<<endl;
}
void indb()
{
	int size=db.size();
	for(int i=0;i<size;i++)
	{
		indanhba(db[i]);
	}
}
int tim(char sdt[11])
{
for(int i=0;i<db.size();i++)
{
	if(strcmp(db[i].sdt,sdt)==0)
	return i;
	 return -1;	
	 	
}
}
void sua (char sdt[11])
{
	int vt=tim(sdt);
	
	db.erase(db.begin()+vt);
	danhba c;
if(vt>=0){

		cout<<"nhap lai danh ba"<<endl<<"ten nguoi dung";
		cin.sync();
		cin>>c.ten;
		cout<<"nhap sdt";
		cin.sync();
		cin>>c.sdt;
		cout<<"nhap email";
		cin.sync();
		cin>>c.email;
		cout<<"nhap gioi tinh";
		cin.sync();
		cin>>c.gioitinh;
		cout<<"nhap dia chi";cin.sync();
		cin>>c.diachi;
		db.insert(db.begin()+vt ,c);
}
else
cout<<"khong thay sdt can tim";
			
}
void xoa(char sdt[11])
{
//	int vt=tim(sdt);
//	if(vt>=0)
//	{
//	db.erase(db.begin()+vt);
//	}
//	else
//	cout<<"khong thay sdt can tim";
for(int i=0;i<db.size();i++)
{
	if(strcmp(db[i].sdt,sdt)==0)
		{
		db.erase(db.begin()+i);	
			
		}
}
}
int timtheoten(char ten[50])
{
for(int i=0;i<db.size();i++)
{
	if(strcmp(db[i].ten,ten)==0)
	return i;
	else return -1;	
	
}
}
int main()
{
	fflush(stdin);
	danhba c;
	strcpy(c.ten,"nguyen huu quang");
	strcpy(c.email,"dbbb");
	strcpy(c.diachi,"binhthuan");
	strcpy(c.gioitinh,"nam");
	strcpy(c.sdt,"016274605");
	themmoi(c);	
	danhba c1;
	strcpy(c1.ten, "nguyen huu quang01");
	strcpy(	c1.diachi,"binhthuan");
	strcpy(	c1.email,"dbbb");
	strcpy(c1.gioitinh,"nam");
	strcpy(c1.sdt,"1");
	themmoi(c1);	
	ghifile();
	sua("016274605");
	xoa("1");
	indb();
	cout<<timtheoten("khong");
}



	

	

