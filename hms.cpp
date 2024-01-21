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

//sort the hospital data by name

bool name (Hospital& A, Hospital& B){
    return A.H_name > B.H_name;
}

void sortHospitalByName (vector<Hospital> hospitals){
    //sort the data
    sort(hospitals.begin(),
    hospitals.end(), name
    ):

    cout << "Sort By Name:"

        << endl
        << endl;
    
        
    PrintHospitalData(hospitals);
}
bool rating (Hospital& A, Hospital& B){
    return A.ratings > B.ratings;
}
