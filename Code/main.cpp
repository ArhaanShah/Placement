//Modules 
#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include <unordered_set>
#include <cmath>
#include "functions.hpp"
#include "students.h"
#include "company.h"
#include "interview.h"

//Global Variables
#define STR_BOOL_TRUE "1"
#define STR_BOOL_FALSE "0"


// Function prototypes
void addNewStudent();
void deleteStudent(const std::string& studentID);
void addNewCompany();
void deleteCompany(const std::string& companyName);
void scheduleAnInterview();
void cancelAnInterview(const std::string& companyName, const std::string& intervieweeID);
// std::vector<int> findCommonElements(const std::vector<std::vector<int>>& vectors);
// void changeInterviewStatus(const std::string& companyName, const std::string& intervieweeID);
void resultAnInterview(const std::string& companyName, const std::string& intervieweeID);
void studentAcceptedOffer(const std::string& companyName, const std::string& intervieweeID);
int studentMenu();
int companyMenu();
int interviewMenu();
int mainMenu();
int analysePastDataMenu();
std::vector<int> filterPastInterviews();
void operationsOnFilteredInterviews(std::vector<int> filteredInterviews);

//Functions

//Gets index of the word in the file
int getIndexFromData(const std::string& filePath, const std::string& searchWord) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
                count++;
            if (line == fD(searchWord)) {
                return count;
            }
        }
    }
    return -1;
}

//Gets the word from the file at a particular index
std::string getDataFromIndex(const std::string& filePath, int index) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (count == index) {
                return line;
            }
        }
    }
    return "";
}

//Returns an array of index of all the strings that match the searchWord
std::vector<int> getIndicesVectorFromSearchWord(const std::string& filePath, const std::string& searchWord) {
    std::vector<int> result;
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (line == fD(searchWord)) {
                result.push_back(count);
            }
        }
    }
    return result;
}

//Returns an array of index of all the Student_IDs that match the year
std::vector<int> getIndicesVectorOfProgramFromStudentIDs(const std::string& searchWord) {
    std::vector<int> result;
    std::ifstream file("Database/PlacementManager/Interview/Interviewee.txt");
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (line.substr(4, 2) == fD(searchWord)) {
                result.push_back(count);
            }
        }
    }
    return result;
}

std::vector<int> getIndicesVectorOfAyearFromStudentIDs(const std::string& searchWord) {
    std::vector<int> result;
    std::ifstream file("Database/PlacementManager/Interview/Interviewee.txt");
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (line.substr(0, 4) == fD(searchWord)) {
                result.push_back(count);
            }
        }
    }
    return result;
}

//Changes the Data at a particular index in the file
void changeDataAtIndex(const std::string& filename, int index, const std::string& newLine) {
    std::ifstream inputFile(filename); 
    std::ofstream tempFile("temp.txt"); 

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (lineNumber == index) {
            if(newLine != "") {
            tempFile << fD(newLine) << std::endl;
            }
            else{
                 tempFile << fD(newLine);
            }
        } else {
            tempFile << line << std::endl;
        }
        
    }

    inputFile.close();
    tempFile.close();

    std::ofstream outputFile(filename, std::ios::out); 
    std::ifstream tempInputFile("temp.txt"); 
    std::string tempLine;
    while (std::getline(tempInputFile, tempLine)) {
        outputFile << tempLine << std::endl;
    }

    tempInputFile.close();
    outputFile.close();
    std::remove("temp.txt");

}

//Company functions
void addNewCompany() {
    std::string companyName, companyEmail, companyContact;
    std::cin.ignore();
    std::cout << "Enter company name: ";
    std::getline(std::cin, companyName);
    std::cout << "Enter company email: ";
    std::getline(std::cin, companyEmail);
    std::cout << "Enter company Contact Number: ";
    std::getline(std::cin, companyContact);
    Company (companyName, companyEmail, companyContact);
    std::cout << "Company Added Successfully!" << std::endl;
}

