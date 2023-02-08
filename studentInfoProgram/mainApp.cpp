#include "./modules/Funcs.h"
#include <fstream>
#include <string>

// main implementation
int main(int argc, char const *argv[])
{
    int marks[100];
    // Student students[100];
    Student *head = NULL;
    Student *newNode = NULL;
    Student *temp = NULL;
    Student *prev = NULL;
    Student *next = NULL;
    Student *current = NULL;
    Student *last = NULL;
    Student *sorted = NULL;
    Student *s = NULL;
    Student st1;

    // get student info from user
    cout << "Enter Student name: ";
    getline(cin, st1.name);
    cout << "Enter Student age: ";
    cin >> st1.age;
    while (st1.age > 30 || st1.age < 10)
    {
        cout << "Invalid age. Enter again (10-30): ";
        cin >> st1.age;
    }

    cout << "Enter Student roll number: ";
    cin >> st1.rollNumber;
    while (st1.rollNumber < 0)
    {
        cout << "Invalid roll number. Enter a Postive Number: ";
        cin >> st1.rollNumber;
    }

    cout << "Enter Student marks: ";
    cin >> st1.marks;
    while (st1.marks > 50 || st1.marks < 0)
    {
        cout << "Invalid marks. Enter again (<50): ";
        cin >> st1.marks;
    }

    ofstream file;
    file.open("./db/studInfo.txt", ios::app);
    file << st1.name << endl;
    file << st1.age << endl;
    file << st1.rollNumber << endl;
    file << st1.marks << endl;
    file.close();

    ifstream studFile;
    int count = 0;
    int i = 0;
    int sti = 0;
    studFile.open("./db/studInfo.txt");
    string line;

    // copy marks to marks array and student students array from a file
    while (getline(studFile, line))
    {
        // copy student to linked list
        if (count == 0)
        {
            newNode = new Student;
            newNode->name = line;
        }
        else if (count == 1)
        {
            newNode->age = stoi(line);
        }
        else if (count == 2)
        {
            newNode->rollNumber = stoi(line);
        }
        else if (count == 3)
        {
            newNode->marks = stof(line);
            count = -1;
            push(&head, newNode);
        }
        count++;
    }

    // // sort students linked list according to marks
    sorted = mergeSortHigh(head);

    cout << endl
         << "Students Info after Sorting according to marks: \n"
         << endl;
    s = sorted;

    while (s != NULL)
    {
        printStudent(s);
        s = s->next;
    }

    return 0;
}
