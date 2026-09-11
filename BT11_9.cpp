#include<bits/stdc++.h>

using namespace std;

class sophuc{
	private: 
	float thuc, ao;
	
	public: 
	sophuc(){
		float thuc =0;
		float ao =0;
	}
	
	sophuc(float phanthuc, float phanao){
		thuc = phanthuc;
		ao = phanao;
	}
	
	~sophuc(){
	}
	
	friend istream& operator >> (istream& is, sophuc& sp){
		cout << "Nhap phan thuc: ";
		is >> sp.thuc;
		cout << "Nhap phan ao: ";
		is >> sp.ao;
		return is;
	}
	friend ostream& operator << (ostream& os, sophuc sp){
		if(sp.thuc ==0 && sp.ao==0){
			os << 0;
		}
		else if(sp.thuc ==0 ){
			os << sp.ao<<"i";
		}
		else if(sp.ao < 0){
			os << sp.thuc << "-" << -sp.ao<< "i";
		}
		else if(sp.ao==0){
			os << sp.thuc;
		}
		else{
			os << sp.thuc << "+"<< sp.ao<< "i";
		}
		return os;
	}
	
	sophuc operator + (sophuc sp2){
		sophuc kq;
		kq.thuc = thuc + sp2.thuc;
		kq.ao = ao + sp2.ao;
		return kq; 
	}
	sophuc operator - (sophuc sp2){
		sophuc kq;
		kq.thuc = thuc - sp2.thuc;
		kq.ao = ao - sp2.ao;
		return kq; 
	}
	sophuc operator * (sophuc sp2){
		sophuc kq;
		kq.thuc = thuc * sp2.thuc - ao * sp2.ao;
		kq.ao = thuc * sp2.ao + ao * sp2.thuc;
		return kq; 
	}
	sophuc operator / (sophuc sp2){
		sophuc kq;
		kq.thuc = (thuc * sp2.thuc + ao * sp2.ao)/(sp2.thuc*sp2.thuc+sp2.ao*sp2.ao);
		kq.ao = (ao * sp2.thuc - thuc * sp2.ao)/(sp2.thuc*sp2.thuc+sp2.ao*sp2.ao);
		return kq; 
	}
	
};

int main(){
	sophuc sp1, sp2;
	
	cout << "===NHAP SO PHUC 1==="<<endl;
	cin >> sp1;
	cout << "===NHAP SO PHUC 2==="<<endl;
	cin >> sp2;
	
	cout << "HAI SO PHUC LA: "<< endl;
	cout << "so phuc 1: "<< sp1<< endl;
	cout << "so phuc 2: "<< sp2<< endl;
	
	cout << "===KET QUA CAC PHEP TINH==="<< endl;
	cout << "Tong: "<< sp1 + sp2<< endl;
	cout << "Hieu: "<< sp1 - sp2<< endl;
	cout << "Tich: "<< sp1 * sp2<< endl;
	cout << "Thuong: "<< sp1 / sp2<< endl;
}
