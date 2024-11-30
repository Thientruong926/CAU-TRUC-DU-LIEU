#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class monhoc
{
private:
    string mamon;
    string tenmon;
    int sotinchi;
    double diem;
    int somonhoc;

public:
    monhoc() : mamon(""), tenmon(""), sotinchi(0), diem(0.0), somonhoc(0)
    {
    }
    // Constructor
    monhoc(string mamon, string tenmon, int sotinchi, double diem, int somonhoc)
    {
        // Sử dụng this-> để gán đúng các thuộc tính
        this->mamon = mamon;
        this->tenmon = tenmon;
        this->sotinchi = sotinchi;
        this->diem = diem;
        this->somonhoc = somonhoc;
    }

    friend istream &operator>>(istream &in, monhoc &mh)
    {
        cout << "Nhap ma mon: ";
        in >> mh.mamon;
        cout << "Nhap ten mon: ";
        in.ignore();
        getline(in, mh.tenmon);
        cout << "Nhap so tin chi: ";
        in >> mh.sotinchi;
        cout << "Nhap diem: ";
        in >> mh.diem;
        cout << "Nhap so mon hoc: ";
        in >> mh.somonhoc;
        return in;
    }
    friend ostream &operator<<(ostream &out, const monhoc &mh)
    {
        out << "Ma mon: " << mh.mamon << ", Ten mon: " << mh.tenmon
            << ", So tin chi: " << mh.sotinchi << ", Diem: " << mh.diem;
        return out;
    }
    float getdiem()
    {
        return this->diem;
    }

    int getsotinchi()
    {
        return this->sotinchi;
    }
};

class sinhvien
{
private:
    string masv;
    string hoten;
    string ngaysinh;
    vector<monhoc> monhoc_sv;

public:
    // Constructor
    sinhvien(string masv, string hoten, string ngaysinh, vector<monhoc> monhoc_sv)
    {
        this->masv = masv;
        this->hoten = hoten;
        this->ngaysinh = ngaysinh;
        this->monhoc_sv = monhoc_sv;
    }
    string getmasv()
    {
        return this->masv;
    }
    string gethoten()
    {
        return this->hoten;
    }
    string sethoten(string hoten)
    {
        return this->hoten = hoten;
    }
    string getngaysinh() const
    {
        return this->ngaysinh;
    }
    vector<monhoc> getmonhoc_sv()
    {
        return this->monhoc_sv;
    }
    friend istream &operator>>(istream &in, sinhvien &sv)
    {
        cout << "Nhap ma sinh vien: ";
        in >> sv.masv;
        cout << "Nhap ho ten: ";
        in.ignore();
        getline(in, sv.hoten);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        in >> sv.ngaysinh;
        cout << "Nhap thong tin mon hoc: " << endl;
        int i = 0;
        while (in >> sv.monhoc_sv[i])
        {
            i++;
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, sinhvien sv)
    {
        out << "Ma sinh vien: " << sv.getmasv() << "\n"
            << "Ho ten: " << sv.gethoten() << "\n"
            << "Ngay sinh: " << sv.getngaysinh() << "\n"
            << "Danh sach mon hoc: \n";
        for (auto &mh : sv.getmonhoc_sv())
        {
            out << mh << "\n";
        }
        return out;
    }
    bool sosanhten(sinhvien a, sinhvien b)
    {
        return a.hoten > b.hoten;
    }

    double diemTBMonHoc()
    {
        if (monhoc_sv.empty())
        {
            return 0.0;
        }

        double tongdiem = 0;
        int tongtinchi = 0;
        for (auto &mh : monhoc_sv)
        {
            tongdiem += mh.getdiem() * mh.getsotinchi();
            tongtinchi += mh.getsotinchi();
        }

        return tongdiem / tongtinchi;
    }

    bool checkDiemMonhoc()
    {
        for (auto &mh : monhoc_sv)
        {
            if (mh.getdiem() < 5)
            {
                return false;
            }
        }

        return true;
    }

    bool operator<(sinhvien other)
    {
        // Tách ngày, tháng, năm từ chuỗi ngaysinh
        int day1 = stoi(ngaysinh.substr(0, 2));
        int month1 = stoi(ngaysinh.substr(3, 2));
        int year1 = stoi(ngaysinh.substr(6, 4));

        int day2 = stoi(other.ngaysinh.substr(0, 2));
        int month2 = stoi(other.ngaysinh.substr(3, 2));
        int year2 = stoi(other.ngaysinh.substr(6, 4));

        // So sánh năm
        if (year1 != year2)
            return year1 < year2;

        // So sánh tháng
        if (month1 != month2)
            return month1 < month2;

        // So sánh ngày
        return day1 < day2;
    }
};

void suaTenSinhVien(vector<sinhvien> &danh_sach_sv, string ma_sv)
{
    bool timthay = false;

    for (auto &sv : danh_sach_sv)
    {
        if (sv.getmasv() == ma_sv)
        {
            cout << "Nhap ten moi cho sinh vien " << ma_sv << ": ";
            string ten_moi;
            // cin.ignore(); // Xóa ký tự newline còn sót
            getline(cin, ten_moi);
            sv.sethoten(ten_moi);
            cout << "ten duoc sua thanh " << ten_moi << endl;
            timthay = true;
            break;
        }
    }

    if (timthay == false)
    {
        cout << "khong tim thay sinh vien" << endl;
    }
}

void sapseptheohoten(vector<sinhvien> &danh_sach_sv)
{
    vector<sinhvien> dsv = danh_sach_sv;
    for (int i = 1; i < danh_sach_sv.size(); i++)
    {
        sinhvien key = dsv[i];
        int j = i - 1;
        while (j >= 0 && dsv[j].gethoten() < key.gethoten())
        {
            dsv[j + 1] = dsv[j];
            j--;
        }
        dsv[j + 1] = key;
    }
}

bool sosanhhoten(sinhvien a, sinhvien b)
{
    return a.gethoten() < b.gethoten();
}

void timkiemnhiphantheohoten(vector<sinhvien> &danh_sach_sv, string hoten)
{
    vector<sinhvien> dsv = danh_sach_sv;
    sort(dsv.begin(), dsv.end(), sosanhhoten);

    int left = 0;
    int right = dsv.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Tính chỉ số giữa

        // Kiểm tra nếu x nằm ở giữa
        if (dsv[mid].gethoten() == hoten)
        {
            dsv.erase(dsv.begin() + mid);
            return;
        }

        // Nếu x nhỏ hơn, bỏ qua nửa phải
        if (dsv[mid].gethoten() > hoten)
            right = mid - 1;
        // Nếu x lớn hơn, bỏ qua nửa trái
        else
            left = mid + 1;
    }

