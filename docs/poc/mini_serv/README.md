# Notes about mini\_serv

## Purpose

The goal of this program is to create a program that wait for a request on a port and response always the same message.

## Notions

*These are the notions to study, in order, to code this program.*

- Reference video : [Video](https://www.youtube.com/watch?v=esXw4bdaZkc&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=2)
- Send Recv ressources : [Link](https://bousk.developpez.com/cours/reseau-c++/TCP/05-envoi-reception-serveur/)

- All client notions.
- bind() (man 2 bind).
  - Assign a socket to an IP and a Port to listen to it.
- listen() (man 2 listen).
  - Turn the socket in listen mode.
- accept() (man 2 accept).
  - Wait until someone want to connect() to the socket listening.
  - It return an error or a new socket to read in.
- read data with recv() from the socket returned.
- send a response to the socket whith send().

## Usage

*PORT : Specify the port to listen.*

./mini\_client [PORT]

## Expected behavior

If a syscall fail, it will print the syscall involved and exit the program.

Else, it will display on STDOUT the FULL response in ASCII that you recieved.

Your server must response correctly to `localhost:[PORT]` by printing `Hello World !`

Your server must not leak file descriptor.

Code is to put in ./login/*.

## Example

Here a screenshot of a working mini_serv :

- Curl example
![img](https://i.imgur.com/xdPtPdp.jpg)

- Chrome example
  - Request
![img](https://i.imgur.com/mqgYSya.jpg)
  - Server log
![img](https://i.imgur.com/Qw9Gohu.jpg)
