#Notes from https://beej.us/guide/bgnet/

## Sockets

- In Unix, everything is file
- To get a file descriptor for network communication, you use `socket`. You communicate with `send` and `recv`
  - It's like `read` and `write`, but with a much bigger control
- There are many types of sockets, but Internet Sockets are the only relevant ones
  - Raw sockets: to look up
  - Stream sockets (`SOCK_STREAM`): a stream of communication, used e.g. by `telnet` and `ssh`. Order is respected when sending info.
    - TCP garantuees that transmission is sequential and error free.
  - Datagram sockets (`SOCK_DGRAM`): sometimes defined as 'conecctionless'. Doesn't garantuee order. Use UDP instead of TCP. Don't need an open connection like streams. Workarounds are used when reliability is paramount (e.g. ACK packages).
    - Speed is the biggest advantage and that's why it's used e.g. in online gaming

## Data encapsulation

- For each protocol level, packages gets encapsulated.
- Layered Network Model:
  - Application (where users interact with the Network)
  - Presentation
  - Session
  - Transport
  - Network
  - Data link
  - Physical (hardware, e.g. Ethernet)

## IP addresses

- IPv6 was created since we are running out of IP addresses
- `::1` is the IPv6 equivalent of `127.0.0.1` and means 'the maching I'm working on'
- You can represent any IPv4 address in IPv6 by prefixing `::ffff:`

## Subnets

- In IPv4, there is usually a `host` and a `network` part
  - The Netmask describes the network portion

## Port numbers

- TCP and UDP also use port numbers
- It is a level of specifity more than the IP address

## Byte order

- Big Endian vs Little Endian order of storing byte
- For network, sequential order is required
  - For portability, you always convert to Network oder with e.g. `htons` or `htonl`

## Structs

- Socket descriptor is an `int`
- `addrinfo`: prep the socket address structures for subsequent use. One of the first things called when making a connection
  - `sockaddr`: holds socket address information for many types of sockets
    - `sockaddr_in`: parallel structure for IPv4. Can be casted to `sockaddr`. This was it can be used for `connect()`.
    - `sockaddr_storage`: big enoug for IPv4 and IPv6. When you don't know yet.

## IP address manipulation

- `inet_pton` can convert an IP address in numbers and dots to a `in_addr` struct
  - `inet_addr` and `inet_aton` are obsolete and don't work with IPv6
- `inet_ntop` converts a binary representation to numbers and dots
  - `inet_ntoa` is an obsolete way of doing this

## Private networks

- With firewalls, NAT translates internal IP addresses to external
- A household with a firewall can have 2 allocated IP addresses, but locally they can use many other possible values. Translation is done by NAT

## System calls

System calls necessary for networking:

1. `getaddrinfo`: helps setting up structs that are necessary later (`gethostbyname` is legacy)

   ```
   int status;
   struct addrinfo hints;
   struct addrinfo *servinfo;  // will point to the results

   memset(&hints, 0, sizeof hints); // make sure the struct is empty
   hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
   hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
   hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

   if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
       fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
       exit(1);
   }

   // servinfo now points to a linked list of 1 or more struct addrinfos

   // ... do everything until you don't need servinfo anymore ....

   freeaddrinfo(servinfo); // free the linked-list
   ```

1. `socket`: `int socket(int domain, int type, int protocol); `
   - You can choose IPv, stream or datagram, TCP or UDP
   - returns socket descriptor
1. `bind`: associate socket with a port on local machine

   ```
       struct addrinfo hints, *res;
   int sockfd;

   // first, load up address structs with getaddrinfo():

   memset(&hints, 0, sizeof hints);
   hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

   getaddrinfo(NULL, "3490", &hints, &res);

   // make a socket:

   sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

   // bind it to the port we passed in to getaddrinfo():

   bind(sockfd, res->ai_addr, res->ai_addrlen);
   ```

   - All ports below 1024 are reserved
   - Depending on what you want to do, it is not always necessary to call `bind`

1. `connect`

   ```
   struct addrinfo hints, *res;
   int sockfd;

   // first, load up address structs with getaddrinfo():

   memset(&hints, 0, sizeof hints);
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;

   getaddrinfo("www.example.com", "3490", &hints, &res);

   // make a socket:

   sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

   // connect!

   connect(sockfd, res->ai_addr, res->ai_addrlen);
   ```

   - If we don't use `bind`, the kernel will automatically choose a port for us

1. `listen`: if you don't want to connect, but wait for incoming connections
   - `backlog` parameter is the number of connections that can be queued
   - `bind` is required here because you have to be able to predict the port number
1. `accept`: you get another file descriptor where you can send or receive

   - `addr_len` should be equal to `sizeof(struct sockaddr_storage)`

   ```
   #include <string.h>
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netdb.h>

   #define MYPORT "3490"  // the port users will be connecting to
   #define BACKLOG 10     // how many pending connections queue will hold

   int main(void)
   {
       struct sockaddr_storage their_addr;
       socklen_t addr_size;
       struct addrinfo hints, *res;
       int sockfd, new_fd;

       // !! don't forget your error checking for these calls !!

       // first, load up address structs with getaddrinfo():

       memset(&hints, 0, sizeof hints);
       hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
       hints.ai_socktype = SOCK_STREAM;
       hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

       getaddrinfo(NULL, MYPORT, &hints, &res);

       // make a socket, bind it, and listen on it:

       sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       bind(sockfd, res->ai_addr, res->ai_addrlen);
       listen(sockfd, BACKLOG);

       // now accept an incoming connection:

       addr_size = sizeof their_addr;
       new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
   }
   ```

1. `send` and `recv`: only for streams or unconnected data sockets
   - `send` returns the number of bytes actually sent out, it might be less. In this case, rest of data must be sent manually
   - `recv` returns the number of bytes actually read into the buffer. Return `0` if connection was closed
1. `close` and `shutdown`
   - `shutdown` allows for a finer control on how to limit use of socket
1. `getpeername`: tells you who is at other end of connection
   - `inet_ntop`, `getnameinfo`, or `gethostbyaddr` to get more information
1. `gethostname` to get the name of the host

## Client-server background

- A server can handle multiple clients with `fork`
- See POC for live example

## Blocking

- Blocking is techie jargon for sleeping
- When setting a socket to non-blocking, you can "poll" for information
- `poll` can be used to see if there's data waiting to be read
  - You can monitor more sockets at once and handle those with data ready
  - It is not otpmised for a big number of connections
  - In `struct pollfd` we can specify which sockets to monitor and what kind of events
    - `POLLIN` for receiving, `POLLOUT` for sending
  - Returns the number of element for which events have occurred

- `select`: monitor several sockets at the same times and tell you which are ready for reading, writing, and raised exceptions
  - `FD_SET`: add `fd` to set
  - `FD_CLR`: remove `fd` from set
  - `FD_ISSET`: returns `true` if `fd` is in set
  - `FD_ZERO`: clear all entries

## Handling partial `send`s