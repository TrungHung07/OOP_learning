#include<bits/stdc++.h>
using namespace std;

//ĐỀ : XÂY DỰNG LỚP ĐA THỨC BẬC N VÀ CÁC TOÁN TỬ << ; >> ; +

class equation//polynomial equation: da thuc
{
    friend istream& operator >> (istream&,equation&);
    friend ostream& operator << (ostream&,equation);
    protected:
    int element;
    // int exponent;
    public:
    equation operator + (equation);
};


equation equation::operator+(equation a)
{
    equation c;
    c.element=this->element+a.element;
    return c;
}   



class Polynomial
{
    protected:
    int quantity;
    equation don_thuc[1000];
    public:
    void nhap();
    void xuat();
    Polynomial operator+(Polynomial);
};


Polynomial Polynomial::operator+(Polynomial b)
{
    Polynomial c;
    c.quantity=max(this->quantity,b.quantity);
    c.don_thuc[c.quantity];
    for(int i=0;i<c.quantity;i++)
    {
        c.don_thuc[i]=this->don_thuc[i]+b.don_thuc[i];
    }
    return c;
}


istream& operator>>(istream& in,equation& a)
{
    cout<<"nhap vao lan luot so hang: ";
    in>>a.element;
    return in;
}

ostream& operator<<(ostream& out,equation a)
{
    out<<a.element<<"^";
    return out;
}


void Polynomial::nhap()
{
    cout<<"nhap vao bac lon nhat cua da thuc: ";
    cin>>this->quantity;
    don_thuc[quantity];
    for(int i=0;i<quantity;i++)
    {
        cin>>don_thuc[i];
    }
}

void Polynomial::xuat()
{
    cout<<"da thuc: ";
    for(int i=0;i<quantity-1;i++)
    {
        cout<<don_thuc[i]<<i+1<<" + ";
    }    
    cout<<don_thuc[quantity-1]<<quantity;
}



int main()
{
    Polynomial a;
    a.nhap();
    a.xuat();
    Polynomial b;
    b.nhap();
    b.xuat();
    cout<<"cong hai da thuc a va b: ";
    (a+b).xuat();
    return 0;
}