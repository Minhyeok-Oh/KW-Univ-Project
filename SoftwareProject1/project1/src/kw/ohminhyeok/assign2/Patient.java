package kw.ohminhyeok.assign2;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Patient implements Comparable<Patient>{
	String name; // patient name
	String doctor; // a doctor in charge
	String disease; // patient disease
	int Number; // patient Number
	String Modified_time; // created or modified time

	Patient(String name, String doctor, String disease, int Number) { // patient info constructor 
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); // SimpleDateFormat
		Date time = new Date(); // now time 

		String modified_time = format.format(time); // formating modified time

		this.name = name;
		this.doctor = doctor;
		this.disease = disease;
		this.Number = Number;
		this.Modified_time = modified_time;

	}
	
	@Override
	public int compareTo(Patient patient) { // Overiding compareTo function based on modified_time for sorting function
		return this.Modified_time.compareTo(patient.Modified_time);
	}

}
