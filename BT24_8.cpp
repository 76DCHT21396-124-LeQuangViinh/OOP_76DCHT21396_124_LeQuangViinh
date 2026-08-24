#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

    NhanVien (){
        manv = "";
        tennv = "";
        ngaysinh = "";
        diachi = "";
    }

    NhanVien (string manv, string tennv, string ngaysinh, string diachi) {
    this -> manv=manv;
    this -> tennv=tennv;
    this -> ngaysinh=ngaysinh;
    this -> diachi=diachi;
}

//    void nhap(){
//        cout << "Nhap ma nhan vien: ";
//        getline(cin,manv);
//        cout << "Nhap ten nhan vien: ";
//        getline(cin,tennv);
//        cout << "Nhap ngay sinh: ";
//        getline(cin,ngaysinh);
//        cout << "Nhap dia chi: ";
//        getline(cin,diachi);
//        NhanVien nv(manv, tennv, ngaysinh, diachi);
//    }
    void xuat(){
        cout << left
             << setw(20) << manv
             << setw(30) << tennv
             << setw(15) << ngaysinh
             << setw(20) << diachi
             << endl;
    }
};

int main(){

	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cin.ignore();

//	NhanVien Minh("001","Minh","27/07/2004","Ha Noi");
//	Minh.xuat();
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
            string manv;
            string tennv;
            string ngaysinh;
            string diachi;

            cout << "Nhap ma nhan vien: ";
            getline(cin,manv);
            cout << "Nhap ten nhan vien: ";
            getline(cin,tennv);
            cout << "Nhap ngay sinh: ";
            getline(cin,ngaysinh);
            cout << "Nhap dia chi: ";
            getline(cin,diachi);
            NhanVien nv(manv, tennv, ngaysinh, diachi);
            dsnv.push_back(nv);
        }

    cout << "===========================DANH SACH NHAN VIEN=========================="<<endl;
    cout << left
         << setw(20) << "Ma Nhan Vien"
         << setw(30) << "Ten Nhan Vien"
         << setw(15) << "Ngay Sinh"
         << setw(20) << "Dia Chi"
         << endl
         << string(72,'-')
         <<endl;

	for(int i=0;i<n;i++){
		dsnv[i].xuat();
	}

    return 0;
}
