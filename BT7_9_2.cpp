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
		else{
			mau = mauso;
		}
	}
	
	~PhanSo(){
	}
	
	void rutgon(){
		if(tu == 0 ){
			mau = 1;
			return;
		}
		int ucln = UCLN(tu, mau);
		tu /= ucln;
		mau /= ucln;
	}
	
	friend istream& operator >> (istream& is, PhanSo& ps){
		cout << "Nhap tu so: ";
		is >> ps.tu;
		cout << "Nhap mau so(khac 0): ";
		is >> ps.mau;
		while (ps.mau == 0){
			cout << "Mau so phai khac 0; Vui long nhap lai."<< endl;
			is >> ps.mau;
		}
		return is;
	}
	
	friend ostream& operator << (ostream& os,PhanSo ps){
		if(ps.mau == 1){
			os << ps.tu;
		}
		else if(ps.mau == -1){
			os << -ps.tu;
		}
		else if(ps.tu == 0){
			os << 0;
		}
		else if(ps.mau < 0){
			ps.tu = -ps.tu;
			ps.mau = -ps.mau;
			os << ps.tu << "/" << ps.mau;
		}
		else {
			os << ps.tu << "/" << ps.mau;
		}
		return os;
	}
	
	PhanSo operator+(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau + mau*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	}
	PhanSo operator-(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau - mau*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	} 
	PhanSo operator*(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.tu;
		kq.mau = mau*ps2.mau;
		kq.rutgon();
		return kq;
	}
	
	PhanSo operator/(PhanSo ps2){
		PhanSo kq;
		kq.tu = tu*ps2.mau;
		kq.mau = mau*ps2.tu;
		kq.rutgon();
		return kq;
	}
};
	
int main(){
	PhanSo ps1, ps2;
	
	cout << "===NHAP PHAN SO THU NHAT==="<< endl;
	cin >> ps1;
	cout << "===NHAP PHAN SO THU HAI==="<< endl;
	cin >> ps2;
	
	ps1.rutgon();
	ps2.rutgon();
	
	cout << "HAI PHAN SO DA DUOC RUT GON LA: "<< endl;
	cout << "Phan so 1: "<< ps1 << endl;
	cout << "Phan so 2: "<< ps2 << endl;
	
	cout << "=== KET QUA PHEP TINH ==="<< endl;
	
	cout << "Tong = "<< (ps1 + ps2)<< endl;
	cout << "Hieu = "<< (ps1 - ps2)<< endl;
	cout << "Tich = "<< (ps1 * ps2)<< endl;
	cout << "Thuong = "<< (ps1 / ps2)<< endl;

	return 0;
}
