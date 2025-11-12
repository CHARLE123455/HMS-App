#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Hospital {
public:
    string name;
    string location;
    int available_beds;
    float rating;
    string contact;
    string doctor_name;
    int price_per_bed;
};

class Patient {
public:
    string name;
    int id;
    string contact;
    string city;
    string assigned_hospital;
    int expenditure;
};


void printHospitalData(const vector<Hospital> &hospitals) {
    cout << "\n=== HOSPITAL DATA ===\n";
    cout << left << setw(15) << "Hospital Name"
         << setw(15) << "Location"
         << setw(17) << "Beds Available"
         << setw(10) << "Rating"
         << setw(25) << "Contact"
         << setw(15) << "Doctor"
         << setw(12) << "Price/Bed" << endl;

    cout << string(110, '-') << endl;

    for (const auto &h : hospitals) {
        cout << left << setw(15) << h.name
             << setw(15) << h.location
             << setw(17) << h.available_beds
             << setw(10) << h.rating
             << setw(25) << h.contact
             << setw(15) << h.doctor_name
             << setw(12) << h.price_per_bed << endl;
    }
    cout << endl;
}

void printPatientData(const vector<Patient> &patients) {
    cout << "\n=== PATIENT DATA ===\n";
    cout << left << setw(15) << "Patient Name"
         << setw(10) << "ID"
         << setw(15) << "City"
         << setw(20) << "Contact"
         << setw(20) << "Hospital"
         << setw(15) << "Expenditure" << endl;

    cout << string(95, '-') << endl;

    for (const auto &p : patients) {
        cout << left << setw(15) << p.name
             << setw(10) << p.id
             << setw(15) << p.city
             << setw(20) << p.contact
             << setw(20) << p.assigned_hospital
             << setw(15) << p.expenditure << endl;
    }
    cout << endl;
}

void sortByName(vector<Hospital> &hospitals) {
    sort(hospitals.begin(), hospitals.end(),
         [](const Hospital &a, const Hospital &b) {
             return a.name < b.name;
         });
    cout << "\n--- Sorted by Name ---\n";
    printHospitalData(hospitals);
}

void sortByRating(vector<Hospital> &hospitals) {
    sort(hospitals.begin(), hospitals.end(),
         [](const Hospital &a, const Hospital &b) {
             return a.rating > b.rating;
         });
    cout << "\n--- Sorted by Rating ---\n";
    printHospitalData(hospitals);
}

void sortByBeds(vector<Hospital> &hospitals) {
    sort(hospitals.begin(), hospitals.end(),
         [](const Hospital &a, const Hospital &b) {
             return a.available_beds > b.available_beds;
         });
    cout << "\n--- Sorted by Available Beds ---\n";
    printHospitalData(hospitals);
}

void sortByPrice(vector<Hospital> &hospitals) {
    sort(hospitals.begin(), hospitals.end(),
         [](const Hospital &a, const Hospital &b) {
             return a.price_per_bed < b.price_per_bed;
         });
    cout << "\n--- Sorted by Price ---\n";
    printHospitalData(hospitals);
}

void printHospitalsByCity(const string &city, const vector<Hospital> &hospitals) {
    cout << "\n=== HOSPITALS IN " << city << " ===\n";
    cout << left << setw(15) << "Hospital Name"
         << setw(15) << "Location"
         << setw(17) << "Beds Available"
         << setw(10) << "Rating"
         << setw(25) << "Contact"
         << setw(15) << "Doctor"
         << setw(12) << "Price/Bed" << endl;

    cout << string(110, '-') << endl;

    for (const auto &h : hospitals) {
        if (h.location == city) {
            cout << left << setw(15) << h.name
                 << setw(15) << h.location
                 << setw(17) << h.available_beds
                 << setw(10) << h.rating
                 << setw(25) << h.contact
                 << setw(15) << h.doctor_name
                 << setw(12) << h.price_per_bed << endl;
        }
    }
    cout << endl;
}

void assignHospitals(vector<Patient> &patients, vector<Hospital> &hospitals) {
    sort(hospitals.begin(), hospitals.end(),
         [](const Hospital &a, const Hospital &b) {
             return a.price_per_bed < b.price_per_bed;
         });

    for (auto &p : patients) {
        bool assigned = false;

        for (auto &h : hospitals) {
            if (h.location == p.city && h.available_beds > 0) {
                p.assigned_hospital = h.name;
                p.expenditure = h.price_per_bed;
                h.available_beds--; 
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            for (auto &h : hospitals) {
                if (h.available_beds > 0) {
                    p.assigned_hospital = h.name + " (Cheapest)";
                    p.expenditure = h.price_per_bed;
                    h.available_beds--;
                    break;
                }
            }
        }
    }
}

void HospitalManagement(
    const vector<string> &patientNames,
    const vector<int> &patientIds,
    const vector<string> &patientContacts,
    const vector<string> &patientCities,
    const vector<string> &hospitalNames,
    const vector<string> &locations,
    const vector<int> &beds,
    const vector<float> &ratings,
    const vector<string> &hospitalContacts,
    const vector<string> &doctorNames,
    const vector<int> &prices
) {
    vector<Hospital> hospitals;
    for (size_t i = 0; i < hospitalNames.size(); ++i) {
        hospitals.push_back({
            hospitalNames[i],
            locations[i],
            beds[i],
            ratings[i],
            hospitalContacts[i],
            doctorNames[i],
            prices[i]
        });
    }

    vector<Patient> patients;
    for (size_t i = 0; i < patientNames.size(); ++i) {
        patients.push_back({
            patientNames[i],
            patientIds[i],
            patientContacts[i],
            patientCities[i],
            "",
            0  
        });
    }

    assignHospitals(patients, hospitals);

    printHospitalData(hospitals);
    printPatientData(patients);

    sortByName(hospitals);
    sortByRating(hospitals);
    sortByBeds(hospitals);
    sortByPrice(hospitals);
    printHospitalsByCity("Lagos", hospitals);
}


int main() {
    vector<string> patientNames = {"John", "Mary", "David", "Emily"};
    vector<int> patientIds = {1, 2, 3, 4};
    vector<string> patientContacts = {"1234567890", "2345678901", "3456789012", "4567890123"};
    vector<string> patientCities = {"Lagos", "Abuja", "Kano", "Port Harcourt"};

    vector<string> hospitalNames = {"Hospital1", "Hospital2", "Hospital3", "Hospital4"};
    vector<string> locations = {"Lagos", "Abuja", "Port Harcourt", "Ibadan"};
    vector<int> beds = {2, 1, 2, 1};
    vector<float> ratings = {4.5, 4.2, 4.8, 4.9};
    vector<string> hospitalContacts = {
        "hospital1@example.com",
        "hospital2@example.com",
        "hospital3@example.com",
        "hospital4@example.com"
    };
    vector<string> doctorNames = {"Dr. John", "Dr. Mary", "Dr. David", "Dr. Emily"};
    vector<int> prices = {500, 600, 700, 800};

    HospitalManagement(patientNames, patientIds, patientContacts, patientCities,
                       hospitalNames, locations, beds, ratings,
                       hospitalContacts, doctorNames, prices);

    return 0;
}
