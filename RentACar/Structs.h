#pragma once
#include<iostream>
using namespace std;
// structura mashini
struct Car
{
    char carBrand[20];
    char carModel[20];
    char color[15];
    char registrationNumber[15];
    int yearOfProduction{};
    double engineCar{};
    int rentalPricePerDay{};
};
// struktura klienta
struct Client
{
    char name[20];
    char surname[40];
    char middleName[10];
};
// struktura kontrakta
struct Contract {
    char name[20];
    char surname[40];
    char middleName[10];
    char registrationNumber[15];
    char carBrand[100];
    char carModel[100];
    short rentDays{};
    char startDay[10];
    char endDay[10];
    short totalRentalPrice{};
};