void deleteCompany(const std::string& companyName){
    int index = getIndexFromData("Database/PlacementManager/Company/CompanyName.txt", companyName);
    if(index == -1){
        std::cout << "No such company found!" << std::endl;
    }
    changeDataAtIndex("Database/PlacementManager/Company/CompanyName.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Company/CompanyEmail.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Company/CompanyContactNumber.txt", index, "");
    std::cout << "Company deleted successfully!" << std::endl;

}


//Student functions
void addNewStudent() {
    std::string studentID, fullName, email, program, contactNumber, alternateNumber, skypeID;
    std::cin.ignore();
    std::cout << "Enter student ID: ";
    std::getline(std::cin, studentID);
    std::cout << "Enter Fullname (Format: firstname lastname): ";
    std::getline(std::cin, fullName);
    std::cout << "Enter Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter Program (Format: B-Tech ICT): ";
    std::getline(std::cin, program);
    std::cout << "Enter Contact Number: ";
    std::getline(std::cin, contactNumber);
    std::cout << "Enter Alternate Number: ";
    std::getline(std::cin, alternateNumber);
    std::cout << "Enter Skype ID: ";
    std::getline(std::cin, skypeID);
    Student(studentID, fullName, email, program, contactNumber, alternateNumber, skypeID);
    std::cout << "Student Added Successfully!" << std::endl;
}

void deleteStudent(const std::string& studentID){
    int index = getIndexFromData("Database/PlacementManager/Student/Student_ID.txt", studentID);
    if(index == -1){
        std::cout << "No such student found!" << std::endl;
    }
    changeDataAtIndex("Database/PlacementManager/Student/Student_ID.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/FullName.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/Email.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/Program.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/ContactNumber.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/AlternateNumber.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/SkypeID.txt", index, "");

    std::cout << "Student deleted successfully!" << std::endl;


}

//Takes in vector of vectors and return a vector with all the common elemnents in all the vectors
std::vector<int> findCommonElements(const std::vector<std::vector<int>>& vectors) {
    std::vector<int> result;
    
    if (vectors.empty())
        return result; 

    std::unordered_set<int> commonElements(vectors[0].begin(), vectors[0].end());

    for (const auto& vec : vectors) {
        std::unordered_set<int> tempSet(vec.begin(), vec.end());
        std::unordered_set<int> newCommon;
        for (int num : commonElements) {
            if (tempSet.count(num) > 0) {
                newCommon.insert(num);
            }
        }
        commonElements = newCommon;
    }

    result.assign(commonElements.begin(), commonElements.end());
    return result;
}


int calculateMedianPackage(const std::vector<int>& indices) {
    std::vector<int> nums;
    for (int index : indices) {
        std::string line;
        line = getDataFromIndex("Database/PlacementManager/Interview/PackageOffered.txt", index);
        if (line != "nothired"){
            nums.push_back(std::stoi(line));
        } else {
            nums.push_back(0);
        }
       
    }

    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return static_cast<int>((nums[n/2 - 1] + nums[n/2]) / 2.0);
    } else {
        return nums[n/2];
    }
}

int calculateMeanPackage(const std::vector<int>& indices) {
    std::vector<int> nums;
    for (int index : indices) {
        std::string line;
        line = getDataFromIndex("Database/PlacementManager/Interview/PackageOffered.txt", index);
        if (line != "nothired"){
            nums.push_back(std::stoi(line));
        } else {
            nums.push_back(0);
        }
        
    }

    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return static_cast<int>(std::round(static_cast<double>(sum) / nums.size()));
}

