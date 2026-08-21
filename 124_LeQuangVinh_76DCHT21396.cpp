#include <iostream>
#include <string>

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
    NhanVien Minh;

    Minh.nhap();
    Minh.xuat();

    return 0;
}
