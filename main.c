#include <stdio.h>
// the following includes have header files you won't need to use,
// i'm using them for stuff you must ignore
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "parser.h"
#include "helpers.h"
#include "api.h"

// --- FEATURE FUNCTIONS ---

// --- IGNORE ALL THESE FUNCTIONS, THEY DO NOT
// CONCERN YOU, THEY ARE JUST FOR THE APP TO WORK ---
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// FEATURE 0: PRINT BUS LINES (GENERAL)

int streak = 0;


void print_bus_lines() {
  printf("\n---------------------------------------------------\n");
  printf("Bus Lines:\n");
  int indices[6] = {0, 2, 4, 6, 7, 9};
  for (int i = 0; i < 6; i++) {
    int j = indices[i];
    printf("%s\n", bus_lines[j]);
  }
  printf("Write the number of the bus line you want to choose OR press 0 to go back.\n");
  return;
}

// FEATURE 1: PRINT DEPARTURES
void print_departures(int bus_index) {
  printf("\n---------------------------------------------------\n");
  int i = 1;
  while (i < departures[bus_index][0][1]) {
    printf("%02d:%02d\n", departures[bus_index][i][0], departures[bus_index][i][1]);
    i++;
  }
  printf("Press Enter to go back to the main menu...\n");
  getchar();
  getc(stdin);
  clearScreen();
  return;
}

void departures_menu() {
  clearScreen();
  print_bus_lines();
  int bus_choice;
  scanf("%d", &bus_choice);
  // go back if 0 is pressed
  if (bus_choice == 0) return;
  int direction = 0;
  if (bus_choice != 250 && bus_choice != 666) {
    direction = find_direction();
  }
  int bus_index = index_of_bus(bus_choice, direction);
  clearScreen();
  print_departures(bus_index);
  return;
}


// FEATURE 2: PRINT ARRIVALS

void individual_stop_arrivals(int stop_index, int arrival_index) {
  clearScreen();
  int* local_time = grab_local_time();
  printf("\n---------------------------------------------------\n");
  printf("%s:\n", bus_stops[stop_index][1]);
  // find which bus lines pass through this stop
  int i = 0;
  int stop_code = atoi(bus_stops[stop_index][0]);
  int* bus_lines_that_pass_through_stop = find_bus_lines_for_stop(stop_code, &i);
  int* arrival_times = NULL;
  printf("\n- - - - - - - - - - - - - - - - - - - - - - -\n");
  for (int j = 0; j < i; j++) {
    int bus_index = bus_lines_that_pass_through_stop[j];
    arrival_times = list_of_arrival_times_two_hour_window(local_time, arrival_index, bus_index);
    printf("%s \t ", bus_lines[bus_index]);
    if (arrival_times) {
      printf("in ");
      for (int k = 0; k < 15 && arrival_times[k] >= 0; k++) {
        printf("%d ", arrival_times[k]);
      }
      printf("minutes\n");
      free(arrival_times);
    }
    arrival_times = NULL;
    printf("\n- - - - - - - - - - - - - - - - - - - - - - -\n");
  }
  free(bus_lines_that_pass_through_stop);
  free(local_time);
  printf("Press R to refresh the arrivals OR press Enter to go back to the main menu...\n");
  char choice;
  getchar();
  choice = getc(stdin);
  if (choice == 'R' || choice == 'r') {
    individual_stop_arrivals(stop_index, arrival_index);
  }
  return;
}

void print_arrivals(int bus_index, int* bus_indices, int num_stops) {
  clearScreen();
  printf("\n---------------------------------------------------\n");
  printf("%s:\n", bus_lines[bus_index]);
  int i = 0;
  while (i < num_stops) {
    int stop_index = bus_indices[i];
    printf("%d. %s\n", i + 1, bus_stops[stop_index][1]);
    i++;
  }
  printf("\n---------------------------------------------------\n");
  printf("Enter the number of the stop you want to choose:\n");
  scanf("%d", &i);
  if (i < 1 || i > num_stops) {
    printf("Wrong Input! Try again.\n");
    print_arrivals(bus_index, bus_indices, num_stops);
    return;
  }
  int stop_index = bus_indices[i - 1];
  individual_stop_arrivals(stop_index, i - 1);
  clearScreen();
  return;
}

