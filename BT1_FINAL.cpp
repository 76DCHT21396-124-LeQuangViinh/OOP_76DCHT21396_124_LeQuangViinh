#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct NhanVien{
    string manv;
    string tennv;
    long luong;
    int heso;
};

void nhap(NhanVien nv[], int n){
    for(int i=0; i<n; i++){
        cout << "NHAP THONG TIN NHAN VIEN THU "<< i+1<< "\n";
        cin.ignore();
        cout << "Nhap ma nhan vien: ";
        getline(cin, nv[i].manv);
        cout << "Nhap ho va ten nhan vien: ";
        getline(cin, nv[i].tennv);
        cout << "Luong co ban: ";
        cin >> nv[i].luong;
        cout << "He so: ";
        cin >> nv[i].heso;
        cout << "\n";
    }
}

void xuat(NhanVien nv[], int n){
    for(int i=0; i<n; i++){
        cout << left
             << setw(20) << nv[i].manv
             << setw(25) << nv[i].tennv
             << setw(20) << nv[i].luong
             << setw(10) << nv[i].heso
             << endl;
    }
}

int main(){
    NhanVien nv[100];
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cout << endl;
    nhap(nv,n);
    cout << "---------------------------THONG TIN NHAN VIEN---------------------------\n";
    cout << left
         << setw(20) << "Ma Nhan Vien"
         << setw(25) << "Ho va Ten"
         << setw(20) << "Luong Co Ban"
         << setw(10) << "He So"
         << endl;
    cout << "-------------------------------------------------------------------------\n";
    xuat(nv,n);
    return 0;
}

