#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee(int empId, string empName, float empSalary) 
        : id(empId), name(empName), salary(empSalary) {}

    Employee() : id(0), name(""), salary(0.0f) {}

    // Nhap ten và luong
    void input() {
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);
        cout << "Nhap luong nhan vien: ";
        cin >> salary;
        cin.ignore(); // Xoa ky tu newline
    }

    // Hien thi thong tin theo yeu cau
    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }

    int getId() {
        return id;
    }

    void setSalary(float newSalary) {
        salary = newSalary;
    }

    void setId(int empId) {
        id = empId;
    }
};

class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    EmployeeManager() : nextId(3001) {}

    void addEmployee() {
        Employee newEmp;
        newEmp.setId(nextId);
        newEmp.input();
        list.push_back(newEmp);
        nextId++;
        cout << "Them nhan vien thanh cong!" << endl;
    }

    void showAll() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!" << endl;
        } else {
            cout << "----- DANH SACH NHAN VIEN -----" << endl;
            for (size_t i = 0; i < list.size(); ++i) {
                list[i].printInfo();
            }
            cout << "-------------------------------" << endl;
        }
    }

    void updateSalaryById() {
        int searchId;
        cout << "Nhap ma nhan vien can cap nhat: ";
        cin >> searchId;
        cin.ignore();

        bool found = false;
        for (size_t i = 0; i < list.size(); ++i) {
            if (list[i].getId() == searchId) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                cin.ignore();
                list[i].setSalary(newSalary);
                cout << "Cap nhat luong thanh cong!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien voi ma: " << searchId << endl;
        }
    }

    void deleteById() {
        int searchId;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> searchId;
        cin.ignore();

        bool found = false;
        for (size_t i = 0; i < list.size(); ++i) {
            if (list[i].getId() == searchId) {
                list.erase(list.begin() + i);
                cout << "Xoa nhan vien thanh cong!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien voi ma: " << searchId << endl;
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n=====MENU=====" << endl;
            cout << "1. Them nhan vien" << endl;
            cout << "2. Hien thi danh sach" << endl;
            cout << "3. Cap nhat luong" << endl;
            cout << "4. Xoa nhan vien" << endl;
            cout << "5. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    showAll();
                    break;
                case 3:
                    updateSalaryById();
                    break;
                case 4:
                    deleteById();
                    break;
                case 5:
                    cout << "Thoat chuong trinh." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                    break;
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}
