#include <iostream>

using namespace std;
class Student
{
public:
	string Name;
	int Age;
	char Gender;
	float Programming_greid;

};
void print_students(Student* students, int size) {
	for (int i = 0; i < size; i++) {
		cout << "STUDENT" << i + 1 << "\t";
		cout << students[i].Name << "\t";
		cout << students[i].Age << "\t";
		cout << students[i].Gender << "\t";
		cout << students[i].Programming_greid << "\n";
	}
}

int main()
{
	int size;
	cout << "Number of students";
	cin >> size;
	Student* students = new Student[size];
	for (int i = 0; i < size; i++) {
		cout << "STUDENT" << i+1 << endl;
		Student s;
		cout << "Name:"; 
		cin >> s.Name;
		cout << "Age:";
		cin >> s.Age;
		cout << "Gender:";
		cin >> s.Gender;
		cout << "Programming greid:";
		cin >> s.Programming_greid;
 
		students[i] = s;
	}

	print_students(students, size);

	delete[] students;
   cin.get();
}

