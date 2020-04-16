#include<iostream>
#include<cmath>
using namespace std;
	
double Condition_01_X(double,double,double,double,double,double,double,double,double);
double Condition_01_Y(double,double,double,double,double,double,double,double,double);
double Distance_at_plane(double);

const int	H=3;            //Height=3m

int main(){
	while(1){				//�i��h������ 

	//�w�q�ܼ� 
	double L[3];
	double D[3];
	double	x[3];   		 //x,y���w�b3�I 
	double	y[3];
	double  X,Y;					//user����m 
	
	/*	L_0,L_1,L_2 are what Sensors detect; */
	for(int i=1; i<=3;i++){
		cout<<"�Z��"<<i<<": ";
		cin>>L[i-1];
		cout<<"�y��"<<i<<"(x,y): ";
		cin>>x[i-1]>>y[i-1];
	}
	for(int j=0;j<=2;j++){
		D[j]=Distance_at_plane(L[j]);
	}
	//�z�Q���p�A�T�Ӷ�ۥ�u��X�@���I 
	for (int k=0;k<1;k++){
		X=Condition_01_X(D[k],D[k+1],D[k+2],x[k],x[k+1],x[k+2],y[k],y[k+1],y[k+2]);
		Y=Condition_01_Y(D[k],D[k+1],D[k+2],x[k],x[k+1],x[k+2],y[k],y[k+1],y[k+2]);
	}
	cout<<"(x,y) = "<<"("<<X<<","<<Y<<")"<<endl<<endl;
	} 
	system("pause");
	return 0;	
} 

/*�쥻�ǨӪ��Z���t�����סA�b���v�T�U�ݭn�ѤT�תŶ�����{���A�N�����p²�Ƭ��G�תŶ�*/ 
//�禡Disatnce_at_plane�D�����y�Ъ��Z�� 
double Distance_at_plane(double x){ 
	double distance;
	distance=sqrt(pow(x,2)-pow(H,2));
	return distance;	
}
//Condition_01 ���O�D�XUser�b�z�Q���p�W��(x,y)�� 
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
