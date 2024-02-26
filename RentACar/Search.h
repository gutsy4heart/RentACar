#pragma once
#include<iostream>
using namespace std;
void searchCarsByBrand(Car* cars, const char* user, int length) {
    for (int i = 0; i < length; i++) {
        if (_stricmp(user, cars[i].carBrand) == 0) {
            displayCarInfo(cars[i]);
        }
    }
}

void searchCarsByColor(Car* cars, const char* user, int length) {
    for (int i = 0; i < length; i++) {
        if (_stricmp(user, cars[i].color) == 0) {
            displayCarInfo(cars[i]);
        }
    }
}

void searchCarsByRegisterNumber(Car* cars, const char* user, int length) {
    for (int i = 0; i < length; i++) {
        if (_stricmp(user, cars[i].registrationNumber) == 0) {
            displayCarInfo(cars[i]);
        }
    }
}

void searchCarsByYearOfProduction(Car* cars, int user, int length) {
    int check = 0;
    for (int i = 0; i < length; i++) {
        if (user == cars[i].yearOfProduction) {
            displayCarInfo(cars[i]);
            check = 1;
        }
    }
}
void searchCarsByPriceRange(Car* cars, short start_range, short end_range, int length) {
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (cars[i].rentalPricePerDay >= start_range && cars[i].rentalPricePerDay <= end_range) {
            displayCarInfo(cars[i]);
            found = 1;
        }
    }

}

void searchContractsByTenant(Client* search_client, char* userName, char* userSurname, char* userMiddleName, int& length) {
    bool check = false;
    for (int i = 0; i < length; i++)
    {
        if (_stricmp(userName, search_client[i].name) == 0 &&
            _stricmp(userSurname, search_client[i].surname) == 0 &&
            _stricmp(userMiddleName, search_client[i].middleName) == 0)

        {
            displayClientInfo(search_client[i]);
            check = true;
        }

    }
}
void searchContractByClient(Contract* contract, Car* cars, char* userName, char* userSurname, char* userMiddleName, int& length) {
    bool found = false;
    for (int i = 0; i < length; i++)
    {
        if (_stricmp(userName, contract[i].name) == 0 &&
            _stricmp(userSurname, contract[i].surname) == 0 &&
            _stricmp(userMiddleName, contract[i].middleName) == 0)

        {
            displayContractInfo(cars[i], contract[i]);
            found = true;
        }
        if (!found) {
            cout << "Cannot find this contract!" << endl;
        }
    }
}