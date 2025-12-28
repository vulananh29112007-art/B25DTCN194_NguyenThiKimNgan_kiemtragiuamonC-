#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Lớp Employee
class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Hàm tạo có tham số
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    // Hàm tạo không tham số
    Employee() {
        id = 0;
        name = "";
        salary = 0;
    }

    // Nhập thông tin (mã được truyền từ ngoài)
    void input() {
        cout << "Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
        cin.ignore();
    }

    // Hiển thị thông tin
    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << fixed << setprecision(0) << salary << endl;
    }

    // Trả về mã nhân viên
    int getId() {
        return id;
    }

    // Set mã nhân viên
    void setId(int id) {
        this->id = id;
    }

    // Cập nhật lương
    void setSalary(float salary) {
        this->salary = salary;
    }
};

// Lớp EmployeeManager
class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    // Khởi tạo nextId = 3001
    EmployeeManager() {
        nextId = 3001;
    }

    // Thêm mới nhân viên
    void addEmployee() {
        Employee emp;
        emp.setId(nextId);  // Truyền mã từ ngoài
        emp.input();        // Nhập tên và lương
        list.push_back(emp);
        cout << "Da them nhan vien thanh cong! ID: " << nextId << endl;
        nextId++;
    }

    // Hiển thị danh sách nhân viên
    void showAll() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!" << endl;
            return;
        }
        cout << "\n----- DANH SACH NHAN VIEN -----" << endl;
        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
        cout << "-------------------------------\n" << endl;
    }

    // Cập nhật lương nhân viên
    void updateSalaryById() {
        int id;
        cout << "Nhap ma nhan vien can cap nhat: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                list[i].setSalary(newSalary);
                cout << "Da cap nhat luong thanh cong!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien co ID: " << id << endl;
        }
        cin.ignore();
    }

    // Xóa nhân viên theo id
    void deleteById() {
        int id;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "Da xoa nhan vien thanh cong!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien co ID: " << id << endl;
        }
        cin.ignore();
    }

    // Hiển thị menu chức năng
    void menu() {
        int choice;
        do {
            cout << "\n----- MENU -----" << endl;
            cout << "1. Them nhan vien" << endl;
            cout << "2. Hien thi danh sach" << endl;
            cout << "3. Cap nhat luong" << endl;
            cout << "4. Xoa nhan vien" << endl;
            cout << "5. Thoat" << endl;
            cout << "----------------" << endl;
            cout << "Lua chon cua ban: ";
            
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                continue;
            }

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
                    cout << "Cam on ban da su dung!" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                    break;
            }
        } while (choice != 5);
    }
};

// Hàm main
int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}

