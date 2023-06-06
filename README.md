# Personal ATM Simulator

This is a simple Java program that simulates an ATM (Automated Teller Machine). It allows users to perform operations such as withdrawing money, checking their account balance, and changing their PIN (Personal Identification Number).

## Usage Instructions

1. Clone this repository to your local machine.
2. Open the `Cajero.java` file in your Java development environment.
3. Compile and run the program.

## Features

The program offers the following options:

1. **Withdraw Money**: Allows the user to withdraw a specific amount of money from their account balance.
2. **Check Account Balance**: Displays the user's current account balance.
3. **Change PIN**: Allows the user to change their PIN.

## Code Structure

The code is organized into the following classes:

- `Cajero`: This class contains the main `main` method and is responsible for displaying the menu options to the user and calling the corresponding classes to handle different operations.
- `RetiroDeDinero`: This class handles the functionality of withdrawing money. It verifies if the requested amount is valid and updates the account balance if the withdrawal is confirmed.
- `ConsultaDeSaldo`: This class is responsible for displaying the user's current account balance.
- `CambioDeNIP`: This class manages the PIN change process. It verifies the previous PIN and then prompts for and validates the new PIN.

## Why Use This Simulator?

- **Practice**: Utilize this program to practice Java programming concepts, such as object-oriented programming, user input handling, and conditional statements.
- **Portfolio**: Include this project in your portfolio to demonstrate your skills in Java development and software engineering.
- **Learning**: Explore the code to gain a better understanding of how an ATM system can be implemented in Java.

## Personalize and Customize

Feel free to customize and modify the code to suit your needs. You can add additional features, improve user experience, or enhance the overall functionality.

## Conclusion

Using this personal ATM simulator, you can gain hands-on experience with Java programming while simulating real-life banking operations. Enjoy exploring the world of software development and best of luck with your job search!

Please note that this is a simulated ATM program and should not be used for actual banking transactions.
