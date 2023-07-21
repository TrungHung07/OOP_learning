#include<bits/stdc++.h>
using namespace std;

class Date
{
    protected:
    int day;
    int month;
    int year;
    public:
    void nhap()
    {
        cout<<"nhap lan luot ngay va thang va nam: ";
        cin>>day>>month>>year;
    }
    void xuat()
    {
        cout<<"xuat lan luot ngay va thang va nam: ";
        cout<<day<<"/"<<month<<"/"<<year;
    }
};



class Human
{
    protected:
    char name[1000];
    char cmnd[1000];
    int born_year;
    char address[1000];
    public:
    void nhap_nguoi()
    {
        cout<<"nhap vao ten : ";
        fflush(stdin);
        gets(name);
        cout<<"nhap cmnd: ";
        cin>>cmnd;
        cout<<"nhap di chia nha: ";
        fflush(stdin);
        gets(address);
        cout<<"nhap nam sinh : ";
        cin>>born_year;
    }
    void xuat_nguoi()
    {
        cout<<"xuat thong tin nguoi so huu : "<<name<<" "<<cmnd<<" "<<address<<" "<<born_year<<endl;
    }
};



class Dat_dai
{
    protected:
    char sogiaychungnhan[1000];
    Human nguoi_so_huu;
    int so_thua;
    int so_to_ban_do;
    char dia_chi_dat[1000];
    int dien_tich;
    Date ngay_cap;
    int thue;
    public:
    virtual void nhap()
    {
        nguoi_so_huu.nhap_nguoi();
        ngay_cap.nhap();
        cout<<"nhap giay so giay chung nhan ( chuoi ): ";
        cin>>sogiaychungnhan;  
        cout<<"nhap so thua ,so to ban do va dien tich cung nhu la thue : ";
        cin>>so_thua>>so_to_ban_do>>dien_tich>>thue;
    }
    virtual void xuat()
    {
        nguoi_so_huu.xuat_nguoi();
        ngay_cap.xuat();
        cout<<"xuat thong tin cua dat dai : ";
        cout<<sogiaychungnhan<<" "<<so_thua<<" "<<so_to_ban_do<<" "<<dien_tich<<" "<<thue<<endl;
    }
    virtual bool check_nong_nghiep()
    {
        return false;
    }
};


class dat_o : public Dat_dai {};

class dat_nong_nghiep : public Dat_dai
{
    protected:
    Date thoi_han_su_dung;
    public:
    void nhap()
    {
        Dat_dai::nhap();
        cout<<"nhap thoi han su dung: ";
        thoi_han_su_dung.nhap();
    }
    void xuat()
    {
        Dat_dai::xuat();
        cout<<"thoi gian su dung: ";
        thoi_han_su_dung.xuat();
    }
    bool check_nong_nghiep()
    {
        return true;
    }
};


class DanhSach_dat
{
    protected:
    int size;
    Dat_dai *Dat[1000];
    public:
    void nhap()
    {
        cout<<"nhap so luong : ";cin>>size;
        for(int i=0;i<size;i++)
        {
            int type;
            cout<<"nhap vao lua chon: "<<endl;
            cout<<"1 la dat nong nghiep."<<endl;
            cout<<"2 la dat o (dat phi nong nghiep)."<<endl;
            cin>>type;
            switch (type)
            {
            case 1: {Dat[i]=new dat_nong_nghiep();break;}
            case 2: {Dat[i]=new dat_o();break;}
            }
            Dat[i]->nhap();
        }
    }
    void xuat()
    {
        for(int i=0;i<size;i++)
        {
            Dat[i]->xuat();
        }
    }
};



int main()
{
    DanhSach_dat a;
    a.nhap();
    a.xuat();


    return 0;
}









