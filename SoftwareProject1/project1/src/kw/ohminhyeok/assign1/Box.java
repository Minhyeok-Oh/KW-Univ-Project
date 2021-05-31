package kw.ohminhyeok.assign1;

import java.util.List;

public class Box {

	int[][] box = new int[10][10];
	int[] topOfBox = new int[10];
	
	public Box() {
		for (int i = 0; i < 10; i++) {
			topOfBox[i] = 9;
			for (int j = 0; j < 10; j++) {
				box[i][j] = 0;
			}
		}
	}

	public void PrintBox() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (box[i][j] == 0) {
					System.out.print('□');
				} else {
					System.out.print('■');
				}

			}
			System.out.println();
		}
	}

	public boolean isUsable(int[][] shape, int x, int y, int w, int h) { // can block is located in board 
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (shape[i][j] != 0) {
					if (j + x >= 10 || i + y >= 10) {
						return false;
					}
					if (box[y + i][x + j] != 0) {
						return false;
					}
				}
			}
		}

		return true;
	}

	public void addBlock(int[][] shape, int x, int y, int w, int h) { // add block in board
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				box[y + i][x + j] = shape[i][j];
			}
		}

		topOfBoxUpdate();
	}

	public void PrintErrorMessage(List<String> command) { // print error message 
		for (String error : command) {
			System.out.println("Error : Not enough space for " + error);
		}
	}
	
	public void topOfBoxUpdate() { // for checking top line of board
		for (int i = 9; i >= 0; i--) {
			for (int j = 9; j >= 0; j--) {
				if(box[i][j] == 1) {
					topOfBox[j] = i - 1;
				}
			}
		}
	}
}
