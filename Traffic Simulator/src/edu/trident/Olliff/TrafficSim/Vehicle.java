package edu.trident.Olliff.TrafficSim;

import java.util.Random;

public abstract class Vehicle implements VehicleInt {
	protected int vehicleID;
	protected int startPoint;
	protected int destination;
	protected double minDistance;
	protected double prefSpeed;
	protected double speed;
	protected double position;
	protected VehicleType type;
	
	protected Random generator = new Random();
	
	public Vehicle(int ID) {
		vehicleID = ID;
		startPoint = locationGen();
		destination = locationGen();
		position = 0;
		speed = 0.0;
	}
	
	private int locationGen() {
		int location;
		location = generator.nextInt(4);
		return location;
	}
	
	protected int speedPrefGen(int beginRange, int endRange) {
		long range = (long)beginRange - (long)endRange + 1;
		long fraction = (long)(range * generator.nextDouble());
		int ranNum = (int)(fraction + beginRange);
		
		return ranNum;
	}

	@Override
	public int getID() {
		return vehicleID;
	}

	@Override
	public int getStart() {
		return startPoint;
	}

	@Override
	public int getDest() {
		return destination;
	}

	@Override
	public VehicleType getType() {
		return type;
	}

	@Override
	public double getMinDist() {
		return minDistance;
	}

	@Override
	public double getPrefSpeed() {
		return prefSpeed;
	}

	@Override
	public double getSpeed() {
		return speed;
	}

	@Override
	public double getPostion() {
		// FIXME Clarify how vehicles are going to know where they are
		return position;
	}

	@Override
	public boolean move() {
		// TODO Establish a method of moving a vehicle
		// TODO Update speed and position within here as the vehicles move.
		return false;
	}
}
