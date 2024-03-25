#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_Seats1 40 
#define MAX_Seats2 60
#define MAX_Seats3 72
#define MAX_Seats4 85
#define MAX_PASSENGER_NAME_LENGTH 100

// Define a structure for Bus seats
typedef struct BusSeats {
    int numseat;
    bool isreserved;
    char passengername[MAX_PASSENGER_NAME_LENGTH];
} bus;
// Function Prototypes
void welcome();
void bustype();
void displayoptions();
void initializeseats(bus seats[], int seatnumber);
void reservationrequest(bus seats[], int busseatnumber,int cps,const char* filename);
void availableseats(bus seats[], int seatnumber,const char* filename);
void cancelreservation(bus seats[], int seatnumber,int refund,const char* filename);
void cancelseatsinbus();

int main() {
    // Initialize variables and arrays
    int bus1seats, bus2seats, bus3seats, bus4seats;
    bus1seats = MAX_Seats1;
    bus2seats = MAX_Seats2;
    bus3seats = MAX_Seats3;
    bus4seats = MAX_Seats4;
    bus BUS1[MAX_Seats1];
    bus BUS2[MAX_Seats2];
    bus BUS3[MAX_Seats3];
    bus BUS4[MAX_Seats4];
    int busavailableseats;
    int options;
    int options2;
    int reservebusseat;
    int cancelseat;
    int numbus;
    int busnumber;
    int screen;
    int cps_bus1 = 1000,cps_bus2 = 1200,cps_bus3 = 2500, cps_bus4 = 3000;

    // Initialize bus seats
    initializeseats(BUS1, bus1seats);
    initializeseats(BUS2, bus2seats);
    initializeseats(BUS3, bus3seats);
    initializeseats(BUS4, bus4seats);
    // Main Program loop
    do{
        // Display Welcome screen and user input
    welcome();
    scanf("%d", &options);
    switch (options) {
    case 1:printf("\n");
        printf("\t\t\t%d.\t",options);displayoptions();
        scanf("%d", &options2);
        switch (options2) {
        case 1:
            bustype();
            scanf("%d", &reservebusseat);
            switch (reservebusseat) {
            case 1:
                reservationrequest(BUS1, bus1seats,cps_bus1,"Bus1.txt");
                break;
            case 2:
                reservationrequest(BUS2, bus2seats,cps_bus2,"Bus2.txt");
                break;
            case 3:
                reservationrequest(BUS3, bus3seats,cps_bus3,"Bus3.txt");
                break;
            case 4:
                reservationrequest(BUS4, bus4seats,cps_bus4,"Bus4.txt");
                break;
            }
            break;
        case 2:
            cancelseatsinbus();
            scanf("%d", &cancelseat);
            switch (cancelseat) {
            case 1:
                cancelreservation(BUS1, bus1seats,cps_bus1,"Bus1.txt");
                break;
            case 2:
                cancelreservation(BUS2, bus2seats,cps_bus2,"Bus2.txt");
                break;
            case 3:
                cancelreservation(BUS3, bus3seats,cps_bus3,"Bus3.txt");
                break;
            case 4:
                cancelreservation(BUS4, bus4seats,cps_bus4,"Bus4.txt");
                break;
            }
            break;
        case 3:
            bustype();
            scanf("%d", &busavailableseats);
            switch (busavailableseats) {
            case 1:
                availableseats(BUS1, bus1seats,"Bus1.txt");
                break;
            case 2:
                availableseats(BUS2, bus2seats,"Bus2.txt");
                break;
            case 3:
               availableseats(BUS3, bus3seats,"Bus3.txt");
                break;
            case 4:
                availableseats(BUS4, bus4seats,"Bus4.txt");
                break;
            }
            break;
        default:
            break;
        }
        break;
    case 2:
    	printf("\n");
        printf("\t\t%d.\t\t",options);bustype();
        break;
    case 3:
        printf("\t----------------------------------------------------------------------------------------------------------\n");
        printf("\t\t%d.\tHi! This is TRAVGO Travel agency since 2012 Our transports are all over Punjab\t\t\t\t\n",options);
        printf("\t----------------------------------------------------------------------------------------------------------\n");
        break;
    }
    }while(options!=4);
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using this System:\t\t\t\t\t\t\n");
    printf("\t\t\t\t\tDeveloped By Muhammad Abdullah:\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    return 0;
}
// Function to display Welcome message
void welcome() {
    printf("\n\t\t\t\tHi! Welcome, Please let us know\n\t\t\t\tHow can we help you\n");
    printf("\t\t\t\t\t[1]=> Booking Options:\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Bus Types We have:\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> About Us:\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> To exit:\n");
}
// Function To display information about bus types
void bustype() {
   
     printf("We have these Four Types of buses: \n");
     printf("Choose Where you want to have a seat \n");
     printf("\n");
     printf("\t\t\t\t\t  =>  1.Have 40 Seats And also have AC & Heater \nSahiwal To Lahore\n");
     printf("\t\t\t\t\t  =>  Cost Of each seat is 1000 rupees \n");
     printf("\t\t\t\t\t  =>  Total luggage load can be 60kg\n");
     printf("\t\t\t\t\t  =>  1 bag is allowed per ticket individually\n");
     printf("\t\t\t\t\t  =>  Time : 7:00AM\n");
     printf("\n");
printf("\n");
     printf("\t\t\t\t\t  =>  2.Have 60 Seats, AC & Heater service also\nSahiwal To Multan\n");
     printf("\t\t\t\t\t  =>  Cost Of each seat is 1200 rupees \n");
     printf("\t\t\t\t\t  =>  Total luggage load can be 80kg\n");
     printf("\t\t\t\t\t  =>  2 bag is allowed per ticket individually\n");
     printf("\t\t\t\t\t  =>  Time : 8:00AM\n");
     printf("\n");
printf("\n");
     printf("\t\t\t\t\t  =>  3.Have 72 Seats, AC, Heater & Wifi also available\nSahiwal To Karachi\n");
     printf("\t\t\t\t\t  =>  Cost Of each seat is 2500 rupees \n");
     printf("\t\t\t\t\t  =>  Total luggage load can be 90kg\n");
     printf("\t\t\t\t\t  =>  3 bag is allowed per ticket individually\n");
     printf("\t\t\t\t\t  =>  Time : 4:00AM\n");
     printf("\n");
printf("\n");
     printf("\t\t\t\t\t  =>  4.Have 85 Seats, AC & Heater & Wifi also available\nSahiwal To Islamabad\n");
     printf("\t\t\t\t\t  =>  Cost Of each seat is 3000 rupees \n");
     printf("\t\t\t\t\t  =>  Total luggage load can be 100kg\n");
     printf("\t\t\t\t\t  =>  4 bag is allowed per ticket individually\n");
     printf("\t\t\t\t\t  =>  Time : 9:00PM\n");
     printf("\n");
printf("\n");
     return;
}
// Function to display options for reservation, cancellation, and available seats
void displayoptions() {
     printf("What You want to do? :\n");
     printf("1. Request to Reserve a seat\n");
     printf("2. Cancel resevation\n");
     printf("3. Want to see available seats\n");
     printf("\n");
    return;
}

// Function to initialize bus seats
void initializeseats(bus seat[], int seatnumber) 
{
    for (int i = 0; i < seatnumber; ++i) {
        seat[i].numseat = i + 1;
        seat[i].isreserved = false;
        seat[i].passengername[0] = '\0';
    }
}
// Function to handle reservation requests
void reservationrequest(bus seats[], int busseatnumber,int cps, const char* filename) {
    FILE *file = fopen(filename, "a");
    int seatNumber;
    int Amount = 0;
    int seatstoreserve;
    printf("Enter Seats you want to reserve: \n");
    scanf("%d", &seatstoreserve);
    for (int i = 1; i <= seatstoreserve; i++) {
        printf("============================Enter the details for ticket no ============================\n\n\n");
        printf("\t\t\t\tEnter the seat number you want to reserve:---> ");
        scanf("%d", &seatNumber);
        getchar();
        if (seatNumber < 1 || seatNumber > busseatnumber || seats[seatNumber - 1].isreserved) {
            printf("Invalid or already reserved seat. Please enter a valid seat number.\n");
            i--;
        } else {
            seats[seatNumber - 1].isreserved = true;
            printf("\t\t\t\tEnter passenger name:---> ");
            fgets(seats[seatNumber-1].passengername, sizeof(seats[seatNumber-1].passengername), stdin);
            printf("Seat %d reserved successfully for %s.\n", seatNumber, seats[seatNumber - 1].passengername);
            printf("\n======================================================================================================\n\n");
            fprintf(file, "%d\t\t %d\t\t %s\t\t\n", seats[seatNumber - 1].numseat, seats[seatNumber - 1].isreserved, seats[seatNumber - 1].passengername);
            Amount += cps;
        }
    }
    printf("\n\n");
printf("======================================================================================================\n");
    printf("\t\t\t\tTotal Charges: %d\t\t\t\n", Amount);
printf("======================================================================================================\n");
    fprintf(file, "Total Charges: %d\n", Amount);
    fclose(file);
}


// Function to display available seats
void availableseats(bus seats[], int seatnumber, const char* filename) {
    FILE* file = fopen(filename, "r");
    printf("\n--- Available Seats ---\n");
    for (int i = 0; i < seatnumber; i++) {
        int result = fscanf(file, "%d %d", &seats[i].numseat, &seats[i].isreserved);
        // Read the passenger name using fgets to handle spaces in the name
        fgets(seats[i].passengername, MAX_PASSENGER_NAME_LENGTH, file);
        if (!seats[i].isreserved) {
            printf("\n\n\t\t\tSeat %d: Available\n", seats[i].numseat);
        }
    }
    fclose(file);
}
// Function to handle seat cancellations
void cancelreservation(bus seats[], int busseatnumber,int refund, const char* filename) {
    int seatstocancel;
    int seatNumber;
    int trefundamount=0;
    printf("Enter Total seats you want to cancel:\n");
    scanf("%d",&seatstocancel);
    for (int i=1;i<=seatstocancel;i++)
    {
        printf("Enter the seat number you want to cancel reservation: ");
    scanf("%d", &seatNumber);
    if (seatNumber < 1 || seatNumber > busseatnumber || !seats[seatNumber - 1].isreserved) {
        printf("Invalid or unreserved seat. Please enter a valid seat number.\n");
        return;
    }
    // Adjust seatNumber to match array index
     seatNumber--;
    FILE* file = fopen(filename, "w+");
    for (int i = 0; i < busseatnumber; ++i) {
        if (i == seatNumber) {
            seats[i].isreserved = false;
            seats[i].passengername[0] = '\0';
            printf("Reservation for Seat %d canceled successfully.\n", seatNumber + 1);
        }
        fprintf(file, "%d\t\t %d\t\t %s\t\t\n", seats[i].numseat, seats[i].isreserved, seats[i].passengername);
    }
     trefundamount+=refund;
     printf("\n\n");
printf("======================================================================================================\n");
     printf("\t\t\t\tYour Payment will refund you: %d\t\t\t\n", refund);
printf("======================================================================================================\n");
     fprintf(file, "Total Refund Amount: %d\n",trefundamount);
    fclose(file);
    } 
}
// Function to prompt user to choose a bus for seat cancellation
void cancelseatsinbus() {
    printf("From Which Bus you want to cancel reservation: \n");
    printf("1. Bus which has 40 seats\n");
    printf("2. Bus which has 60 seats\n");
    printf("3. Bus which has 72 seats\n");
    printf("4. Bus which has 85 seats\n");
}