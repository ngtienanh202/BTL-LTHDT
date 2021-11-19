#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

class NhanVien{
    protected:
        string HoTen, QueQuan, MaNV;
        int SoNgayLam;
        long PhuCap;
        int NamVaoLam;
        long Tienthuong;
        string ChucVu;
    public:
    	NhanVien();
        ~NhanVien();
        virtual void Nhap();
        virtual void Xuat();
        virtual long TinhLuong() = 0;
        long getLuong(){
            return TinhLuong();
        }
        string getMaNV(){
        	return MaNV;
		}
        string getTen(){
            return HoTen;
        }
        int getSoNgayLam(){
            return SoNgayLam;
        }
        int getNamVaoLam(){
            return NamVaoLam;
        }
        void setChucVu(string cv);
        string getChucVu();
};

NhanVien::NhanVien(){
	HoTen = "";
	QueQuan = "";
    ChucVu = "";
	SoNgayLam = 0;
	PhuCap = 200000;
	NamVaoLam = 0;
	Tienthuong = 0;
}

NhanVien::~NhanVien(){}

void NhanVien::setChucVu(string cv){
    this->ChucVu = cv;
}

string NhanVien::getChucVu(){
    return this->ChucVu;
}

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

class PhucVu:public NhanVien{
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
    cout << "Cong thuc tinh luong: Luong co ban * So ngay lam + (Phu cap * (2021-Nam vao lam)) + Tien thuong" << endl;
    cout << "Nhap ma nhan vien: ";
    fflush(stdin);
    getline(cin, MaNV);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, HoTen);
    cout << "Nhap que quan: ";
    fflush(stdin);
    getline(cin, QueQuan);
    cout << "Nhap nam vao lam: ";
    cin >> NamVaoLam;
    cout << "Nhap so ngay lam: ";
    cin >> SoNgayLam;
    cout << "Nhap tien thuong: ";
    cin >> Tienthuong;
}

