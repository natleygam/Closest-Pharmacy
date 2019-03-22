#include "Pharmacies.h"
#include <iostream>
#include <string>
#include <fstream>

Pharmacies::Pharmacies(std::string pharm, std::string add, std::string cit, std::string stat, int z, double latitude, double longit)
{
  name = pharm;
  address = add;
  city = cit;
  state = stat;
  zip = z;
  lat = latitude;
  lon = longit;
}


std::string Pharmacies::getName()
{
	return(name);
}

std::string Pharmacies::getCity()
{
    return(city);
}

std::string Pharmacies::getAdd()
{
    return(address);
}

double Pharmacies::getLat()
{
    return(lat);
}

double Pharmacies::getLon()
{
    return(lon);
}

std::string Pharmacies::getState()
{
    return(state);
}

int Pharmacies::getZip()
{
    return(zip);
}
