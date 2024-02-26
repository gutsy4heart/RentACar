#pragma once
#include<iostream>
using namespace std;
void displayCarInfo(Car& information) {
    cout << "Brand:\t\t" << information.carBrand << endl;
    cout << "Model:\t\t" << information.carModel << endl;
    cout << "Color:\t\t" << information.color << endl;
    cout << "Year:\t\t" << information.yearOfProduction << endl;
    cout << "Price:\t\t" << information.rentalPricePerDay << " $" << endl;
    cout << "Engine:\t\t" << information.engineCar << " L" << endl;
    cout << "Registration Number: " << information.registrationNumber << endl;
}
void displayClientInfo(Client& information) {
    cout << "Name:\t\t" << information.name << endl;
    cout << "Surname:\t" << information.surname << endl;
    cout << "Middle name:\t" << information.middleName << endl;
}
void displayContractInfo(Car& car, Contract& information) {
    cout << "Name:\t\t" << information.name << endl;
    cout << "Surname:\t" << information.surname << endl;
    cout << "Middle name:\t" << information.middleName << endl;
    cout << "Registration number of car: " << information.registrationNumber << endl;
    cout << "Days: " << information.rentDays << endl;
    cout << "From " << information.startDay << " to " << information.endDay << endl;
    cout << "Total price: " << information.totalRentalPrice << endl;
}