#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Hospital {
public:
    string H_name;
    string locations;
    int available_beds;
    float ratings;
    string contact;
    string doctor_name;
    int price;
};

class Patient : public Hospital {
public:
    string P_name;
    int P_id;
};

void PrintHospitalData(vector<Hospital> &hospitals) {
    cout << "PRINT HOSPITAL DATA:" << endl;
    cout << "HospitalName" << "Location" << "Beds_Available" << "Ratings" << "Hospital_Contact" << "Doctor_Name" << "Price_Per_Bed" << endl;
    for (int i = 0; i < hospitals.size(); i++) {
        cout << hospitals[i].H_name << " " << hospitals[i].locations << " " << hospitals[i].available_beds << " " << hospitals[i].ratings << " " << hospitals[i].contact << " " << hospitals[i].doctor_name << " " << hospitals[i].price << endl;
    }
    cout << endl << endl;
}

void print_patient(vector<Patient> &patients, vector<Hospital> &hospitals) {
    cout << "Print patients Data:" << endl;
    cout << "patient_Name" << "patient_id" << "patient_contact" << "alloted_hospital" << "patient_expenditure" << endl;
    for (int i = 0; i < patients.size(); i++) {
        cout << patients[i].P_name << " " << patients[i].P_id << " " << patients[i].contact << " " << patients[i].H_name << " " << patients[i].price << endl;
    }
    cout << endl << endl;
}

bool name(Hospital &A, Hospital &B) {
    return A.H_name > B.H_name;
}

void sortHospitalByName(vector<Hospital> hospitals) {
    sort(hospitals.begin(), hospitals.end(), name);
    cout << "Sort By Name:" << endl << endl;
    PrintHospitalData(hospitals);
}

bool rating(Hospital &A, Hospital &B) {
    return A.ratings > B.ratings;
}

void sortHospitalByRatings(vector<Hospital> hospitals) {
    sort(hospitals.begin(), hospitals.end(), rating);
    cout << "Sort By Rating:" << endl << endl;
    PrintHospitalData(hospitals);
}

bool Beds(Hospital &A, Hospital &B) {
    return A.available_beds > B.available_beds;
}

void sortHospitalByBedsAvailable(vector<Hospital> hospitals) {
    sort(hospitals.begin(), hospitals.end(), Beds);
    cout << "Sort By Available Beds" << endl << endl;
    PrintHospitalData(hospitals);
}

bool Price(Hospital &A, Hospital &B) {
    return A.price > B.price;
}

void sortHospitalByPrice(vector<Hospital> hospitals) {
    sort(hospitals.begin(), hospitals.end(), Price);
    cout << "Sort By Price" << endl << endl;
    PrintHospitalData(hospitals);
}

void PrintHospitalByCity(string city, vector<Hospital> hospitals) {
    cout << "Print Hospitals By Name:" << city << endl;
    cout << "HospitalName" << "Location" << "Beds_Availabel" << "Ratings" << "Hospital_Contact" << "Doctor_Name" << "Price_Per_Bed" << endl;
    for (int i = 0; i < hospitals.size(); i++) {
        if (hospitals[i].locations == city) {
            cout << hospitals[i].H_name << " " << hospitals[i].locations << " " << hospitals[i].available_beds << " " << hospitals[i].ratings << " " << hospitals[i].contact << " " << hospitals[i].doctor_name << " " << hospitals[i].price << endl;
        }
    }
    cout << endl << endl;
}

void HospitalManagement(string patient_Name[], int patient_id[], string patient_contact[], int bookingCost[], string hospital_Name[], int booking[], string location[], int beds[], float rating[], string hospital_Contact[], string doctor_Name[], int prices[]) {
    vector<Hospital> hospitals;
    Hospital h;
    for (size_t i = 0; i < 4; i++) {
        h.H_name = hospital_Name[i];
        h.locations = location[i];
        h.available_beds = beds[i];
        h.ratings = rating[i];
        h.contact = hospital_Contact[i];
        h.doctor_name = doctor_Name[i];
        h.price = prices[i];
        hospitals.push_back(h);
    }

    vector<Patient> patients;
    Patient p;
    for (size_t i = 0; i < 4; i++) {
        p.P_name = patient_Name[i];
        p.P_id = patient_id[i];
        p.contact = patient_contact[i];
        p.price = bookingCost[i];
        patients.push_back(p);
    }

    cout << endl;
    PrintHospitalData(hospitals);
    print_patient(patients, hospitals);
    sortHospitalByName(hospitals);
    sortHospitalByRatings(hospitals);
    sortHospitalByBedsAvailable(hospitals);
    sortHospitalByPrice(hospitals);
    PrintHospitalByCity("Lagos", hospitals);
}

int main() {
    string patient_Name[] = {"John", "Mary", "David", "Emily"};
    int patient_id[] = {1, 2, 3, 4};
    string patient_contact[] = {"1234567890", "2345678901", "3456789012", "4567890123"};
    int bookingCost[] = {1000, 2000, 3000, 4000};
    string hospital_Name[] = {"Hospital1", "Hospital2", "Hospital3", "Hospital4"};
    int booking[] = {10, 20, 30, 40};
    string location[] = {"Lagos", "Abuja", "Port Harcourt", "Ibadan"};
    int beds[] = {100, 200, 300, 400};
    float rating[] = {4.5, 4.2, 4.8, 4.9};
    string hospital_Contact[] = {"hospital1@example.com", "hospital2@example.com", "hospital3@example.com", "hospital4@example.com"};
    string doctor_Name[] = {"Dr. John", "Dr. Mary", "Dr. David", "Dr. Emily"};
    int prices[] = {500, 600, 700, 800};

    HospitalManagement(patient_Name, patient_id, patient_contact, bookingCost, hospital_Name, booking, location, beds, rating, hospital_Contact, doctor_Name, prices);

    return 0;
}