void printInterviewDetails(const std::vector<int>& filteredInterviews){
    // std::vector<int> nums;
    for (int index : filteredInterviews) {

        std::string line1 = getDataFromIndex("Database/PlacementManager/Interview/InterviewingCompany.txt", index);
        std::string line2 = getDataFromIndex("Database/PlacementManager/Interview/Interviewee.txt", index);
        std::string line3 = getDataFromIndex("Database/PlacementManager/Interview/DateOfInterview.txt", index);
        std::string line4 = getDataFromIndex("Database/PlacementManager/Interview/TimeOfInterview.txt", index);
        std::string line5 = getDataFromIndex("Database/PlacementManager/Interview/Venue.txt", index);
        std::string line6 = getDataFromIndex("Database/PlacementManager/Interview/Status.txt", index);
        std::string line7 = getDataFromIndex("Database/PlacementManager/Interview/PackageOffered.txt", index);
        std::string line8 = getDataFromIndex("Database/PlacementManager/Interview/OfferAccepted.txt", index);
        std::cout << "Interviewing Company: " << line1 << std::endl;
        std::cout << "Interviewee: " << line2 << std::endl;
        std::cout << "Date Of Interview: " << line3 << std::endl;
        std::cout << "Time Of Interview: " << line4 << std::endl;
        std::cout << "Venue: " << line5 << std::endl;
        std::cout << "Status: " << line6 << std::endl;
        std::cout << "Package Offered: " << line7 << std::endl;
        std::cout << "Offered Accepted: " << line8 << std::endl;
        
    }
    
        

}






//Main Function
int main(){
    mainMenu();      
}


//Interview Functions
void scheduleAnInterview() {

    std::string companyName, intervieweeID, interviewDate, interviewTime, venue, status, packageoffered, offeraccepted;
    std::cin.ignore();
    std::cout << "Enter Interviewing Company Name: ";
    std::getline(std::cin, companyName);
    std::cout << "Enter Interviewee Student ID: ";
    std::getline(std::cin, intervieweeID);
    std::cout << "Enter Interview Date (Format: dd/mm/yyyy): ";
    std::getline(std::cin, interviewDate);
    std::cout << "Enter Interview Time (Format: hh:mm): ";
    std::getline(std::cin, interviewTime);
    std::cout << "Enter Interview Venue: ";
    std::getline(std::cin, venue);
    Interview(companyName, intervieweeID, interviewDate, interviewTime, venue);
    std::cout << "Interview Scheduled Successfully!" << std::endl;

}

int getTheIndexOfInterview(const std::string companyName,const std::string intervieweeID){
    std::vector<int> indicesOfCompanyName = getIndicesVectorFromSearchWord("Database/PlacementManager/Interview/InterviewingCompany.txt", companyName);
    std::vector<int> indicesOfIntervieweeID = getIndicesVectorFromSearchWord("Database/PlacementManager/Interview/Interviewee.txt", intervieweeID);
    for(int i=0; i<indicesOfCompanyName.size(); i++){
        for(int j=0; j<indicesOfIntervieweeID.size(); j++){
            if(indicesOfCompanyName[i] == indicesOfIntervieweeID[j]){
                return indicesOfCompanyName[i];
            }
        }
    }
    return -1;
}

void changeInterviewStatus(const std::string companyName, const std::string intervieweeID){
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    std::string status;
    std::cout << "Enter new status (C for completed/I for incomplete): ";
    std::getline(std::cin, status);
    changeDataAtIndex("Database/PlacementManager/Interview/Status.txt", index, fD(status));
    std::cout << "Status changed successfully!" << std::endl;
}

void cancelAnInterview(const std::string& companyName, const std::string& intervieweeID) {
    int index = getTheIndexOfInterview(companyName, intervieweeID);

    if (index == -1) {
        std::cout << "No such interview found!" << std::endl;
    } else {
        changeDataAtIndex("Database/PlacementManager/Interview/InterviewingCompany.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Interviewee.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/DateOfInterview.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/TimeOfInterview.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Venue.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Status.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/PackageOffered.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/OfferAccepted.txt", index, "");
    }
}

