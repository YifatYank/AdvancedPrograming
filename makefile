a.out: Server.out Client.out

# Make the Server exe file
Server.out: Server/main.o Server/BfsGrid.o Server/Cab.o Server/Driver.o Server/Grid.o Server/GridNode.o Server/Luxury.o Server/Passenger.o Server/Point.o Server/PointNode.o Server/TaxiCenter.o Server/Standart.o Server/Trip.o Server/Socket.o Server/Udp.o
	g++ -std=c++0x Server/main.o Server/BfsGrid.o Server/Cab.o Server/Driver.o Server/Grid.o Server/GridNode.o Server/Luxury.o Server/Passenger.o Server/Point.o Server/PointNode.o Server/TaxiCenter.o Server/Standart.o Server/Trip.o Server/Socket.o Server/Udp.o -lboost_serialization -o Server.out

Server/main.o: Server/main.cpp
	g++ -std=c++0x -c Server/main.cpp -o Server/main.o

Server/BfsGrid.o: Server/BfsGrid.cpp Server/BfsGrid.h
	g++ -std=c++0x -c Server/BfsGrid.cpp -o Server/BfsGrid.o

Server/Cab.o: Server/Cab.cpp Server/Cab.h
	g++ -std=c++0x -c Server/Cab.cpp -o Server/Cab.o

Server/Driver.o: Server/Driver.cpp Server/Driver.h
	g++ -std=c++0x -c Server/Driver.cpp -o Server/Driver.o

Server/Grid.o: Server/Grid.cpp Server/Grid.h
	g++ -std=c++0x -c Server/Grid.cpp -o Server/Grid.o

Server/GridNode.o: Server/GridNode.cpp Server/GridNode.h
	g++ -std=c++0x -c Server/GridNode.cpp -o Server/GridNode.o

Server/Luxury.o: Server/Luxury.cpp Server/Luxury.h
	g++ -std=c++0x -c Server/Luxury.cpp -o Server/Luxury.o

Server/Passenger.o: Server/Passenger.cpp Server/Passenger.h
	g++ -std=c++0x -c Server/Passenger.cpp -o Server/Passenger.o

Server/PointNode.o: Server/PointNode.cpp Server/PointNode.h
	g++ -std=c++0x -c Server/PointNode.cpp -o Server/PointNode.o

Server/Point.o: Server/Point.cpp Server/Point.h
	g++ -std=c++0x -c Server/Point.cpp -o Server/Point.o

Server/Standart.o: Server/Standart.cpp Server/Standart.h
	g++ -std=c++0x -c Server/Standart.cpp -o Server/Standart.o

Server/TaxiCenter.o: Server/TaxiCenter.cpp Server/TaxiCenter.h
	g++ -std=c++0x -c Server/TaxiCenter.cpp -o Server/TaxiCenter.o

Server/Trip.o: Server/Trip.cpp Server/Trip.h
	g++ -std=c++0x -c Server/Trip.cpp -o Server/Trip.o

Server/Udp.o: Server/Udp.cpp Server/Udp.h
	g++ -std=c++0x -c Server/Udp.cpp -o Server/Udp.o

Server/Socket.o: Server/Socket.cpp Server/Socket.h
	g++ -std=c++0x -c Server/Socket.cpp -o Server/Socket.o

#Make the Client exe file
Client.out: Client/main.o Client/Cab.o Client/Driver.o Client/Luxury.o Client/Passenger.o Client/Point.o Client/Standart.o Client/Trip.o Client/Socket.o Client/Udp.o
	g++ -std=c++0x Client/main.o Client/Cab.o Client/Driver.o Client/Luxury.o Client/Passenger.o Client/Point.o Client/Standart.o Client/Trip.o Client/Socket.o Client/Udp.o -lboost_serialization -o Client.out

Client/main.o: Client/main.cpp
	g++ -std=c++0x -c Client/main.cpp -o Client/main.o

Client/Cab.o: Client/Cab.cpp Client/Cab.h
	g++ -std=c++0x -c Client/Cab.cpp -o Client/Cab.o 

Client/Driver.o: Client/Driver.cpp Client/Driver.h
	g++ -std=c++0x -c Client/Driver.cpp -o Client/Driver.o

Client/Luxury.o: Client/Luxury.cpp Client/Luxury.h
	g++ -std=c++0x -c Client/Luxury.cpp -o Client/Luxury.o

Client/Passenger.o: Client/Passenger.cpp Client/Passenger.h
	g++ -std=c++0x -c Client/Passenger.cpp -o Client/Passenger.o

Client/Point.o: Client/Point.cpp Client/Point.h
	g++ -std=c++0x -c Client/Point.cpp -o Client/Point.o

Client/Standart.o: Client/Standart.cpp Client/Standart.h
	g++ -std=c++0x -c Client/Standart.cpp -o Client/Standart.o 

Client/Trip.o: Client/Trip.cpp Client/Trip.h
	g++ -std=c++0x -c Client/Trip.cpp -o Client/Trip.o 

Client/Udp.o: Client/Udp.cpp Client/Udp.h
	g++ -std=c++0x -c Client/Udp.cpp -o Client/Udp.o

Client/Socket.o: Client/Socket.cpp Client/Socket.h
	g++ -std=c++0x -c Client/Socket.cpp -o Client/Socket.o

clean:
	rm -f Server/*.o Client/*.o Server.out Client.out
