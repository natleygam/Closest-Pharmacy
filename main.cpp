/* -----------------------------------------------------------------------------
    *
    * File Name:  main.cpp
    * Author: Natalia Leyba
    *
    ---------------------------------------------------------------------------- */

#include <string>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include "Pharmacies.h"

int main()
{
    double longit, lat, distance;
    std::unordered_map<double, Pharmacies> allPharm;

    //Take in user input
    std::cout<< "Input your Latitude: ";
    std::cin>>lat;
    std::cout<< "Input your Longitude: ";
    std::cin>>longit;

    //Define and Open Pharmacies file
    std::ifstream inFile;
    std::string filename = "pharmacies.csv";
    inFile.open(filename);

    if(inFile.is_open()){
      std::string cols;
      for(int i=0;i<6;i++)
      {
        getline (inFile, cols, ',');
      }
      inFile >> cols;

      int latitude, longitude;
      std::string pharmacy, address, city, state, zipStr, latitudeStr, longitu;
      int zip, i=0;
      double myDs[30];

      //Read and store values from file
      while(!(inFile.eof()))
      {
        getline(inFile, pharmacy, ',');
        getline(inFile, address, ',');
        getline(inFile, city, ',');
        getline(inFile, state, ',');
        getline(inFile, zipStr, ',');
        getline(inFile, latitudeStr, ',');
        getline(inFile, longitu, '\n');

        latitude = stod(latitudeStr);
        zip = stoi(zipStr);
        longitude = stod(longitu);
        //get comparison between user location and pharmacy
        distance = fabs(latitude-lat) + fabs(longitude-longit);

        //store distances in array
        myDs[i] = distance;
        i++;
        //create and store in unordered_map each pharmacy
        Pharmacies myPharm(pharmacy, address, city, state, zip, latitude, longitude);
        allPharm.insert(std::make_pair(distance, myPharm));

      }

      //sort distance array
      std::sort(myDs,myDs+30);

      //Put information into a file
      std::ofstream Output;
      Output.open("output.txt");
      Pharmacies closest = (allPharm.find(myDs[0]))->second;
      Output<<"Closest Pharmacy: "<< closest.getName()<<'\n';
      Output<<"Located at: "<<closest.getAdd()<<", "<<closest.getCity()<<", "<<closest.getState()<<", "<<closest.getZip()<<'\n';
      double userlat, userlong, pharlat, pharlong, dLat, dLong, distance, l1;
      userlat = lat*(M_PI/180);
      userlong = longit*(M_PI/180);
      pharlat = closest.getLon()*(M_PI/180);
      pharlong = closest.getLat()*(M_PI/180);
      dLong = userlong - pharlong;
      dLat = userlat - pharlat;
      l1= pow(sin(dLat/2.0),2.0)+cos(userlat)*cos(pharlat)*pow(sin(dLong/2),2);
      distance=3963.19*2*atan2(sqrt(l1),sqrt(1.0-l1));
      Output<<distance<<" miles away.";
      std::cout<< "The information of the closest pharmacy has been outputed to output.txt"<<'\n';
    }

    return(0);
}
