#ifndef STUDENT_H
#define STUDENT_H


//Modules
#include "functions.hpp"
#include <string>
#include <fstream>



std::string stripWhitespace(const std::string& inputString);
std::string toLowercase(const std::string& inputString);
std::string fD(const std::string& inputString);

class Student {

private:

    //Private Student Variables
    std::string Student_ID;
    std::string FullName;
    std::string Email;
    std::string Program;
    std::string ContactNumber;
    std::string AlternateNumber;
    std::string SkypeID;

    //Resoures for database
    std::string ColumnPath="Database/PlacementManager/Student/";
    

public:

    //Constructor
        Student(const std::string& studentID, const std::string& fullName, const std::string& email,
            const std::string& program, const std::string& contactNumber, const std::string& alternateNumber, const std::string& skypeID)
        : Student_ID(fD(studentID)), FullName(fD(fullName)), Email(fD(email)), Program(fD(program)),
          ContactNumber(fD(contactNumber)), AlternateNumber(fD(alternateNumber)), SkypeID(fD(skypeID)) {

            std::ofstream studentid(ColumnPath+"Student_ID.txt", std::ios::app);
            if (studentid.is_open()){
                studentid << Student_ID << std::endl;
                studentid.close();
            }

            std::ofstream fullname(ColumnPath+"FullName.txt", std::ios::app);
            if (fullname.is_open()){
                fullname << FullName << std::endl;
                fullname.close();
            }

            std::ofstream studentemail(ColumnPath+"Email.txt", std::ios::app);
            if (studentemail.is_open()){
                studentemail << Email << std::endl;
                studentemail.close();
            }

            std::ofstream studentprogram(ColumnPath+"Program.txt", std::ios::app);
            if (studentprogram.is_open()){
                studentprogram << Program << std::endl;
                studentprogram.close();
            }

            std::ofstream contactnumber(ColumnPath+"ContactNumber.txt", std::ios::app);
            if (contactnumber.is_open()){
                contactnumber << ContactNumber << std::endl;
                contactnumber.close();
            }

            std::ofstream alternatenumber(ColumnPath+"AlternateNumber.txt", std::ios::app);
            if (alternatenumber.is_open()){
                alternatenumber << AlternateNumber << std::endl;
                alternatenumber.close();
            }

            std::ofstream skypeid(ColumnPath+"SkypeID.txt", std::ios::app);
            if (skypeid.is_open()){
                skypeid << SkypeID << std::endl;
                skypeid.close();
            }
    }   

};

#endif 
