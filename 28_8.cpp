#include <iostream>
#include <iomanip>

using namespace std;

class MaTran {
private:
    int soHang;
    int soCot;
    int phanTu[100][100];

public:
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;
        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "Phan tu [" << i << "][" << j << "] = ";
                cin >> phanTu[i][j];
            }
        }
    }
    void nhapDongCap(int hang, int cot) {
        soHang = hang;
        soCot = cot;
        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "Phan tu [" << i << "][" << j << "] = ";
                cin >> phanTu[i][j];
            }
        }
    }
    void xuat() {
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << right << setw(5)<< phanTu[i][j];
            }
            cout << endl;
        }
    }
    int getSoHang() { return soHang; }
    int getSoCot() { return soCot; }

    friend MaTran truMaTran(MaTran mt1, MaTran mt2);
};

MaTran truMaTran(MaTran mt1, MaTran mt2) {
    MaTran mtKetQua;
    mtKetQua.soHang = mt1.soHang;
    mtKetQua.soCot = mt1.soCot;

    for (int i = 0; i < mt1.soHang; i++) {
        for (int j = 0; j < mt1.soCot; j++) {
            mtKetQua.phanTu[i][j] = mt1.phanTu[i][j] - mt2.phanTu[i][j];
        }
    }
    return mtKetQua;
}

int main() {
    MaTran mt1, mt2, mtHieu;

    cout << "--- NHAP MA TRAN THU NHAT ---\n";
    mt1.nhap();

    cout << "\n--- NHAP MA TRAN THU HAI (Dong cap) ---\n";
    mt2.nhapDongCap(mt1.getSoHang(), mt1.getSoCot());

    mtHieu = truMaTran(mt1, mt2);

    cout << "\n--- MA TRAN BAN DAU 1 ---\n";
    mt1.xuat();

    cout << "\n--- MA TRAN BAN DAU 2 ---\n";
    mt2.xuat();

    cout << "\n--- MA TRAN KET QUA (MT1 - MT2) ---\n";
    mtHieu.xuat();

    return 0;
}
