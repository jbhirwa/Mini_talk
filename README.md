# Mini_talk

## Checklist
- Understand Pid
- Understand KILL
- Understand Signal
- Understand SIGUSR1 & SIGUSR2

## Helpful links
Pay attention to what kill and signal do
- https://www.youtube.com/watch?v=83M5-NPDeWs&list=TLPQMDIwMzIwMjKHMUoSdBrXow&index=1

Should supplement what you learnt from previous video, as well as introduce SIGUSR1 & SIGUSR2
- https://www.youtube.com/watch?v=PErrlOx3LYE&list=TLPQMDIwMzIwMjKHMUoSdBrXow&index=2

## Code Implementation Breakdown 

### Server.c
Step 1. Reset/Initialise data structure variables.

Step 2. Produce and print Pid (Pid will be used by client)

Step 7. The signal function waits until it recieves an appropriate signal from KILL (these signals are SIGUSR1 & SIGUSR2), these signals
  
  represent 1 or 0. So using these signals in the handler function we are able to transmit binary of the character from client to server. Once we have recieved
  eight binary digits we can then convert them to characters that we can write onto the command line.

### Client.c
Step 3. Check arguements from command line as client takes in pid from server and the message you want to display.

Step 4. Convert Pid to int

Step 5. Send the message to a function that sends each character in that message to another function that converts each character to its binary equivalent.

Step 6. The function that converts to binary sends a KILL signal either to SIGNUSR1 or SIGNUSR2 depending on the binary digit
