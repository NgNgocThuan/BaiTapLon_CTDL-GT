#ifndef Car_h
#define Car_h

#include <iostream>
#include <string> 
#include <iomanip>

using namespace std;

class Car{
	string maXe, hangXe, mauXe, color;
	float giaXe;
	int namSx, soChoNgoi;
	public :
		Car(){};
		friend istream& operator>>(istream &is, Car &c); 
		friend ostream& operator<<(ostream &os, Car &c); 
		bool operator<(const Car &c);
		float getGiaXe(){
			return giaXe;
		}
		int getNamSx(){
			return namSx;
		}
		string getMaXe(){
			return maXe;
		}
};

istream& operator>>(istream &is, Car &c){
	if(&is == &cin){
		cout<<"Nhap ma xe: ";
		is.ignore();
		getline(is,c.maXe);
		cout<<"Nhap hang xe: ";
		getline(is,c.hangXe);
		cout<<"Nhap kieu xe: ";
		getline(is,c.mauXe);
		cout<<"Nhap mau sac xe: ";
		getline(is,c.color);
		cout<<"Nhap gia xe: ";
		is>>c.giaXe;
		cout<<"Nhap nam san xuat: ";
		is>>c.namSx;
		cout<<"Nhap so cho ngoi: ";
		is>>c.soChoNgoi;
	}else{
		getline(is,c.maXe);
		getline(is,c.hangXe);
		getline(is,c.mauXe);
		getline(is,c.color);
		is>>c.giaXe;
		is>>c.namSx;
		is>>c.soChoNgoi;
		is.ignore();
	}
	return is;
}

ostream& operator<<(ostream &os, Car &c){
	os<<"|"<<left<<setw(15)<<c.maXe;
	os<<"|"<<left<<setw(15)<<c.hangXe;
	os<<"|"<<left<<setw(15)<<c.mauXe;
	os<<"|"<<left<<setw(15)<<c.color;
	os<<"|"<<left<<setw(23)<<c.giaXe;
	os<<"|"<<left<<setw(15)<<c.namSx;
	os<<"|"<<left<<setw(15)<<c.soChoNgoi;
	os<<"|"<<endl;
	return os;
}

bool Car :: operator<(const Car &c){
	return giaXe < c.giaXe;
}

//int main(){
//	Car c1, c2;
//	cin>>c1>>c2;
//	cout<<c1<<endl;
//	cout<<c2<<endl;
//	if(c1<c2) cout<<"Yes"<<endl;
//	else cout<<"NO"<<endl;
//}

#endif
