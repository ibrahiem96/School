#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm>

using std::string;
using std::fstream; 
using std::vector; 
using std::stringstream; 
using std::getline; 
using std::sort; 
using std::cout; 
using std::cin;
using std::endl;

//
// Exam Score Analysis
//
// Ibrahiem Mohammad
// U. of Illinois, Chicago
// CS341, Spring 2016
// HW #1

class Student
{
public:
	string Name;
	int Midterm;
	int Final;

	Student(string name, int mid, int fnl)
	: Name(name), Midterm(mid), Final(fnl)
	{ }

	double ExamAvg()
	{
		return (Midterm + Final)/2.0;
	}

};

int main()
{
	fstream	file("exams.txt");
	string	line, name;
	int		mid, fnl;
	int 	option;

	//Step 1: input data into Vector

	vector<Student> students;

	while (getline(file, line)){
		stringstream ss(line);

		ss >> name;	//parse line
		ss >> mid;
		ss >> fnl;

		Student S(name, mid, fnl);

		students.push_back(S);
	}


	//Step 2: get sorting options from input

	while (1){
		cout << ("** Welcome to the Exam Analysis Program **") << endl << endl;
		cout << ("What type of analysis would you like?") << endl << 
		("\t1. By name") << endl <<
		("\t2. By exam average") << endl <<
		("\t3. By midterm") << endl <<
		("\t4. By final") << endl <<
		("(If you want to quit, enter 0)") << endl;
		
		cin >> option;
		
		if (option == 0) break;

		//Step 3: sort vector according to user input

		//#1 sort in ascending order ONLY by name
		if (option == 1){
			sort(students.begin(), students.end(), [](Student s1, Student s2)
			{
				//TODO: sort by name ascending -- may be faster way to do this
				if (s1.Name < s2.Name) return true;
				else return false;
			}
			);
		}

		//#2 sort in descending order & by ascending order name
		else if (option == 2){
			sort(students.begin(), students.end(), [](Student s1, Student s2)
			{
				//sort in descension
				if (s1.ExamAvg() > s2.ExamAvg()) return true;
				else if (s1.ExamAvg() < s2.ExamAvg()) return false;

				else	//sort by name (secondary search)
					if (s1.Name < s2.Name) return true;
					else return false;
			}

			);
		}

		//#3 sort by descending order by midterm & by descending final & by ascending name
		else if (option == 3){
			sort(students.begin(), students.end(), [](Student s1, Student s2)
			{
				if (s1.Midterm > s2.Midterm) return true;
				else if (s1.Midterm < s2.Midterm) return false;

				else if (s1.Final > s2.Final) return true;
				else if (s1.Final < s2.Final) return false;

				else 
					if (s1.Name < s2.Name) return true;
					else return false;
			}
			);
		}
		
		//#4 sort by descending order final & by descending order midterm & by ascending name
		else if (option == 4){
			sort(students.begin(), students.end(), [](Student s1, Student s2)
			{
				if (s1.Final > s2.Final) return true;
				else if (s1.Final < s2.Final) return false;

				else if (s1.Midterm > s2.Midterm) return true;
				else if (s1.Midterm < s2.Midterm) return false;

				else 
					if (s1.Name < s2.Name) return true;
					else return false;
			}
			);
		}

		else cout << ("Error: Invalid Option") << endl;


		//Step 4: output

		cout << std::fixed;
		cout << std::setprecision(2);

		if (option == 1 || option == 2) cout << ("Name\tExam Avg") << endl;
		else if (option == 3) cout << ("Name\tMidterm\tFinal") << endl;
		else if (option == 4) cout << ("Name\tFinal\tFinal") << endl;

		//TODO: need to fix output in looping so it only does it once
		//simple solution vs clean solution
		for (Student s : students){
			if (option == 1) cout << s.Name << ":\t" << s.ExamAvg() << endl;
			else if (option == 2) cout << s.Name << ":\t" << s.ExamAvg() << endl;
			else if (option == 3) cout << s.Name << ":\t" << s.Midterm << "\t" << s.Final << endl;
			else if (option == 4) cout << s.Name << ":\t" << s.Final << "\t" << s.Midterm << endl;
		}
	}

	return 0;

}