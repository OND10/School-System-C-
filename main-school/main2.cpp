#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
int id;
int con_line = 0;
int barz = 11;
int bar = 0;
int varX = 83;
using namespace std;
void display();
void stdudent_section();
void print_function();
void edit_function();
void teacher_function();
void about();
void print_teacher();
void Loading_function();

//
fstream file;

fstream zfile;
//
int countt = 0;
vector<string> name_student(100);
vector<string> sex(100);
vector<string> level(100);
string teacher_name[100];
string teacher_salary[100];
string teacher_subject[100];
string teacher_phone[100];
// bool del[2];
string input;
// int student_id[100], Fees[100], age[100];
vector<int> age(100);
vector<int> Fees(100);
vector<int> student_id(1);
int back = 0;
//
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorposition;
COORD Ipcursor;
void get_line(int a, int b, int c, int d, int e, int f, int x1, int x2)
{
	// hidecursor();
	// clearScreen();
	if (_kbhit())
	{
		switch (_getch())
		{
		case 77:
			if (varX == a)
				varX = b;
			else if (varX == b)
				varX = c;
			else if (varX == c)
				varX = d;
			else if (varX == d)
				varX = e;
			else if (varX == e)
				varX = f;
			else if (varX == f)
				varX = a;
			break;
		case 75:
			if (varX == f)
				varX = e;
			else if (varX == e)
				varX = d;
			else if (varX == d)
				varX = c;
			else if (varX == c)
				varX = b;
			else if (varX == b)
				varX = a;
			break;
		case 13:
			if (varX == a)
				bar = 82;
			else if (varX == b)
				bar = 92;
			else if (varX == c)
				bar = 102;
			else if (varX == d)
				bar = 4;
			else if (varX == e)
				bar = 5;
			else if (varX == f)
				bar = 6;
			break;
		case 8:
			if (varX == 83 || varX == 93 || varX == 103)
			{
				// studentF>>disply
				bar = 0;
				display();
			}
			else if (back == 1)
			{
				// edit_student>>stud
				varX = 83;
				bar = 0;
				stdudent_section();
			}
			else if (back == 2)
			{
				// teacher>>disply
				varX = 30;
				bar = 0;
				display();
			}
			else if (back == 3)
			{
				// editT>>teacher_function()
				varX = 30;
				bar = 0;
				teacher_function();
			}
			break;
		}
	}
	// the solution is to make a function for writing
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	for (int x = x1; x <= x2; x++)
	{

		if (x == varX)
		{

			cout << "=========";
		}
		else
		{
			cout << " ";
		}
	}
}
void get(int x, int y)
{
	cursorposition.X = x;
	cursorposition.Y = y;
	SetConsoleCursorPosition(console, cursorposition);
}
void clearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
	cout << "\n";
}
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
string sub_name[8] = {"Database", "Program", "Web", "Digtil Design", "Network", "math", "Basic of computer", "Total"};
struct subjects
{
	int sub_grade[8];
};
subjects sub_stu[10];
int main()
{
	fstream file;
	file.open("student.txt", ios::in | ios::out | ios::app);
	fstream zfile;
	zfile.open("zfile.txt", ios::in | ios::out | ios::app);

	char line[100];
	int count = 0;
	while (zfile.eof() == 0)
	{
		zfile.getline(line, sizeof(line));
		++count;
		// cout<<line<<endl;
	}
	con_line = count;
	for (int i = 1; i < con_line; i++)
	{
		file >> student_id[i] >> name_student[i] >> Fees[i] >> age[i] >> level[i] >> sex[i];
	}
	fstream tfile;
	tfile.open("tfile.txt", ios::in | ios::out | ios::app);
	fstream teacherN;
	teacherN.open("teacher_name.txt", ios::in | ios::out | ios::app);
	char lines[100];
	while (tfile.eof() == 0)
	{
		tfile.getline(lines, sizeof(lines));
		++countt;
	}
	for (int x = 1; x < countt; x++)
	{
		teacherN >> teacher_name[x] >> teacher_salary[x] >> teacher_phone[x] >> teacher_subject[x];
	}
	// teacher_function();
	// stdudent_section();
	display();
	// edit_function();
}

