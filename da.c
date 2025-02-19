#include<stdio.h>
struct Hospital { 
    char name[50]; 
    char city[50]; 
    int beds; 
    float price; 
    float rating; 
    int reviews; 
}; 
struct Patient { 
    char name[50]; 
    int age; 
    char gender;
    int contact_no;
};
int i,j;
void dispHospitalDetails(struct Hospital hosp){
    printf("Hospital Name: %s\n", hosp.name); 
    printf("City: %s\n", hosp.city); 
    printf("Total Beds: %d\n", hosp.beds); 
    printf("Price per Bed: Rs.%.2f\n", hosp.price); 
    printf("Rating: %.1f\n", hosp.rating); 
    printf("Reviews: %d\n", hosp.reviews); 
    printf("\n"); 
}
void dispPatientDetails(struct Patient patient){
    printf("Patient Name: %s\n", patient.name); 
    printf("Patient Age: %d\n", patient.age);
    printf("Patient Gender: %d\n",patient.gender);
    printf("Patient Contact Number: %d\n", patient.contact_no);
    printf("\n");
}
void SortByPrice(struct Hospital hospitals[], int n){
    for (i=0;i<n-1;i++){ 
        for (j=0;j<n-i-1;j++){
            if (hospitals[j].price > hospitals[j+1].price){
                struct Hospital temp = hospitals[j];
                hospitals[j] = hospitals[j+1];
                hospitals[j+1]=temp;
            }
        }
    }
}
void SortByBeds(struct Hospital hospitals[], int n){ 
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (hospitals[j].beds<hospitals[j+1].beds){
                struct Hospital temp =hospitals[j];
                hospitals[j]=hospitals[j+1]; 
                hospitals[j+1]=temp;
            }
        }
    }
}
void SortByName(struct Hospital hospitals[], int n){ 
        for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (strcmp(hospitals[j].name, hospitals[j+1].name) >0) { 
                struct Hospital temp = hospitals[j];
                hospitals[j] = hospitals[j+1];
                hospitals[j+1] = temp; 
            }
        }
    }
}
void SortByRating(struct Hospital hospitals[], int n){
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (hospitals[j].rating * hospitals[j].reviews < hospitals[j+1].rating * hospitals[j+1].reviews){
                struct Hospital temp = hospitals[j];
                hospitals[j] = hospitals[j+1];
                hospitals[j+1] = temp;
            }
        }
    }
}
void SortByCity(struct Hospital hospitals[]){ 
    char city[50];
    int hospitalsFound=0;   
    printf("Enter city name: "); 
    scanf("%s", city);
    printf("Hospitals in %s:\n", city); 
    for (i=0;i<5;i++){
        if (strcasecmp(hospitals[i].city,city)==0){
            printf("Hospital Name: %s\n", hospitals[i].name);
            printf("City: %s\n", hospitals[i].city);
            printf("Total Beds: %d\n", hospitals[i].beds);
            printf("Price per Bed: $%.2f\n", hospitals[i].price);
            printf("Rating: %.1f\n", hospitals[i].rating);
            printf("Reviews: %d\n", hospitals[i].reviews); 
            printf("\n");
            hospitalsFound++;
        } 
    }   
    if (hospitalsFound == 0) { 
        printf("No hospitals found in %s\n", city); 
    }
}
int main(){
    struct Hospital hospitals[5]={
        {"Amrita Hospital", "Faridabad", 100, 250.0, 4.5, 100}, 
        {"Sarvodya Hospital", "Gurgaon", 150, 2000.0, 4.2, 80}, 
        {"Apollo Hospital", "Delhi", 200, 3000.0, 4.0, 120}, 
        {"Fortis Hospital", "Gurgaon", 80, 350.0, 4.8, 90}, 
        {"Sunshine Hospital", "Mumbai", 120, 220.0, 4.6, 110} 
    }; 
    struct Patient patients[5][3]={
        {{"Ram", 40}, {"Sita", 42}, {"Shyam", 21}}, 
        {{"Mary", 52}, {"Preity", 79}, {"Stuti", 55}}, 
        {{"Rohan", 40}, {"Anshuman", 8}, {"Rita", 98}}, 
        {{"Veer", 15}, {"Zaara", 30}, {"Aishwarya", 38}}, 
        {{"Geet", 56}, {"Aditya", 90}, {"Rahul", 26}} 
    };  
    int n = 5;  
    int choice; 
    char city[50]; 
    do{
    	printf("*********** Hospital Management System Menu:************\n"); 
        printf("1. Printing Hospital Data\n"); 
        printf("2. Printing Patients Data\n"); 
        printf("3. Sorting Hospitals by Beds Price\n"); 
        printf("4. Sorting Hospitals by Available Beds\n"); 
        printf("5. Sorting Hospitals by Name\n"); 
        printf("6. Sorting Hospitals by Rating and Reviews\n"); 
        printf("7. Print Hospitals in a Specific City\n"); 
        printf("8. Exit\n\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice){
        	case 1:
        		printf("\nPrinting Hospital Data:\n\n"); 
                for (i = 0; i < n; i++){ 
                    dispHospitalDetails(hospitals[i]); 
                }
                break;
            case 2: 
                printf("Printing Patients Data:\n\n"); 
                for (i=0;i<n;i++) { 
                    printf("Hospital: %s\n", hospitals[i].name); 
                    for (j=0;j<3;j++) { 
                        dispPatientDetails(patients[i][j]); 
                    }
                }
                break; 
            case 3: 
                printf("Sorting Hospitals by Beds Price:\n"); 
                SortByBeds(hospitals, n); 
                for (i=0;i<n;i++){
                    dispHospitalDetails(hospitals[i]); 
                }
                break; 
            case 4: 
                printf("Sorting Hospitals by Available Beds:\n"); 
                SortByBeds(hospitals, n);
                for (i=0;i<n;i++) { 
                    dispHospitalDetails(hospitals[i]); 
                } 
                break; 
            case 5: 
                printf("Sorting Hospitals by Name:\n"); 
                SortByName(hospitals, n); 
                for (i = 0; i < n; i++) { 
                    dispHospitalDetails(hospitals[i]); 
                } 
                break; 
            case 6: 
                printf("Sorting Hospitals by Rating and Reviews:\n"); 
                SortByRating(hospitals, n); 
                for (i = 0; i < n; i++) { 
                    dispHospitalDetails(hospitals[i]); 
                }
                break;
            case 7:
                SortByCity(hospitals); 
                break; 
            case 8: 
                printf("Exiting the program.\n"); 
                break; 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } while (choice != 8); 
    return 0; 
}
