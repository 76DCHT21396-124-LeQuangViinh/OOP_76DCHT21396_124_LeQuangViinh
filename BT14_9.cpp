#include<bits/stdc++.h>

using namespace std;

class nguoi{
	protected:
		string hoten;
		int namsinh;
	// ham tao khong doi
	nguoi(){
		hoten = "";
		namsinh = 0;
	}
	// ham tao co doi
	nguoi(string hoten, int namsinh){
		this->hoten=hoten;
		this->namsinh=namsinh;
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
		float dtb;
	public:
		sinhvien():nguoi(){
		}
		sinhvien(string hoten, int namsinh, string masv, float dtb):nguoi(hoten, namsinh){
			this->masv = masv;
			this->dtb = dtb;
		}
		void nhap(){
			nguoi::nhap();//goi nhap lop nguoi
			cin.ignore();
			cout << "Nhap msv: ";
			getline(cin, masv);
			cout << "Nhap dtb: ";
			cin >> dtb;
		}
		void xuat(){
			nguoi::xuat();
			cout << left
				 << setw(15) << masv
				 << setw(10) << dtb << endl;
		}
		
		
		float diemtb(){
			return dtb;
		}
};

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	vector<sinhvien> dssv;
	for(int i=0; i<n; i++){
		cout << "NHAP SINH VIEN THU "<< i+1<<endl;
		sinhvien sv;
		
		sv.nhap();
		dssv.push_back(sv);
		cin.ignore();
	}
	cout << "=====DANH SACH SINH VIEN====="<< endl;
	cout << left
		 << setw(20) << "Ho va ten"
		 << setw(10) << "Nam sinh"
		 << setw(15) << "Ma sinh vien"
		 << setw(10) << "diem trung binh"<< endl;
	for(int i=0; i<dssv.size(); i++){
		dssv[i].xuat();
	}
	for(int i=0; i<dssv.size()-1; i++){
		for(int j=i+1; j<dssv.size(); j++){
			if(dssv[i].diemtb()<dssv[j].diemtb()){
				sinhvien tg = dssv[i];
				dssv[i] = dssv[j];
				dssv[j] = tg;
			}
		}
	}
	cout << "=====DANH SACH SAU SAP XEP====="<< endl;
	cout << left
		 << setw(20) << "Ho va ten"
		 << setw(10) << "Nam sinh"
		 << setw(15) << "Ma sinh vien"
		 << setw(10) << "diem trung binh"<< endl;
	for(int i=0; i<dssv.size(); i++){
		dssv[i].xuat();
	}
	
	return 0;
	
}

