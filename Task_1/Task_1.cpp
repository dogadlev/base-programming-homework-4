// Homework 4. Task 1.

#include <iostream>
#include <string>
#include <fstream>

class Address 
{
private:
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;

public:
    Address(std::string city, std::string street, std::string building, std::string appartment) 
    {
        this->city = city;
        this->street = street;
        this->building = building;
        this->appartment = appartment;
    }

    Address() {}

    std::string outputAddress()
    {
        std::string outStr = city + ", " + street + ", " + building + ", " + appartment;
        return outStr;
    }
};

int getAddressCount(std::ifstream &dataFile) 
{
    int addressCount = 0;
    dataFile >> addressCount;

    return addressCount;
}

void getAddress(std::ifstream& dataFile, int addressCount, Address* addressArr)
{
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;
    for (int i = 0; i < addressCount; ++i)
    {
        dataFile >> city;
        dataFile >> street;
        dataFile >> building;
        dataFile >> appartment;
        addressArr[i] = Address(city, street, building, appartment);
    }
}

void outputAddress(std::ofstream& outFile, int addressCount, Address* addressArr)
{
    outFile << addressCount << std::endl;
    for (int i = addressCount - 1; i >= 0; --i)
    {
        outFile << addressArr[i].outputAddress() << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::ifstream dataFile("in.txt");
    if (!dataFile.is_open()) 
    {
        std::cout << "Could not open the file in.txt. Check the file name.";
        return 1;
    }
    else
    {
        int addressCount = getAddressCount(dataFile);
        Address* addressArr = new Address[addressCount];
        getAddress(dataFile, addressCount, addressArr);
        dataFile.close();
        std::ofstream outFile("out.txt");
        outputAddress(outFile, addressCount, addressArr);
        outFile.close();
        delete[] addressArr;
        return 0;
    }
}