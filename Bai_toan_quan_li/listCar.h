#ifndef listCar_h
#define listCar_h

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Car.h"

using namespace std;

class listCar{
	vector<Car> v;
	public :
		listCar(){};
		void them(int n);
		void xuat();
		void docFile(string tenFile);
		void sapxepTheoTien();
		void sapxepTheoNam();
		vector<Car> timXeDatNhat();
		vector<Car> timXeGieNhat();
		Car timKiem(string ma);
		void xoa(string ma);
		int getSize(){
			return v.size();
		}
};

// nhap vao ds Car voi n phtu
void listCar :: them(int n){
	for(int i=0; i<n; i++){
		Car tmp;
		cout<<"(*) Nhap thong tin xe thu "<<i+1<<" :"<<endl;
		cin>>tmp;
		v.push_back(tmp);
	}
}

// Xuat ds Car
void listCar :: xuat(){
	if(v.empty()){
		cout<<"Danh sach trong !"<<endl;
		return;
	}
	char line[127];
	memset(line, '-', sizeof(line));
	for(int i=0; i<127; i++){
		cout<<line[i];
	}
	cout<<endl;
	cout<<"|"<<left<<setw(5)<<"STT";
	cout<<"|"<<left<<setw(15)<<"Ma xe";
	cout<<"|"<<left<<setw(15)<<"Hang xe";
	cout<<"|"<<left<<setw(15)<<"Kieu xe";
	cout<<"|"<<left<<setw(15)<<"Mau xe";
	cout<<"|"<<left<<setw(23)<<"Gia xe (trieu dong)";
	cout<<"|"<<left<<setw(15)<<"Nam suat ban";
	cout<<"|"<<left<<setw(15)<<"So cho ngoi";
	cout<<"|"<<endl;
	for(int i=0; i<127; i++){
		cout<<line[i];
	}
	cout<<endl;
	for(int i=0; i<v.size(); i++){
		cout<<"|"<<left<<setw(5)<<i+1;
		cout<<v[i];
	}
	for(int i=0; i<127; i++){
		cout<<line[i];
	}
	cout<<endl;
}

// Doc du lieu tu file
void listCar :: docFile(string tenFile){
	fstream file;
	file.open(tenFile);
	if(!file.is_open()){
		cout<<"Loi mo file !"<<endl;
		return;
	}
	Car tmp;
	while(file >> tmp){
		v.push_back(tmp);
	}
	file.close();
}

// Sap xep theo gia tien tang dan
void listCar :: sapxepTheoTien(){
	sort(v.begin(), v.end(), [](Car a, Car b){return a.getGiaXe() < b.getGiaXe();});
	cout<<"Da sap xep"<<endl;
}

//Sap xep theo nam xuat ban tang dan
void listCar :: sapxepTheoNam(){
	sort(v.begin(), v.end(), [](Car a, Car b){return a.getNamSx() < b.getNamSx();});
	cout<<"Da sap xep"<<endl;
}

// Tim cac xe co gia tien cao nhat
vector<Car> listCar :: timXeDatNhat(){
	vector<Car> tmp;
	float m = -1;
	for(int i=0; i<v.size(); i++){
		m = max(m,v[i].getGiaXe());
	}
	for(int i=0; i<v.size(); i++){
		if(v[i].getGiaXe() == m){
			tmp.push_back(v[i]);
		}
	}
	return tmp;
}

// Tim cac xe co gia tien thap nhat
vector<Car> listCar :: timXeGieNhat(){
	vector<Car> tmp;
	float m = 1e9+7;
	for(int i=0; i<v.size(); i++){
		m = min(m,v[i].getGiaXe());
	}
	for(int i=0; i<v.size(); i++){
		if(v[i].getGiaXe() == m){
			tmp.push_back(v[i]);
		}
	}
	return tmp;
}

// Tim kiem xe theo ma xe
Car listCar :: timKiem(string ma){
	for(int i=0; i<v.size(); i++){
		if(v[i].getMaXe() == ma){
			return v[i];
		}
	}
	return Car();
} 

// Xoa 
void listCar :: xoa(string ma){
	int pos = -1;
	for(int i=0; i<v.size(); i++){
		if(v[i].getMaXe()==ma){
			pos = i;
			break;
		}
	}
	if(pos!=-1){
		v.erase(v.begin()+pos);
		cout<<"Da xoa"<<endl;
	}
	else cout<<"Ma khong hop le"<<endl;
}
#endif
