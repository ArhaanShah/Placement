#include "functions.hpp"
#include "students.h"
#include "company.h"


#ifndef INTERVIEW_H
#define INTERVIEW_H


std::string stripWhitespace(const std::string& inputString);
std::string toLowercase(const std::string& inputString);
std::string fD(const std::string& inputString);

class Interview{
    
    private:
    std::string InterviewingCompany;
    std::string Interviewee;
    std::string DateOfInterview;   //(dd/mm/yyyy)
    std::string TimeOfInterview;   //(hh:mm)
    std::string Venue;
    std::string Status;  //Complete-Incomplete
    std::string PackageOffered;  //Package obtain if Hired
    std::string OfferAccepted;   //Yes-No

    std::string ColumnPath = "Database/PlacementManager/Interview/";

    public:
    Interview(const std::string& interviewingcompany, const std::string& interviewee, const std::string& date, const std::string& time, const std::string& venue, const std::string& status = "i", const std::string& package="0", const std::string& offeracceptedbystudent = "n")
        :InterviewingCompany(fD(interviewingcompany)), Interviewee(fD(interviewee)), DateOfInterview(fD(date)), TimeOfInterview(fD(time)), Venue(fD(venue)), Status(fD(status)), PackageOffered(fD(package)), OfferAccepted(fD(offeracceptedbystudent)) 
        {

            std::ofstream nameofinterviewingcompany;
            nameofinterviewingcompany.open(ColumnPath+"InterviewingCompany.txt", std::ios::app);
            if (nameofinterviewingcompany.is_open()){
                nameofinterviewingcompany << InterviewingCompany << std::endl;
                nameofinterviewingcompany.close();
            }

            std::ofstream nameofinterviewee;
            nameofinterviewee.open(ColumnPath+"Interviewee.txt", std::ios::app);
            if (nameofinterviewee.is_open()){
                nameofinterviewee << Interviewee << std::endl;
                nameofinterviewee.close();
            }

            std::ofstream dateoftheinterview;
            dateoftheinterview.open(ColumnPath+"DateOfInterview.txt", std::ios::app);
            if (dateoftheinterview.is_open()){
                dateoftheinterview << DateOfInterview << std::endl;
                dateoftheinterview.close();
            }

            std::ofstream timeoftheinterview;
            timeoftheinterview.open(ColumnPath+"TimeOfInterview.txt", std::ios::app);
            if (timeoftheinterview.is_open()){
                timeoftheinterview << TimeOfInterview << std::endl;
                timeoftheinterview.close();
            }

            std::ofstream venueoftheinterview;
            venueoftheinterview.open(ColumnPath+"Venue.txt", std::ios::app);
            if (venueoftheinterview.is_open()){
                venueoftheinterview << Venue << std::endl;
                venueoftheinterview.close();
            }

            std::ofstream statusoftheinterview;
            statusoftheinterview.open(ColumnPath+"Status.txt", std::ios::app);
            if (statusoftheinterview.is_open()){
                statusoftheinterview << Status << std::endl;
                statusoftheinterview.close();
            }
            
            std::ofstream packagereceivedifHired(ColumnPath+"PackageOffered.txt", std::ios::app);
            if (packagereceivedifHired.is_open()){
                packagereceivedifHired << PackageOffered << std::endl;
                packagereceivedifHired.close();
            }

            std::ofstream candidatehiredOrnot(ColumnPath+"OfferAccepted.txt", std::ios::app);
            if (candidatehiredOrnot.is_open()){
                candidatehiredOrnot << OfferAccepted << std::endl;
                candidatehiredOrnot.close();
            }

    }


};

#endif