#include "functions.hpp"
#include <fstream>
#include <string>


#ifndef COMPANY_H
#define COMPANY_H




class Company {
    

    private:

    std::string CompanyName;
    std::string CompanyEmail;
    std::string CompanyContactNumber;

    std::string ColumnPath = "Database/PlacementManager/Company/";

    public:

    //constructor
    Company(const std::string& companyname, const std::string& companyemail, const std::string& companycontactnumber)
        :CompanyName(fD(companyname)), CompanyEmail(fD(companyemail)), CompanyContactNumber(fD(companycontactnumber)) {
            
            std::ofstream constructorcompanyname(ColumnPath+"CompanyName.txt", std::ios::app);
            if (constructorcompanyname.is_open()){
                constructorcompanyname << fD(CompanyName) << std::endl;
                constructorcompanyname.close();
            }
            std::ofstream constructorcompanyemail(ColumnPath+"CompanyEmail.txt", std::ios::app);
            if (constructorcompanyemail.is_open()){
                constructorcompanyemail << CompanyEmail << std::endl;
                constructorcompanyemail.close();
            }
            std::ofstream constructorcompanycontactnumber(ColumnPath+"CompanyContactNumber.txt", std::ios::app);
            if (constructorcompanycontactnumber.is_open()){
                constructorcompanycontactnumber << CompanyContactNumber << std::endl;
                constructorcompanycontactnumber.close();
            }

    }

    // std::string getCompanyName() const {
    //     return CompanyName;
    // }
};

#endif