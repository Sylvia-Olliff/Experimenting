package edu.trident.Olliff.TrafficSim;

public class Truck extends Vehicle {

private static final int SIZE = 3;
	
	public Truck(int ID) {
		super(ID);
		minDistance = 3;
		type = VehicleType.TRUCK;
		prefSpeed = speedPrefGen(60,70);
	}
	
	public int getSize() {
		return SIZE; 
	}

}