void resultAnInterview(const std::string& companyName, const std::string& intervieweeID) {
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    std::string hired, package;
    std::cout << "Is the candidate hired? (Y/N): ";
    std::getline(std::cin, hired);
    if (fD(hired) == "y") {
        std::cout << "Offer Package Amount (Format:XXXXXXXX): ";
        std::getline(std::cin, package);
        changeDataAtIndex("DataBase/PlacementManager/Interview/PackageOffered.txt", index, fD(package));
    } else {
        changeDataAtIndex("DataBase/PlacementManager/Interview/PackageOffered.txt", index, "notHired");
        changeDataAtIndex("DataBase/PlacementManager/Interview/OfferAccepted.txt", index, "notHired");
    }
    std::cout << "Interview Resulted Successfully!" << std::endl;
}

void studentAcceptedOffer(const std::string& companyName, const std::string& intervieweeID) {
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    changeDataAtIndex("Database/PlacementManager/Interview/OfferAccepted.txt", index, "y");
    std::cout << "Offer Marked Accepted Successfully!" << std::endl;
}


int mainMenu() {
    int mainMenuChoice;
    do {
        std::cout << "Welcome to DA-IICT Placement Management System!\n" << std::endl;
        std::cout << "---MAIN MENU---\n1. Student\n2. Company\n3. Interview\n4. Analyse Past Data\n5. Exit\nEnter number to select option: ";
        std::cin >> mainMenuChoice;

        switch(mainMenuChoice){
            case 1:
                studentMenu();
                break;
            case 2:
                companyMenu();
                break;
            case 3:
                interviewMenu();
                break;
            case 4:
                analysePastDataMenu();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid option! Please enter a number between 1-4." << std::endl;
        }
    } while(mainMenuChoice != 4);
    return 0;
}

int studentMenu() {
    int studentChoice;
    do {
        std::cout << "---STUDENT MENU---\n1. Add Student\n2. Delete Student\n3. Back to Main Menu\nEnter number to select option: ";
        std::cin >> studentChoice;
        
        switch(studentChoice){
            case 1:
                addNewStudent();
                break;
            case 2: {
                std::string studentID;
                std::cout << "Enter Student ID to Delete: ";
                std::cin >> studentID;
                deleteStudent(studentID);
                break;
            }
            case 3:
                mainMenu();
            default:
                std::cout << "Invalid option! Please enter a number between 1-3." << std::endl;
        }
    } while(studentChoice != 3);
    return 0;
}

int companyMenu() {
    int companyChoice;
    do {
        std::cout << "---COMPANY MENU---\n1. Add Company\n2. Delete Company\n3. Back to Main Menu\nEnter number to select option: ";
        std::cin >> companyChoice;
        
        switch(companyChoice){
            case 1:
                addNewCompany();
                break;
            case 2: {
                std::string companyName;
                std::cout << "Enter Company Name to Delete: ";
                std::cin >> companyName;
                deleteCompany(companyName);
                break;
            }
            case 3:
                break;
            default:
                std::cout << "Invalid option! Please enter a number between 1-3." << std::endl;
        }
    } while(companyChoice != 3); 
    return 0;
}

