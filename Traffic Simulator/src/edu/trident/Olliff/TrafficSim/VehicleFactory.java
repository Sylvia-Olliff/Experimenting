package edu.trident.Olliff.TrafficSim;

import java.util.Random;

public class VehicleFactory {
	private Motorcycle motor;
	private Car car;
	private Truck truck;
	private Cargo cargo;
	private Emergency emer;
	
	private int numVehicles = 0;
	
	//Likelihood of different vehicles being generated
	private int[] weightedSelection = new int[100];
	
	/**
	 * Currently will be internal but will allow the user to specify the likelihood of different vehicles being 
	 * generated. 
	 * <b>NOTE:</b> All values sent must total up to 100
	 * @param motoInit
	 * @param carInit
	 * @param truckInit
	 * @param cargoInit
	 * @param emerInit
	 * @throws PercentageException
	 */
	public VehicleFactory(int motoInit, int carInit, int truckInit, int cargoInit, int emerInit) throws PercentageException {
		if (motoInit + carInit + truckInit + cargoInit + emerInit != 100) {
			throw new PercentageException();
		} else {
			int tracker = 0;
			for(int count = 0; count<motoInit; count++) {
				weightedSelection[tracker] = 0;
				tracker++;
			}
			for(int count = 0; count<carInit; count++) {
				weightedSelection[tracker] = 1;
				tracker++;
			}
			for(int count = 0; count<truckInit; count++) {
				weightedSelection[tracker] = 2;
				tracker++;
			}
			for(int count = 0; count<cargoInit; count++) {
				weightedSelection[tracker] = 3;
				tracker++;
			}
			for(int count = 0; count<emerInit; count++) {
				weightedSelection[tracker] = 4;
				tracker++;
			}
		}
	}
	
	/**
	 * Builds and returns a vehicle of a random type
	 * @return car || motor || truck || cargo || emer
	 */
	public Vehicle buildVehicle() {
		int whichType = vehicleSelect();
		
		switch(whichType) {
			case 0: {
				motor = new Motorcycle(numVehicles);
				numVehicles++;
				return motor;
			}
			case 1: {
				car = new Car(numVehicles);
				numVehicles++;
				return car;
			}
			case 2: {
				truck = new Truck(numVehicles);
				numVehicles++;
				return truck;
			}
			case 3: {
				cargo = new Cargo(numVehicles);
				numVehicles++;
				return cargo;
			}
			case 4: {
				emer = new Emergency(numVehicles);
				numVehicles++;
				return emer;
			}
			default: {
				return null;
			}
		}
	}
	
	/**
	 * picks a random vehicle type using weighted values
	 * @return int 0-3
	 */
	private int vehicleSelect() {
		Random generator = new Random();
		int selection = generator.nextInt(100);
		return weightedSelection[selection];
	}
	
	/**
	 * returns the total number of vehicles created so far
	 * @return numVehicles
	 */
	public int getTotalVehicles() {
		return numVehicles;
	}
}
