package kw.ohminhyeok.assign2;

import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		String command = null;
		Manager manager = new Manager();

		while (true) { 
			//////////// making command Line interface //////////
			System.out.println("=================================================================================");
			System.out.println("1.input 2.view 3.modify 4.delete 5.search 6.sort 7.file output 8.file read 9.quit");
			System.out.println("=================================================================================");
			/////////////////////////////////////////////////////
			Scanner sc = new Scanner(System.in);
			System.out.print("Input Command : "); // command input
			command = sc.nextLine();
			String[] cmd = command.split(" "); // String Tokenizing command

			if (cmd[0].equals("input")) { // input function
				manager.input();
			} else if (cmd[0].equals("view")) { // view function
				manager.view();
			} else if (cmd[0].equals("modify")) { // modify function
				int number = 0;
				String category = "";
				String modifytext = "";
				if (cmd.length == 6) {
					if (cmd[1].equals("-n")) { // number
						number = Integer.parseInt(cmd[2]);
						modifytext = cmd[5];
						if (cmd[3].equals("-c")) { // category
							category = cmd[4];
						} else {
							System.out.println("input failed. please re input");
						}
					} else if (cmd[1].equals("-c")) { // category
						category = cmd[2];
						modifytext = cmd[5];
						if (cmd[3].equals("-n")) { // number
							number = Integer.parseInt(cmd[4]);
						} else {
							System.out.println("input failed. please re input");
						}
					} else {
						System.out.println("input failed. please re input");
					}
					manager.modify(category, number, modifytext);
				} else {
					System.out.println("input failed. please re input");
				}
			} else if (cmd[0].equals("delete")) { // delete function
				if (cmd.length > 1) {
					int num = Integer.parseInt(cmd[1]);
					manager.delete(num);
					manager.view();
				} else {
					System.out.println("input failed. please re input");
				}
			} else if (cmd[0].equals("search")) { // search function
				String category = "";
				String keyword = "";
				if (cmd.length == 5) {
					if (cmd[1].equals("-c")) { // category
						category = cmd[2];
						if (cmd[3].equals("-k")) { // keyword
							keyword = cmd[4];
						} else {
							System.out.println("input failed. please re input");
						}
					} else if (cmd[1].equals("-k")) { // keyword
						keyword = cmd[2];
						if (cmd[3].equals("-c")) { // category
							category = cmd[4];
						} else {
							System.out.println("input failed. please re input");
						}
					} else {
						System.out.println("input failed. please re input");
					}
					manager.search(category, keyword);
				} else {
					System.out.println("input failed. please re input");
				}

			} else if (cmd[0].equals("sort")) { // sort function
				manager.sort();
			} else if (cmd[0].equals("file")) {
				if (cmd[1].equals("read")) { // file read function
					manager.file_read();
				} else if (cmd[1].equals("output")) { // file output function
					manager.file_output();
				} else {
					System.out.println("input failed. please re input");
				}
			} else if (cmd[0].equals("quit")) {
				manager.quit();
				break;
			} else {
				System.out.println("input failed. please re input");
			}
		}
	}
}
