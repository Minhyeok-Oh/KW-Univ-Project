package kw.ohminhyeok.assign1;

public class Block { // Block class definition
	int x; // block input column
	int y; // block input row
	int h; // block height
	int w; // block width

	int[][] S_shape = null; // Small shape
	int[][] L_shape = null; // Large Shape
	int[][] M_shape = null; // Medium Shape
}

class OBlock extends Block {

	OBlock(int x, int y, char shape) { // O block Contructor
		S_shape = new int[][] { { 1, 1 }, { 1, 1 } };

		M_shape = new int[][] { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };

		L_shape = new int[][] { { 1, 1, 1, 1 }, { 1, 0, 0, 1 }, { 1, 0, 0, 1 }, { 1, 1, 1, 1 } };

		this.x = x;
		this.y = y;

		if (shape == 'S') {
			if(x >= 9) {
				this.x = 8;
			}
			this.h = 2;
			this.w = 2;
		} else if (shape == 'M') {
			if(x >= 8) {
				this.x = 7;
			}
			this.h = 3;
			this.w = 3;
		} else if (shape == 'L') {
			if(x >= 7) {
				this.x = 6;
			}
			this.h = 4;
			this.w = 4;
		} else {
			System.out.println("error");
		}
	}
}

class CBlock extends Block {

	CBlock(int x, int y, char shape) { // C block Contructor
		S_shape = new int[][] { { 1, 1 }, { 0, 1 } };

		M_shape = new int[][] { { 1, 1, 1 }, { 1, 0, 0 }, { 1, 1, 1 } };

		L_shape = new int[][] { { 1, 1, 1, 1 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 1, 1 } };

		this.x = x;
		this.y = y;

		if (shape == 'S') {
			if(x >= 9) {
				this.x = 8;
			}
			this.h = 2;
			this.w = 2;
		} else if (shape == 'M') {
			if(x >= 8) {
				this.x = 7;
			}
			this.h = 3;
			this.w = 3;
		} else if (shape == 'L') {
			if(x >= 7) {
				this.x = 6;
			}
			this.h = 4;
			this.w = 4;
		} else {
			System.out.println("error");
		}
	}
}

class LBlock extends Block {

	LBlock(int x, int y, char shape) { // L block Contructor
		S_shape = new int[][] { { 1, 0 }, { 1, 1 } };

		M_shape = new int[][] { { 1, 0, 0 }, { 1, 0, 0 }, { 1, 1, 1 } };

		L_shape = new int[][] { { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 1, 0 } };
		this.x = x;
		this.y = y;

		if (shape == 'S') {
			if(x >= 9) {
				this.x = 8;
			}
			this.h = 2;
			this.w = 2;
		} else if (shape == 'M') {
			if(x >= 8) {
				this.x = 7;
			}
			this.h = 3;
			this.w = 3;
		} else if (shape == 'L') {
			if(x >= 8) {
				this.x = 7;
			}
			this.h = 4;
			this.w = 3;
		} else {
			System.out.println("error");
		}
	}

}

class UBlock extends Block {

	UBlock(int x, int y, char shape) { // U block Contructor
		S_shape = new int[][] { { 1, 1 }, { 1, 0 } };

		M_shape = new int[][] { { 1, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };

		L_shape = new int[][] { { 1, 0, 0, 1 }, { 1, 0, 0, 1 }, { 1, 0, 0, 1 }, { 1, 1, 1, 1 } };
		this.x = x;
		this.y = y;

		if (shape == 'S') {
			if(x >= 9) {
				this.x = 8;
			}
			this.h = 2;
			this.w = 2;
		} else if (shape == 'M') {
			if(x >= 8) {
				this.x = 7;
			}
			this.h = 3;
			this.w = 3;
		} else if (shape == 'L') {
			if(x >= 7) {
				this.x = 6;
			}
			this.h = 4;
			this.w = 4;
		} else {
			System.out.println("error");
		}
	}
}