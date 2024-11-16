#include<iostream>
#include<array>
#include<string>

constexpr int DEFAULT_ID = 0;
constexpr int DEFAULT_AGE = 0;
constexpr int DEFAULT_OPTION = 0;
constexpr int DEFAULT_NUMBEROFITEMS = 0;
constexpr int MAX_RECORDS = 100;


int numberOfItems = DEFAULT_NUMBEROFITEMS;

class RecordItem
{

public:
    //Variables
    int ID = numberOfItems;
    std::string Name;
    int Age = DEFAULT_AGE;
    //Functions

};

std::array <RecordItem, MAX_RECORDS> RecordsArray;

void Add_Record(/*const std::array<RecordItem, MAX_RECORDS> &RecordsArray_Ref*/)
{
        
    std::cout << "Add User. Please Enter Username and Age\n";
    std::cout << "Name: ";
    std::cin >> RecordsArray[numberOfItems].Name;
    std::cout << "Age: ";
    std::cin >> RecordsArray[numberOfItems].Age;
    std::cout << "\n\nUser record added successfully.\n\n";
    numberOfItems++;
    RecordsArray[numberOfItems-1].ID = numberOfItems;

    std::cout << "Item ID: "<<RecordsArray[numberOfItems-1].ID;
    std::cout << "\nItem Name: "<<RecordsArray[numberOfItems-1].Name;
    std::cout << "\nItem Age: "<<RecordsArray[numberOfItems-1].Age;


    //ecordsArray[numberOfItems].ID++;
    

}
void Fetch_Record()
{
#ifdef DEBUG
        for(int i=0; i< numberOfItems; i++)
        {
            std::cout << "Item ID: "<<RecordsArray[i].ID;
            std::cout << "\nItem Name: "<<RecordsArray[i].Name;
            std::cout << "\nItem Age: "<<RecordsArray[i].Age <<"\n";
        }

#else
    int User_ID = DEFAULT_ID;
    
    std::cout << "numberOfItems: "<< numberOfItems <<"\n";

    std::cout << "Please Enter User ID: \n";
    std::cout << "User ID: ";
    std::cin >> User_ID;

    if(User_ID >= numberOfItems)
    {
        std::cout << "INVALID User ID\n";
    }
    else
    {
        for(int i=0; i< numberOfItems; i++)
        {
            if (RecordsArray[i].ID == User_ID)
            {
                std::cout << "User Name: " << RecordsArray[User_ID].Name;
                std::cout << "\nUser Age: " << RecordsArray[User_ID].Age << "\n\n";
                break;
            }
            else
            {
                continue;
            }
        }
    }
#endif
}



int main()
{

    bool IsRunning = true;
    int option = DEFAULT_OPTION;

    std::cout << "User SignUp Application\n";
    while(IsRunning)
    {
        std::cout << "Please select an option: \n";
        std::cout << "1. Add Record \n";
        std::cout << "2. Fetch Record \n";
        std::cout << "3. Quit \n\n";
        std::cout << "Enter option: ";

        std::cin >> option;

        switch (option)
        {
        case 1:
            if (numberOfItems < 100)
            {
                Add_Record();
            }
            else
            {

            }
            break;
        case 2:
            
            Fetch_Record();
            break;

        case 3:
            IsRunning = false;
            break;

        default:
            break;
        }
    }

}