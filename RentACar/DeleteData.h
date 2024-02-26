#pragma once
#include<iostream>
using namespace std;

Car* deleteCar(Car* cars, int& lengthCars) {
	if (lengthCars == 0) {
		cout << "No cars to delete." << endl;
		return cars;
	}

	cout << "Cars:" << endl;
	for (int i = 0; i < lengthCars; i++) {
		cout << "Car " << (i + 1) << ":" << endl;
		cout << "Brand: " << cars[i].carBrand << endl;
		cout << "Color: " << cars[i].color << endl;
		cout << "Registration number: " << cars[i].registrationNumber << endl;
		cout << "Year of production: " << cars[i].yearOfProduction << endl;
		cout << "Engine: " << cars[i].engineCar << endl;
		cout << "Rent price: " << cars[i].rentalPricePerDay << endl;
		cout << "--------------------------" << endl;
	}

	int choiceCar;
	cout << "Choose the car to delete: ";
	cin >> choiceCar;

	if (choiceCar < 1 || choiceCar > lengthCars) {
		cout << "Invalid choice. No car deleted." << endl;
		return cars;
	}

	Car* newCar = createCarArray(lengthCars - 1);

	for (int i = 0, j = 0; i < lengthCars; i++) { // ispolzuyu vtoruyu peremennuyu dlya iteracii po novomu massivu
		if (i != choiceCar - 1) {
			newCar[j] = cars[i];
			j++;
		}
	}

	delete[] cars;

	lengthCars--;
	cout << "Car has been deleted." << endl;

	return newCar;
}

Contract* deleteContract(Contract* deletecontracts, int& lengthContracts) {
	cout << "Contracts:" << endl;
	for (int i = 0; i < lengthContracts; i++) {
		cout << "Contract " << (i + 1) << ":" << endl;
		cout << "Name: " << deletecontracts[i].name << endl;
		cout << "Surname: " << deletecontracts[i].surname << endl;
		cout << "Middle name: " << deletecontracts[i].middleName << endl;
		cout << "--------------------------" << endl;
	}
	int choiceContract;
	cout << "Choose the client to delete: ";
	cin >> choiceContract;
	if (choiceContract < 1 || choiceContract > lengthContracts) {
		cout << "Invalid choice. No contract deleted." << endl;
		return deletecontracts;
	}
	Contract* newContract = createContractArray(lengthContracts - 1);
	for (int i = 0, j = 0; i < lengthContracts; i++)
	{
		if (i != choiceContract - 1) {
			newContract[j] = deletecontracts[i];
			j++;
		}
	}
	delete[] deletecontracts;
	lengthContracts--;
	cout << "Contract has been deleted!" << endl;
	return newContract;
}

Client* deleteClient(Client* deleteclients, int& lengthClients) {
	if (lengthClients == 0)
	{
		cout << "No client delete." << endl;
		return deleteclients;
	}
	cout << "Clients:" << endl;
	for (int i = 0; i < lengthClients; i++) {
		cout << "Client " << (i + 1) << ":" << endl;
		cout << "Name: " << deleteclients[i].name << endl;
		cout << "Surname: " << deleteclients[i].surname << endl;
		cout << "Middle name: " << deleteclients[i].middleName << endl;
		cout << "--------------------------" << endl;
	}
	int choiceClient;
	cout << "Choose the client to delete: ";
	cin >> choiceClient;
	if (choiceClient < 1 || choiceClient > lengthClients) {
		cout << "Invalid choice. No client deleted." << endl;
		return deleteclients;
	}

	Client* newClients = new Client[lengthClients - 1];
	// ispolzuyu vtoruyu peremennuyu dlya iteracii po novomu massivu
	for (int i = 0, j = 0; i < lengthClients; i++) {
		if (i != choiceClient - 1) {
			newClients[j] = deleteclients[i];
			j++;
		}
	}

	lengthClients--;
	delete[] deleteclients;
	cout << "Client has been deleted!" << endl;
	return newClients;
}

void deleteAllData(Car* allcars, Client* allclients, Contract* allcontracts, int& lengthCars, int& lengthClients, int& lengthContracts) {
	// udalenniye dannix o mashine
	for (int i = 0; i < lengthCars; i++) {
		delete[] allcars[i].carBrand;
		delete[] allcars[i].carModel;
		delete[] allcars[i].color;
		delete[] allcars[i].registrationNumber;
	}
	delete[] allcars;

	// udalenniye dannix o klientax
	for (int i = 0; i < lengthClients; i++) {
		delete[] allclients[i].name;
		delete[] allclients[i].surname;
		delete[] allclients[i].middleName;
	}
	delete[] allclients;

	// udalenniye dannix o kontrakte
	for (int i = 0; i < lengthContracts; i++) {
		delete[] allcontracts[i].name;
		delete[] allcontracts[i].surname;
		delete[] allcontracts[i].middleName;
		delete[] allcontracts[i].carBrand;
		delete[] allcontracts[i].carModel;
		delete[] allcontracts[i].registrationNumber;
	}
	delete[] allcontracts;

	// sbros dlin massivov na 0
	lengthCars = 0;
	lengthClients = 0;
	lengthContracts = 0;
	cout << "\t\t\t\t\t\t\t All data is deleted!" << endl;
}