    // Nếu không tìm thấy
    return;
}

void sapsepdiemtrungbinh(vector<sinhvien> &danh_sach_sv)
{
    vector<sinhvien> dsv = danh_sach_sv;
    for (int i = 1; i < danh_sach_sv.size(); i++)
    {
        int min = i;

        for (int j = i + 1; j < danh_sach_sv.size(); j++)
        {
            if (dsv[j].diemTBMonHoc() < dsv[min].diemTBMonHoc())
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(dsv[min], dsv[i]);
        }
    }
}

void danhSachhocbong(vector<sinhvien> &danh_sach_sv)
{
    vector<sinhvien> dsv = danh_sach_sv;
    vector<sinhvien> dsvHocBong;
    for (int i = 0; i < danh_sach_sv.size(); i++)
    {
        if (dsv[i].diemTBMonHoc() >= 7.0 && dsv[i].checkDiemMonhoc())
        {
            dsvHocBong.push_back(dsv[i]);
        }
    }

    for (auto &sv : dsvHocBong)
    {
        cout << sv;
    }
}

void sapSepTheoNamSinh(vector<sinhvien> &danh_sach_sv, int l, int r)
{
    sinhvien p = danh_sach_sv[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (danh_sach_sv[i] < p)
        {
            i++;
        }

        while (!(danh_sach_sv[i] < p))
        {
            j--;
        }
        if (i <= j)
        {
            swap(danh_sach_sv[i], danh_sach_sv[j]);
            i++;
            j--;
        }
    }

    if (i < r)
    {
        sapSepTheoNamSinh(danh_sach_sv, i, r);
    }
    if (l < j)
    {
        sapSepTheoNamSinh(danh_sach_sv, l, j);
    }
}

int main()
{
    vector<sinhvien> danh_sach_sv;

    // sinhvien sv("4901", "hoang tan dung", "11/12/2005", {monhoc()});
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> danh_sach_sv[i];
    }
    // danh_sach_sv.push_back(sv);
    // suaTenSinhVien(danh_sach_sv, "4901");

    suaTenSinhVien(danh_sach_sv, "4901");
    sapseptheohoten(danh_sach_sv);
    timkiemnhiphantheohoten(danh_sach_sv, "dung");
    sapsepdiemtrungbinh(danh_sach_sv);
    danhSachhocbong(danh_sach_sv);
    sapSepTheoNamSinh(danh_sach_sv, 0, danh_sach_sv.size());
    return 0;
}