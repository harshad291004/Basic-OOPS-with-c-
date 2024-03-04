#include <iostream>
using namespace std;
class EMPLOYEE {
private:
 int Employee_Number;
 string Employee_Name;
 float Basic, DA, IT, Net_Salary;
public:
 void readData() {
 cout << "Enter Employee Number: ";
 cin >> Employee_Number;
 cout << "Enter Employee Name: ";
 cin.ignore(); // Ignore the newline character left in the buffer

 getline(cin, Employee_Name);
 cout << "Enter Basic Salary: ";
 cin >> Basic;
 }
 void calculateNetSalary() {
 DA = 0.52 * Basic;
 float grossSalary = Basic + DA;
 IT = 0.3 * grossSalary;
 Net_Salary = Basic + DA - IT;
 }
 void printData() {
 cout << "Employee Number: " << Employee_Number << std::endl;
 cout << "Employee Name: " << Employee_Name << std::endl;
 cout << "Basic Salary: " << Basic << std::endl;
 cout << "Dearness Allowance (DA): " << DA << std::endl;
 cout << "Income Tax (IT): " << IT << std::endl;
 cout << "Net Salary: " << Net_Salary << std::endl << std::endl;
 }
};
int main() {
 int N;
 cout << "Enter the number of employees (N): ";
 cin >> N;
 
 EMPLOYEE* employees = new EMPLOYEE[N]; // Use dynamic memory allocation
 for (int i = 0; i < N; ++i) {
 cout << "\nEnter details for Employee " << i + 1 << ":\n";
 employees[i].readData();
 employees[i].calculateNetSalary();
 }
 cout << "\nEmployee Details:\n";
 for (int i = 0; i < N; ++i) {
 employees[i].printData();
 }
 delete[] employees;
 return 0;
}