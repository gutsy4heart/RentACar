#pragma once
#include<iostream>
using namespace std;

short currentDebt(Contract* contracts, Client* clients, Car* cars, int lengthContracts, int lengthClients, int lengthCars, char* nameClient, char* surnameClient, char* middleNameClient, short currentDay);
Car* addCar(Car* cars, int& length) {
    Car* newCars = createCarArray(length + 1);
    if (newCars) {
        cout << "Enter the car brand: ";
        cin >> newCars[length].carBrand;
        cout << "Enter the car model: ";
        cin >> newCars[length].carModel;
        cout << "Enter the car color: ";
        cin >> newCars[length].color;
        cout << "Enter the car year: ";
        cin >> newCars[length].yearOfProduction;
        cout << "Enter the car price: ";
        cin >> newCars[length].rentalPricePerDay;
        cout << "Enter the car registration number: ";
        cin >> newCars[length].registrationNumber;
        cout << "Enter the car engine: ";
        cin >> newCars[length].engineCar;

        for (int i = 0; i < length; i++) {
            newCars[i] = cars[i];
        }

        length++;
        delete[] cars;

        cout << "Your car has been added successfully!" << endl;
        return newCars;
    }
    return cars;
}

Client* addClient(Client* clients, int& length) {
    Client* tmp = createClientArray(length + 1);
    if (tmp) {
        Client newClient;
        cout << "Enter the client name: ";
        cin >> newClient.name;
        cout << "Enter the client surname: ";
        cin >> newClient.surname;
        cout << "Enter the client middle name: ";
        cin >> newClient.middleName;
        for (int i = 0; i < length; i++) {
            tmp[i] = clients[i];
        }
        tmp[length] = newClient;
        length++;
        delete[] clients;
        return tmp;
    }
    else {
        cout << "The maximum number of entries has been reached. Cannot add more clients." << endl;
        return clients;
    }
}

Contract* addContract(Contract* contracts, Car* cars, Client* clients, int& lengthContracts, int lengthCars, int lengthClients) {
    if (lengthClients == 0) {
        cout << "No clients available. Please add clients first." << endl;
        return contracts;
    }

    if (lengthCars == 0) {
        cout << "No cars available. Please add cars first." << endl;
        return contracts;
    }

    cout << "Clients:" << endl;
    for (int i = 0; i < lengthClients; i++) {
        cout << "Client " << (i + 1) << ":" << endl;
        cout << "Name: " << clients[i].name << endl;
        cout << "Surname: " << clients[i].surname << endl;
        cout << "Middle name: " << clients[i].middleName << endl;
        cout << "--------------------------" << endl;
    }

    int clientChoice;
    cout << "Enter the number of the client to add to the contract: ";
    cin >> clientChoice;

    if (clientChoice < 1 || clientChoice > lengthClients) {
        cout << "Invalid choice. No contract added." << endl;
        return contracts;
    }

    cout << "Cars:" << endl;
    for (int i = 0; i < lengthCars; i++) {
        cout << "Car " << (i + 1) << ":" << endl;
        cout << "Brand: " << cars[i].carBrand << endl;
        cout << "Model: " << cars[i].carModel << endl;
        cout << "Registration Number: " << cars[i].registrationNumber << endl;
        cout << "Rental price per day: " << cars[i].rentalPricePerDay << " $" << endl;
        cout << "--------------------------" << endl;
    }

    int carChoice;
    cout << "Enter the number of the car to rent: ";
    cin >> carChoice;

    if (carChoice < 1 || carChoice > lengthCars) {
        cout << "Invalid choice. No contract added." << endl;
        return contracts;
    }


    cout << "Enter rental period (in days): ";
    int rentDays;
    cin >> rentDays;

    cout << "Enter the start day (ex 12.02.23): ";
    char startDay[10];
    cin >> startDay;

    cout << "Enter the end day: ";
    char endDay[10];
    cin >> endDay;

    Contract newContract;

    strcpy_s(newContract.name, sizeof(newContract.name), clients[clientChoice - 1].name);
    strcpy_s(newContract.surname, sizeof(newContract.surname), clients[clientChoice - 1].surname);
    strcpy_s(newContract.middleName, sizeof(newContract.middleName), clients[clientChoice - 1].middleName);

    strcpy_s(newContract.carBrand, sizeof(newContract.carBrand), cars[carChoice - 1].carBrand);
    strcpy_s(newContract.carModel, sizeof(newContract.carModel), cars[carChoice - 1].carModel);
    strcpy_s(newContract.registrationNumber, sizeof(newContract.registrationNumber), cars[carChoice - 1].registrationNumber);

    strcpy_s(newContract.startDay, sizeof(newContract.startDay), startDay);
    strcpy_s(newContract.endDay, sizeof(newContract.endDay), endDay);

    newContract.rentDays = rentDays;
    newContract.totalRentalPrice = rentDays * cars[carChoice - 1].rentalPricePerDay;


    short debt = currentDebt(contracts, clients, cars, lengthContracts, lengthClients, lengthCars, newContract.name, newContract.surname, newContract.middleName, newContract.rentDays);


    system("cls");
    // Vivid dobavlennoqo klienta
    cout << "Added Contract:" << endl;
    cout << "Name: " << newContract.name << endl;
    cout << "Surname: " << newContract.surname << endl;
    cout << "Middle name: " << newContract.middleName << endl;
    cout << "Car brand: " << newContract.carBrand << endl;
    cout << "Car model: " << newContract.carModel << endl;
    cout << "Registration number: " << newContract.registrationNumber << endl;
    cout << "--------------------------" << endl;

    Contract* tmp = new Contract[lengthContracts + 1];
    for (int i = 0; i < lengthContracts; i++) {
        tmp[i] = contracts[i];
    }


    tmp[lengthContracts] = newContract;
    delete[] contracts;
    contracts = tmp;
    lengthContracts++;

    cout << "Contract is added!" << endl;

    return tmp;
}