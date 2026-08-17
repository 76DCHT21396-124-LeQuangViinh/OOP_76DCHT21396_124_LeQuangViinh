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
        cout << "Nhap thong tin nhan vien "<< i+1<< "\n";
        cin.ignore();
        cout << "Nhap ma nhan vien: ";
        getline(cin, nv[i].manv);
        cout << "Nhap ten nhan vien: ";
        getline(cin, nv[i].tennv);
        cout << "Luong: ";
        cin >> nv[i].luong;
        cout << "He so: ";
        cin >> nv[i].heso;
        cout << "\n";
    }
}

void xuat(NhanVien nv[], int n){
    for(int i=0; i<n; i++){
        cout << left
             << setw(15) << nv[i].manv
             << setw(30) << nv[i].tennv
             << setw(25) << nv[i].luong
             << setw(10) << nv[i].heso
             << "\n";
    }
}

int main(){
    NhanVien nv[100];
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    nhap(nv,n);
    xuat(nv,n);
    return 0;
}