void NhanVien::Xuat(){
	cout << setw(12) << MaNV << setw(17) << this->getChucVu() << setw(20) << HoTen << setw(18) << QueQuan << setw(12) << NamVaoLam << setw(15) << SoNgayLam << setw(20) << TinhLuong() << endl;
    
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

long PhucVu::TinhLuong(){
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
	cout << "Luong co ban mot ngay la 450000." << endl;
	NhanVien::Nhap();
}

void LeTan::Xuat(){
	NhanVien::Xuat();
}

void BaoVe::Nhap(){
	cout << "Luong co ban mot ngay la 400000." << endl;
	NhanVien::Nhap();
}

void BaoVe::Xuat(){
	NhanVien::Xuat();
}

void PhucVu::Nhap(){
	cout << "Luong co ban mot ngay la 500000." << endl;
	NhanVien::Nhap();
}

void PhucVu::Xuat(){
	NhanVien::Xuat();
}

void DauBep::Nhap(){
	cout << "Luong co ban mot ngay la 600000." << endl;
	NhanVien::Nhap();
}

void DauBep::Xuat(){
	NhanVien::Xuat();
}

class QuanLyNhanVien{
	private:
		vector<NhanVien *> dsNhanVien;
        vector<string> chucVu;
	public:
        void doc_ChucVu(ifstream& filein);
		void NhapDS();
		void XuatDS();
        void SapXep();
        void MaxLong();
        void TongLuong();
        void TimKiem_NV();
};
//Nhap danh sach nhan vien
void QuanLyNhanVien::NhapDS(){  
	NhanVien *nv;
	int k;
	do{
        system("cls");
        cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << setw(119) <<"========================================================" << endl;
		cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(119) <<"||=====||=============================================||" << endl;       
        cout << setw(119) <<"||  1  || Le tan                                      ||" << endl;
        cout << setw(119) <<"||  2  || Bao ve                                      ||" << endl;
        cout << setw(119) <<"||  3  || Phuc vu                               ||" << endl;
        cout << setw(119) <<"||  4  || Dau bep                                     ||" << endl;
        cout << setw(119) <<"||  0  || Quay lai menu chinh                         ||" << endl;
        cout << setw(119) <<"========================================================" << endl;
        cout << setw(119) <<"Chon chuc vu muon them: ";
        cin >> k;
        switch(k){
        	case 1:
                nv = new LeTan; 
                nv->Nhap();
                nv->setChucVu("Le Tan");
                dsNhanVien.push_back(nv); 
                break;
            case 2:
                nv = new BaoVe;
                nv->Nhap();
                nv->setChucVu("Bao ve");
                dsNhanVien.push_back(nv);            
                break;
            case 3:
                nv = new PhucVu;
                nv->Nhap();
                nv->setChucVu("Phuc vu");
				dsNhanVien.push_back(nv);
                break;
            case 4:
                nv = new DauBep;
                nv->Nhap();
                nv->setChucVu("Dau bep");
				dsNhanVien.push_back(nv);
                break;
            default:
				break;
		}
	} while (k != 0);
}

//Xuat danh sach nhan vien
void QuanLyNhanVien::XuatDS(){
	cout << setw(5) << "========================================================================================================================" << endl;
	cout << setw(5) << "||  MA NHAN VIEN  ||  CHUC VU  ||      HO VA TEN      ||  QUE QUAN  ||  NAM VAO LAM  ||  SO NGAY LAM  ||  TIEN LUONG  ||" << endl;
	cout << setw(5) << "========================================================================================================================" << endl;
	for (int i = 0; i < dsNhanVien.size(); i++){
		dsNhanVien[i]->Xuat();
	}
}

//Sap xep nhan vien theo luong  
void QuanLyNhanVien::SapXep(){
    int key, choose;
    do {
        system("cls");
        cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << setw(119) <<"========================================================" << endl;
		cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(119) <<"||=====||=============================================||" << endl;       
        cout << setw(119) <<"||  1  || Theo ten nhan vien                          ||" << endl;
        cout << setw(119) <<"||  2  || Theo nam vao lam                            ||" << endl;
        cout << setw(119) <<"||  3  || Theo luong                                  ||" << endl;
        cout << setw(119) <<"||  0  || Quay lai                                    ||" << endl;
        cout << setw(119) <<"========================================================" << endl;
        cout << setw(119) <<"Chon chuc nang : "; 
		cin >> key;
        switch (key){
        case 1:
            do{
                system("cls");
                cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
		        cout << setw(119) <<"========================================================" << endl;
				cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
				cout << setw(119) <<"||=====||=============================================||" << endl;       
		        cout << setw(119) <<"||  1  || Chieu xuoi                                  ||" << endl;
		        cout << setw(119) <<"||  2  || Chieu nguoc                                 ||" << endl;
		        cout << setw(119) <<"||  0  || Quay lai                                    ||" << endl;
		        cout << setw(119) <<"========================================================" << endl;
		        cout << setw(119) <<"Chon chuc nang : "; 
				cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getTen().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getTen().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) > 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getTen().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getTen().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) < 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        case 2:
            do{
                system("cls");
                cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
		        cout << setw(119) <<"========================================================" << endl;
				cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
				cout << setw(119) <<"||=====||=============================================||" << endl;       
		        cout << setw(119) <<"||  1  || Chieu xuoi                                  ||" << endl;
		        cout << setw(119) <<"||  2  || Chieu nguoc                                 ||" << endl;
		        cout << setw(119) <<"||  0  || Quay lai                                    ||" << endl;
		        cout << setw(119) <<"========================================================" << endl;
		        cout << setw(119) <<"Chon chuc nang : "; 
				cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getNamVaoLam() > dsNhanVien.at(j)->getNamVaoLam()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getNamVaoLam() < dsNhanVien.at(j)->getNamVaoLam()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        case 3:
            do{
                system("cls");
                cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
		        cout << setw(119) <<"========================================================" << endl;
				cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
				cout << setw(119) <<"||=====||=============================================||" << endl;       
		        cout << setw(119) <<"||  1  || Chieu xuoi                                  ||" << endl;
		        cout << setw(119) <<"||  2  || Chieu nguoc                                 ||" << endl;
		        cout << setw(119) <<"||  0  || Quay lai                                    ||" << endl;
		        cout << setw(119) <<"========================================================" << endl;
		        cout << setw(119) <<"Chon chuc nang : "; 
				cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getLuong() > dsNhanVien.at(j)->getLuong()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getLuong() < dsNhanVien.at(j)->getLuong()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        default:
            break;
        }
    }while(key != 0);
}
//Nhan vien co luong cao nhat
void QuanLyNhanVien::MaxLong(){
    vector<string> chucVu;
    ifstream filein;
    for(int i=0;i<chucVu.size(); i++){
        getline(filein, chucVu.at(i), ',');
    }
    NhanVien *max=dsNhanVien.at(0);
    for(int i=1;i<dsNhanVien.size();i++){
        if(dsNhanVien.at(i)->getLuong() > max->getLuong())
            max = dsNhanVien.at(i);
    }
    cout<<endl<<"Nhan Vien co Luong cao nhat: "<<endl;
    max->Xuat();
}

//Tim kiem nhan vien
void QuanLyNhanVien::TimKiem_NV(){
    int key, nam, dem = 0;
    string tukhoa;
    do{
        system("cls");
        cout << setw(119) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << setw(119) <<"========================================================" << endl;
		cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(119) <<"||=====||=============================================||" << endl;       
        cout << setw(119) <<"||  1  || Theo ma nhan vien                           ||" << endl;
        cout << setw(119) <<"||  2  || Theo ten nhan vien                          ||" << endl;
        cout << setw(119) <<"||  3  || Theo nam vao lam                            ||" << endl;
        cout << setw(119) <<"||  0  || Quay lai                                    ||" << endl;
        cout << setw(119) <<"========================================================" << endl;
        cout << setw(119) <<"Chon chuc nang : "; 
		cin >> key;
        switch (key){
        case 1:
            cout << "\nNhap ma nhan vien muon tim: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getMaNV().length()];
                strcpy(str2, dsNhanVien.at(i)->getMaNV().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!";
            system("pause");
            break;
        case 2:
            cout << "\nNhap ten nhan vien muon tim: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getTen().length()];
                strcpy(str2, dsNhanVien.at(i)->getTen().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!";
            system("pause");
            break;
        case 3:
            cout << "\nNhap nam vao lam muon tim: ";
            cin >> nam;
            for(int i=0; i<dsNhanVien.size(); i++){
                if(nam == dsNhanVien.at(i)->getNamVaoLam()){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!";
            system("pause");
            break;
        default:
            break;
        }
    }while(key != 0);
}

//Tong tien khach san tra luong cho nhan vien
void QuanLyNhanVien::TongLuong(){
    long tong=0;
    for(int i=0;i<dsNhanVien.size();i++){
        tong += dsNhanVien.at(i)->getLuong();
    }
    cout<<endl<<"Tong tien khach san tra luong cho nhan vien: "<<tong<< " VND" << endl;
}
int Menu(){
	int k;
    QuanLyNhanVien qlnv;
	do{
        system("cls");
        cout << setw(119) <<"* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << setw(119) <<"========================================================" << endl;
		cout << setw(119) <<"|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(119) <<"||=====||=============================================||" << endl;        
        cout << setw(119) <<"||  1  || Nhap nhan vien                              ||" << endl;
        cout << setw(119) <<"||  2  || Xuat nhan vien                              ||" << endl;
        cout << setw(119) <<"||  3  || Sap xep luong nhan vien                     ||" << endl;
        cout << setw(119) <<"||  4  || Nhan vien co luong cao nhat                 ||" << endl;
        cout << setw(119) <<"||  5  || Tim kiem nhan vien                          ||" << endl;
        cout << setw(119) <<"||  6  || Tong luong khach san phai tra cho nhan vien ||" << endl;
        cout << setw(119) <<"||  0  || Thoat chuong trinh                          ||" << endl;
        cout << setw(119) <<"========================================================" << endl;
        cout << setw(119) <<"Chon chuc nang: ";
        cin >> k;
        switch(k){
            case 1:
                qlnv.NhapDS();
                break;
            case 2:
            	qlnv.XuatDS();
                system("pause");
    			break;
            case 3:
                qlnv.SapXep();
                system("pause");
                break;
            case 4:
                qlnv.MaxLong();
                system("pause");
                break;
            case 5:   
                qlnv.TimKiem_NV();
                system("pause");
                break;
            case 6:
                qlnv.TongLuong();
                system("pause");
                break;
    		default:
				break;
        }
    } while(k != 0);
}

int main(){
	Menu();
}
