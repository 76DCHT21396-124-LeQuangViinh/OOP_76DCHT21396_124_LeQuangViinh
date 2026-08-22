#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Đối tượng: Nhân Viên(Mã Nhân Viên, Họ tên, Nhày sinh, Dịa chỉ)
// Kiểu dữ liệu
//manv: string
//tennv: string
//ngaysinh: string
//diachi: string

class NhanVien{
private:
    string manv;
    string tennv;
    string ngaysinh;
    string diachi;
public:
    void nhap(){
        cout << "Nhap ma nhan vien: ";
        getline(cin,manv);
        cout << "Nhap ten nhan vien: ";
        getline(cin,tennv);
        cout << "Nhap ngay sinh: ";
        getline(cin,ngaysinh);
        cout << "Nhap dia chi: ";
        getline(cin,diachi);
    }
    void xuat(){
        cout << "===THONG TIN NHAN VIEN==="<<endl;
        cout << "Ma nhan vien: "<< manv<<endl;
        cout << "Ten nhan vien: "<< tennv<< endl;
        cout << "Ngay sinh: "<< ngaysinh<< endl;
        cout << "Dia chi: "<< diachi<< endl;
    }
};

int main(){
	
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cin.ignore();
	
//	cach 1 dung mang
//    NhanVien dsnv[n];
//	for(int i=0;i<n;i++){
//		dsnv[i].nhap();
//	}
//	
//	for(int i=0;i<n;i++){
//		dsnv[i].xuat();
//	}

//	cach 2 dung con tro cap phat dong
//	NhanVien *dsnv;
//	dsnv = new NhanVien[n];
//	for(int i=0;i<n;i++){
//		dsnv[i].nhap();
//	}
//	
//	for(int i=0;i<n;i++){
//		dsnv[i].xuat();
//	}

//	cach 3 dung vector 
	vector <NhanVien> dsnv;
	for(int i=0;i<n;i++){
		NhanVien nv;
		nv.nhap();
		
		dsnv.push_back(nv);
	}
	
	for(int i=0;i<n;i++){
		dsnv[i].xuat();
	}
 
    return 0;
}
