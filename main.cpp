#include<iostream>
#include<string>
using namespace std;

class AbstractEmployee {
public:
	virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:

	string Company;
	int Age;
protected:
	string Name;
public:
	// a constructor is a method that has no return type 
	// a constructor has the same name as the class that it belongs to 
	// constructor are usually public

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	void Behavior() {
		cout << "Hello, My name is " << this->Name <<
			" and I am working in Company " << Company <<
			" and I am of age " << Age;
		cout << endl;
	}

	void set_name(string name) {
		Name = name;
	}
	void set_company(string company) {
		Company = company;
	}

	void set_age(int age) {
		Age = age;
	}

	string get_company() {
		return Company;
	}
	string get_name() {
		return Name;
	}
	int get_age() {
		return Age;
	}

	void AskForPromotion() {
		if (Age > 20) {
			cout << Name << " got promoted." << endl;
		}
		else {
			cout << Name << ", sorry no promotion for you." << endl;
		}
	}

	virtual void Work() {
		cout << Name << " is checking email, task backlog , ..... " << endl;
	}
};

class Developer : public Employee {
public:
	string Language;
	Developer(string name, string company, int age, string language) : Employee(name, company, age) {
		Language = language;
	}

	void FixBug() {
		cout << Name << " fixed bug using " << Language << endl;
	}
	void Work() {
		cout << Name << " is writing code in " << Language << endl;
	}

	void AskForPromotion() {
		cout << "tina mina pina pani khau" << endl;
	}
};

class Teacher: public Employee {
public:
	string Subject;
	Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
		Subject = subject;
	}
	void PrepareLesson() {
	
		cout << Name << " is preparing " << Subject << " lesson " << endl;
		cout << endl;
	}

	void Work() {
		cout << Name << " is teaching " << Subject << endl;
	}
};


int main() {
	// play with main function to uncover core OOP properties like encapsulation(easy), abstraction, inheritence, and polymorphism
	Developer d = Developer("Saldina","YT Code Beauty",22,"C++");
	Teacher t = Teacher("Anurodh", "Prasadi Academy", 17, "Computer");
	t.PrepareLesson();
	t.AskForPromotion();

	d.Work();
	t.Work();
	Employee* e1 = &d;
	Employee* e2 = &t;

	e1->Work();
	e2->Work();
	e1->AskForPromotion();
	return 0;
}

// inheritances are private by default so we cannot access methods outside class
// polymorphism means many forms of a method
// virtual means base's functions will be overloaded if there exists a same function in derived class