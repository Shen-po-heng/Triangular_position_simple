#include<iostream>
#include<cmath>
using namespace std;
	
double Condition_01_X(double,double,double,double,double,double,double,double,double);
double Condition_01_Y(double,double,double,double,double,double,double,double,double);
double Distance_at_plane(double);

const int	H=3;            //Height=3m

int main(){
	while(1){				//進行多次測試 

	//定義變數 
	double L[3];
	double D[3];
	double	x[3];   		 //x,y假定在3點 
	double	y[3];
	double  X,Y;					//user的位置 
	
	/*	L_0,L_1,L_2 are what Sensors detect; */
	for(int i=1; i<=3;i++){
		cout<<"距離"<<i<<": ";
		cin>>L[i-1];
		cout<<"座標"<<i<<"(x,y): ";
		cin>>x[i-1]>>y[i-1];
	}
	for(int j=0;j<=2;j++){
		D[j]=Distance_at_plane(L[j]);
	}
	//理想狀況，三個圓相交只交出一個點 
	for (int k=0;k<1;k++){
		X=Condition_01_X(D[k],D[k+1],D[k+2],x[k],x[k+1],x[k+2],y[k],y[k+1],y[k+2]);
		Y=Condition_01_Y(D[k],D[k+1],D[k+2],x[k],x[k+1],x[k+2],y[k],y[k+1],y[k+2]);
	}
	cout<<"(x,y) = "<<"("<<X<<","<<Y<<")"<<endl<<endl;
	} 
	system("pause");
	return 0;	
} 

/*原本傳來的距離含有高度，在此影響下需要解三度空間的方程式，將此狀況簡化為二度空間*/ 
//函式Disatnce_at_plane求平面座標的距離 
double Distance_at_plane(double x){ 
	double distance;
	distance=sqrt(pow(x,2)-pow(H,2));
	return distance;	
}
//Condition_01 分別求出User在理想狀況上的(x,y)值 
double Condition_01_X(double d_0,double d_1,double d_2,double x_0,double x_1,double x_2,double y_0,double y_1,double y_2){
	double D_12,X_12,Y_12,A_son,A_mom;
	double D_01,X_01,Y_01,B_son,B_mom;
	double x,total_son,total_mom;
	D_12=pow(d_1,2)-pow(d_2,2);
	X_12=pow(x_2,2)-pow(x_1,2);
	Y_12=pow(y_2,2)-pow(y_1,2);
	A_son=D_12+X_12+Y_12;
	A_mom=2*(y_2-y_1);
	
	D_01=pow(d_0,2)-pow(d_1,2);
	X_01=pow(x_1,2)-pow(x_0,2);
	Y_01=pow(y_1,2)-pow(y_0,2);
	B_son=D_01+X_01+Y_01;
	B_mom=2*(y_1-y_0);
	
	total_son= (A_son/A_mom-B_son/B_mom);
	total_mom= ((x_2-x_1)/(y_2-y_1))-((x_1-x_0)/(y_1-y_0));
	x=total_son/total_mom;	
	return x;	
}
double Condition_01_Y(double d_0,double d_1,double d_2,double x_0,double x_1,double x_2,double y_0,double y_1,double y_2){
	
	double D_12,X_12,Y_12,A_son,A_mom;
	double D_01,X_01,Y_01,B_son,B_mom;
	double y,total_son,total_mom;
	D_12=pow(d_1,2)-pow(d_2,2);
	X_12=pow(x_2,2)-pow(x_1,2);
	Y_12=pow(y_2,2)-pow(y_1,2);
	A_son=D_12+X_12+Y_12;
	A_mom=2*(x_2-x_1);
	
	D_01=pow(d_0,2)-pow(d_1,2);
	X_01=pow(x_1,2)-pow(x_0,2);
	Y_01=pow(y_1,2)-pow(y_0,2);
	B_son=D_01+X_01+Y_01;
	B_mom=2*(x_1-x_0);
	
	total_son= (A_son/A_mom-B_son/B_mom);
	total_mom= ((y_2-y_1)/(x_2-x_1))-((y_1-y_0)/(x_1-x_0));
	y=total_son/total_mom;	
	return y;
}
