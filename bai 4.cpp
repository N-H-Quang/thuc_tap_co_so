#include<iostream>
#include <fstream>
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
#define INFINITY 9999
#define MAX 100
void dijkstra(int G[MAX][MAX], int n, int startnode)
{

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	//pred[] luu cac dinh ma khoang cach ngan nhat tu no den dinh nguon
	//count dem so nut ma di qua den den dich
	//Tao ma tran trong so
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];

	//Khoi tao mang pred[],distance[] and visited[]
	for (i = 0; i<n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count<n - 1)
	{
		mindistance = INFINITY;

		//Nut ke tiep co khoang cach nho nhat
		for (i = 0; i<n; i++)
			if (distance[i]<mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}

		//Kiem tra neu co duong dan tot hon: tinh lai khoang cach cac nut chua duoc tham      
		visited[nextnode] = 1;
		for (i = 0; i<n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i]<distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	//In ra duong di va khoang cach den moi nut
	for (i = 0; i<n; i++)
		if (i != startnode)
		{
			printf("\nKhoang cac toi nut %d=%d", i, distance[i]);
			printf("\nDuong di =%d", i);

			j = i;
			do
			{
				j = pred[j];
				printf("<-%d", j);
			} while (j != startnode);
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
dijkstra(a,n,bd);


}
