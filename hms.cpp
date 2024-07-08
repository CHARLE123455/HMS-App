#include <bitset>/stdc++.h>
#include <iostream>
using namespace std;

// store the hospital data

class Hospital
{
public:
    string H_name;
    string locations;
    int available_beds; // number
    float ratings;
    string contact;
    string doctor_name;
    int price;
};

// store patient data

class Patient : public Hospital
{
public:
    string P_name;
    int P_id; // number
};

// Hospital data

void PrintHospitalData(vector<Hospital> &hospitals)
{
    cout << "PRINT HOSPITAL DATA:"
         << endl;

    cout << "HospitalName"
         << "Location"
         << "Beds_Available"
         << "Ratings"
         << "Hospital_Contact"
         << "Doctor_Name"
         << "Price_Per_Bed \n";

    for (int i = 0; i < 4 : i++)
    {
        cout << hospitals[i].H_name
             << "     "
             << " "
             << hospitals[i].locations
             << " "
             << hospitals[i].available_beds
             << " "
             << hospitals[i].ratings
             << " "
             << hospitals[i].contact
             << " "
             << hospitals[i].doctor_name
             << "     "
             << " "
             << hospitals[i].price
             << " "
             << endl;
    }

    cout << endl
         << endl;
}

// print patient data in the hospital

void print_patient(vector<Patient> &patients, vector<Hospitals> &hospitals)
{
    cout << "Print patients Data:"
         << endl;
    cout << "patient_Name  "
         << "patient_id "
         << "patient_contact "
         << "alloted_hospital "
         << "patient_expenditure  \n";

    for (int i = 0; i < 4; i++)
    {
        cout << "      "
             << " "
             << patients[i].P_name
             << "    "
             << " "
             << patients[i].P_id
             << "     "
             << " "
             << patients[i].contact
             << "   "
             << " "
             << patients[i].H_name
             << " "
             << patients[i].price
             << " "
             << endl;
    }

    cout << endl
         << endl;
}

// sort the hospital data by name

bool name(Hospital &A, Hospital &B)
{
    return A.H_name > B.H_name;
}

void sortHospitalByName(vector<Hospital> hospitals)
{
    // sort the data
    sort(hospitals.begin(),
         hospitals.end(), name);

    cout << "Sort By Name:"

         << endl
         << endl;

    PrintHospitalData(hospitals);
}
bool rating(Hospital &A, Hospital &B)
{
    return A.ratings > B.ratings;
}

// sort the ratings by numerating them

void sortHospitalByRatings(vector<Hospital> hospitals)
{
    sort(hospitals.begin(), hospitals.end(), rating);

    cout << "Sort By Rating:"
         << endl
         << endl;

    PrintHospitalData(hospitals);
}

// comparator function to sort hospital data by Beds available

bool Beds(Hospital &A, Hospital &B)
{
    return A.available_beds > B.available_beds;
}

// sort the data by beds available

void sortHospitalByBedsAvailable(vector<Hospital> hospitals)
{
    sort(hospitals.begin(), hospitals.end(), Beds);

    cout << "Sort By Available Beds"
         << endl
         << endl;

    PrintHospitalData(hospitals);
}

// comparator function to sort hospital data by price

bool Price(Hospital &A, Hospital &B)
{
    return A.price > B.price;
}

// sort data by price

void sortHospitalByPrice(vector<Hospital> hospitals)
{
    sort(hospitals.begin(), hospitals.end(), Price);

    cout << "Sort By Price"
         << endl
         << endl;

    PrintHospitalData(hospitals);
}

// comparator function to sort hospital data by city

void PrintHospitalByCity(
    string city, vector<Hospital> hospitals)
{
    cout << "Print Hospitals By Name:"
         << city << endl;

    cout << "HospitalName "
         << "Location "
         << "Beds_Availabel "
         << "Ratings "
         << "Hospital_Contact "
         << "Doctor_Name "
         << "Price_Per_Bed \n";

    for (int i = 0; i < 4 : i++)
    {
        if (hospitals[i].locations != city)
            continue;
        cout << "   "
             << " "
             << hospitals[i].locations
             << " "
             << hospitals[i].available_beds
             << " "
             << hospitals[i].ratings
             << "  "
             << hospitals[i].contact
             << "   "
             << hospitals[i].doctor_name
             << "      "
             << "    "
             << hospitals[i].price
             << " "
             << endl;
    }

    cout << endl
         << endl;
}

// funtion to implement Hospital Management system

void HospitalManagement(
    string patient_Name[], int patient_id[], string patient_contact[], int bookingCost[], string hospital_Name[],
    int booking[], string location[], int beds[], float rating[], string hospital_Contact[],
    string doctor_Name[], int prices[])

{

    // store hospital and user data

    vector<Hospital> hospitals;

    // create objects for hospital and users

    Hospital h;

    for (size_t i = 0; i < 4; i++)
    {
        h.H_name = hospital_Name[i];
        h.locations = location[i];
        h.available_beds = beds[i];
        h.ratings = rating[i];
        h.contact = hospital_Contact[i];
        h.doctor_name = doctor_Name[i];
        h.price = prices[i];
        hospitals.push_back(h);
    }

    // store the patients data

    vector<Patient> patients

        Patient p;

    for (size_t i = 0; i < 4; i++)
    {
        p.P_name = patient_Name[i];
        p.P_id = patient_Id[i];
        p.contact = patient_Contact[i];
        p.price = bookingCost[i];
        patients.push_back(p);
    }

    cout << endl;

    // call the various operations

    PrintHospitalData(hospitals);
    PrintPatientData(patients, hospitals);

    sortHospitalByName(hospitals);
    sortHospitalByRatings(hospitals);
    sortHospitalByBedsAvailable(hospitals);
    sortHospitalByPrice(hospitals);
    PrintHospitalByCity("Lagos", hospitals);
}

// Add Driver Code and make function call to test the code
