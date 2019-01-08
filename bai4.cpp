#include<iostream>
#include <fstream>
#define vocung 9999
#define max 100
using namespace std;
fstream doc;
void docfile(int a[100][100],int n)
{

for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				doc>>a[i][j];
			}
	}
	doc.close();
}
void xuatfile(int a[100][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			
				cout<<a[i][j]<<" ";
				
			
			cout<<endl;
			
	}
}
int taomatran (int a[100][100],int &n)
{
	cout<<"nhap n";
	cin>>n;
	doc.open("quang03.txt",ios::out | ios::app);
	doc<<n;
	doc<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
			cout<<"nhap a"<<"["<<i<<"]"<<"["<<j<<"]";
			cin>>a[i][j];
				doc<<a[i][j];
				doc<<" ";
			}
			doc<<endl;
	}
}
void duongdingannhat (int a[max][max],int batdau,int n)
{
	int hp[max][max], dadi[max], vet[max], pt[max];
	int dem,mini,toi; 
	//khoi tao ma tran goc neu =0 thi bang vo cung
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[i][j]==0)
				hp[i][j]=vocung;
				else
				hp[i][j]=a[i][j];
			}
	}
	//khoi tao ma tran dadi[],vet[],int pt[]
	for(int i=0;i<n;i++)
	{
		vet[i]=batdau;
		dadi[i]=0;
		pt[i]=hp[batdau][i];
	}
	dem=1;
	pt[batdau]=0;//tu mot diem di mot diem thi bang 0
	dadi[batdau]=1;//diem dau tien da di qua nen dat bang 1
	while(dem<n-1 )
	{
		mini=vocung;
		for(int i=0;i<n;i++/* tim diem ke tiep gan nhat */)
		{
			if(dadi[i]!=1&&pt[i]<mini)
			{
				mini=pt[i];
				toi=i;
				
			}
		}
		dadi[toi]=1;
		for(int i=0;i<n;i++)
		{
			if(dadi[i]!=1)
				if(mini+hp[toi][i]<pt[i] /* neu tim duoc duong di tu dau den diem can tim ngan hon thi */)
					{
						pt[i]=mini+hp[toi][i];
						vet[i]=toi;
					}
		} 
		dem++;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=batdau)
		{
			cout<<endl;
			cout<<"Khoang cach  nut "<<batdau<<"->"<< i << ":" <<pt[i] <<"   ";
			cout<<"duong di  "<<i;
		int j=i;
		  do
		  {
		  	j=vet[j];
		  	cout<<"<-"<<j;
		  }
		  while(j!=batdau);
		}
	}
}
int main()
{
	int n;
	int bd;
	doc.open("quang.txt",ios::in);
doc>>n;
doc>>bd;
int a[100][100];
int b[100][100];
int n1;
docfile(a,n);
xuatfile(a,n);
duongdingannhat(a,bd,n);

}
