/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/
#include <iostream>
using namespace std;
class Employee
{
    string empname;
    double salary;

public:
    Employee()
    {
        empname = "";
        salary = 0;
    }
    Employee(string n, double sal) : empname(n), salary(sal) {}
    double getsalary() { return salary; }
    string getname() { return empname; }
};
class Department
{
    string name;
    int noOfemp;
    Employee *employees;

public:
    Department()
    {
        name = "";
        noOfemp = 0;
        employees = nullptr;
    }
    Department(string name, Employee *arr, int noOfemp) : name(name), noOfemp(noOfemp)
    {
        employees = new Employee[noOfemp];
        for (int i = 0; i < noOfemp; i++)
        {
            employees[i] = arr[i];
        }
    }

    double HigestSalary()
    {
        double max = employees[0].getsalary();
        for (int i = 1; i < noOfemp; i++)
        {
            if (employees[i].getsalary() > max)
            {
                max = employees[i].getsalary();
            }
        }
        return max;
    }
    double AverageSalary()
    {
        double sum = 0.0;
        for (int i = 0; i < noOfemp; i++)
        {
            sum += employees[i].getsalary();
        }
        return (noOfemp > 0) ? sum / noOfemp : 0;
    }
    string getName() { return name; }
    ~Department()
    {
        delete[] employees;
    }
};
class University
{
    int noOfDepartment;
    Department **jagged;

public:
    University(int noOfDepart, Department *arr[])
    {
        noOfDepartment = noOfDepart;
        jagged = new Department *[noOfDepartment];
        for (int i = 0; i < noOfDepartment; i++)
        {
            jagged[i] = arr[i];
        }
    }
    void showHighestSalaries()
    {
        for (int i = 0; i < noOfDepartment; i++)
        {
            cout << "Highest salary in Department " << jagged[i]->getName() << " = " << jagged[i]->HigestSalary() << endl;
        }
    }
    // void setDepartment(int index,Department *d)
    // {
    //     jagged[index]=d;
    // }
    void showDeptWithMaxAverage()
    {
        double maxAvg = jagged[0]->AverageSalary();
        int index = 0;
        for (int i = 1; i < noOfDepartment; i++)
        {
            double avg = jagged[i]->AverageSalary();
            if (avg > maxAvg)
            {
                maxAvg = avg;
                index = i;
            }
        }
        cout << "Department with max average salary: " << jagged[index]->getName() << " (Average = " << maxAvg << ")" << endl;
    }
    ~University()
    {
        for (int i = 0; i < noOfDepartment; i++)
        {
            delete jagged[i];
        }
        delete[] jagged;
    }
};
int main()
{
    // --- Employees for Department 1 ---
    Employee dept1Emp[] = {
        Employee("Ali", 50000),
        Employee("Hasnain", 60000),
        Employee("Obaid", 55000)};
    Department *d1 = new Department("CS", dept1Emp, 3);

    // --- Employees for Department 2 ---
    Employee dept2Emp[] = {
        Employee("Ahmed", 70000),
        Employee("Ibrahim", 80000)};
    Department *d2 = new Department("IT", dept2Emp, 2);

    // --- Employees for Department 3 ---
    Employee dept3Emp[] = {
        Employee("Ahsan", 45000),
        Employee("Bilal", 40000),
        Employee("Zain", 47000),
        Employee("Saad", 46000)};
    Department *d3 = new Department("Finance", dept3Emp, 4);

    // --- Put departments into an array ---
    Department *arr[] = {d1, d2, d3};

    // --- Create University (Jagged Array of Departments) ---
    University uni(3, arr);

    // --- Show Results ---
    uni.showHighestSalaries();
    uni.showDeptWithMaxAverage();

    return 0;
}
