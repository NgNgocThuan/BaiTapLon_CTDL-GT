#include<bits/stdc++.h>
using namespace std;

struct Node{
	string key;
	string value;
	Node *next;
};

class Dictionary {
	Node **HashTable;
	int size;
	public :
		Dictionary(int size);
		~Dictionary();
		int Hash(string key);
		void insert(string key, string value);
		string getValue(string key);
		bool remove(string key);
		bool update(string key, string newValue);
		void readFile();
		void writeFile();
		void in();
};

Dictionary :: Dictionary(int size){
	this->size = size;
	HashTable = new Node*[size];
	for(int i=0; i<size; i++){
		HashTable[i] = nullptr;
	}
}

Dictionary :: ~Dictionary(){
	for(int i=0; i<size; i++){
		Node *tmp = HashTable[i];
		while(tmp != nullptr){
			Node *p = tmp;
			tmp = tmp->next;
			delete p;
		}
	}
	delete[] HashTable;
}

void Dictionary :: in(){
	bool check = true;
	for(int i=0; i<size; i++){
		Node *tmp = HashTable[i];
		while(tmp != nullptr){
			check = false;
			cout<<" "<<tmp->key<<" - "<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
	if(check){
		cout<<" Khong co tu nao trong tu dien !"<<endl;
	}
	cout<<endl;
}

int Dictionary :: Hash(string key){
	int tong = 0;
	for(char c : key){
		tong += static_cast<int>(tolower(c));
	}
	return tong % size;
}

void Dictionary :: insert(string key, string value){
	int i = Hash(key);
	Node *newNode = new Node{key, value};
	if(HashTable[i] == nullptr){
		HashTable[i] = newNode;
	}else {
		Node *tmp = HashTable[i];
		while(tmp->next != nullptr){
			if(tmp->key == key){
				tmp->value = value;
				delete newNode;
				return;   // tu can them da ton tai
			}
			tmp = tmp->next;
		}
		if(tmp->key == key){
			tmp->value = value;
			delete newNode;
			return;
		}else {
			tmp->next = newNode;
			// Them thanh cong
		}
	}
}

string  Dictionary :: getValue(string key){
	int i = Hash(key);
	Node *tmp = HashTable[i];
	while(tmp != nullptr){
		if(tmp->key == key){
			return tmp->value;
		}
		tmp = tmp->next;
	}
	return "";	// neu khong tim thay tra ve rong
}

bool Dictionary :: remove(string key){
	int i = Hash(key);
	Node *tmp = HashTable[i];
	Node *p = nullptr;
	while(tmp != nullptr){
		if(tmp->key == key){
			if(p != nullptr){
				p->next = tmp->next;
			}else{
				HashTable[i] = tmp->next;
			}
			delete tmp;
			return true;
		}
		p = tmp;
		tmp = tmp->next;
	}
	return false;	// Khong tim thay tu de xoa
}

bool Dictionary :: update(string key, string newValue){
	int i = Hash(key);
	Node *tmp = HashTable[i];
	while(tmp != nullptr){
		if(tmp->key == key){
			tmp->value = newValue;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void Dictionary :: readFile(){
	fstream file;
	file.open("dictionaryInput.txt");
	if(!file.is_open()){
		cout<<" Loi doc file !"<<endl;
		return;
	}
	string line;
while (getline(file, line)) {
        int Pos = line.find(" - ");  // Tìm vị trí của chuỗi " - "
        
        if (Pos != string::npos) { // Nếu tìm thấy chuỗi " - "
            string key = line.substr(0, Pos);  // Lấy phần trước " - " làm key
            string value = line.substr(Pos + 3);  // Lấy phần sau " - " làm value
            
            insert(key, value);  // Chèn cặp key-value vào từ điển
        }
    }
    
    file.close();
}

void Dictionary :: writeFile(){
	ofstream file;
	file.open("dictionaryOutput.txt");
	if(!file.is_open()){
		cout<<" Khong the mo file de ghi !"<<endl;
		return;
	}
	for(int i=0; i<size; i++){
		Node *tmp = HashTable[i];
		while(tmp != nullptr){
			file<<tmp->key<<" - "<<tmp->value<<endl;
			tmp = tmp->next;
		}
	}
	file.close();
} 

void menu(){
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"a.Chen cap tu tieng Anh va tu tieng Viet vao tu dien voi khoa la tu tieng anh"<<endl;
	cout<<"b.Lay nghia cua tu tieng Viet voi dau vao la mot tu tieng Anh"<<endl;
	cout<<"c.Xoa cap tu khoi tu dien"<<endl;
	cout<<"d.Cap nhat mot tu da co trong tu dien"<<endl;
	cout<<"e.Doc du lieu tu mot tep tin (file) de chen vao tu dien"<<endl;
	cout<<"f.Xuat du lieu cua tu dien ra mot tep tin (file)"<<endl;
	cout<<"g.In cac tu trong tu dien"<<endl;
	cout<<"h.Thoat chuong trinh"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}

int main(){
	Dictionary d(997);
	menu();
	char c;
	do {
		cout<<"Nhap lua chon: ";
		cin>>c;
		switch(c){
			case 'a': {
				string ta, tv;
				cout<<" Nhap tu tieng anh: ";
				cin.ignore();
				getline(cin,ta);
				cout<<" Nhap nghia tieng viet cua no: ";
				getline(cin,tv);
				d.insert(ta, tv);
				cout<<" Da them vao tu dien"<<endl;
				cout<<endl;
				break;
			}
			case 'b': {
				string ta;
				cout<<" Nhap tu tieng anh: ";
				cin.ignore();
				getline(cin,ta);
				string tv = d.getValue(ta);
				if(tv != ""){
					cout<<" Ngia cua tu "<<ta<<" la: "<<tv<<endl;
				}else {
					cout<<" Khong tim thay trong tu dien"<<endl;
				}
				cout<<endl;
				break;
			}
			case 'c': {
				string ta;
				cout<<" Nhap tu tieng anh muon xoa: ";
				cin.ignore();
				getline(cin, ta);
				bool check = d.remove(ta);
				if(check) cout<<" Da xoa khoi tu dien"<<endl;
				else cout<<" Khong tim thay trong tu dien"<<endl;
				cout<<endl;
				break;
			}
			case 'd': {
				string ta, tv;
				cout<<" Nhap tu tieng anh muon cap nhat: ";
				cin.ignore();
				getline(cin, ta);
				cout<<" Nhap ngia tieng viet: ";
				getline(cin, tv);
				bool check = d.update(ta, tv);
				if(check){
					cout<<" Da cap nhat thanh cong"<<endl;
				}else {
					cout<<"Khong tim thay trong tu dien"<<endl;
				}
				cout<<endl;
				break;
			}
			case 'e': {
				d.readFile();
				cout<<" Du lieu da duoc doc tu file dictionaryInput.txt va luu vao tu dien"<<endl;
				cout<<endl;
				break;
			}
			case 'f': {
				d.writeFile();
				cout<<" Du lieu da duoc luu vao file dictionaryOutput.txt"<<endl;
				cout<<endl;
				break;
			}
			case 'g': {
				d.in();
				break;
			}
			case 'h':
				cout<<" Thoat chuong chinh."<<endl;
				cout<<endl;
				break;
			default:
                cout<<" Lua chon khong hop le!" << endl;
                cout<<endl;
                break;
		}
	}while(c != 'h');
}