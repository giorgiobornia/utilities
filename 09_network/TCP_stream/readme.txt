Simple example of transmission via TCP stream

......... server_tcp.c ............ server TCP 
......... client_tcp.c ............ client TCP 

Goal: 
The client request connection to the server and sends a string.
The server receives the string, moves the characters by 2, and sends it back to the client.
The client receives the moved string and prints it out.


N.B. 
Place the two files on two different hosts, ( ex.: server_tcp.c on host1 and client_tcp.c on host2 ), 

compile, 

first execute server_tcp on host1 (ex: ./server_tcp 5001), 
 then execute client_tcp on host2 (ex: ./client_tcp IP_host1 5001 ), 


N.B. Compiling

--- on linux --- 

gcc -o server_tcp server_tcp.c 
gcc -o client_tcp client_tcp.c 

--- on Solaris --- 

gcc -o server_tcp -lsocket -lnsl server_tcp.c 
gcc -o client_tcp -lsocket -lnsl client_tcp.c 