void arrivals_menu() {
  clearScreen();
  print_bus_lines();
  int bus_choice;
  scanf("%d", &bus_choice);
  // go back if 0 is pressed
  if (bus_choice == 0) return;
  int direction = 0;
  if (bus_choice != 250 && bus_choice != 666) {
    direction = find_direction();
  }
  int bus_index = index_of_bus(bus_choice, direction);
  int num_stops = 0;
  int* bus_indices = grab_bus_indices(bus_index, &num_stops);
  print_arrivals(bus_index, bus_indices, num_stops);
  return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// --- IGNORE UP UNTIL HERE, THE ABOVE FUNCTIONS ARE JUST FOR THE APP TO WORK ---

// --- THIS IS WHAT YOU HAVE TO DO, PAY ATTENTION
// TO THE BELOW FUNCTION!!! ---
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// FEATURE 3 -> YOUR TASK: ADD YOUR FEATURE FUNCTION HERE
void your_awesome_feature_menu() {
  clearScreen();
  printf("\n---------------------------------------------------\n");
  printf("ADD REPORT - CHOOSE LINE\n");

  print_bus_lines();
  int bus_choice;
  scanf("%d", &bus_choice);
  // go back if 0 is pressed
  if (bus_choice == 0) return;
  int direction = 0;
  if (bus_choice != 250 && bus_choice != 666) {
    direction = find_direction();
  }
  int bus_index = index_of_bus(bus_choice, direction);
  int num_stops = 0;
  int* bus_indices = grab_bus_indices(bus_index, &num_stops);


  clearScreen();
  printf("\n---------------------------------------------------\n");
  printf("%s:\n", bus_lines[bus_index]);
  int i = 0;
  while (i < num_stops) {
    int stop_index = bus_indices[i];
    printf("%d. %s\n", i + 1, bus_stops[stop_index][1]);
    i++;
  }
  printf("\n---------------------------------------------------\n");
  printf("Enter the number of the stop you want to choose:\n");
  scanf("%d", &i);
  if (i < 1 || i > num_stops) {
    printf("Wrong Input! Try again.\n");
    print_arrivals(bus_index, bus_indices, num_stops);
    return;
  }
  int stop_index = bus_indices[i - 1];
  clearScreen();
  
  printf("\n---------------------------------------------------\n");
  printf("Give your report: \n");
  printf("\n---------------------------------------------------\n\n");

  float crowd_of_people;
  printf("Were you satisfied with how crowded the bus was (1 - 10): ");
  scanf(" %f", &crowd_of_people);

  float personnel;
  printf("How was the personnel (1 - 10): ");
  scanf(" %f", &personnel);

  float condition;
  printf("How was the condition of the bus (1 - 10): ");
  scanf(" %f", &condition);

  printf("Bus: %d\n", bus_choice);
  printf("Direction: %s\n", get_bus_line_name(bus_choice, direction));
  printf("Nearest stop: %s\n", get_stop_name_on_line( bus_choice,  direction,  i));
  printf("Report Event Time: %d:%d. \n", get_current_hour(), get_current_minute());
  printf("Report average: %0.2f\n\n", (crowd_of_people + personnel + condition)/3);

  FILE *reporttxt;

  reporttxt = fopen("reports.txt", "a");

  fprintf(reporttxt, "%d,%s,%s,%d:%d,%0.2f\n", bus_choice, get_bus_line_name(bus_choice, direction), get_stop_name_on_line( bus_choice,  direction,  i), get_current_hour(), get_current_minute(), (crowd_of_people + personnel + condition)/3);

  fclose(reporttxt);
  streak++;
  if (streak == 10){
    printf("\n---------------------------------------------------\n");
    printf("CONGRATULATIONS!! You earned a free ticket with  the following code <code> !!! Thanks for your reports!\n");
    printf("\n---------------------------------------------------\n\n");
    streak = 0;

  }else{
    printf("\n---------------------------------------------------\n");
    printf("Report sent! You're on a %d day streak. %d days left for your reward.\n", streak, (10-streak));
    printf("\n---------------------------------------------------\n\n");
  }

  printf("\n---------------------------------------------------\n");
  printf("ALL REPORTS\n");
  printf("\n---------------------------------------------------\n\n");

  FILE *fptr;


  fptr = fopen("reports.txt", "r");
  char myString[300];

  while(fgets(myString, 300, fptr)) {
    printf("%s", myString);
  }

  fclose(fptr);



  printf("\n\nPress Enter to go back to the main menu...\n");
  getchar();
  getc(stdin);
  clearScreen();


  
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// --- FEATURE FUNCTIONS END ---

// -- ALSO IGNORE THE BELOW FUNCTIONS, THEY ARE JUST FOR THE APP TO WORK ---
// function for the printing of the home page
void homepage() {
  printf("\n---------------------------------------------------\n");
  printf("You are at the homepage of the OASA app.\n");
  printf("Choose an option:\n");
  printf("Bus Departures (Press 1) | Bus Stops Arrivals (Press 2) | Add Report / Show All (Press 3) | Press 0 to exit the app. \n");
  int choice = 0;
  // user-input
  scanf("%d", &choice);
  // switch statement -> choice of the user
  switch (choice) {
  case 0:
    return;
  case 1:
    departures_menu();
    break;
  case 2:
    arrivals_menu();
    break;
  case 3:
    your_awesome_feature_menu();
    break;
  // default case -> in case the choice input is invalid
  default:
    //fflush(stdin);
    // calls the function itself again to print the above again
    printf("Wrong Input. Try again.\n");
  }
  clearScreen();
  homepage();
  // ends function and goes back to main
  return;
}

// main function
int main() {
  // parsing -- ignore
  parse_departures();
  parse_stops();
  match_stops_with_lines();
  // calls the homepage function
  homepage();


  // freeing -- ignore
  free_departures();
  free_bus_stops();
  return 0;
}