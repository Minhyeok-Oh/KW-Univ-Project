package kw.ohminhyeok.assign3;

import java.io.IOException;
import java.util.Scanner;

public class main {
	public static void main(String[] args) throws IOException {
		
		Chess chess = new Chess();
		
		String command = null;
		
		while (true) {
			// command line interface
			System.out.println("==========Chess Chatter=========");
			System.out.println("  1.load 2. start 3.end 4.search");
			System.out.println("==========Chess Chatter=========");
			
			Scanner sc = new Scanner(System.in);
			System.out.print("Input Command : ");
			command = sc.nextLine();
			String[] cmd = command.split(" ");
			int start_r, start_c;
			int end_r, end_c;
			
			
			if(cmd[0].equals("load")) { // load function
				chess.load();
			} else if(cmd[0].equals("start")) { // start function
				if(cmd.length == 5) {
					if(cmd[1].equals("-r")&&cmd[3].equals("-c")) {
						chess.start(Integer.parseInt(cmd[2]),Integer.parseInt(cmd[4]));
					}else if(cmd[1].equals("-c")&&cmd[3].equals("-r")) {
						chess.start(Integer.parseInt(cmd[4]),Integer.parseInt(cmd[2]));
					}else {// default
						chess.end(0,0);
					}
				} else {
					chess.end(0,0);// default
				}
			}else if(cmd[0].equals("end")) { // end function
				if(cmd.length == 5) {
					if(cmd[1].equals("-r")&&cmd[3].equals("-c")) {
						chess.end(Integer.parseInt(cmd[2]),Integer.parseInt(cmd[4]));
					}else if(cmd[1].equals("-c")&&cmd[3].equals("-r")) {
						chess.end(Integer.parseInt(cmd[4]),Integer.parseInt(cmd[2]));
					}else { // default
						chess.end(0,0); // default
					}
				} else {// default
					chess.end(0,0);
				}
			}else if(cmd[0].equals("search")) { // search function
				chess.search();
				chess = new Chess();
				break;
			} else {
				System.out.println("Input error, re input please");
			}
		}
	}

}
