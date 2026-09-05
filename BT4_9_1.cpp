#include<bits/stdc++.h>

using namespace std;

class Sinhvien{
	private:
		string hoten;
		int namsinh;
		float diem[5];
		string tenmon[5] = {
			"Toan", "Van", "Anh", "Hoa", "Ly"
		};
		
	public:
		void nhap(){
			cout << "Nhap ho ten: ";
			getline(cin,hoten);
			
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
			
			for(int i=0; i<5; i++){
				cout << "Nhap diem mon "<< tenmon[i]<< ": ";
				cin >> diem[i];
			}
			cin.ignore();
		}
		
		float diemtb(){
			float tong = 0;
			
			for(int i=0; i<5; i++){
				tong += diem[i];
			}
			
			return tong/5;
		}
		
		void xuat(){
			cout << left 
				 << setw(20)<< hoten
				 << setw(15)<< namsinh;
				 for(int i=0; i<5; i++){
				 	cout << left 
				 		 << setw(15)<< diem[i];
				 }
				 cout << left << setw(20)<< diemtb()<< endl;
		}
		
		void thilai(){
			for(int i=0; i<5; i++){
				if(diem[i]<5){
					cout << left
						 << setw(20)<< hoten
						 << setw(15)<< namsinh
						 << setw(15)<< tenmon[i]
						 << setw(10)<< diem[i]<< endl;
				}
			}	
		}
};

int main(){
	
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	
	vector <Sinhvien> dssv;
	
	for(int i=0; i<n; i++){
		cout << "===NHAP SINH VIEN THU "<< i+1 << "==="<< endl;
		
		Sinhvien sv;
		sv.nhap();
		
		dssv.push_back(sv);
	}
	
	cout << "================================================DANH SACH SINH VIEN=========================================================="<< endl;
	cout << left 
				 << setw(20)<< "Ho va Ten"
				 << setw(15)<< "Nam sinh"
				 << setw(15)<< "Diem Toan"
				 << setw(15)<< "Diem Van"
				 << setw(15)<< "Diem Anh"
				 << setw(15)<< "Diem Hoa"
				 << setw(15)<< "Diem Ly"
				 << setw(20)<< "Diem trung binh"<< endl;
	

	
	for(int i=0; i< dssv.size(); i++){
		dssv[i].xuat();
	}
	
	cout << "=================DANH SACH SINH VIEN THI LAI=================="<< endl;
	
	cout << left
		 << setw(20)<< "Ho va Ten"
		 << setw(15)<< "Nam Sinh"
		 << setw(15)<< "Ten Mon"
		 << setw(10)<< "Diem"<< endl;
	for(int i=0; i< dssv.size(); i++){
		dssv[i].thilai();
	}
	return 0;
	
}
