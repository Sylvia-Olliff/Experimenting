package edu.trident.Olliff.TrafficSim;

public class TrafficSimulator {
	//TODO All throwable errors, movement, collisions, and traffic actions should be processed and handled here
	//TODO convert this to a thread and call methods on events
	private VehicleFactory factory;
	private int numVehicles;
	
	//These represent the length of all roads and exits involved in the intersection
	private double[] roads = {10000.0,10000.0,10000.0,10000.0};
	private double[] exits = {2350.0,2350.0,2350.0,2350.0,2350.0,2350.0,2350.0,2350.0};
	
	//check values for if a vehicle exists at a starting point or destination
	private boolean[] starts = new boolean[4];
	private boolean[] destinations = new boolean[4];
	
	//These are the points of entry and exit on each road
	private final double FIRST_EXIT = 3520.0;
	private final double SECOND_EXIT = 7040.0;
	private final double FIRST_ENTRANCE = 2350.0;
	private final double SECOND_ENTRANCE = 6460.0;
	
	/**
	 * Initializes the simulation, given the number of vehicles to be simulated
	 * @param trafficAmount
	 */
	public TrafficSimulator(int trafficAmount) {
		factory = new VehicleFactory(10,40,30,18,2);
		numVehicles = trafficAmount;
	}
	
	/**
	 * <p>Runs the simulation.</p>
	 * <b>NOTE:</b> This may take some time
	 */
	public void run() {
		while(numVehicles>0) {
			
		}
	}
}
