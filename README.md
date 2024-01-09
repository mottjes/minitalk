# minitalk

### Description

The purpose of this project is to code a small data exchange program using UNIX signals.

It is a simple communication program in the form of a client and a server.
The client sends a message to the server, which receives and prints it on the screen.

For more detail: The subject pdf is inside of the project folder.

### How to run

1. compile and create the excutables:
```bash
make
```

2. Run the server and copy its PID to the client with the message you want to send:
```bash
./server
```
```bash
./client <SERVER_PID> <Your message here>
```
