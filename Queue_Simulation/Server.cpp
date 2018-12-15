#include "Server.h"

void Server::newArrival( int newArrivalTime ) {
  currentTime = newArrivalTime;// Immediately jump to this new arrival time
  numberOfClients++;           // increment the total number of clients served
  cout << "Time=" << newArrivalTime << ": a new client has arrived" << endl;
  if ( nextDepartureTime == INF ) { // no one is being served at the beginning
    nextDepartureTime = currentTime + SERVICE_TIME; // serve him/her instantly
    cout << "Time=" << nextDepartureTime << ": a client arrived at "
	 << currentTime << " has served" << endl;
  } else
    clientQueue.push( Client( newArrivalTime ) ); // someone is being served
}						  // a new client should wait.

void Server::giveService( ) {
  currentTime = nextDepartureTime;	// start serving the next person
  if ( !clientQueue.empty( ) ) {		// from the queue
    Client client = clientQueue.front( );
    clientQueue.pop( );
    // calculate the waiting time
    sumOfWaitingTime += currentTime - client.getArrivalTime( ); 
    nextDepartureTime = currentTime + SERVICE_TIME; // schedule the time to get
					// finished with serving him/her
    cout << "Time=" << nextDepartureTime << ": a client arrived at "
	 << client.getArrivalTime( ) << " has served" << endl;
  } else
    nextDepartureTime = INF;
}

void Server::runSimulation( ) {
  int SENTINEL = 999;
  int newArrivalTime;

  cin >> newArrivalTime;
  while ( newArrivalTime != SENTINEL ) {
    if ( newArrivalTime < nextDepartureTime ) {
      newArrival( newArrivalTime );
      cin >> newArrivalTime;
    } else
      giveService( );
  }

  while ( nextDepartureTime < INF )
    giveService( );
}

void Server::printResult( ) {
  if ( numberOfClients == 0 )
    cout << "No client requested a service" << endl;
  else
    cout << "avarage waiting time = " 
	 << double( sumOfWaitingTime ) / double( numberOfClients ) << endl;
}



