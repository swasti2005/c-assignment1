#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double hourlyRate;
    double hoursWorked;
public:
    Employee(string name, double hourlyRate) : name(name), hourlyRate(hourlyRate), hoursWorked(0.0) {}

    void setHoursWorked(double hours) {
        hoursWorked = hours;
    }

    double calculateSalary() {
        return hourlyRate * hoursWorked;
    }

    string getName() {
        return name;
    }
};

class Payroll {
private:
    vector<Employee> employees;
public:
    void addEmployee(Employee emp) {
        employees.push_back(emp);
    }

    void enterHoursWorked(string name, double hours) {
        for (Employee& emp : employees) {
            if (emp.getName() == name) {
                emp.setHoursWorked(hours);
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void generatePayrollReport() {
        cout << "Payroll Report:" << endl;
        for (Employee& emp : employees) {
            cout << "Employee: " << emp.getName() << ", Salary: " << emp.calculateSalary() << endl;
        }
    }
};

int main() {
    Payroll payroll;

    // Adding employees
    payroll.addEmployee(Employee("aman", 15000.0));
    payroll.addEmployee(Employee("Anshu", 20000.0));
    payroll.addEmployee(Employee("ram", 18000.0));

    // Entering hours worked
    payroll.enterHoursWorked("aman", 9.0);
    payroll.enterHoursWorked("Anshu",8.0);
    payroll.enterHoursWorked("ram", 6.0);

    // Generating payroll report
    payroll.generatePayrollReport();

    return 0;
}
