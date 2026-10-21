#include <iostream>
using namespace std;

const int MAX = 100;

void display(int a[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? ", " : "");
    cout << "]\n";
}

void maxMin(int a[], int n) {
    int mx = a[0], mn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }
    cout << "Maximum: " << mx << "\nMinimum: " << mn << "\n";
}

double average(int a[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return sum / n;
}

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

void insertMark(int a[], int &n, int pos, int val) {
    if (n == MAX || pos < 0 || pos > n) { cout << "Cannot insert.\n"; return; }
    for (int i = n - 1; i >= pos; i--) a[i + 1] = a[i];   // shift right
    a[pos] = val;
    n++;
}

void deleteMark(int a[], int &n, int pos) {
    if (pos < 0 || pos >= n) { cout << "Invalid position.\n"; return; }
    for (int i = pos; i < n - 1; i++) a[i] = a[i + 1];    // shift left
    n--;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
}

int countAboveAvg(int a[], int n) {
    double avg = average(a, n);
    int c = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > avg) c++;
    return c;
}

int main() {
    int a[MAX] = {78, 45, 92, 66, 81};
    int n = 5, ch, x, p;

    do {
        cout << "\n1.Display 2.Max/Min 3.Average 4.Search 5.Insert 6.Delete "
                "7.Sort 8.Above average 9.Enter/replace marks 0.Exit\nChoice: ";
        if (!(cin >> ch)) {
            cerr << "Invalid input.\n";
            return 1;
        }
        switch (ch) {
            case 1: display(a, n); break;
            case 2:
                if (n == 0) cout << "Enter marks first.\n";
                else maxMin(a, n);
                break;
            case 3:
                if (n == 0) cout << "Enter marks first.\n";
                else cout << "Average: " << average(a, n) << "\n";
                break;
            case 4:
                cout << "Mark to search: ";
                if (!(cin >> x)) {
                    cerr << "Invalid input.\n";
                    return 1;
                }
                p = linearSearch(a, n, x);
                if (p >= 0) cout << "Found at index " << p << "\n";
                else cout << "Not found\n";
                break;
            case 5:
                cout << "Position and mark: ";
                if (!(cin >> p >> x)) {
                    cerr << "Invalid input.\n";
                    return 1;
                }
                insertMark(a, n, p, x); display(a, n);
                break;
            case 6:
                cout << "Position: ";
                if (!(cin >> p)) {
                    cerr << "Invalid input.\n";
                    return 1;
                }
                deleteMark(a, n, p); display(a, n);
                break;
            case 7: bubbleSort(a, n); display(a, n); break;
            case 8:
                if (n == 0) cout << "Enter marks first.\n";
                else cout << "Above average: " << countAboveAvg(a, n) << "\n";
                break;
            case 9: {
                int count;
                cout << "Number of students (0-" << MAX << "): ";
                if (!(cin >> count)) {
                    cerr << "Invalid input.\n";
                    return 1;
                }
                if (count < 0 || count > MAX) {
                    cout << "Number of students must be between 0 and " << MAX << ".\n";
                    break;
                }

                int marks[MAX];
                cout << "Enter marks: ";
                for (int i = 0; i < count; i++) {
                    if (!(cin >> marks[i])) {
                        cerr << "Invalid input.\n";
                        return 1;
                    }
                }
                for (int i = 0; i < count; i++) a[i] = marks[i];
                n = count;
                break;
            }
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 0);
    return 0;
}