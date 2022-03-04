# Mini_talk

## Checklist
- Understand Pid/Processes
- Understand KILL
- Understand Signal
- Understand SIGUSR1 & SIGUSR2
- Understand bit shifting and operations

## Helpful links
Pay attention to what kill and signal do
- https://www.youtube.com/watch?v=83M5-NPDeWs&list=TLPQMDIwMzIwMjKHMUoSdBrXow&index=1

Should supplement what you learnt from previous video, as well as introduce SIGUSR1 & SIGUSR2
- https://www.youtube.com/watch?v=PErrlOx3LYE&list=TLPQMDIwMzIwMjKHMUoSdBrXow&index=2

Understanding proccesses and pid
- https://www.youtube.com/watch?v=ss1-REMJ9GA

You don't have to watch the whole video on bit shifing
- https://www.youtube.com/watch?v=oCBlwsY8sR4&list=TLPQMDIwMzIwMjKHMUoSdBrXow&index=4

Decent explanation of bitwise operations
- https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
- 
## Code Implementation Breakdown 

### Server.c
Step 1. Reset/Initialise data structure variables. One variable will hold whole binary for one character, the other variable will count binary digits.

Step 2. Produce and print Pid (Pid will be used by client).

Step 7. The signal function waits until it recieves an appropriate signal from KILL (these signals are SIGUSR1 & SIGUSR2), these signals represent 1 or 0. So using these signals in the handler function in server we are able to recieve transmitted binary of the character from client. Once we have recieved eight binary digits we can then write onto the command line.

### Client.c
Step 3. Check arguements from command line as client takes in pid from server and the message you want to display.

Step 4. Convert Pid to int.

Step 5. Send the message to a function that sends each character in that message to another function that converts each character to its binary equivalent.

Step 6. The function that converts to binary sends a KILL signal type of SIGNUSR1 or SIGNUSR2 depending on the binary digit. KILL also takes in Pid as a parameter, so the signal is sent to the Pid of the server.
