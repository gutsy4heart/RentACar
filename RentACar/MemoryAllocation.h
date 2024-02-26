#pragma once
#include<iostream>
using namespace std;
Car* createCarArray(int size) {
    Car* cars = new Car[size];
    return cars;
}
Client* createClientArray(int size) {
    Client* clients = new Client[size];
    return clients;
}
Contract* createContractArray(int size) {
    Contract* contarcts = new Contract[size];
    return contarcts;
}