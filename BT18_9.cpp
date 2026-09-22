#include<bits/stdc++.h>

using namespace std;

class nguoi{
	protected:
		string hoten;
		int namsinh;
	nguoi(){
		hoten = "";
		namsinh = 0;
	}
	nguoi(string hoten, int namsinh){
		this->hoten = hoten;
		this->namsinh = namsinh;
	}
	
	public:
		void nhap(){
			cout << "Nhap ho ten: ";
			getline(cin,hoten);
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
		}
		void xuat(){
			cout << left
				 << setw(20)<< hoten
				 << setw(10)<< namsinh;
		}	
};

class sinhvien : public nguoi{
	private:
		string masv;
		double dtb;
	public:
	sinhvien():nguoi(){
	}	
	sinhvien(string masv, string hoten, int namsinh, double dtb):nguoi(hoten, namsinh){
		this->masv = masv;
		this->dtb = dtb;
	}
	void nhap(){
		nguoi::nhap();
		cin.ignore();
		cout << "Nhap ma sinh vien: ";
		getline(cin,masv);
		cout << "Nhap diem trung binh: ";
		cin >> dtb;
	}
	void xuat(){
		nguoi::xuat();
		cout << left
			 << setw(15) << masv
			 << setw(10) << dtb << endl;
	}
	
	string getmasv(){
		return masv;
	}
	string gethoten(){
		return hoten;
	}
};

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	vector<sinhvien> dssv;
	// Nhap
	for(int i=0; i<n; i++){
		cout << "=====NHAP SINH VIEN THU "<< i+1 << "====="<< endl;
		cin.ignore();
		sinhvien sv;
		sv.nhap();
		dssv.push_back(sv);
	}
	// Xuat
	cout << "=====DANH SACH SINH VIEN====="<< endl;
	cout << left
		 << setw(20) << "Ho va ten"
		 << setw(10) << "Nam sinh"
		 << setw(15) << "Ma sinh vien"
		 << setw(10) << "diem trung binh"<< endl;
	for(int i=0; i<dssv.size(); i++){
		dssv[i].xuat();
	}
	
	// Tim kiem
	string tukhoa;
	cout << endl << "Nhap ma sinh vien hoac ten sinh vien muon tim: ";
	cin.ignore();
	getline(cin,tukhoa);
	int dem=0;
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].getmasv() == tukhoa || dssv[i].gethoten() == tukhoa){
			cout << "=====DANH SACH SINH VIEN TIM THAY====="<< endl;
			cout << left
				 << setw(20) << "Ho va ten"
				 << setw(10) << "Nam sinh"
				 << setw(15) << "Ma sinh vien"
				 << setw(10) << "diem trung binh"<< endl;
			dssv[i].xuat();
			dem ++;
		}
	}
	if(dem == 0){
			cout << "Khong tim thay sinh vien!!";
		}
	
		return 0;	
}
