#include<bits/stdc++.h>

using namespace std;

class SinhVien{
	private:
		string hoten;
		int namsinh;
		float diem[4];
		string monhoc[4] = {
			"Toan", "Hoa", "Ly", "Sinh"	
		};
		
	public:
		void nhap(){
			cin.ignore();
			cout << "Nhap ho va ten: ";
			getline(cin, hoten);
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
			for(int i=0; i<4; i++){
				cout << "Nhap diem mon "<< monhoc[i]<< ": ";
				cin >> diem[i];
			}
		}
		
		float diemtb(){
			float tong=0;
			for(int i=0; i<4; i++){
				tong += diem[i];
			}
			return tong/4;
		}
		
		void xuat(){
			cout << left
				 << setw(20)<< hoten
				 << setw(15)<< namsinh;
				 for(int i=0; i<4; i++){
				 	cout << setw(15) << diem[i];
				 }
			cout << setw(15)<< diemtb() << endl;
		}
		
		bool kiemtra(){
			for(int i=0; i<4; i++){
				if(diem[i]<5){
					return false;
				}
			}
			return true;
		}

};

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	vector <SinhVien> dssv;
	
	for(int i=0; i<n; i++){
		cout << "=== NHAP THONG TIN SINH VIEN THU "<< i+1<< "==="<< endl;
		
		SinhVien sv;
		
		sv.nhap();
		
		dssv.push_back(sv);	
	}
	
	cout << endl << "=========================================== DANH SACH SINH VIEN =============================================="<< endl;
	
	cout << left
		 << setw(20)<< "Ho va Ten"
		 << setw(15)<< "Nam Sinh"
		 << setw(15)<< "Diem Toan"
		 << setw(15)<< "Diem Ly"
		 << setw(15)<< "Diem Hoa"
		 << setw(15)<< "Diem Sinh"
		 << setw(15)<< "Diem Trung Binh"<<endl;
	
	for(int i=0; i<dssv.size(); i++){
		dssv[i].xuat();
	}
	
	
	cout << endl << "==================================== DANH SACH SINH VIEN THI TOT NGHIEP ======================================"<< endl;
	
	cout << left
		 << setw(20)<< "Ho va Ten"
		 << setw(15)<< "Nam Sinh"
		 << setw(15)<< "Diem Toan"
		 << setw(15)<< "Diem Ly"
		 << setw(15)<< "Diem Hoa"
		 << setw(15)<< "Diem Sinh"
		 << setw(15)<< "Diem Trung Binh"<<endl;
	
	int count =0;
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].diemtb()<7 && dssv[i].kiemtra() == true){
			dssv[i].xuat();
			count ++;
		}
	}
	if(count == 0){
			cout << "Danh sach trong";
	}
	return 0;
	
}
