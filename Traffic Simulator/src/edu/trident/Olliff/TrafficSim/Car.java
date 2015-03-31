package edu.trident.Olliff.TrafficSim;

public class Car extends Vehicle {

private static final int SIZE = 2;
	
	public Car(int ID) {
		super(ID);
		minDistance = 2.25;
		type = VehicleType.CAR;
		prefSpeed = speedPrefGen(60,70);
	}
	
	public int getSize() {
		return SIZE; 
	}

}
