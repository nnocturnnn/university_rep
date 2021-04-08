#include <iostream>
#include <time.h> 
#include <malloc.h>


using namespace std;

void print_matrix(int** m) {

    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        for (int j = 0; j < _msize(m) / sizeof(int); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int** create_matrix(int size, int percent) {

    int** mat = new int* [size];
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        mat[i] = new int[size];

        for (int j = 0; j < size; ++j) {
            if ((rand() % 100) < percent) {
                mat[i][j] = 1;
            }
            else {
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

void swap(int*& m, int m1, int m2) {
    if ((m1 < _msize(m) / sizeof(int)) && (m2 < _msize(m) / sizeof(int))) {
        int temp = m[m1];
        m[m1] = m[m2];
        m[m2] = temp;
    }
}

void row_swap(int**& m, int i1, int i2) {

    if ((i1 < _msize(m) / sizeof(int)) && (i2 < _msize(m) / sizeof(int))) {
        int* temp = m[i1];
        m[i1] = m[i2];
        m[i2] = temp;
    }
}
void col_swap(int**& m, int j1, int j2) {

    if ((j1 < _msize(m) / sizeof(int)) && (j2 < _msize(m) / sizeof(int))) {
        for (int i = 0; i < _msize(m) / sizeof(int); i++) {
            int temp = m[i][j1];
            m[i][j1] = m[i][j2];
            m[i][j2] = temp;
        }
    }
}

int min_row(int**& m, int from) {

    int min = INT_MAX;
    int row = 0;
    for (int i = from; i < _msize(m) / sizeof(int); i++) {
        int temp = 0;
        for (int j = from; j < _msize(m) / sizeof(int); j++) {
            if (m[i][j] == 1)
                temp++;
        }
        if (temp <= min) {
            min = temp;
            row = i;
        }
    }
    return row;
}

int max_col(int**& m, int from) {

    int max = INT_MIN;
    int col = 0;
    for (int i = from; i < _msize(m) / sizeof(int); i++) {
        if (m[from][i] == 1) {
            int temp = 0;
            for (int j = from; j < _msize(m) / sizeof(int); j++) {
                if (m[j][i] == 1)
                    temp++;
            }
            if (temp >= max) {
                max = temp;
                col = i;
            }
        }
    }

    return col;
}

void replace(int**& m) {
    int* row = new int[_msize(m) / sizeof(int)];
    int* col = new int[_msize(m) / sizeof(int)];


    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        row[i] = i + 1;
        col[i] = i + 1;
    }

    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        int r = min_row(m, i);
        swap(row, i, r);
        row_swap(m, i, r);
        int c = max_col(m, i);
        swap(col, i, c);
        col_swap(m, i, c);
    }
    cout << "  ";
    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        cout << row[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        cout << col[i] << " ";
        for (int j = 0; j < _msize(m) / sizeof(int); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
void replace_w(int**& m) {


    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        row_swap(m, i, min_row(m, i));
        col_swap(m, i, max_col(m, i));
    }

}


bool check_conflicts(int**& m, int r, int c) {
    bool conflicts = false;

    for (int j = c + 1; j < _msize(m) / sizeof(int); j++) {
        if (r < j) {
            if (m[j][r] == 1) {
                conflicts = true;
                m[j][r] = 0;
            }
        }
    }

    return conflicts;
}
void find_zm(int**& m) {
    int best = 0;
    int temp;
    bool conflicts = false;
    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        temp = i;
        for (int j = i; j < _msize(m) / sizeof(int); j++) {
            if (m[i][j] == 1) {
                temp = j;
            }
        }
        if (temp > best) {
            best = temp;
        }

        if (conflicts == false) {
            conflicts = check_conflicts(m, i, best);
        }
        else
            check_conflicts(m, i, best);
    }

    if (conflicts) {
        cout << "Matrix has conflicts!\n";

    }
    else  cout << "Matrix does not have conflicts!\n";

}


bool find_zms(int**& m) {
    int best = 0;
    int temp;

    for (int i = 0; i < _msize(m) / sizeof(int); i++) {
        temp = i;
        for (int j = i; j < _msize(m) / sizeof(int); j++) {
            if (m[i][j] == 1) {
                temp = j;
            }
        }
        if (temp > best) {
            best = temp;
        }

        if (check_conflicts(m, i, best)) return true;
    }
    return false;
}


void testing() {
    int size;
    cin >> size;
    double d;
    for (int n = 0; n < 100; n++) {
        d = 0;
        for (int i = 0; i < 100; i++) {
            int** mat = create_matrix(size, n);
            replace_w(mat);
            if (find_zms(mat))
                d++;
        }
        cout << n << "% - " << d / 100 << "\n";

    }
    cout << endl;
};

int main()
{
    testing();
    system("pause");

}