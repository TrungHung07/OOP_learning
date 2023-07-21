#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Date
{
private:
    int ngay;
    int thang;
    int nam;
public:
    void nhap();
    void xuat();
};

class nguoi
{
private:
    int makhach;
    string ten;
    string sdt;
public:
    void nhap();
    void xuat();
};


class sanpham
{
protected:
    string ma_so;
    string tieude;
    long giaban;
public:
    virtual void nhap();
    virtual void xuat();
    long getgiaban();
};


class tranh : public sanpham
{
protected:
    int rong;
    int cao;
    string hoasi;
public:
    void nhap();
    void xuat();
};


class CD : public sanpham
{
protected:
    string casi;
    string studio;
public:
    void nhap();
    void xuat();
};

class hoadon
{
protected:
    int n;
    string ma_hoa_don;
    nguoi khachhang;
    Date ngay_mua;
    sanpham *a[100];
    long sum;
public:
    void nhap();
    void xuat();
    long tong();
};

class danh_sach
{
protected:
    int size;
    hoadon b[100];
public:
    void nhap();
    void xuat();
    long get_thu_nhap();
};


void Date::nhap()
{
    cout<<"nhap ngay: ";
    cin>>ngay;
    cout<<"nhap thang: ";
    cin>>thang;
    cout<<"nhap nam: ";
    cin>>nam;
}


void Date::xuat()
{
    cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

void nguoi::nhap()
{
    cout<<"nhap ten: ";
    cin>>ten;
    cout<<"nhap sdt: ";
    cin>>sdt;
    cout<<"nhap ma so khach hang : ";
    cin>>makhach;
}

void nguoi::xuat()
{
    cout<<"ten :"<<ten<<endl;
    cout<<"ma khach hang: "<<makhach<<endl;
    cout<<"sdt khach hang: "<<sdt<<endl;
}

void sanpham::nhap()
{
    cout<<"nhap tieu de cua san pham: ";
    cin>>tieude;
    cout<<"nhap gia ban cua san pham: ";
    cin>>giaban;
    cout<<"nhap ma so cua san pham: ";
    cin>>ma_so;
}

void sanpham::xuat()
{
    cout<<"tieu de : ";
    cout<<tieude<<endl;
    cout<<"gia ban : ";
    cout<<giaban<<endl;
    cout<<"ma so : ";
    cout<<this->ma_so<<endl;
}

long sanpham::getgiaban()
{
    return giaban;
}


void tranh::nhap()
{
    sanpham::nhap();
    cout<<"nhap chieu rong va chieu cao: ";
    cin>>rong;
    cin>>cao;
    cout<<"nhap ten cua hoa si ve buc tranh nay: ";
    cin>>hoasi;
}


void tranh::xuat()
{
    sanpham::xuat();
    cout<<"chieu rong: "<<this->rong<<endl;
    cout<<"chieu cao : "<<this->cao<<endl;
    cout<<"ten cua hoa si: "<<hoasi<<endl;
}


void CD::nhap()
{
    sanpham::nhap();
    cout<<"nhap vao ten ca si: ";
    cin>>casi;
    cout<<"nhap vao ten studio: ";
    cin>>studio;
}


void CD::xuat()
{
    sanpham::xuat();
    cout<<"ten ca si: "<<casi<<endl;
    cout<<"ten studio: "<<studio<<endl;
}



void hoadon::nhap()
{
    cout<<"nhap ma hoa don : ";
    cin>>ma_hoa_don;
    cout<<"nhap thong tin khach hang: " << endl;
    khachhang.nhap();
    cout << " nhap thong ngay lap hoa don: " << endl;
    ngay_mua.nhap();
    cout<<"nhap vao so luong san pham ma khach hang nay mua: ";
    cin>>this->n;
    for(int i=0;i<n;i++)
    {
        int loai;
        cout<<"nhap vao loai san pham (1/tranh) va (2/CD): ";
        cin>>loai;
        if(loai==1)
        {
            a[i]=new tranh();
        }
        else 
        {
            a[i]=new CD();
        }
        a[i]->nhap();
    }
}

void hoadon::xuat()
{
    cout<<"ma hoa don: ";
    cout<<ma_hoa_don<<endl;
    cout<<"thong tin khach hang: "<<endl;
    khachhang.xuat();
    cout<<"thong tin ngay mua: "<<endl;
    ngay_mua.xuat();
    for(int i=0;i<n;i++)
    {
        a[i]->xuat();
    }
}


long hoadon::tong()
{
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i]->getgiaban();
    }
    return sum;
}


void danh_sach::nhap()
{   
    size=0;
    cout<<"nhap so luong khach hang: ";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        b[i].nhap();
    }
}


void danh_sach::xuat()
{
    for(int i=0;i<size;i++)
    {
        b[i].xuat();
        cout<<"tong tien cua hoa don nay: "<<b[i].tong()<<endl;        
    }
}

long danh_sach::get_thu_nhap()
{
    long sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=b[i].tong();
    }
    return sum;
}





int main()
{
    danh_sach x;
    x.nhap();
    x.xuat();
    cout<<"thu nhap cua quan ( tong cac hoa don ): "<<x.get_thu_nhap()<<endl;
}