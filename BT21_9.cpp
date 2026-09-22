#include<bits/stdc++.h>

using namespace std;

class PS1{
	protected:
		int tu, mau;
		
		
	public:
		void nhap(){
			cout << "Nhap tu so: ";
			cin >> tu;
			do{
				cout << "Nhap mau so: ";
				cin >> mau;
				if(mau==0){
					cout<< "Mau khong duoc bang 0"<< endl;
				}
			}
			while(mau==0);
		}
		
		void xuat(){
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
		
		int UCLN(int a, int b){
			a = abs(a);
			b = abs(b);
			
			while(a*b!=0){
				if(a>b){
					a%=b;
				}
				else{
					b%=a;
				}
			}
			return a+b;
		}
		void rutgon(){
			int ucln = UCLN(tu, mau);
			tu /= ucln;
			mau/= ucln;
		}
};

class PS2 : public PS1 {
	public: 
		PS2& operator = (PS2& ps){
			tu = ps.tu;
			mau = ps.mau;
			return *this;
		}	
		
		bool operator > (PS2& ps){
			float gt1 = (float)tu / mau;
			float gt2 = (float)ps.tu / ps.mau;
			return gt1 > gt2;
		}
};

int main(){
	PS2 dsps[10];
	int n;
	do{
		cout << "Nhap so luong phan so(1 - 10): ";
		cin >> n;
		if(n<1 || n>10){
			cout << "So luong phan tu khong phu hop. vui long nhap lai"<< endl;
		}
	}
	while(n<1 || n>10);
	cout << "===Nhap danh sach phan so==="<< endl;
	for(int i =0; i<n ; i++){
		cout << "Phan so thu "<< i+1<<":"<< endl;
		dsps[i].nhap();
	}
	for(int i =0; i<n ; i++){
		dsps[i].rutgon();
	}
	cout << "Phan so toi gian vua nhap la: ";
	for(int i =0; i<n ; i++){
		dsps[i].xuat();
		cout << "   ";
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsps[j] > dsps[i]) {
                PS2 tg = dsps[i];
                dsps[i] = dsps[j];
                dsps[j] = tg;
            }
        }
    }
    cout << "\n=== DANH SACH SAU KHI SAP XEP GIAM DAN ===\n";
    for (int i = 0; i < n; i++) {
        dsps[i].xuat();
        cout << "   ";
    }
    cout << endl;
}
