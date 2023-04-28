#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define a Student class to store student information
class Student {
private:
    string name;
    int id;
    float gpa;
public:
    Student(string name, int id, float gpa) {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
    }
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    float getGpa() {
        return gpa;
    }
    void setName(string name) {
        this->name = name;
    }
    void setId(int id) {
        this->id = id;
    }
    void setGpa(float gpa) {
        this->gpa = gpa;
    }
};

// Define a University class to manage students
class University {
private:
    vector<Student> students;
public:
    void addStudent(Student student) {
        students.push_back(student);
    }
    void removeStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }
    void displayStudents() {
        cout << "List of Students:" << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << "Name: " << students[i].getName() << ", ID: " << students[i].getId() << ", GPA: " << students[i].getGpa() << endl;
        }
    }
};

// Main function to test the program
int main() {
    University uni;

    // Add some students
    uni.addStudent(Student("John Doe", 1001, 3.8));
    uni.addStudent(Student("Jane Smith", 1002, 3.9));
    uni.addStudent(Student("Bob Johnson", 1003, 3.7));

    // Display the list of students
    uni.displayStudents();

    // Remove a student by ID
    uni.removeStudent(1002);

    // Display the updated list of students
    uni.displayStudents();

    return 0;
}
