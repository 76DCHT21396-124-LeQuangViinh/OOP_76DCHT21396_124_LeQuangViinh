#include<bits/stdc++.h>

using namespace std;

class SP1 {
	protected:
		int thuc, ao;
	public:
		SP1(){
			thuc =0;
			ao =0;
		}
		SP1(int thuc, int ao){
			this->thuc=thuc;
			this->ao=ao;
		}
		void nhap(){
			cout<< "Nhap phan thuc: ";
			cin >> thuc;
			cout << "Nhap phan ao: ";
			cin >> ao;
		}
		void xuat(){
			if(thuc == 0 && ao == 0){
				cout << 0;
			}
			else if(thuc == 0){
				cout << ao << "i";
			}
			else if(ao == 0){
				cout << thuc;
			}
			else if(ao < 0){
				cout << thuc << " - " << -ao<< "i";
			}
			else{
				cout << thuc << " + "<< ao<< "i";
			}
		}
		
		float module(){
			float md;
			md = sqrt(pow(thuc,2)+pow(ao,2));
			return md;
		}	
};
class SP2 : public SP1{
	public:
		SP2& operator = (SP2& sp){
			thuc = sp.thuc;
			ao = sp.ao;
			return *this;
		}
		bool operator > (SP2& sp){
			return module() > sp.module();
		}
};


int main(){
	int n;
	SP2 dssp[10];
	do{
		cout << "Nhap so luong so phuc(1 - 10): ";
		cin >> n;
		if(n<1 || n>10){
			cout << "So luong so phuc khong phu hop. vui long nhap lai"<< endl;
		}
	}
	while(n<1 || n>10);
	
	cout << "===Nhap so phuc==="<< endl;
	for(int i=0; i<n; i++){
		cout << "So phuc thu "<< i+1<< endl;
		dssp[i].nhap();
	}
	cout << "cac so phuc vua nhap la: ";
	for(int i=0; i<n; i++){
		dssp[i].xuat();
		if(i<n-1){
			cout << " , ";
		}
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(dssp[j].module() > dssp[i].module()){
				SP2 tg = dssp[i];
				dssp[i] = dssp [j];
				dssp[j] = tg;
			}
		}
	}
	
	cout << endl;
	cout << "danh sach so phuc sau sap xep: ";
	for(int i=0; i<n; i++){
		dssp[i].xuat();
		if(i<n-1){
			cout << " , ";
		}
	}
	return 0;
}
