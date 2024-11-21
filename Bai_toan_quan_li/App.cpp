#include<iostream>
#include"listCar.h"
#include"Car.h"

using namespace std;

class App{
	listCar car;
	public :
		void menu(){
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"1.Doc du lieu tu file"<<endl;
			cout<<"2.Them phan tu vao danh sach"<<endl;
			cout<<"3.Xuat danh sach"<<endl;
			cout<<"4.Sap xep danh sach theo gia tang dan"<<endl;
			cout<<"5.Sap xep danh sach theo nam san xuat tang dan"<<endl;
			cout<<"6.Tim xe dat nhat"<<endl;
			cout<<"7.Tim xe gie nhat"<<endl;
			cout<<"8.Tim kiem theo ma xe"<<endl;
			cout<<"9.Xoa mot phan tu"<<endl;
			cout<<"10.Thoat chuong chinh"<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
		}
		void QuanLi(){
			int c; 
			do{
				cout<<"Nhap lua chon: ";
				cin>>c;
				switch(c){
					case 1: {
						string tenFile;
						cout<<"Nhap ten file: ";
						cin>>tenFile;
						car.docFile(tenFile);
						cout<<"Da luu du lieu cua file vao danh sach"<<endl;
					break;
					}
					case 2: {
						int n;
						cout<<"Nhap so phan tu muon them: ";
						cin>>n;
						car.them(n);
						break;
					}
					case 3:
						car.xuat();
						break;
					case 4:
						car.sapxepTheoTien();
						break;
					case 5:
						car.sapxepTheoNam();
						break;
					case 6: {
						vector<Car> a = car.timXeDatNhat();
						char line[121];
						memset(line, '-', sizeof(line));
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						cout<<"|"<<left<<setw(15)<<"Ma xe";
						cout<<"|"<<left<<setw(15)<<"Hang xe";
						cout<<"|"<<left<<setw(15)<<"Kieu xe";
						cout<<"|"<<left<<setw(15)<<"Mau xe";
						cout<<"|"<<left<<setw(23)<<"Gia xe (trieu dong)";
						cout<<"|"<<left<<setw(15)<<"Nam suat ban";
						cout<<"|"<<left<<setw(15)<<"So cho ngoi";
						cout<<"|"<<endl;
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						for(int i=0; i<a.size(); i++){
							cout<<a[i];
						}
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						break;
					}
					case 7: {
						vector<Car> a = car.timXeGieNhat();
						char line[121];
						memset(line, '-', sizeof(line));
						for(int i=0; i<121; i++){
							cout<<line[i];
						}		
						cout<<endl;
						cout<<"|"<<left<<setw(15)<<"Ma xe";
						cout<<"|"<<left<<setw(15)<<"Hang xe";
						cout<<"|"<<left<<setw(15)<<"Kieu xe";
						cout<<"|"<<left<<setw(15)<<"Mau xe";
						cout<<"|"<<left<<setw(23)<<"Gia xe (trieu dong)";
						cout<<"|"<<left<<setw(15)<<"Nam suat ban";
						cout<<"|"<<left<<setw(15)<<"So cho ngoi";
						cout<<"|"<<endl;
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						for(int i=0; i<a.size(); i++){
							cout<<a[i];
						}
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						break;
					}
					case 8: {
						string ma;
						cout<<"Nhap ma xe can tim: ";
						cin>>ma;
						Car a = car.timKiem(ma);
						if(a.getMaXe() == ""){
						cout<<"Ma xe khong hop le"<<endl;
						break;
						}
						cout<<"Da tim thay"<<endl;
						char line[121];
						memset(line, '-', sizeof(line));
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						cout<<"|"<<left<<setw(15)<<"Ma xe";
						cout<<"|"<<left<<setw(15)<<"Hang xe";
						cout<<"|"<<left<<setw(15)<<"Kieu xe";
						cout<<"|"<<left<<setw(15)<<"Mau xe";
						cout<<"|"<<left<<setw(23)<<"Gia xe (trieu dong)";
						cout<<"|"<<left<<setw(15)<<"Nam suat ban";
						cout<<"|"<<left<<setw(15)<<"So cho ngoi";
						cout<<"|"<<endl;
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						cout<<a;
						for(int i=0; i<121; i++){
							cout<<line[i];
						}
						cout<<endl;
						break;
					}
					case 9: {
						string ma; 
						cout<<"Nhap ma cua xe muon xoa:  ";
						cin>>ma;
						car.xoa(ma);
						if(car.getSize() == 0){
							cout<<"Da xoa het danh sach"<<endl;
						}
						break;
					}
					case 10:
						cout<<"Thoat chuong chinh."<<endl;
						break;
					default:
               			cout<<"Lua chon khong hop le!" << endl;
               		 	break;
					}
			}while(c!=10);
		}
};

int main(){
	App app;
	app.menu();
	app.QuanLi();
}