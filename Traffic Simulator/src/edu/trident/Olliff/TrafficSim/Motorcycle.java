package edu.trident.Olliff.TrafficSim;

public class Motorcycle extends Vehicle {

	private static final int SIZE = 1;
	
	public Motorcycle(int ID) {
		super(ID);
		minDistance = 1.5;
		type = VehicleType.MOTOR;
		prefSpeed = speedPrefGen(60,80);
	}
	
	public int getSize() {
		return SIZE; 
	}

}
