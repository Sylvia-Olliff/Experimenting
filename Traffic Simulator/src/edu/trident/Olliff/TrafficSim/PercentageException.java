package edu.trident.Olliff.TrafficSim;

public class PercentageException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	public PercentageException(){
		super("All weighted values must add up to 100\n");
	}

}
