#include <string>
#include <iostream>
#include <fstream>
#ifndef Pharmacies_H
#define Pharmacies_H

class Pharmacies

{       public:
                Pharmacies(std::string pharm, std::string add, std::string cit, std::string stat, int z, double latitude, double longit);
                std::string getName();
                std::string getAdd();
                std::string getCity();
                std::string getState();
                int getZip();
                double getLat();
                double getLon();
        private:
                std::string name;
                std::string address;
                std::string city;
                std::string state;
                double lat;
                double lon;
                int zip;
};
#endif
