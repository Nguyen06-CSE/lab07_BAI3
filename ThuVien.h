#define MAX 1000

typedef char chuoi[MAX];

void NhapChuoi(chuoi s);
void XoaKyTuTrangDauCuoi(chuoi s);
void KhuKyTuTrang(chuoi s);
int DemKhoangTrang(chuoi s);
int ViTriXuatHien(chuoi s, chuoi t);
int TimVTXuatHien(chuoi s, char x);
void DaoTu(chuoi s);
void DoiKyTuDauHoa(chuoi s);
void LietKe(chuoi s);





void NhapChuoi(chuoi s)
{
    cin.ignore();
    gets_s(s, MAX);
}

void HoanVi(char& a, char& b) {
    char tmp = a;
    a = b;
    b = tmp;
}

void XoaKyTuTrangDauCuoi(chuoi s)
{
    int i = 0;
    while (s[i] == ' ') {
        ++i;
    }
    int j = 0;
    while (s[i] != '\0') {
        s[j++] = s[i++];
    }
    s[j] = '\0';   
    j--;  
    while (s[j] == ' ') {
        --j;
    }
    s[j + 1] = '\0';
}

void KhuKyTuTrang(chuoi s)
{
    int i = 0; 
    while (s[i] != NULL) {
        int j = i + 1;
        if (s[i] == ' ' && s[j] == ' '){
            while (s[j] != NULL) {
                s[j] = s[j + 1];
                ++j;
            }
        }
        else    ++i;
    }
}

int DemKhoangTrang(chuoi s)
{
    int i = 0, dem = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') ++dem;
        ++i;
    }
    return dem;
}

int ViTriXuatHien(chuoi s, chuoi t)
{
    int vt = -1, i = 0, j = 0, dem = 0;
    while (t[j] != '\0') {
        ++dem;
        ++j;
    }
    j = 0;
    while (s[i] != '\0') {
        if (s[i] == t[j]) {
            ++j;
            vt = i;
        }
        ++i;
    }
    if (vt != -1) {
        return vt - dem;
    }
    return vt ;
}

int TimVTXuatHien(chuoi s, char x) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == x)   return i;
        ++i;
    }
    return -1;
}

void DaoTu(chuoi s) {
    chuoi tmp;
    int i = 0, j = 0;

    while (s[i] != '\0') {
        ++i;
    }
    int length = i;  

    i = length - 1;   

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        int cuoi = i;

        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        int dau = i + 1;

        for (int k = dau; k <= cuoi; ++k) {
            tmp[j++] = s[k];
        }

        if (i >= 0) {
            tmp[j++] = ' ';
        }
    }

    tmp[j] = '\0';  

    cout << tmp;
}

void DoiKyTuDauHoa(chuoi s)
{
    if (s[0] >= 'a' && s[0] <= 'z')  s[0] -= 32;
    int i = 1;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z')  s[i] += 32;
        ++i;
    }
}

void LietKe(chuoi s) {
    int i = 0;
    bool counted[MAX] = { false };  
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
        ++i;
    }
    i = 0;
    while (s[i] != '\0') {
        if (!counted[i] && s[i] != ' ') {  
            int dem = 1;
            int j = i + 1;

            while (s[j] != '\0') {
                if (s[i] == s[j]) {
                    ++dem;
                    counted[j] = true;  
                }
                ++j;
            }
            cout << s[i] << " xuat hien " << dem << " lan" << endl;
        }
        ++i;
    }
}
