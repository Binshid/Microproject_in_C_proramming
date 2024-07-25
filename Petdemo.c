#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 100
#define MAX_RECORDS 100
#define MAX_REMINDERS 100
#define MAX_APPOINTMENTS 100

typedef struct {
    char date[11];
    char description[100];
} HealthRecord;

typedef struct {
    char date[11];
    char vaccine[50];
} VaccinationReminder;

typedef struct {
    char date[11];
    char service[50];
} GroomingAppointment;

typedef struct {
    char name[50];
    char species[50];
    int age;
    HealthRecord healthRecords[MAX_RECORDS];
    int healthRecordCount;
    VaccinationReminder vaccinationReminders[MAX_REMINDERS];
    int vaccinationReminderCount;
    GroomingAppointment groomingAppointments[MAX_APPOINTMENTS];
    int groomingAppointmentCount;
} Pet;

Pet pets[MAX_PETS];
int petCount = 0;

void addPet() {
    if (petCount >= MAX_PETS) {
        printf("Maximum number of pets reached.\n");
        return;
    }
    printf("Enter pet's name: ");
    scanf("%s", pets[petCount].name);
    printf("Enter pet's species: ");
    scanf("%s", pets[petCount].species);
    printf("Enter pet's age: ");
    scanf("%d", &pets[petCount].age);
    pets[petCount].healthRecordCount = 0;
    pets[petCount].vaccinationReminderCount = 0;
    pets[petCount].groomingAppointmentCount = 0;
    petCount++;
   printf("\nAdded"); 
}

void addHealthRecord() {
    char petName[50];
    printf("Enter pet's name: ");
    scanf("%s", petName);
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].name, petName) == 0) {
            if (pets[i].healthRecordCount >= MAX_RECORDS) {
                printf("Maximum number of health records reached.\n");
                return;
            }
            printf("Enter health record date (YYYY-MM-DD): ");
            scanf("%s", pets[i].healthRecords[pets[i].healthRecordCount].date);
            printf("Enter health record description: ");
            scanf(" %s", pets[i].healthRecords[pets[i].healthRecordCount].description);
            pets[i].healthRecordCount++;
            printf("Health Condition updated");
            return;
        }
    }
    printf("Pet not found.\n");
}

void setVaccinationReminder() {
    char petName[50];
    printf("Enter pet's name: ");
    scanf("%s", petName);
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].name, petName) == 0) {
            if (pets[i].vaccinationReminderCount >= MAX_REMINDERS) {
                printf("Maximum number of vaccination reminders reached.\n");
                return;
            }
            printf("Enter vaccination date (YYYY-MM-DD): ");
            scanf("%s", pets[i].vaccinationReminders[pets[i].vaccinationReminderCount].date);
            printf("Enter vaccine name: ");
            scanf("%s", pets[i].vaccinationReminders[pets[i].vaccinationReminderCount].vaccine);
            pets[i].vaccinationReminderCount++;
            printf("Set vaccination reminder");
            return;
        }
    }
    printf("Pet not found.\n");
}

void addGroomingAppointment() {
    char petName[50];
    printf("Enter pet's name: ");
    scanf("%s", petName);
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].name, petName) == 0) {
            if (pets[i].groomingAppointmentCount >= MAX_APPOINTMENTS) {
                printf("Maximum number of grooming appointments reached.\n");
                return;
            }
            printf("Enter grooming appointment date (YYYY-MM-DD): ");
            scanf("%s", pets[i].groomingAppointments[pets[i].groomingAppointmentCount].date);
            printf("Enter grooming service: ");
            scanf("%s", pets[i].groomingAppointments[pets[i].groomingAppointmentCount].service);
            pets[i].groomingAppointmentCount++;
            printf("Set grooming appointment");
            return;
        }
    }
    printf("Pet not found.\n");
}

void displayPetInfo() {
    char petName[50];
    printf("Enter pet's name: ");
    scanf("%s", petName);
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].name, petName) == 0) {
            printf("Name: %s, Species: %s, Age: %d\n", pets[i].name, pets[i].species, pets[i].age);
            printf("Health Records:\n");
            for (int j = 0; j < pets[i].healthRecordCount; j++) {
                printf(" - %s: %s\n", pets[i].healthRecords[j].date, pets[i].healthRecords[j].description);
            }
            printf("Vaccination Reminders:\n");
            for (int j = 0; j < pets[i].vaccinationReminderCount; j++) {
                printf(" - %s: %s\n", pets[i].vaccinationReminders[j].date, pets[i].vaccinationReminders[j].vaccine);
            }
            printf("Grooming Appointments:\n");
            for (int j = 0; j < pets[i].groomingAppointmentCount; j++) {
                printf(" - %s: %s\n", pets[i].groomingAppointments[j].date, pets[i].groomingAppointments[j].service);
            }
            return;
        }
    }
    printf("Pet not found.\n");
}

void mainMenu() {
    int choice;
    while (1) {
        printf("\nPet Care Management System\n");
        printf("1. Add Pet\n");
        printf("2. Track Pet Health Records\n");
        printf("3. Set Vaccination Reminders\n");
        printf("4. Manage Grooming Appointments\n");
        printf("5. Display Pet Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPet();
                break;
            case 2:
                addHealthRecord();
                break;
            case 3:
                setVaccinationReminder();
                break;
            case 4:
                addGroomingAppointment();
                break;
            case 5:
                displayPetInfo();
                break;
            case 6:
            printf("Exiting..");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
