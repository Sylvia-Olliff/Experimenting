package edu.trident.Olliff.TrafficSim;

public class Emergency extends Vehicle {

private static final int SIZE = 2;
	
	private boolean lightsOn;

	public Emergency(int ID) {
		super(ID);
		minDistance = 3;
		type = VehicleType.EMER;
		prefSpeed = speedPrefGen(60,100);
		lightsOn = emerLightsGen();
	}
	
	public int getSize() {
		return SIZE; 
	}
	
	public boolean getLights() {
		return lightsOn;
	}
	
	private boolean emerLightsGen() {
		int on = generator.nextInt(2);
		if(on == 1) {
			return true;
		} else {
			return false;
		}
	}

}