void display()
{
	system("cls");
	get(0, 3);
	while (true)
	{
		hidecursor();
		clearScreen();

		// get(42, 5);cout << "======================================\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		get(57, 11);
		cout << "Student";
		get(57, 13);
		cout << "Teachers";
		get(57, 15);
		cout << "Format";
		get(57, 17);
		cout << "About";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		for (int i = 9; i < 19; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			get(42, 8);
			cout << "====================================";
			get(41, i);
			cout << "|";
			get(79, i);
			cout << "|";
			get(42, 19);
			cout << "====================================";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case 80:
				if (barz == 11)
					barz = 13;
				else if (barz == 13)
					barz = 15;
				else if (barz == 15)
					barz = 17;
				else if (barz == 17)
					barz = 11;
				break;
			case 72:

				if (barz == 17)
					barz = 15;
				else if (barz == 15)
					barz = 13;
				else if (barz == 13)
					barz = 11;
				break;
			case 13:
				if (barz == 11)
				{
					varX = 83;
					Loading_function();
					stdudent_section();
				}
				else if (barz == 13)
				{
					bar = 0;
					varX = 30;
					Loading_function();
					teacher_function();
				}
				else if (barz == 15)
				{
					Loading_function();
					fstream teacherN;
					teacherN.open("teacher_name.txt", ios::in | ios::out | ios::trunc);
					fstream file;
					file.open("student.txt", ios::in | ios::out | ios::trunc);
					fstream zfile;
					zfile.open("zfile.txt", ios::in | ios::out | ios::trunc);
					fstream tfile;
					tfile.open("tfile.txt", ios::in | ios::out | ios::trunc);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					get(0, 20);
					cout << "All the files has deleted, please restart the programe \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					// main();
				}
				else if (barz == 17)
				{
					Loading_function();
					about();
				}
			}
		}
		for (int x = 11; x <= 17; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			if (x == barz)
			{
				get(53, barz);
				cout << "==>";
			}
			else
			{
				get(53, x);
				cout << "   ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
}
void stdudent_section()
{

	fstream file;
	file.open("student.txt", ios::in | ios::out | ios::app);
	fstream zfile;
	zfile.open("zfile.txt", ios::in | ios::out | ios::app);
	system("cls");
	print_function();
	while (true)
	{
		hidecursor();
		clearScreen();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		get(83, 2);
		get_line(83, 93, 103, 83, 83, 83, 0, 103);
		if (bar == 82)
		{
			while (true)
			{
				print_function();
				cout << "Enter the name of the student: " << con_line << "- ";
				// cin.ignore();
				getline(cin, input);
				// cin>>input;
				if (input >= "a" && input <= "z")
				{
					for (; con_line < 100;)
					{
						zfile << "1" << endl;
						student_id[con_line] = con_line;
						Fees[con_line] = 1250;
						// student_id[con_line] +=1;
						name_student[con_line] = input;
						sex[con_line] = "empty";
						level[con_line] = "empty";
						age[con_line] = 0;

						file << student_id[con_line] << endl;
						file << name_student[con_line] << endl;
						file << Fees[con_line] << endl;
						file << age[con_line] << endl;
						file << level[con_line] << endl;
						file << sex[con_line] << endl;
						con_line++;
						system("cls");
						break;
					}
				}
				else if (input == "/")
				{
					bar = 0;
					stdudent_section();
				}
			}
		}
		else if (bar == 92)
		{
			print_function();
			cout << "Enter the ID of the Student: ";
			cin >> id;
			edit_function();
			bar = 0;
			// if (id == 8)
			// bar = 0; stdudent_section();
		}
		else if (bar == 102)
		{
			bar = 0;
			display();
		}
	}
}
void print_function()
{
	// system("cls");
	hidecursor();
	clearScreen();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "    ---------------------------------------------------------------------------------------------------------------- \n";
	cout << "   |                                                                                                                 |";
	cout << "      ---------------------------------------------------------------------------------------------------------------- \n";
	if (bar == 82)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		get(85, 2);
		cout << "1-Add      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(95, 2);
		cout << "2-Edit     ";
		get(105, 2);
		cout << "3-Back    ";
		// bar = 0;
	}
	else if (bar == 92)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(85, 2);
		cout << "1-Add      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		get(95, 2);
		cout << "2-Edit    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(105, 2);
		cout << "3-Back     ";
		// bar = 0;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(85, 2);
		cout << "1-Add      ";
		get(95, 2);
		cout << "2-Edit     ";
		get(105, 2);
		cout << "3-Back    ";
		// bar = 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	get(0, 6);
	cout << "   __________________________________________________________________________________________________________________\n\n";

	cout << " \t\t"
		 << " ID"
		 << "  "
		 << "   Fees"
		 << " \t\t\t\t"
		 << "Name"
		 << " \n"
		 << endl;
	for (int i = 1; i < 100; i++)
	{
		if (name_student[i] >= "a" && name_student[i] <= "z")
		{
			cout << " \t\t ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << student_id[i];
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << Fees[i] << "$";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " \t\t\t\t";
			cout << name_student[i] << endl;
		}
	}
	cout << "\n";
}

void about()
{
	system("cls");
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t\t  ---------------------------------------------\n";
	cout << "\t\t\t\t\t |                                             |\n";
	cout << "\t\t\t\t\t |    This little programme has devloped by:   |\n";
	cout << "\t\t\t\t\t |                                             |\n";
	cout << "\t\t\t\t\t |      |-Moh'd Al-Sulami  |-Osama Damaj       |\n";
	cout << "\t\t\t\t\t |                                             |\n";
	cout << "\t\t\t\t\t |               @copyWrite 2022               |\n";
	cout << "\t\t\t\t\t |                                             |\n";
	cout << "\t\t\t\t\t |                                             |\n";
	cout << "\t\t\t\t\t  ---------------------------------------------\n";
	cout << "\t\t\t\t\t      -------------------------------------     \n";
	cout << "\t\t\t\t\t         -------------------------------        \n";
	cout << "\t\t\t\t\t                  ------------                  \n";
	cout << "\t\t\t\t\t                      ---                       \n";
	cout << "\t\t\t\t\t                       -                        \n";

	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 8:
				display();
			}
		}
	}
}
void edit_function()
{
	int w = 1;
	fstream file;
	file.open("student.txt", ios::in | ios::out);
	file.trunc;
	while (w < 100)
	{
		file << student_id[w] << endl;
		file << name_student[w] << endl;
		file << Fees[w] << endl;
		file << age[w] << endl;
		file << level[w] << endl;
		file << sex[w] << endl;
		w++;
	}
	bar = 0;
	back = 1;
	system("cls");
	// print_function();
	int m;
	string name, edit;
	// cout << "What are you want to edit?\n1-Name\t\t\t\t2-Age\t\t\t\t3-Sex\n4-Level \t\t\t\t5-Fees 6-Delete\n\n";
	cout << "\n\n\n\n\n";
	cout << "Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << name_student[id] << "\t\t\t\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Sex: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << sex[id] << endl
		 << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Age: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << age[id] << "\t\t\t\t\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Level: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << level[id];

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\t\t\t\t\t"
		 << "Fees: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << Fees[id] << "$" << endl
		 << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << "1-Name\t\t2-Sex\t\t3-Age\t\t4-Level\t\t5-Fees\t\t6-Delete";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	varX = 0;
	while (true)
	{
		clearScreen();
		hidecursor();
		get(0, 8);
		get_line(0, 14, 30, 47, 63, 80, 0, 300);
		if (bar != 0)
			break;
	}
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (bar == 102)
	{
		int ag;
		cout << "Enter the Age: ";
		cin >> ag;
		age[id] = ag;
	}
	else if (bar == 82)
	{
		// bar = 0;
		cout << "Enter the new name: ";
		cin >> name;
		cin.ignore();
		name_student[id] = name;
	}
	else if (bar == 92)
	{
		// bar = 0;
		string s;
		cout << "Enter the sex: ";
		cin >> s;
		sex[id] = s;
	}

	else if (bar == 4)
	{
		system("cls");
		cout << "Name: " << name_student[id] << endl
			 << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << sub_name[i] << " = " << sub_stu[id].sub_grade[i] << endl;
		}

		char conf;
		cout << "Do you want to change the degrees of the subjects y/n: ";
		cin >> conf;
		while (conf != 'n')
		{
			int total = 0;
			for (int i = 0; i < 7; i++)
			{
				cout << "\nEnter the grade of " << sub_name[i] << ": ";
				cin >> sub_stu[id].sub_grade[i];
				total += sub_stu[id].sub_grade[i];
			}
			sub_stu[id].sub_grade[7] = total;
			conf = 'n';
		}
	}
	else if (bar == 5)
	{
		cout << "Enter the number: ";
		cin >> m;
		Fees[id] = m;
	}
	else if (bar == 6)
	{
		bool replacing = false;
		for (int i = 1; i <= con_line; i++)
		{
			if (student_id[i] == id)
			{
				replacing = true;
				con_line--;
			}
			if (replacing == true)
			{
				student_id[i] = student_id[i];
				name_student[i] = name_student[i + 1];
			 	Fees[i] = Fees[i + 1];
				sex[i] = sex[i + 1];
				level[i] = level[i + 1];
				age[i] = age[i+1];
				//sub_stu[1].sub_grade[] = sub_stu[i].sub_grade[i+1];
			}

		}
	}
	edit_function();
}

