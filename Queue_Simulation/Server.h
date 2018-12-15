#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <queue>
#include "Client.h"

using namespace std;

class Server{
 public:
  Server( ) : 
    currentTime( 0 ), numberOfClients( 0 ),
    sumOfWaitingTime( 0 ), nextDepartureTime( INF ) { }
  void runSimulation( );
  void printResult( );
 private:
  const static int INF = 10000;
  const static int SERVICE_TIME = 12;
  
  int currentTime;
  int nextDepartureTime;
  int numberOfClients;
  int sumOfWaitingTime;
  queue<Client> clientQueue;

  void newArrival( int newArrivalTime );
  void giveService( );
};

#endif
