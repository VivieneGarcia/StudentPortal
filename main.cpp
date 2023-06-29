#include <iostream>
#include <limits>
using namespace std;

struct Node
{
    string NAME;
    int SRCODE;
    string SUBJ;
    string PROF;
    string SCHED;
    Node* next;
};

class StudentPortal
{
private:
	
    Node* head = nullptr;
    Node* tail = nullptr;

public:
	
    void addStudent()
    {
        Node* newNode = new Node;

        cout << endl << "+---------------------+" << endl;
        cout << "| Input Student Info" << "  |"
            << endl << "+---------------------+" << endl;
        cout << "Enter Name: ";
        cin >> newNode->NAME;

        bool sr_dupe;

        do
        {
            cout << "Enter SR-CODE: ";
            cin >> newNode->SRCODE;

            while (cin.fail())
            {
                cout << "// Invalid SR-CODE. Input an integer //";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                cout << endl;
                cout << "Enter SR-CODE: ";
                cin >> newNode->SRCODE;
            }

            Node* current = head;
            sr_dupe = false;

            while (current != nullptr)
            {
                if (current->SRCODE == newNode->SRCODE)
                {
                    sr_dupe = true;
                    cout << "// SR-CODE is already taken. Choose another one //" << endl;
                    break;
                }
                current = current->next;
            }

        } while (sr_dupe);

        cout << "Enter Subject Code: ";
        cin >> newNode->SUBJ;

        cout << "Enter Professor: ";
        cin >> newNode->PROF;

        cout << "Enter Schedule: ";
        cin >> newNode->SCHED;

        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void searchStudent(int srcode)
    {
        Node* current = head;
        bool found = false;

        while (current != nullptr)
        {
            if (current->SRCODE == srcode)
            {
                system("CLS");
                cout << endl << "+---------------+" << endl;
                cout << "| Student Info " << " |" << endl << "+---------------+" << endl;
                cout << "Name: " << current->NAME << endl;
                cout << "SR-Code: " << current->SRCODE << endl;
                cout << "Subject Code: " << current->SUBJ << endl;
                cout << "Professor: " << current->PROF << endl;
                cout << "Schedule: " << current->SCHED << endl;

                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << endl << "// No Student found!//" << endl;
        }
    }

    void deleteStudent(int srcode)
    {
        Node* current = head;
        Node* prev = nullptr;

        if (current->SRCODE == srcode)
        {
            head = head->next;
            delete current;
            cout << endl << "// Deleted successfully //" << endl;
            return;
        }

        while (current != nullptr && current->SRCODE != srcode)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << endl << "// No Student found! // " << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << endl << "// Deleted successfully //" << endl;
    }

    void printAllStudents()
    {
        system("CLS");
        cout << endl << "| All Student Information |" << endl;

        Node* current = head;
        while (current != nullptr)
        {
            cout << endl << "+---------------+" << endl;
            cout << "| Student " << current->SRCODE << endl;
            cout << "+---------------+" << endl;
            cout << "Name: " << current->NAME << endl;
            cout << "SR-CODE: " << current->SRCODE << endl;
            cout << "Subject Code: " << current->SUBJ << endl;
            cout << "Professor: " << current->PROF << endl;
            cout << "Schedule: " << current->SCHED << endl;

            current = current->next;
        }
    }

    void run()
    {
        int number_of_student;

        cout << "+================+" << endl;
        cout << "| STUDENT PORTAL |" << endl;
        cout << "+================+" << endl << endl;

        while (true)
        {
            cout << "Input No. of Students: ";
            cin >> number_of_student;

            if (cin.fail())
            {
                cout << "// Invalid Input //" << endl;
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            else 
			{
                break;
            }
        }

        for (int i = 0; i < number_of_student; i++)
        {
            addStudent();
        }

        char choice;

        do
        {
            cout << endl;
            menu();
            cin >> choice;

            while (choice != 'P' && choice != 'S' && choice != 'Q' && choice != 'p' && choice != 's' && choice != 'q' && choice != 'A' && choice != 'a' && choice != 'D' && choice != 'd')
            {
                cout << endl << endl;

                cout << "// Invalid Input //"<< endl;
                menu();
                cin >> choice;
            }

            if (choice == 'S' || choice == 's')
            {
                int find;
                system("CLS");
                cout << endl << "+----Searching Student----+" << endl;
                cout << endl << "Type SR-CODE: ";
                cin >> find;

                while (cin.fail())
                {
                    cout << endl << " // Invalid SR-CODE //";
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                    cout << endl << endl;
                    cout << "Type SR-CODE: ";
                    cin >> find;
                }

                searchStudent(find);
            }

            else if (choice == 'P' || choice == 'p')
            {
                printAllStudents();
            }

            else if (choice == 'A' || choice == 'a')
            {
            	system("CLS");
                cout << endl << "+----Adding Student----+" << endl;
                addStudent();
                cout << endl << "// Added successfully //"<< endl;
            }

            else if (choice == 'D' || choice == 'd')
            {
                int find;
                system("CLS");
                cout << endl << "+----Deleting Student----+" << endl;

                cout << endl << "Type SR-CODE: ";
                cin >> find;

                while (cin.fail())
                {
                    cout << endl << " // Invalid SR-CODE //";
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                    cout << endl << endl;
                    cout << "Type SR-CODE: ";
                    cin >> find;
                }

                deleteStudent(find);
            }

        } while (choice != 'Q' && choice != 'q');
		
        cout << endl << "Thank you!" << endl;
    }

    void menu()
    {
        cout << "+---------------------------------------------------+" << endl;
        cout << " [S]earch | [P]rint All | [A]dd | [D]elete | [Q]uit " << endl;
        cout << "+---------------------------------------------------+" << endl;
        cout << "Choice: ";
    }
};

int main()
{
    StudentPortal portal;
    portal.run();

    return 0;
}
