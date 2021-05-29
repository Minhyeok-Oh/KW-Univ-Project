package kw.ohminhyeok.assign2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Date;
import java.util.Scanner;

public class Manager {
	ArrayList<Patient> PatientList = new ArrayList<Patient>();
	int number = 0;

	public void input() {
		Scanner sc = new Scanner(System.in);

		System.out.print("Input Name : ");
		String Name = sc.nextLine();
		System.out.print("Input Doctor : ");
		String Doctor = sc.nextLine();
		System.out.print("Input Disease : ");
		String Disease = sc.nextLine();

		number++;

		Patient patient = new Patient(Name, Doctor, Disease, number);

		PatientList.add(patient);
	}

	public void view() { // printing all patient info 
		System.out.println("Number | Name | Doctor | Disease                | Modified time");
		for (Patient patient : PatientList) {
			System.out.printf("%-6d | %-4s | %-6s | %-22s | %-19s\n", patient.Number, patient.name, patient.doctor,
					patient.disease, patient.Modified_time);
		}
	}

	public void search(String category, String keyword) { // patient information searching based on keyword of category
		System.out.println("Number | Name | Doctor | Disease                | Modified time");
		for (Patient patient : PatientList) {
			if (category.equals("number")) {
				int number = Integer.parseInt(keyword);
				if (patient.Number == number) {
					System.out.printf("%-6d | %-4s | %-6s | %-20s | %-19s\n", patient.Number, patient.name,
							patient.doctor, patient.disease, patient.Modified_time);
				}
			} else if (category.equals("name")) {
				if (patient.name.equals(keyword)) {
					System.out.printf("%-6d | %-4s | %-6s | %-20s | %-19s\n", patient.Number, patient.name,
							patient.doctor, patient.disease, patient.Modified_time);
				}
			} else if (category.equals("doctor")) {
				if (patient.doctor.equals(keyword)) {
					System.out.printf("%-6d | %-4s | %-6s | %-20s | %-19s\n", patient.Number, patient.name,
							patient.doctor, patient.disease, patient.Modified_time);
				}
			} else if (category.equals("disease")) {
				if (patient.disease.equals(keyword)) {
					System.out.printf("%-6d | %-4s | %-6s | %-20s | %-19s\n", patient.Number, patient.name,
							patient.doctor, patient.disease, patient.Modified_time);
				}
			}
		}
		System.out.println("No data.");
	}

	public void modify(String category, int number, String modifytext) { // specific patinet information modify
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		Date time = new Date();
		String modified_time = format.format(time);

		for (Patient patient : PatientList) {
			if (number == patient.Number) {
				if (category.equals("name")) {
					patient.name = modifytext;
				} else if (category.equals("doctor")) {
					patient.doctor = modifytext;
				} else if (category.equals("disease")) {
					patient.disease = modifytext;
				} else {

				}
				patient.Modified_time = modified_time;
			} else {

			}
		}
		view();
	}

	public void delete(int num) { // delete specific patient info with num
		PatientList.remove(num - 1);
	}

	public void sort() { // patient list sorting based on modified_time
		Collections.sort(PatientList);
		view();
	}

	public void file_output() throws IOException { // to send out all patient information output to file
		Scanner sc = new Scanner(System.in);
		System.out.print("Input file name : ");
		String file_name = sc.nextLine();
		String file_path = "C://Users/alsgu/eclipse-workspace/2017202037/src/kw/ohminhyeok/assign2/";
		BufferedWriter bw;
		if(file_name == null) {
			bw = new BufferedWriter(new FileWriter("C://Users/alsgu/eclipse-workspace/2017202037/src/kw/ohminhyeok/assign2/data.txt"));
		}
		else {
			bw = new BufferedWriter(new FileWriter(file_path + file_name));
		}
		for (Patient patient : PatientList) {
			bw.write(patient.name + "$" + patient.doctor + "$" + patient.disease);
			bw.newLine();
		}
		bw.close();

		System.out.println("Data Saved as '" + file_name + "'");
	}

	public void file_read() throws IOException { // to bring up patient list from file
		Scanner sc = new Scanner(System.in);
		System.out.print("Input file name : ");
		String file_name = sc.nextLine();
		String file_path = "C://Users/alsgu/eclipse-workspace/2017202037/src/kw/ohminhyeok/assign2/";
		
		BufferedReader br;
		if(file_name == null) {
			br = new BufferedReader(new FileReader(file_path + "data.txt"));
		} else {
			br = new BufferedReader(new FileReader(file_path + file_name));
		}
		String line = br.readLine();
		while (line != null) {
			String[] tokens = line.split("[$]");

			number++;

			Patient patient = new Patient(tokens[0], tokens[1], tokens[2], number);
			PatientList.add(patient);
			line = br.readLine();

		}
		br.close();

		System.out.println("Data loaded from '" + file_name + "'");
	}

	public void quit() { // reference release
		PatientList = null;
	}
}
