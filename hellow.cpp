#include<iostream>
using namespace std;
void spiral(int A[3][6],int n ,int m)
{

int row_start=0;
int row_end=m;
int column_start=0;
int column_end=n;

cout<<"\n"<<endl;
while(row_start<row_end && column_start<column_end)
{

for(int i=row_start;i<row_end;i++)
{
cout<<"col:"<<i<<" row:"<<column_start<<" "<<A[column_start][i]<<" \n";

}
column_start++;
//int p;
//cin>>p;

for(int i=column_start;i<column_end;i++)
{
cout<<"col:"<<row_end-1<<" row:"<<i<<" "<<A[i][row_end-1]<<" \n";

}
row_end--;
if(column_end>column_start){
for(int i=row_end-1;i>=row_start;i--)
{
cout<<"col:"<<i<<" row:"<<column_end-1<<" "<<A[column_end-1][i]<<"\n ";

}
column_end--;
}
if(row_start<row_end){
for(int i=column_end-1;i>=column_start;i--)
{
cout<<"col:"<<row_start<<" row:"<<i<<" "<<A[i][row_start]<<"\n ";

}

row_start++;
}

}



return ;
}

int main(){
int R=3,C=6;
int a[3][6] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
spiral(a,3,6);
return 0;

}
