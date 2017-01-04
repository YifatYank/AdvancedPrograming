a.out: server.out client.out

# Make the server exe file
server.out: server/main.o server/BfsGrid.o server/Cab.o server/Driver.o server/Grid.o server/GridNode.o server/Luxury.o server/Passenger.o server/Point.o server/PointNode.o server/TaxiCenter.o server/Standart.o server/Trip.o server/Socket.o server/Udp.o
	g++ -std=c++0x server/main.o server/BfsGrid.o server/Cab.o server/Driver.o server/Grid.o server/GridNode.o server/Luxury.o server/Passenger.o server/Point.o server/PointNode.o server/TaxiCenter.o server/Standart.o server/Trip.o server/Socket.o server/Udp.o -lboost_serialization -o server.out

server/main.o: server/main.cpp
	g++ -std=c++0x -c server/main.cpp -o server/main.o

server/BfsGrid.o: server/BfsGrid.cpp server/BfsGrid.h
	g++ -std=c++0x -c server/BfsGrid.cpp -o server/BfsGrid.o

server/Cab.o: server/Cab.cpp server/Cab.h
	g++ -std=c++0x -c server/Cab.cpp -o server/Cab.o

server/Driver.o: server/Driver.cpp server/Driver.h
	g++ -std=c++0x -c server/Driver.cpp -o server/Driver.o

server/Grid.o: server/Grid.cpp server/Grid.h
	g++ -std=c++0x -c server/Grid.cpp -o server/Grid.o

server/GridNode.o: server/GridNode.cpp server/GridNode.h
	g++ -std=c++0x -c server/GridNode.cpp -o server/GridNode.o

server/Luxury.o: server/Luxury.cpp server/Luxury.h
	g++ -std=c++0x -c server/Luxury.cpp -o server/Luxury.o

server/Passenger.o: server/Passenger.cpp server/Passenger.h
	g++ -std=c++0x -c server/Passenger.cpp -o server/Passenger.o

server/PointNode.o: server/PointNode.cpp server/PointNode.h
	g++ -std=c++0x -c server/PointNode.cpp -o server/PointNode.o

server/Point.o: server/Point.cpp server/Point.h
	g++ -std=c++0x -c server/Point.cpp -o server/Point.o

server/Standart.o: server/Standart.cpp server/Standart.h
	g++ -std=c++0x -c server/Standart.cpp -o server/Standart.o

server/TaxiCenter.o: server/TaxiCenter.cpp server/TaxiCenter.h
	g++ -std=c++0x -c server/TaxiCenter.cpp -o server/TaxiCenter.o

server/Trip.o: server/Trip.cpp server/Trip.h
	g++ -std=c++0x -c server/Trip.cpp -o server/Trip.o

server/Udp.o: server/Udp.cpp server/Udp.h
	g++ -std=c++0x -c server/Udp.cpp -o server/Udp.o

server/Socket.o: server/Socket.cpp server/Socket.h
	g++ -std=c++0x -c server/Socket.cpp -o server/Socket.o

#Make the client exe file
client.out: client/main.o client/Cab.o client/Driver.o client/Luxury.o client/Passenger.o client/Point.o client/Standart.o client/Trip.o client/Socket.o client/Udp.o
	g++ -std=c++0x client/main.o client/Cab.o client/Driver.o client/Luxury.o client/Passenger.o client/Point.o client/Standart.o client/Trip.o client/Socket.o client/Udp.o -lboost_serialization -o client.out

client/main.o: client/main.cpp
	g++ -std=c++0x -c client/main.cpp -o client/main.o

client/Cab.o: client/Cab.cpp client/Cab.h
	g++ -std=c++0x -c client/Cab.cpp -o client/Cab.o 

client/Driver.o: client/Driver.cpp client/Driver.h
	g++ -std=c++0x -c client/Driver.cpp -o client/Driver.o

client/Luxury.o: client/Luxury.cpp client/Luxury.h
	g++ -std=c++0x -c client/Luxury.cpp -o client/Luxury.o

client/Passenger.o: client/Passenger.cpp client/Passenger.h
	g++ -std=c++0x -c client/Passenger.cpp -o client/Passenger.o

client/Point.o: client/Point.cpp client/Point.h
	g++ -std=c++0x -c client/Point.cpp -o client/Point.o

client/Standart.o: client/Standart.cpp client/Standart.h
	g++ -std=c++0x -c client/Standart.cpp -o client/Standart.o 

client/Trip.o: client/Trip.cpp client/Trip.h
	g++ -std=c++0x -c client/Trip.cpp -o client/Trip.o 

client/Udp.o: client/Udp.cpp client/Udp.h
	g++ -std=c++0x -c client/Udp.cpp -o client/Udp.o

client/Socket.o: client/Socket.cpp client/Socket.h
	g++ -std=c++0x -c client/Socket.cpp -o client/Socket.o

clean:
	rm -f server/*.o client/*.o server.out client.out