void teacher_function()
{
	back = 2;
	bar = 0;
	system("cls");
	ofstream tfile;
	tfile.open("tfile.txt", ios::app);
	// system("cls");
	fstream teacherN;
	teacherN.open("teacher_name.txt", ios::in | ios::out | ios::app);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	get(30, 3);
	cout << "Add";
	get(60, 3);
	cout << "Edit";
	get(90, 3);
	cout << "Back";
	cout << "\n\n________________________________________________________________________________________________________________________\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	print_teacher();
	varX = 28;
	while (true)
	{

		clearScreen();
		hidecursor();
		get(0, 2);
		get_line(28, 58, 88, 28, 28, 28, 0, 91);
		if (bar != 0)
			break;
	}
	cout << "\n\n";
	if (bar == 82)
	{
		while (true)
		{
			system("cls");
			print_teacher();
			string press;
			cout << "presss any key to start writing or press / to quit: ";
			cin >> press;
			cout << "\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			if (press == "/")
			{
				bar = 0;
				teacher_function();
				break;
			}
			// else if (press == "print")
			// 	print_teacher();
			for (; countt <= 100;)
			{
				tfile << "1" << endl;
				cout << "Enter the name of teacher " << countt << "- ";
				cin >> teacher_name[countt];
				cout << "Enter the salary of teacher: ";
				cin >> teacher_salary[countt];
				cout << "Enter the phone of teacher: ";
				cin >> teacher_phone[countt];
				cout << "Enter the subject of teacher: ";
				cin >> teacher_subject[countt];
				teacherN << teacher_name[countt] << endl;
				teacherN << teacher_salary[countt] << endl;
				teacherN << teacher_phone[countt] << endl;
				teacherN << teacher_subject[countt] << endl;
				countt++;
				break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	else if (bar == 92)
	{
		back = 3;
		bar = 0;
		int id;
		system("cls");
		print_teacher();
		cout << "Enter the id: ";
		cin >> id;
		cout << "\n\t\t\tName\t\tPhone\t\tSalary\t\tSubject\n";
		varX = 22;
		while (true)
		{
			hidecursor();
			clearScreen();
			print_teacher();
			cout << "\n";
			get_line(22, 38, 54, 71, 22, 22, 0, 71);
			if (bar != 0)
				break;
		}
		fstream teacherN;
		teacherN.open("teacher_name.txt", ios::in | ios::out);
		string edit;
		if (bar == 82)
		{

			cout << "\nEnter the new name: ";
			cin >> edit;
			teacher_name[id] = edit;
			teacherN.trunc;
			for (int i = 0; i <= 100; i++)
			{
				if (teacher_name[i] >= "a" && teacher_name[i] <= "z")
				{
					teacherN << teacher_name[i] << endl;
					teacherN << teacher_salary[i] << endl;
					teacherN << teacher_phone[i] << endl;
					teacherN << teacher_subject[i] << endl;
				}
			}
		}
		else if (bar == 92)
		{
			cout << "\nEnter the new number phone: ";
			cin >> edit;
			teacher_phone[id] = edit;
			teacherN.trunc;
			for (int i = 0; i <= 100; i++)
			{
				if (teacher_name[i] >= "a" && teacher_name[i] <= "z")
				{
					teacherN << teacher_name[i] << endl;
					teacherN << teacher_salary[i] << endl;
					teacherN << teacher_phone[i] << endl;
					teacherN << teacher_subject[i] << endl;
				}
			}
		}
		else if (bar == 102)
		{
			cout << "\nEnter the new Salary: ";
			cin >> edit;
			teacher_salary[id] = edit;
			teacherN.trunc;
			for (int i = 0; i <= 100; i++)
			{
				if (teacher_name[i] >= "a" && teacher_name[i] <= "z")
				{
					teacherN << teacher_name[i] << endl;
					teacherN << teacher_salary[i] << endl;
					teacherN << teacher_phone[i] << endl;
					teacherN << teacher_subject[i] << endl;
				}
			}
		}
		else if (bar == 4)
		{
			cout << "\nEnter the new Subject: ";
			cin >> edit;
			teacher_subject[id] = edit;
			teacherN.trunc;
			for (int i = 0; i <= 100; i++)
			{
				if (teacher_name[i] >= "a" && teacher_name[i] <= "z")
				{
					teacherN << teacher_name[i] << endl;
					teacherN << teacher_salary[i] << endl;
					teacherN << teacher_phone[i] << endl;
					teacherN << teacher_subject[i] << endl;
				}
			}
		}
		system("cls");
		teacher_function();
		// Sleep(200000000);
	}
	else if (bar == 102)
	{
		bar = 0;
		display();
	}
}
void print_teacher()
{
	// system("cls");
	// cout<<"\n";
	if (bar == 82)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		get(30, 3);
		cout << "Add";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(60, 3);
		cout << "Edit";
		get(90, 3);
		cout << "Back";
		// bar = 0;
	}
	else if (bar == 92)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(30, 2);
		cout << "Add";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		get(60, 2);
		cout << "Edit";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(90, 2);
		cout << "Back";
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		get(30, 3);
		cout << "Add";
		get(60, 3);
		cout << "Edit";
		get(90, 3);
		cout << "Back";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	get(0, 5);
	cout << "________________________________________________________________________________________________________________________\n";
	get(24, 7);
	cout << "\t"
		 << "Id"
		 << "\t"
		 << "\t"
		 << "Name"
		 << "\t\t"
		 << "Salary"
		 << "\t\t"
		 << "Subject"
		 << "\t\t"
		 << "Phone" << endl
		 << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//
	for (int i = 0; i <= 100; i++)
	{
		if (teacher_name[i] >= "a" && teacher_name[i] <= "z")
		{
			cout << "\t\t\t\t" << i << "\t\t" << teacher_name[i] << "\t\t" << teacher_salary[i] << "$\t\t" << teacher_subject[i] << "\t\t" << teacher_phone[i] << endl;
		}
	}
}
void Loading_function()
{

	get(45, 20);
	cout << "Loading....";
	get(40, 22);
	for (int a = 0; a <= 40; a++)
	{

		cout << "!";
		Sleep(4);
	}
}
