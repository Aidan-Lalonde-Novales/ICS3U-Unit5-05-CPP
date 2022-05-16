// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-05-15
// This program properly formats a canadian postal address with user input.

#include <iostream>
#include <cmath>
#include <algorithm>

std::string AddressFormat(
    std::string name, std::string streetNumber, std::string streetInfo,
    std::string city, std::string province, std::string postalCode,
    std::string apartmentNumber = ""
    ) {
    // this function formats a postal address
    std::string postalAddress;

    // process
    if (apartmentNumber != "") {
            postalAddress = name + "\n" + apartmentNumber + "-";
            postalAddress += streetNumber + " " + streetInfo + "\n" + city;
            postalAddress += " " + province + "  " + postalCode;
        } else {
            postalAddress = name + "\n";
            postalAddress += streetNumber + " " + streetInfo + "\n" + city;
            postalAddress += " " + province + "  " + postalCode;
        }

    // transforms to uppercase
    std::transform(
        postalAddress.begin(),
        postalAddress.end(),
        postalAddress.begin(),
        ::toupper);

    return postalAddress;
}


int main() {
    // this function gets input, calls a function, gives output

    std::string name;
    std::string askApartment;
    std::string apartmentNumber;
    std::string streetNumber;
    std::string streetInfo;
    std::string city;
    std::string province;
    std::string postalCode;
    int apartmentCheck;
    int streetCheck;
    std::string postalAddress;

    std::cout <<
    "This program formats a mailing address using your information."
    << std::endl;
    std::cout << "" << std::endl;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, askApartment);
    if (askApartment == "Y" || askApartment == "y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, apartmentNumber);
    }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name and type (ex. Main St): ";
    std::getline(std::cin, streetInfo);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province (abbreviated, ex. ON): ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code: ";
    std::getline(std::cin, postalCode);

    try {
        // will skip to exception if numbers are not integers
        if (apartmentNumber != "") {
            apartmentCheck = std::stoi(apartmentNumber);
        }
        streetCheck = std::stoi(streetNumber);

        // function calls
        if (apartmentNumber != "") {
            postalAddress = AddressFormat(name, streetNumber, streetInfo, city,
            province, postalCode, apartmentNumber);
        } else {
            postalAddress = AddressFormat(name, streetNumber, streetInfo, city,
            province, postalCode);
        }

        // output
        std::cout << "" << std::endl;
        std::cout << postalAddress;
    } catch (std::invalid_argument) {
        std::cout <<
        "\nYour information is invalid. "
        "Please verify it is accurate and resubmit.";
    }

    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
