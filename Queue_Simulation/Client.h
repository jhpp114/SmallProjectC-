#ifndef CLIENT_H
#define CLIENT_H

class Client {
 public:
  Client( ) : arrivalTime( 0 ) { };
  Client( int time ) : arrivalTime( time ) { };
  int getArrivalTime( ) { return arrivalTime; };
 private:
  int arrivalTime;
};

#endif
