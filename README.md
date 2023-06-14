# atm-udp-client-server
This program, implemented in C/C++, simulates an ATM system using UDP communication between a server and multiple clients. The ATM performs three main steps: Card Reading, Pin Verification, and Cash Withdrawal, following a specific sequence.

# PART A - Server-Side
To simulate the ATM system, a server program is designed to handle the following tasks:

The server assigns functionalities to three clients based on the numbers 1, 2, and 3.
Each number corresponds to a specific task:
1: Card Reading
2: Pin Verification
3: Cash Withdrawal
0: Exit (terminates the ATM function)
The server initiates the process and assigns tasks to the clients accordingly.
The clients check the status of the current task and proceed accordingly, querying the server before starting their execution.
A main menu allows users to request ATM withdrawals, where the server generates a random number between 0 and 50000 to represent the customer's current account balance.
The server asks the customer for the withdrawal amount, ensuring it doesn't exceed the current balance (with a withdrawal limit of 25000).
The server generates a random number between 0 and 3. If the number is 0, an error message "Transaction Failed" is reported, and another random number is generated (>0).
The server assigns the tasks to the clients, making sure there are no repetitions in the random numbers assigned to each client.
Once all clients send their acceptance status, the server assigns tasks to the clients in sequence.
After a task is completed, the server prints the IP addresses of each client along with the output of the task performed by the client

# PART B - Client-Side
Each client, after receiving their assigned task, performs the required functionality and sends the output back to the server. The sequence of tasks is as follows:

Client A: Card Reading
Client B: Pin Verification
Client C: Cash Withdrawal


# Running the Program

Compile the server program using the following command:
**gcc server.c -o server**

Compile the client program using the following command:
**gcc client.c -o client**

Run the server executable:
**./server**

Run the client executables in separate terminals or command prompts:
**./client**

Follow the prompts on the client-side and observe the server's output as the ATM simulation progresses.
