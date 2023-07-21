#include<bits/stdc++.h>
using namespace std;

//đề:
class IntArr
{
    private:
    int count;
    int *value;//mang cac so nguyen
    public:
    IntArr();
    IntArr(int size);
    IntArr(int size,int element);
    IntArr(const IntArr& a);
    ~IntArr();
    IntArr concat(const IntArr& a);
    IntArr& operator = (const IntArr& a);
    friend istream& operator >> (istream&,IntArr&);
    friend ostream& operator << (ostream&,IntArr);
    void push(int val);
    //làm bài tại đây
    //code thêm để main chạy được 
};


IntArr::IntArr()
{
    count=0;
    value=nullptr;
}


IntArr::IntArr(int size)
{
    count=size;
    value=new int[count];
    for(int i=0;i<count;i++)
    {
        value[i]=0;
    }
}


IntArr::IntArr(int size,int data)//khởi tạo mảng với tất cả phần tử là số 0
{
    count=size;
    value=new int[count];
    for(int i=0;i<count;i++)
    {
        value[i]=data;
    }
}

IntArr::IntArr(const IntArr& a)
{
    count=a.count;
    value=new int[count];
    for(int i=0;i<count;i++)
    {
        value[i]=a.value[i];
    }
}

IntArr::~IntArr()
{
    cout<<"destructor has been called: "<<endl;
    delete[] this->value;
}


IntArr& IntArr::operator=(const IntArr& a)
{
    delete[] this->value;//xóa dữ liệu ,giải phóng bộ nhớ
    count=a.count;//gán số lượng phần tử mới 
    value=new int[count];//khởi tạo mảng động
    for(int i=0;i<count;i++)
    {
        value[i]=a.value[i];//gán giá trị phần tử mới 
    }
    return *this;//trả về con trỏ 
}


void IntArr::push(int val)
{
    IntArr temp(1,val);//khởi tạo mảng temp 1 phần tử với data là temp
    *this=this->concat(temp);
}


IntArr IntArr::concat(const IntArr& a)//hàm chèn mảng a vào sau mảng ban đầu 
{
    IntArr ret(this->count+a.count);//mang co count phan tu
    int iRet=0;
    for(int i=0;i<this->count;i++)
    {
        ret.value[iRet]=this->value[i];
        ++iRet;
    }
    for(int i=0;i<a.count;i++)
    {
        ret.value[iRet]=a.value[i];
        ++iRet;
    }
    return ret;
}

istream& operator >> (istream& in,IntArr& a)
{
    cout<<"nhap vao so luong phan tu: ";
    in>>a.count;
    cout<<"nhap vao tung phan tu cua mang: ";
    for(int i=0;i<a.count;i++)
    {
        in>>a.value[i];
    }
    return in;
}


ostream& operator << (ostream& out,IntArr a)
{
    for(int i=0;i<a.count;i++)
    {
        out<<a.value[i];
    }
    return out;
}


int main()
{
    IntArr l1;
    IntArr l2(3,2);//tạo mảng 3 phần tử , tất cả đều có giá trị là 2 
    IntArr l3(2);//tạo một mảng 2 phần tử 
    IntArr l4=l2.concat(l3);//tạo một intarr mới có nội dung là kết quả của việc nối các phần tử l3 vào cuối các phần tử l2 theo thứ tự 
    l2.push(3);//thêm số 3 vào cuối danh sách trong đối tượng l2
    cin>>l2;//nạp chồng toán tử nhập 
    cout<<l2;//nạp chồng toán tử xuất
    cout<<"xuat mang l4: "<<endl;
    cout<<l4;
    return 0;
}