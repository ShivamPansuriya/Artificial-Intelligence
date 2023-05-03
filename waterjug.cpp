#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,goal,x=0,y=0,temp;
	cin>>a>>b>>goal;
	if(b>a){
		swap(a,b);
	}
	while((x+y)!=goal){
		cout<<x<<" "<<y<<endl;
		if(x==0){
			x=a;
			continue;
		}
		if(y!=b){
			temp = min(x,b-y);
			x-=temp;
			y+=temp;
			continue;
		}
		if(y==b){
			y=0;
			continue;
		}
	}
	cout<<x<<" "<<y<<endl;
}