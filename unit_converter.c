/*
 * unit_converter.c
 *
 * A program that converts temperature and
 * US or Canadian dollars to a few other
 * currencies.
 *
 * author: Ryan Morehouse
 * license: MIT
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CURRENCY REFERENCE STRUCTS
struct Ref {
  char key[10];
  double value;
};

struct Map {
  struct Ref refs[9];
} CAD, USD, EURO, JPY, GBP, AUD, CHF, CNH, SEK, NZD;

// INITIALIZATION FOR CURRENCY REFERENCE STRUCTS
void initialize_currency() {
  // Canadian Dollars
  strcpy(CAD.refs[0].key, "USD");
  strcpy(CAD.refs[1].key, "EURO");
  strcpy(CAD.refs[2].key, "JPY");
  strcpy(CAD.refs[3].key, "GBP");
  strcpy(CAD.refs[4].key, "AUD");
  strcpy(CAD.refs[5].key, "CHF");
  strcpy(CAD.refs[6].key, "CNH");
  strcpy(CAD.refs[7].key, "SEK");
  strcpy(CAD.refs[8].key, "NZD");
  CAD.refs[0].value = 0.76;
  CAD.refs[1].value = 0.68;
  CAD.refs[2].value = 82.43;
  CAD.refs[3].value = 0.61;
  CAD.refs[4].value = 1.09;
  CAD.refs[5].value = 0.75;
  CAD.refs[6].value = 5.26;
  CAD.refs[7].value = 7.12;
  CAD.refs[8].value = 1.14;
  
  // US Dollars
  strcpy(USD.refs[0].key, "CAD");
  strcpy(USD.refs[1].key, "EURO");
  strcpy(USD.refs[2].key, "JPY");
  strcpy(USD.refs[3].key, "GBP");
  strcpy(USD.refs[4].key, "AUD");
  strcpy(USD.refs[5].key, "CHF");
  strcpy(USD.refs[6].key, "CNH");
  strcpy(USD.refs[7].key, "SEK");
  strcpy(USD.refs[8].key, "NZD");
  USD.refs[0].value = 1.31;
  USD.refs[1].value = 0.89;
  USD.refs[2].value = 107.74;
  USD.refs[3].value = 0.79;
  USD.refs[4].value = 1.42;
  USD.refs[5].value = 0.98;
  USD.refs[6].value = 6.88;
  USD.refs[7].value = 9.31;
  USD.refs[8].value = 1.49;
  
  // Euros
  strcpy(EURO.refs[0].key, "CAD");
  strcpy(EURO.refs[1].key, "USD");
  strcpy(EURO.refs[2].key, "JPY");
  strcpy(EURO.refs[3].key, "GBP");
  strcpy(EURO.refs[4].key, "AUD");
  strcpy(EURO.refs[5].key, "CHF");
  strcpy(EURO.refs[6].key, "CNH");
  strcpy(EURO.refs[7].key, "SEK");
  strcpy(EURO.refs[8].key, "NZD");
  EURO.refs[0].value = 1.48;
  EURO.refs[1].value = 1.13;
  EURO.refs[2].value = 121.6;
  EURO.refs[3].value = 0.9;
  EURO.refs[4].value = 1.6;
  EURO.refs[5].value = 1.11;
  EURO.refs[6].value = 7.76;
  EURO.refs[7].value = 10.51;
  EURO.refs[8].value = 1.68;
  
  // Japanese Yen
  strcpy(JPY.refs[0].key, "CAD");
  strcpy(JPY.refs[1].key, "USD");
  strcpy(JPY.refs[2].key, "EURO");
  strcpy(JPY.refs[3].key, "GBP");
  strcpy(JPY.refs[4].key, "AUD");
  strcpy(JPY.refs[5].key, "CHF");
  strcpy(JPY.refs[6].key, "CNH");
  strcpy(JPY.refs[7].key, "SEK");
  strcpy(JPY.refs[8].key, "NZD");
  JPY.refs[0].value = 0.012;
  JPY.refs[1].value = 0.0093;
  JPY.refs[2].value = 0.0082;
  JPY.refs[3].value = 0.0074;
  JPY.refs[4].value = 0.013;
  JPY.refs[5].value = 0.0091;
  JPY.refs[6].value = 0.064;
  JPY.refs[7].value = 0.086;
  JPY.refs[8].value = 0.014;
  
  // Great Britain Pounds
  strcpy(GBP.refs[0].key, "CAD");
  strcpy(GBP.refs[1].key, "USD");
  strcpy(GBP.refs[2].key, "EURO");
  strcpy(GBP.refs[3].key, "JPY");
  strcpy(GBP.refs[4].key, "AUD");
  strcpy(GBP.refs[5].key, "CHF");
  strcpy(GBP.refs[6].key, "CNH");
  strcpy(GBP.refs[7].key, "SEK");
  strcpy(GBP.refs[8].key, "NZD");
  GBP.refs[0].value = 1.64;
  GBP.refs[1].value = 1.26;
  GBP.refs[2].value = 1.11;
  GBP.refs[3].value = 135.46;
  GBP.refs[4].value = 1.79;
  GBP.refs[5].value = 1.24;
  GBP.refs[6].value = 8.65;
  GBP.refs[7].value = 11.7;
  GBP.refs[8].value = 1.87;
  
  // Australian Dollars
  strcpy(AUD.refs[0].key, "CAD");
  strcpy(AUD.refs[1].key, "USD");
  strcpy(AUD.refs[2].key, "EURO");
  strcpy(AUD.refs[3].key, "JPY");
  strcpy(AUD.refs[4].key, "GBP");
  strcpy(AUD.refs[5].key, "CHF");
  strcpy(AUD.refs[6].key, "CNH");
  strcpy(AUD.refs[7].key, "SEK");
  strcpy(AUD.refs[8].key, "NZD");
  AUD.refs[0].value = 0.92;
  AUD.refs[1].value = 0.7;
  AUD.refs[2].value = 0.62;
  AUD.refs[3].value = 75.81;
  AUD.refs[4].value = 0.56;
  AUD.refs[5].value = 0.69;
  AUD.refs[6].value = 4.84;
  AUD.refs[7].value = 6.55;
  AUD.refs[8].value = 1.05;
  
  // Swiss Francs
  strcpy(CHF.refs[0].key, "CAD");
  strcpy(CHF.refs[1].key, "USD");
  strcpy(CHF.refs[2].key, "EURO");
  strcpy(CHF.refs[3].key, "JPY");
  strcpy(CHF.refs[4].key, "GBP");
  strcpy(CHF.refs[5].key, "AUD");
  strcpy(CHF.refs[6].key, "CNH");
  strcpy(CHF.refs[7].key, "SEK");
  strcpy(CHF.refs[8].key, "NZD");
  CHF.refs[0].value = 1.33;
  CHF.refs[1].value = 1.01;
  CHF.refs[2].value = 0.9;
  CHF.refs[3].value = 109.3;
  CHF.refs[4].value = 0.81;
  CHF.refs[5].value = 1.44;
  CHF.refs[6].value = 6.98;
  CHF.refs[7].value = 9.44;
  CHF.refs[8].value = 1.51;
  
  // Chinese Renminbi
  strcpy(CNH.refs[0].key, "CAD");
  strcpy(CNH.refs[1].key, "USD");
  strcpy(CNH.refs[2].key, "EURO");
  strcpy(CNH.refs[3].key, "JPY");
  strcpy(CNH.refs[4].key, "GBP");
  strcpy(CNH.refs[5].key, "AUD");
  strcpy(CNH.refs[6].key, "CHF");
  strcpy(CNH.refs[7].key, "SEK");
  strcpy(CNH.refs[8].key, "NZD");
  CNH.refs[0].value = 0.19;
  CNH.refs[1].value = 0.15;
  CNH.refs[2].value = 0.13;
  CNH.refs[3].value = 15.66;
  CNH.refs[4].value = 0.12;
  CNH.refs[5].value = 0.21;
  CNH.refs[6].value = 0.14;
  CNH.refs[7].value = 1.35;
  CNH.refs[8].value = 0.22;
  
  // Swedish Krona
  strcpy(SEK.refs[0].key, "CAD");
  strcpy(SEK.refs[1].key, "USD");
  strcpy(SEK.refs[2].key, "EURO");
  strcpy(SEK.refs[3].key, "JPY");
  strcpy(SEK.refs[4].key, "GBP");
  strcpy(SEK.refs[5].key, "AUD");
  strcpy(SEK.refs[6].key, "CHF");
  strcpy(SEK.refs[7].key, "CNH");
  strcpy(SEK.refs[8].key, "NZD");
  SEK.refs[0].value = 0.14;
  SEK.refs[1].value = 0.11;
  SEK.refs[2].value = 0.095;
  SEK.refs[3].value = 11.57;
  SEK.refs[4].value = 0.085;
  SEK.refs[5].value = 0.15;
  SEK.refs[6].value = 0.11;
  SEK.refs[7].value = 0.74;
  SEK.refs[8].value = 0.16;
  
  // New Zealand Dollar
  strcpy(NZD.refs[0].key, "CAD");
  strcpy(NZD.refs[1].key, "USD");
  strcpy(NZD.refs[2].key, "EURO");
  strcpy(NZD.refs[3].key, "JPY");
  strcpy(NZD.refs[4].key, "GBP");
  strcpy(NZD.refs[5].key, "AUD");
  strcpy(NZD.refs[6].key, "CHF");
  strcpy(NZD.refs[7].key, "CNH");
  strcpy(NZD.refs[8].key, "SEK");
  NZD.refs[0].value = 0.88;
  NZD.refs[1].value = 0.67;
  NZD.refs[2].value = 0.59;
  NZD.refs[3].value = 72.33;
  NZD.refs[4].value = 0.53;
  NZD.refs[5].value = 0.95;
  NZD.refs[6].value = 0.66;
  NZD.refs[7].value = 4.62;
  NZD.refs[8].value = 6.25;
}

// MAP REFERENCE FOR CURRENCY STRUCTS
double reference_map(struct Map map, char *currency) {
  // iterate through the 9 conversions
  for(int i = 0; i < 9; i++) {
    int compare = strcmp(map.refs[i].key, currency);
    if(compare == 0)
      return map.refs[i].value;
  }
  
  // reference not found
  return 0.0;
}

// quick test of one currency struct
void test_usd() {
  char *currency = "USD";
  double conversions[9];
  conversions[0] = reference_map(USD, "CAD");
  conversions[1] = reference_map(USD, "EURO");
  conversions[2] = reference_map(USD, "JPY");
  conversions[3] = reference_map(USD, "GBP");
  conversions[4] = reference_map(USD, "AUD");
  conversions[5] = reference_map(USD, "CHF");
  conversions[6] = reference_map(USD, "CNH");
  conversions[7] = reference_map(USD, "SEK");
  conversions[8] = reference_map(USD, "NZD");
  
  printf("Test Currency Structs and Methods:\n");
  printf("USD to CAD: %f\n", conversions[0]);
  printf("USD to EURO: %f\n", conversions[1]);
  printf("USD to JPY: %f\n", conversions[2]);
  printf("USD to GBP: %f\n", conversions[3]);
  printf("USD to AUD: %f\n", conversions[4]);
  printf("USD to CHF: %f\n", conversions[5]);
  printf("USD to CNH: %f\n", conversions[6]);
  printf("USD to SEK: %f\n", conversions[7]);
  printf("USD to NZD: %f\n", conversions[8]);
}

// MENU FUNCTIONS
double get_double(char *prompt) {
  while(1) {
    char input[10];
    printf("%s", prompt);
    fgets(input, 10, stdin);
    double d = atof(input);
    if(d == 0.0) {
      if (input[0] == '0')
        return d;
      else
        printf("Invalid selection, please try again.\n");
    } else {
      return d;
    }
  }
}

int get_menu_selection(char *prompt, int max) {
  while(1) {
    char input[10];
    printf("%s", prompt);
    fgets(input, 10, stdin);
    int i = atoi(input);
    if(i != 0 && i > 0 && i <= max)
      return i;
    else
      printf("Invalid selection, please try again.\n");
  }
}

// TEMPERATURE FUNCTIONS
double convert_kelvin(double k, int new_units) {
  if (new_units == 1)
    return k - 273.0;
  else if(new_units == 2)
    return ((9.0/5.0) * (k - 273.0)) + 32.0;
  else
    return k;
}

double convert_fahrenheit(double f, int new_units) {
  if (new_units == 1)
    return (f - 32.0) * (5.0/9.0);
  else if (new_units == 2)
    return f;
  else
    return 273.0 + ((5.0/9.0) * (f - 32.0));
}

double convert_celsius(double c, int new_units) {
  if (new_units == 1)
    return c;
  else if (new_units == 2)
    return (9.0 * c / 5.0) + 32.0;
  else
    return c + 273.0;
}

// PRIMARY CONVERSION MENUS
void temp_menu() {
  char *temp_menu_1 = "\n---Temperature Converter---\n"
                      "Please select a unit to convert from:\n"
                      "1: Celsius\n"
                      "2: Fahrenheit\n"
                      "3: Kelvin\n"
                      "4: Quit and Return to Main Menu\n";
  
  char *temp_menu_2 = "\nPlease select a unit to convert to:\n"
                      "1: Celsius\n"
                      "2: Fahrenheit\n"
                      "3: Kelvin\n"
                      "4: Quit and Return to Main Menu\n";
  
  char *temp_input_prompt = "\nEnter a temperature to convert: ";

  int selection = get_menu_selection(temp_menu_1, 4);
  if(selection < 4) {
    // stub
    printf("Your Selection: %d\n", selection);
    int selection_2 = get_menu_selection(temp_menu_2, 4);
    if(selection_2 < 4) {
      // get new temp
      double temp = get_double(temp_input_prompt); 
      double new_temp;
      switch(selection) {
        case 1:
          new_temp = convert_celsius(temp, selection_2);
          break;
        case 2:
          new_temp = convert_fahrenheit(temp, selection_2);
          break;
        case 3:
          new_temp = convert_kelvin(temp, selection_2);
          break;
      }

      // get new temp unit name
      char *new_units;
      switch(selection_2) {
        case 1:
          new_units = "Celsius";
          break;
        case 2:
          new_units = "Fahrenheit";
          break;
        case 3:
          new_units = "Kelvin";
          break;
      }

      printf("\nThat converts to %f %s\n", new_temp, new_units);
      return;
    }

    else // quit selected from nested temp menu
      return;
  }

  else // quit selected from temp menu
    return;
}

void currency_menu() {
  char *currency_menu_1 = "\n---Currency Converter---\n"
    "Please select a currency to convert from:\n"
    "1: CAD\n"
    "2: USD\n"
    "3: EURO\n"
    "4: JPY\n"
    "5: GBP\n"
    "6: AUD\n"
    "7: CHF\n"
    "8: CNH\n"
    "9: SEK\n"
    "10: NZD\n"
    "11: Quit and Return to Main Menu\n";
  
  char *currency_menu_2 = "\n---Currency Converter---\n"
    "Please select a currency to convert to:\n"
    "1: CAD\n"
    "2: USD\n"
    "3: EURO\n"
    "4: JPY\n"
    "5: GBP\n"
    "6: AUD\n"
    "7: CHF\n"
    "8: CNH\n"
    "9: SEK\n"
    "10: NZD\n"
    "11: Quit and Return to Main Menu\n";
  
  char *amount_prompt = "Please enter an amount of currency to convert: ";

  int selection_1 = get_menu_selection(currency_menu_1, 11);
  if(selection_1 < 11) {
    int selection_2 = get_menu_selection(currency_menu_2, 11);
     
    if(selection_1 == selection_2) {
      printf("Same currency, no conversion required.\n");
      return;
    }
  
    else if(selection_2 < 11) {
      double amount = get_double(amount_prompt);
      double factor;

      // get new currency code
      char *new_code;
      switch(selection_2) {
        case 1:
          new_code = "CAD";
          break;
        case 2:
          new_code = "USD";
          break;
        case 3:
          new_code = "EURO";
          break;
        case 4:
          new_code = "JPY";
          break;
        case 5:
          new_code = "GBP";
          break;
        case 6:
          new_code = "AUD";
          break;
        case 7:
          new_code = "CHF";
          break;
        case 8:
          new_code = "CNH";
          break;
        case 9:
          new_code = "SEK";
          break;
        case 10:
          new_code = "NZD";
          break;
      }

      // get conversion factor and old code
      char *old_code;
      switch(selection_1) {
        case 1:
          factor = reference_map(CAD, new_code);
          old_code = "CAD";
          break;
        case 2:
          factor = reference_map(USD, new_code);
          old_code = "USD";
          break;
        case 3:
          factor = reference_map(EURO, new_code);
          old_code = "EURO";
          break;
        case 4:
          factor = reference_map(JPY, new_code);
          old_code = "JPY";
          break;
        case 5:
          factor = reference_map(GBP, new_code);
          old_code = "GBP";
          break;
        case 6:
          factor = reference_map(AUD, new_code);
          old_code = "AUD";
          break;
        case 7:
          factor = reference_map(CHF, new_code);
          old_code = "CHF";
          break;
        case 8:
          factor = reference_map(CNH, new_code);
          old_code = "CNH";
          break;
        case 9:
          factor = reference_map(SEK, new_code);
          old_code = "SEK";
          break;
        case 10:
          factor = reference_map(NZD, new_code);
          old_code = "NZD";
          break;
      }
      
      // get new currency and print results
      double new_amount = amount * factor;
      printf("%f %s = %f %s\n", amount, old_code, new_amount, new_code);
      return;
    }
  
    else
      return; // quit selected from nested menu
  }
  
  else
    return; // quit selected from top menu
}

int main() {
  initialize_currency();
  
  char *top_menu =  "\n---Unit Converter---\nSelect a unit type from the menu:\n"
                    "1: \"Temperature\"\n"
                    "2: \"Currency\"\n"
                    "3: \"Quit\"\n";
  
  // main menu loop
  while(1) {
    int selection = get_menu_selection(top_menu, 3);
    if(selection == 1)
      temp_menu();
    else if(selection == 2)
      currency_menu();
    else 
      break;
  }
  return 0;
}
