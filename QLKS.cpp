#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

class NhanVien{
    protected:
        string HoTen;
        int SoNgayLam;
        long PhuCap;
        int NamVaoLam;
    public:
    	NhanVien();
        ~NhanVien();
        virtual void Nhap();
        virtual void Xuat();
        virtual long TinhLuong() = 0;
	virtual long getLuong(){
		return TinhLuonh();
	}
};

NhanVien::NhanVien(){
	HoTen = "";
	SoNgayLam = 0;
	PhuCap = 100000;
	NamVaoLam = 0;
}

NhanVien::~NhanVien(){}

class LeTan:public NhanVien{
    protected:
    	long LuongCoBan = 450000;
    public:
        void Nhap();
        void Xuat();
        long TinhLuong();
        
};

class BaoVe:public NhanVien{
    protected:
    	long LuongCoBan = 400000;
    public:
        void Nhap();
        void Xuat();
        long TinhLuong();
};

class PhucVuPhong:public NhanVien{
    protected:
    	long LuongCoBan = 500000;
    public:
        void Nhap();
        void Xuat();
        long TinhLuong();
};

class DauBep:public NhanVien{
    protected:
    	long LuongCoBan = 600000;
    public:
        void Nhap();
        void Xuat();
        long TinhLuong();
};



void NhanVien::Nhap(){
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin, HoTen);
    cout << "Tien phu cap mac dinh la 100000" << endl;
    cout << "Nhap nam vao lam: ";
    cin >> NamVaoLam;
    cout << "Nhap so ngay lam: ";
    cin >> SoNgayLam;
}

void NhanVien::Xuat(){
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Nam vao lam: " << NamVaoLam << endl;
    cout << "So ngay lam: " << SoNgayLam << endl;
    cout << "Tien luong: " << TinhLuong() << endl;
}

long LeTan::TinhLuong(){
	long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long BaoVe::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long PhucVuPhong::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long DauBep::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

void LeTan::Nhap(){
	NhanVien::Nhap();
}

void LeTan::Xuat(){
	NhanVien::Xuat();
}

void BaoVe::Nhap(){
	NhanVien::Nhap();
}

void BaoVe::Xuat(){
	NhanVien::Xuat();
}

void PhucVuPhong::Nhap(){
	NhanVien::Nhap();
}

void PhucVuPhong::Xuat(){
	NhanVien::Xuat();
}

void DauBep::Nhap(){
	NhanVien::Nhap();
}

void DauBep::Xuat(){
	NhanVien::Xuat();
}

class QuanLyNhanVien{
	private:
		vector<NhanVien*> dsNhanVien;
	public:
		void NhapDS();
		void XuatDS();
		void SapXep();
        	void MaxLong();
};

void QuanLyNhanVien::NhapDS(){
	NhanVien *nv;
	int k;
	do{
        system("cls");
        cout << "1. Le tan." << endl;
        cout << "2. Bao ve." << endl;
        cout << "3. Phuc vu phong." << endl;
        cout << "4. Bao ve." << endl;
        cout << "0. Quay lai menu chinh." << endl;
        cout << "Chon chuc nang: ";
        cin >> k;
        switch(k){
        	case 1:
                nv = new LeTan;
                nv->Nhap();
                dsNhanVien.push_back(nv); 
                break;
            case 2:
                nv = new BaoVe;
                nv->Nhap();
                dsNhanVien.push_back(nv);            
                break;
            case 3:
                nv = new PhucVuPhong;
                nv->Nhap();
				dsNhanVien.push_back(nv);
                break;
            case 4:
                nv = new DauBep;
                nv->Nhap();
				dsNhanVien.push_back(nv);
                break;
            case 0:
            	break;
		}
	} while (k != 0);
}

void QuanLyNhanVien::XuatDS(){
	for (int i = 0; i < dsNhanVien.size(); i++) {
		dsNhanVien[i]->Xuat();
		cout << "___________________________" << endl;
	}
}

// Sap Xep theo Luong tang dan
void QuanLyNhanVien::SapXep(){
    for(int i=0;i<dsNhanVien.size();i++){
        for(int j=i+1;j<dsNhanVien.size();j++){
            if(dsNhanVien.at(i)->getLuong()>dsNhanVien.at(j)->getLuong()){
                NhanVien *t=dsNhanVien.at(i);
                dsNhanVien.at(i)=dsNhanVien.at(j);
                dsNhanVien.at(j)=t;
            }
        }
    }
    XuatDS();
}


// Tìm Lương Cao nhất
void QuanLyNhanVien::MaxLong(){
    NhanVien *max=dsNhanVien.at(0);
    for(int i=1;i<dsNhanVien.size();i++){
        if(dsNhanVien.at(i)->getLuong() > max->getLuong())
            max = dsNhanVien.at(i);
    }
    cout<<endl<<"Nhan Vien co Luong cao nhat: "<<endl;
    max->Xuat();
}



int main(){
	int k;
    QuanLyNhanVien qlnv;
	do{
        system("cls");
        cout << "* * * * * QUAN LY NHAN VIEN KHACH SAN * * * * *" << endl;
        cout << "1. Nhap nhan vien" << endl;
        cout << "2. Xuat nhan vien." << endl;
	cout << "3. Sap Xep Luong tang dan."<< endl;
        cout <<" 4. Nhan vien co Luong cao nhat."<<endl;
        cout << "0. Thoat chuong trinh." << endl;
        cout << "Chon chuc nang: ";
        cin >> k;
        switch(k){
            case 1:
                qlnv.NhapDS();
                break;
            case 2:
            	qlnv.XuatDS();
    			break;
	    case 3:
                qlnv.SapXep();
                system("pause");
                break;
            case 4:
                qlnv.MaxLong();
                system("pause");
                break;
    		default:
				break;
        }
    } while(k != 0);
}


