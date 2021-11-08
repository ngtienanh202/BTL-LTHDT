#include <iostream>
#include <conio.h>
using namespace std;

struct Ngay{
    int ngay, thang, nam;
};

class ConNguoi{
    protected:
        string HoTen;
        Ngay NgaySinh;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual long ThanhTien() = 0;
};

class NhanVien:public ConNguoi{
    private:
        float LuongTheoNgay = 100000;
        int SoNgayLam;
        float TienThuong;
    public:
        void Nhap();
        void Xuat();
        long ThanhTien();
};

class KhachHang:public ConNguoi{
    private:
        float NgayO;
        float GiaTien;
    public:
        void Nhap();
        void Xuat();
        long ThanhTien();
};

void ConNguoi::Nhap(){
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin, HoTen);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> NgaySinh.ngay;
    cin >> NgaySinh.thang;
    cin >> NgaySinh.nam;
}

long NhanVien::ThanhTien(){
    return LuongTheoNgay * SoNgayLam + TienThuong;
}

void ConNguoi::Xuat(){
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
}

void NhanVien::Nhap(){
    ConNguoi::Nhap();
    cout << "Muc luong theo ngay la 100000 VND" << endl;
    cout << "Nhap so ngay lam: ";
    cin >> SoNgayLam;
    cout << "Nhap tien thuong: ";
    cin >> TienThuong;
}

void NhanVien::Xuat(){
    ConNguoi::Xuat();
    cout << "So ngay lam: " << SoNgayLam << endl;
    cout << "Tien luong: " << this->ThanhTien() << endl;
}


void KhachHang::Nhap(){
    ConNguoi::Nhap();
    cout << "So ngay o lai khach san: ";
    cin >> NgayO;
    cout << "Gia tien 1 ngay o: ";
    cin >> GiaTien;
}

void KhachHang::Xuat(){
    ConNguoi::Xuat();
    cout << "Thanh tien sau khi o lai khach san " << NgayO << " ngay la: " << ThanhTien();
}

long KhachHang::ThanhTien(){
    return NgayO * GiaTien;
}

int main(){
    ConNguoi *cn;
    int k;
    while(1){
        system("cls");
        cout << "\n1. Nhan vien.";
        cout << "\n2. KhachHang.";
        cout << "\n0. Tro ve Menu chinh.";
        cout << "\nChon chuc nang: ";
        cin >> k;
        switch(k){
            case 1:
                cn = new NhanVien;
                cn->Nhap();
                cn->Xuat();
                system("pause");
                break;
            case 2:
                cn = new KhachHang;
                cn->Nhap();
                cn->Xuat();
                system("pause");
                break;
            case 0:
            return 0;
            default:
                break;
        }
    }
    
}



