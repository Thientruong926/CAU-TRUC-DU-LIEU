#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sach
{
private:
    string masach;
    string tuasach;
    int namsuatban;
    double gia;

public:
    Sach()
    {
        masach = "";
        tuasach = "";
        namsuatban = 1991;
        gia = 0;
    }

    Sach(string masach, string tuasach, int namsuatban, double gia)
    {
        masach = masach;
        tuasach = tuasach;
        namsuatban = namsuatban;
        gia = gia;
    }
    // Getter và Setter cho masach
    string getMasach() const
    {
        return masach;
    }

    void setMasach(const string &ms)
    {
        this->masach = ms;
    }

    // Getter và Setter cho tuasach
    string getTuasach() const
    {
        return tuasach;
    }

    void setTuasach(const string &ts)
    {
        this->tuasach = ts;
    }

    // Getter và Setter cho namsuatban
    int getNamsuatban() const
    {
        return namsuatban;
    }

    void setNamsuatban(int nsb)
    {
        this->namsuatban = nsb;
    }

    // Getter và Setter cho gia
    double getGia() const
    {
        return gia;
    }

    void setGia(double g)
    {
        this->gia = g;
    }
    friend istream &operator>>(istream &is, Sach &s)
    {
        cout << "Nhập mã sách: ";
        is >> s.masach;
        cout << "Nhập tựa sách: ";
        is.ignore();
        getline(is, s.tuasach);
        cout << "Nhập năm xuất bản: ";
        is >> s.namsuatban;
        cout << "Nhập giá sách: ";
        is >> s.gia;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Sach &s)
    {
        os << "Mã sách: " << s.masach << endl;
        os << "Tựa sách: " << s.tuasach << endl;
        os << "Năm xuất bản: " << s.namsuatban << endl;
        os << "Giá sách: " << s.gia << endl;
        return os;
    }
};

void timvasuagiasach(vector<Sach> &danhsanhSach, string tuasach, double giasach)
{
    for (auto &val : danhsanhSach)
    {
        if (tuasach == val.getTuasach())
        {
            val.setGia(giasach);
            return;
        }
    }
}

bool ssmasach(Sach a, Sach b)
{
    return a.getMasach() < b.getMasach();
}
void timvasuaxoasach(vector<Sach> &danhsanhSach, string masach)
{
    sort(danhsanhSach.begin(), danhsanhSach.end(), ssmasach);

    int left = 0;
    int right = danhsanhSach.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Tính chỉ số giữa

        // Kiểm tra nếu x nằm ở giữa
        if (danhsanhSach[mid].getMasach() == masach)
        {
            danhsanhSach.erase(danhsanhSach.begin() + mid);
            return;
        }

        // Nếu x nhỏ hơn, bỏ qua nửa phải
        if (danhsanhSach[mid].getMasach() > masach)
            right = mid - 1;
        // Nếu x lớn hơn, bỏ qua nửa trái
        else
            left = mid + 1;
    }

    // Nếu không tìm thấy
    return;
}

void selectionsortmaSach(vector<Sach> &danhsanhSach)
{
    for (int i = 0; i < danhsanhSach.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < danhsanhSach.size(); i++)
        {
            if (danhsanhSach[j].getMasach() < danhsanhSach[min].getMasach())
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(danhsanhSach[i], danhsanhSach[min]);
        }
    }
}

void insertionsortnamxuatban(vector<Sach> &danhsanhSach)
{
    for (int i = 0; i < danhsanhSach.size(); i++)
    {
        Sach key = danhsanhSach[i];
        int j = i - 1;
        while (j >= 0 && key.getNamsuatban() > danhsanhSach[j].getNamsuatban())
        {
            danhsanhSach[j + 1] = danhsanhSach[j];
            j--;
        }
        danhsanhSach[j + 1] = key;
    }
}

void bubbleSorttuasach(vector<Sach> &danhsanhSach)
{
    bool swapped;
    for (int i = 0; i < danhsanhSach.size() - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < danhsanhSach.size() - i - 1; j++)
        {
            if (danhsanhSach[j].getTuasach() > danhsanhSach[j + 1].getTuasach())
            {
                swap(danhsanhSach[j], danhsanhSach[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

void quicksortgiaSach(vector<Sach> &danhsanhSach, int left, int right)
{
    double x;
    int i, j;
    if (left > right)
        return;
    x = danhsanhSach[(left + right) / 2].getGia();

    i = left, j = right;
    while (i < j)
    {
        while (danhsanhSach[i].getGia() > x)
            i++;
        while (danhsanhSach[i].getGia() < x)
            j--;

        if (i <= j)
        {
            swap(danhsanhSach[i], danhsanhSach[j]);
            i++, j--;
        }
    }

    quicksortgiaSach(danhsanhSach, left, j);
    quicksortgiaSach(danhsanhSach, i, right);
}
int main()
{
    int n;
    cin >> n;
    vector<Sach> danhsachsach(n);

    for (int i = 0; i < n; i++)
    {
        cin >> danhsachsach[i];
    }

    timvasuagiasach(danhsachsach, "toan roi rac", 10000);
    timvasuaxoasach(danhsachsach, "001");
    selectionsortmaSach(danhsachsach);
    insertionsortnamxuatban(danhsachsach);
    bubbleSorttuasach(danhsachsach);
    quicksortgiaSach(danhsachsach, 0, danhsachsach.size() - 1);

    return 0;
}