int interviewMenu() {
    int interviewChoice;
    do {
        std::cout << "---INTERVIEW MENU---\n1. Schedule Interview\n2. Cancel Interview\n3. Change Interview Status\n4. Result Interview\n5. Mark Offer Accepted\n6. Back to Main Menu\nEnter number to select option: ";
        std::cin >> interviewChoice;
        
        switch(interviewChoice){
            case 1:
                scheduleAnInterview();
                break;
            case 2: {
                std::string companyName, intervieweeID;
                std::cout << "Enter Company Name: ";
                std::cin >> companyName;
                std::cout << "Enter Interviewee ID: ";
                std::cin >> intervieweeID;
                cancelAnInterview(companyName, intervieweeID);
                break;
            }
            case 3: {
                std::string companyName, intervieweeID;
                std::cout << "Enter Company Name: ";
                std::cin >> companyName;
                std::cout << "Enter Interviewee ID: ";
                std::cin >> intervieweeID;
                changeInterviewStatus(companyName, intervieweeID);
                break;
            }
            case 4: {
                std::string companyName, intervieweeID;
                std::cout << "Enter Company Name: ";
                std::cin >> companyName;
                std::cout << "Enter Interviewee ID: ";
                std::cin >> intervieweeID;
                resultAnInterview(companyName, intervieweeID);
                break;
            }
            case 5: {
                std::string companyName, intervieweeID;
                std::cout << "Enter Company Name: ";
                std::cin >> companyName;
                std::cout << "Enter Interviewee ID: ";
                std::cin >> intervieweeID;
                studentAcceptedOffer(companyName, intervieweeID);
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Invalid option! Please enter a number between 1-6." << std::endl;
        }
    } while(interviewChoice != 6);
    return 0;
}

int analysePastDataMenu(){
    int analyseChoice;

  do{
    std::cout << "---ANALYSE PAST DATA MENU---\n1. Filter Past Interviews\n2. Back to Main Menu\nEnter number to select option: ";
      std::cin >> analyseChoice;
      switch(analyseChoice){
          case 1:
          {
              std::vector<int> filteredInterviews = filterPastInterviews();
              operationsOnFilteredInterviews(filteredInterviews);
              break;
          }
          case 2:
              break;
          default:
              std::cout << "Invalid option! Please enter a number between 1-2." << std::endl;
      }


    } while(analyseChoice != 2);
    return 0;
}

std::vector<int> filterPastInterviews() {
    // Declare variables
  std::string companyName, year, program;
  std::vector<std::vector<int>> filteredInterviews;

  // Prompt user for filters
  std::cin.ignore();
  std::cout << "Enter Company Name (leave blank to include all): ";
  std::getline(std::cin, companyName);
  /*--------ATTENTION--------*/
  //In this college your graduation year is in your student ID!!!! 202301001 is a student graduating in 2023.
  std::cout << "Enter Batch Year (leave blank to include all): ";
  std::getline(std::cin, year);
  std::cout << "Enter Program Number(01 for BTech ICT, 02 for BTech MnC, 03 for MTech Data Science) (leave blank to include all): ";
  std::getline(std::cin, program);
  if(companyName != ""){
    // Filter by company
    std::vector<int> filteredByCompany = getIndicesVectorFromSearchWord("Database/PlacementManager/Interview/InterviewingCompany.txt", companyName);
    filteredInterviews.push_back(filteredByCompany);
  }
  if(year != ""){
    // Filter by year
    std::vector<int> filteredByYear = getIndicesVectorOfAyearFromStudentIDs(year);
    filteredInterviews.push_back(filteredByYear);
  }
  if(program != ""){
    // Filter by program
    std::vector<int> filteredByProgram = getIndicesVectorOfProgramFromStudentIDs(program);
    filteredInterviews.push_back(filteredByProgram);
  }

  // Find intersection of all filters
  return findCommonElements(filteredInterviews);

}

void operationsOnFilteredInterviews(std::vector<int> filteredInterviews){
    // Menu to select operation
    int operationChoice;
    do{
    std::cout << "---OPERATIONS ON FILTERED INTERVIEWS---\n1. Print All Interview Details\n2. Median Package (All packages that were offered by companies)\n3. Mean Package(All packages that were offered by companies)\n4. Back to Past Menu\nEnter number to select option: ";
    std::cin >> operationChoice;
    switch(operationChoice){
        case 1:
            printInterviewDetails(filteredInterviews);
            break;
        case 2:     
            std::cout << "Median package of filtered interviews is: " << calculateMedianPackage(filteredInterviews) << std::endl;
            break;
        case 3:
            std::cout << "Mean package of filtered interviews is: " << calculateMeanPackage(filteredInterviews) << std::endl;
            break;
        case 4:
            break;
        default:
            std::cout << "Invalid option! Please enter a number between 1-4." << std::endl;
    
    } 
    }while (operationChoice != 4);
       
}
