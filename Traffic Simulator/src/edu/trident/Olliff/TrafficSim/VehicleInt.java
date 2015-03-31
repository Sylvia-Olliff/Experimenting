package edu.trident.Olliff.TrafficSim;

/**
 * Vehicle interface for retrieving Vehicle Attributes and causing the Vehicle to move
 * @author Joesph Olliff
 *
 */
public interface VehicleInt {
	public enum VehicleType {
		MOTOR,
		CAR,
		TRUCK,
		CARGO,
		EMER
	}
	
	/**
	 *  Get the vehicle's tracking ID
	 * @return int ID
	 */
	public int getID();
	
	/**
	 * Get the vehicle's randomly generated starting point
	 * @return int Start
	 */
	public int getStart();
	
	/**
	 * Get the vehicle's randomly generated destination
	 * @return int Destination
	 */
	public int getDest();
	
	/**
	 * Get the vehicle's Type
	 * @return
	 */
	public VehicleType getType();
	
	/**
	 * Get the Vehicle's minimum Distance that it will maintain from other vehicles
	 * @return double minDist
	 */
	public double getMinDist();
	
	/**
	 * get the Vehicle's desired speed that it will attempt to move at
	 * @return double preferedSpeed
	 */
	public double getPrefSpeed();
	
	/**
	 * Get the Vehicle's current Speed
	 * @return double speed
	 */
	public double getSpeed();
	
	/**
	 * Get the vehicle's current position on it's current path
	 * @return
	 */
	public double getPostion();
	
	/**
	 * Move the vehicle along it's path
	 * @return boolean true on successful move
	 */
	public boolean move();
}
