package kw.ohminhyeok.assign1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MyMainClass {
	public static void printing(int[][] shape) {
		for (int i = 0; i < shape.length; i++) {
			for (int j = 0; j < shape[i].length; j++) {
				if (shape[i][j] == 0) {
					System.out.print('□');
				} else {
					System.out.print('■');
				}
			}

			System.out.println();
		}
	}

	public static void main(String[] args) throws IOException {
		String line = "";
		try { // file I O stream exception handling
			BufferedReader br = new BufferedReader(
					new FileReader("C://Users/alsgu/eclipse-workspace/2017202037/src/kw/ohminhyeok/assign1/data.txt"));
			line = br.readLine();

			br.close();
		} catch(Exception e) {
			e.getStackTrace();
		}
		
		


		Box box = new Box(); // make Box class Object

		String[] tokens = line.split("[$]"); // String tokenizing
		List<String> errorCommandList = new ArrayList<String>();
		for (String command : tokens) {
			boolean isadd = false; // check add block or not
			char shape = command.charAt(1); // first letter is size
			int x = command.charAt(3) - 49; // input column number
			if(x < 0) {
				System.out.println("input error");
				return;
			}
			char size = command.charAt(0); // block size (Small ,Medium ,Large )
			if (shape == 'O') { // O block
				for (int i = box.topOfBox[x]; i >= 0; i--) { // i is row
					OBlock O = new OBlock(x, i, size);
					if (size == 'S') { // S size
						if (box.isUsable(O.S_shape, O.x, i, O.w, O.h)) {
							box.addBlock(O.S_shape, O.x, i, O.w, O.h);
							isadd = true;
							break;
						}
					} else if (size == 'M') { // M size
						if (box.isUsable(O.M_shape, O.x, i, O.w, O.h)) {
							box.addBlock(O.M_shape, O.x, i, O.w, O.h);
							isadd = true;
							break;
						}
					} else if (size == 'L') { // L size
						if (box.isUsable(O.L_shape, O.x, i, O.w, O.h)) {
							box.addBlock(O.L_shape, O.x, i, O.w, O.h);
							isadd = true;
							break;
						}
					}else {
						System.out.println("size input error");
						return;
					}
				}

				if (isadd == true) {
					continue;
				} else {
					errorCommandList.add(command); // for error message
				}

			} else if (shape == 'C') { // C block
				for (int i = box.topOfBox[x]; i >= 0; i--) {
					CBlock C = new CBlock(x, i, size);
					if (size == 'S') { // S size
						if (box.isUsable(C.S_shape, C.x, i, C.w, C.h)) {
							box.addBlock(C.S_shape, C.x, i, C.w, C.h);
							isadd = true;
							break;
						}
					} else if (size == 'M') { // M size
						if (box.isUsable(C.M_shape, C.x, i, C.w, C.h)) {
							box.addBlock(C.M_shape, C.x, i, C.w, C.h);
							isadd = true;
							break;
						}
					} else if (size == 'L') { // L size
						if (box.isUsable(C.L_shape, C.x, i, C.w, C.h)) {
							box.addBlock(C.L_shape, C.x, i, C.w, C.h);
							isadd = true;
							break;
						}

					}else {
						System.out.println("size input error");
						return;
					}
				}
				if (isadd == true) {
					continue;
				} else {
					errorCommandList.add(command);
				}
			} else if (shape == 'L') { // L block
				for (int i = box.topOfBox[x]; i >= 0; i--) {
					LBlock L = new LBlock(x, i, size);
					if (size == 'S') { // S size
						if (box.isUsable(L.S_shape, L.x, i, L.w, L.h)) {
							box.addBlock(L.S_shape, L.x, i, L.w, L.h);
							isadd = true;
							break;
						}
					} else if (size == 'M') { // M size
						if (box.isUsable(L.M_shape, L.x, i, L.w, L.h)) {
							box.addBlock(L.M_shape, L.x, i, L.w, L.h);
							isadd = true;
							break;
						}
					} else if (size == 'L') { // L size
						if (box.isUsable(L.L_shape, L.x, i, L.w, L.h)) {
							box.addBlock(L.L_shape, L.x, i, L.w, L.h);
							isadd = true;
							break;
						}
					}else {
						System.out.println("size input error");
						return;
					}
				}
				if (isadd == true) {
					continue;
				} else {
					errorCommandList.add(command);
				}
			} else if (shape == 'U') { // U block
				for (int i = box.topOfBox[x]; i >= 0; i--) {
					UBlock U = new UBlock(x, i, size);
					if (size == 'S') { // S size
						if (box.isUsable(U.S_shape, U.x, i, U.w, U.h)) {
							box.addBlock(U.S_shape, U.x, i, U.w, U.h);
							isadd = true;
							break;
						}
					} else if (size == 'M') { // M size
						if (box.isUsable(U.M_shape, U.x, i, U.w, U.h)) {
							box.addBlock(U.M_shape, U.x, i, U.w, U.h);
							isadd = true;
							break;
						}
					} else if (size == 'L') { // L size
						if (box.isUsable(U.L_shape, U.x, i, U.w, U.h)) {
							box.addBlock(U.L_shape, U.x, i, U.w, U.h);
							isadd = true;
							break;
						}

					}else {
						System.out.println("size input error");
						return;
					}
				}
				if (isadd == true) {
					continue;
				} else {
					errorCommandList.add(command);
				}
			} else {
				System.out.println("shape Input error");
				return;
			}
		}

		box.PrintBox(); // final result box print
		box.PrintErrorMessage(errorCommandList); // print error message
		
	}

}
