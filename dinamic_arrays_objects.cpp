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
	printf("\tDINAMIC ARRAYS OF OBJECTS\n");
	int size;
	cout << "Number of student";
	cin >> size;
	Student* students = new Student[size];
	for (int i = 0; i < size; i++) {
		cout << "STUDENT " << i+1  << endl;

		Student s;
		cout << "Name: ";
		cin >> s.Name;
		cout << "Age: ";
		cin >> s.Age;
		cout << "Gtnder: ";
		cin >> s.Gender;
		cout << "Programming greid: ";
		cin >> s.Programming_greid;

		students[i] = s;
	}

	char choice;
	cout << "Do you want a bigger array?";//-> может тебе нужен массив побольше?
	cin >> choice;
	if (choice == 'n' || choice == 'N') {
		delete[] students;
		return 0;
	}

	int newSize;
	cout << "Enter newSize: ";
	cin >> newSize;
	/*
	  1.allocate newStudents array   //-> создать новый newStudents массив
	  2.copy elements from studens   //-> копировать элементы из students 
	  array into newStudents array   //-> массива в newStudents массмв
	  3.delete [] students           //-> удалить [] students
	  4.students should point to the //-> студенты должны указать на
	  same address as newStudents    //-> тот же адрес, что и у newStudents
	  (students = newStudents)
	*/

	// throw exceptions //-> прописать исключения
	Student* newStudents = new Student[newSize]; // 1...
	// 1. approach-option / первый подход - вариант функция memcpy()/ -> memcpy(newStudents, students, sizeof(Student) * size);// 2...
	for (int i = 0; i < size; i++) {// 2. manual copying / подход ручное копирование 
		newStudents[i] = students[i];//copy elements
	}
	delete [] students;
	students = newStudents;

	for (int i = size; i < newSize; i++) {
		cout << "STUDENT " << i + 1 << endl;

		Student s;
		cout << "Name: ";
		cin >> s.Name;
		cout << "Age: ";
		cin >> s.Age;
		cout << "Gtnder: ";
		cin >> s.Gender;
		cout << "Programming greid: ";
		cin >> s.Programming_greid;

		students[i] = s;
	}
	print_students(students, newSize);

	delete [] students;
   cin.get();
}

