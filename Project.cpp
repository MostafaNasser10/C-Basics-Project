/******************************************************
 * INCLUDES
*******************************************************/
#include <iostream>
#include <string>
#include <array>
#include <vector>

/******************************************************
 * MACROS
*******************************************************/
#define ID_NOT_FOUND 0
#define ID_FOUND     1

/******************************************************
 * CLASSES
*******************************************************/
class StudentInfo
{
public:
    std::string Name ;
    int Age ;
    int ID ;
};

enum class SelectOperation
{
    ADD_RECORD = 1,
    FETCH_RECORD,
    EXIT
};

/******************************************************
 * FUNCTIONS PROTOTYPES
*******************************************************/
void AddRecord(std::string &Name , int &Age );
void FetchRecord(int &ID);
std::istream& operator>>(std::istream& input , SelectOperation& result);

/******************************************************
 * GLOBAL VARIABLES
*******************************************************/
std::vector<StudentInfo> StudentVector ;

/******************************************************
 * APPLICATION
*******************************************************/
int main(void)
{
    std::string Name ;
    int Age , ID;
    SelectOperation Operation ;

    std::cout << "Select Operation \n";
    std::cout << "1- Add Student to Database \n";
    std::cout << "2- Fetch Student from Database \n";
    std::cout << "3- Exit \n";
    std::cin >> Operation; 

    while(Operation != SelectOperation::EXIT)
    {

        switch (Operation)
        {
            case SelectOperation::ADD_RECORD :
                std::cout << "_____________________________________________________\n\n";
              
                std::cout << "Enter Student Name :" ;
                getline(std::cin >> std::ws, Name);

                std::cout << "Enter Student Age :" ;
                std::cin >> Age ;

                std::cout << "_____________________________________________________\n\n";

                AddRecord( Name , Age );
            break;

            case SelectOperation::FETCH_RECORD :
                std::cout << "_____________________________________________________\n\n";

                std::cout << "Enter Student ID :" ;
                std::cin >> ID ;

                std::cout << "_____________________________________________________\n\n";

                FetchRecord(ID);
            break;
        
            default:
                std::cout << "Wrong Selection \n";
            break;
        }

        std::cout << "Select Operation \n";
        std::cout << "1- Add Student to Database \n";
        std::cout << "2- Fetch Student from Database \n";
        std::cout << "3- Exit \n";
        std::cin >> Operation; 

    }



}

/******************************************************
 * FUNCTIONS IMPLEMENTATION
*******************************************************/

/******************************************************/
/*Function Name: AddRecord                            */
/*Parameters: - &Name (Reference to Name)             */
/*            - &Age  (Reference to Age)              */
/*Return: Void                                        */
/******************************************************/
void AddRecord(std::string &Name , int &Age )
{
    StudentInfo TempInfo;

    TempInfo.Name = Name ;
    TempInfo.Age = Age ;
    TempInfo.ID = StudentVector.size();

    StudentVector.push_back(TempInfo);

    std::cout << "Student : " << StudentVector[StudentVector.size() - 1].Name << " ID: " << StudentVector.size() - 1 << " is Added successfully to the database\n" ;
    std::cout << "_____________________________________________________\n\n";
}

/******************************************************/
/*Function Name: FetchRecord                          */
/*Parameters: - &Age  (Reference to Age)              */
/*Return: Void                                        */
/******************************************************/
void FetchRecord(int &ID)
{
    int Flag = ID_NOT_FOUND ;

    for(int loop = 0 ; loop < StudentVector.size() ; loop++)
    {
        if(StudentVector[loop].ID == ID)
        {
            Flag = ID_FOUND ;
            std::cout << "Student Name : " << StudentVector[loop].Name << "\n";
            std::cout << "Student Ade : " << StudentVector[loop].Age << "\n";
            std::cout << "_____________________________________________________\n\n";
            break;
        }
    }

    if(Flag == ID_NOT_FOUND)
    {
        std::cout << "ID Not Found \n";
        std::cout << "_____________________________________________________\n\n";
    }
}

/******************************************************
 * OPERATOR OVERLOADING
*******************************************************/
std::istream& operator>>(std::istream& input , SelectOperation& result)
{
    int Option ;

    input >> Option ;
    result = static_cast<SelectOperation>(Option);

    return input;
}