// Programmer Name: Jennifer Isobe 
// Program Name: Module 6 - Funtions Project - Euro to US Dollar Converter
// Date: 04/12/2024

#include <stdio.h>

double euroDollarConverter(int conversion, double amount);

int main(void){

// define/initialize variables
  int desiredConversion;
  double amountToConvert;
  int quitCommand = 1;
  double outputAmount;
  int totalConversionsEuroToDollar = 0;
  int totalConversionsDollarToEuro = 0;


// Introduce Program
  printf("\nWelcome to the European Euro and US Dollar converter!\nYou may enter 'q' at any time to exit the converter.\n\n");

// Continue Program until the quit command is entered
  while (quitCommand == 1){

// Get desired conversion type and set value for the quit command. scanf should return 1 if the integers are entered and ) if not
    printf("Please enter (without quotes):\n'1' for Euro to Dollar\n'2' for Dollar to Euro\n'q' to exit\n");

    quitCommand = scanf("%d", &desiredConversion);

// Break from while loop if 'q' is entered
    if(quitCommand == 0){
      break;
    }

// Get amount to convert and set value for the quit command. scanf should return 1 if the integers are entered and ) if not
    printf("\nPlease enter amount to convert or 'q' to exit: ");

    quitCommand = scanf("%lf", &amountToConvert);

// Break from while loop if 'q' is entered
    if(quitCommand == 0){
      break;
    }

// Call converter
    outputAmount = euroDollarConverter(desiredConversion, amountToConvert);

// Print the output for the desired conversion with orginal amount and converted amount. Increment the count for conversions of that type
    if (desiredConversion == 1){
      // Euro to dollar
      printf("\n%0.2lf European Euros are worth %0.2lf US Dollars\n\n", amountToConvert, outputAmount);
      totalConversionsEuroToDollar++;
    }else{
      // Dollar to euro
      printf("\n%0.2lf US Dollars are worth %0.2lf European Euros\n\n", amountToConvert, outputAmount);
      totalConversionsDollarToEuro++;
    }
  }

// Exit message. Print the total conversions for each type:
  printf("\nThank you for using the converter program\n\n");

// Euro to dollar total with either plural or singular
  if(totalConversionsEuroToDollar == 1){
    printf("You have completed:\n%d conversion from European Euros to US Dollars", totalConversionsEuroToDollar);
  }else{
    printf("You have completed:\n%d conversions from European Euros to US Dollars", totalConversionsEuroToDollar);
  }

// Dollar to euro with either plural or singular
  if(totalConversionsDollarToEuro == 1){
  printf("\n%d conversion from US Dollars to European Euros\n",totalConversionsDollarToEuro);
  }else{
    printf("\n%d conversions from US Dollars to European Euros\n", totalConversionsDollarToEuro);
  }

  printf("Goodbye!");

  return 0;
}

// Conversion function
double euroDollarConverter(int conversion, double amount){

// Define/initialize variables
  const double EURO_DOLLAR_CONVERTION_RATE = 1.0623605; //1 Euro = 1.0623605 Dollars
  double convertedAmount;

// If the desired conversion is Euro to dollar (input 1) multiply amount by rate
// otherwise, the desired conversion is from dollar to euro (input 2) so divide amount by rate
  if (conversion == 1){
    // Euro to dollar
    convertedAmount = amount * EURO_DOLLAR_CONVERTION_RATE;
  }else{
    // Dollar to euro
    convertedAmount = amount / EURO_DOLLAR_CONVERTION_RATE;
  }

  return convertedAmount;
}