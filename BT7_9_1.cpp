#include<bits/stdc++.h>

using namespace std;

class PhanSo {
	private: 
	int tu, mau;
	
	int UCLN(int a, int b){
		a = abs(a);
		b = abs(b);
		
		while(a*b !=0){
			if(a>b){
				a %= b;
			}
			else {
				b %= a;
			}
		}
		
		return a+b;
	}
	
	
	public: 
	
	PhanSo(){
		tu = 0;
		mau = 1;
	}
	
	PhanSo(int tuso, int mauso){
		tu = tuso;
		if(mauso==0){
			mau = 1;
		}
		mau = mauso;
	}
	
	~PhanSo(){
	}
	
	void nhap();
	void xuat();
	void rutgon();
	PhanSo cong(PhanSo ps2);
	PhanSo tru(PhanSo ps2);
	PhanSo nhan(PhanSo ps2);
	PhanSo chia(PhanSo ps2);
	
};
	void PhanSo::nhap() {
			cout << "Nhap tu so: ";
			cin >> tu;
			
			do {
				cout << "Nhap mau so (Khac 0): ";
				cin >> mau;
				if(mau == 0){
					cout << "Mau so phai khac 0; Vui long nhap lai."<< endl;
				}
			}while(mau ==0);
		}
	void PhanSo::xuat(){
			if(mau == 1){
				cout << tu;
			}
			else if(mau == -1){
				cout << -tu;
			}
			else if(tu == 0){
				cout << 0;
			}
			else if(mau < 0){
				tu = -tu;
				mau = -mau;
				cout << tu << "/" << mau;
			}
			else {
				cout << tu << "/" << mau;
			}
		}
	
	void PhanSo::rutgon(){
		if(tu ==0 ){
			mau = 1;
			return;
		}
		int ucln = UCLN(tu, mau);
		tu /= ucln;
		mau /= ucln;
	}
	
	PhanSo PhanSo::cong(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau + mau*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	}
	
	PhanSo PhanSo::tru(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau - mau*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	} 
	
	PhanSo PhanSo::nhan(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	}
	
	PhanSo PhanSo::chia(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau;
		kq.mau = mau*ps2.tu;
		kq.rutgon();
		return kq;
	}
	
int main(){
	PhanSo ps1, ps2;
	
	cout << "===NHAP PHAN SO THU NHAT==="<< endl;
	ps1.nhap();
	cout << "===NHAP PHAN SO THU HAI==="<< endl;
	ps2.nhap();
	
	ps1.rutgon();
	ps2.rutgon();
	
	cout << "HAI PHAN SO DA DUOC RUT GON LA: "<< endl;
	cout << "Phan so 1: ";
	ps1.xuat();
	cout << endl;
	cout << "Phan so 2: ";
	ps2.xuat();
	cout << endl;
	
	cout << "=== KET QUA PHEP TINH ==="<< endl;
	
	PhanSo tong = ps1.cong(ps2);
	cout << "Tong = ";
	tong.xuat();
	cout << endl;
	
	PhanSo hieu = ps1.tru(ps2);
	cout << "Hieu = ";
	hieu.xuat();
	cout << endl;
	
	PhanSo tich = ps1.nhan(ps2);
	cout << "Tich = ";
	tich.xuat();
	cout << endl;
	
	PhanSo thuong = ps1.chia(ps2);
	cout << "Thuong = ";
	thuong.xuat();
	cout << endl;
	
	
	return 0;
}
