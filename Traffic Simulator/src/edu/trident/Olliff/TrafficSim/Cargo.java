package edu.trident.Olliff.TrafficSim;

public class Cargo extends Vehicle {

private static final int SIZE = 8;
	
	public Cargo(int ID) {
		super(ID);
		minDistance = 4;
		type = VehicleType.CARGO;
		prefSpeed = speedPrefGen(55,65);
	}
	
	public int getSize() {
		return SIZE; 
	}

}
