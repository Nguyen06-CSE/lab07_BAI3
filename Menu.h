
void XuatMenu();
int ChonMenu(int soMenu);
void XyLyMenu(int chon, chuoi s);
void ChayChuongTrinh();




void XuatMenu()
{
    cout << "_______________________MENU________________________\n"
        << "0. thoat khoi chuong trinh\n"
        << "1. nhap ten\n"
        << "2. dem so khoanh trang trong chuoi\n"
        << "3. tim vi tri xuat hien cua chuoi T trong chuoi S \n"
        << "4. tim vi tri xuat hien dau tien cua X trong chuoi s \n"
        << "5. dao vi tri cua tu dau va tu cuoi trong mang \n"
        << "6. doi ky tu dau thanh chu hoa con lai viet thuong \n"
        << "7. liet ke tung ky tu va so lan xuat hien cua no trong chuoi \n"
        << "8. dem so tu trong chuoi s \n"
        << "______________________________________________________\n";
}

int ChonMenu(int soMenu)
{
    int chon;
    do {
        cout << "nhap chon [0......" << soMenu << "] ";
        cin >> chon;
        if (chon >= 0 && chon <= soMenu) break;
    } while (true);
    return chon;
}

void XyLyMenu(int chon, chuoi s) {
    int kt;
    switch (chon) {
    case 0:
        cout << "thoat khoi chuong trinh\n";
        break;
    case 1:
        NhapChuoi(s);
        break;
    case 2:
        cout << "khoang trang trong chuoi " << s << " la: " << DemKhoangTrang(s) << endl;
        break;
    case 3:
        cout << "nhap chuoi t ban muon tim kiem trong chuoi s: ";
        chuoi t; 
        cin.ignore();
        gets_s(t, MAX);
        cout << "vi tri xuat hien cua chuoi " << t << " trong chuoi " << s << " la: " << ViTriXuatHien(s, t) << endl;
        break;
    case 4:
        cout << "nhap ki tu ban muon tim kiem trong chuoi s: ";
        char x; cin >> x;
        kt = TimVTXuatHien(s, x);
        if (kt != -1)    cout << "vi tri cua ki tu " << x << " trong chuoi " << s << " la: " << kt << endl;
        else    cout << "ky tu " << x << " ko co trong chuoi " << s << endl;
        break;
    case 5:
        //ham de khu cac gia tri trang
        XoaKyTuTrangDauCuoi(s);
        KhuKyTuTrang(s);
        //ham de dao tu 
        DaoTu(s);
        break;
    case 6:
        cout << "chuoi " << s << " se duoc viet hoa ky tu dau con lai duoc viet thuong la: \n";
        DoiKyTuDauHoa(s);
        cout << s;
        break;
    case 7:
        LietKe(s);
    default:
        break;
    }
    _getch();
}

void ChayChuongTrinh() {
    int soMenu = 8, chon;
    chuoi s;
    do {
        system("cls");
        XuatMenu();
        chon = ChonMenu(soMenu);
        XyLyMenu(chon, s);
    } while (chon != 0);
}