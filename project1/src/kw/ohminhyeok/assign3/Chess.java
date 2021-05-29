package kw.ohminhyeok.assign3;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Iterator;

public class Chess {
	String[][] ChessBoard;
	String[] D;
	String[][] weight;
	boolean[] check;
	int start_r, start_c;
	int end_r, end_c;
	int size;
	int number;

	public Chess() {
		start_r = 0;
		start_c = 0;
		end_r = 0;
		end_c = 0;
		size = 0;
		number = 0;

	}

	public void load() throws IOException {
		BufferedReader br = new BufferedReader(
				new FileReader("C://Users/alsgu/eclipse-workspace/2017202037/src/kw/ohminhyeok/assign3/maps.txt"));

		String line = br.readLine();
		if(line==null) {
			System.out.println("no input size. program exit.");
			System.exit(0);
		}
		int size = Integer.parseInt(line); // board size
		ChessBoard = new String[size][size]; // ChessBoard made up of string
		this.D = new String[size * size]; // path list for finding shortest path using dijkstra
		this.check = new boolean[size * size]; // visit check list for finding shortest path using dijkstra
		this.size = size; // board size
		this.number = size * size; // node number of ChessBoard

		this.weight = new String[number][number]; // weight array for finding shortest path using dijkstra
		System.out.println("===============MAP================");
		for (int i = 0; i < size; i++) { // bring up board from file and printing Chess board
			line = br.readLine();
			String[] tokens = line.split(" ");
			for (int j = 0; j < size; j++) {
				ChessBoard[i][j] = tokens[j];
				if (j == size - 1) {
					System.out.printf("%-10s", ChessBoard[i][j]);
					break;
				}
				System.out.printf("%-10s|", ChessBoard[i][j]);
			}
			System.out.println();
		}

		br.close();
		String INF = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; // String INF VALUE
		///////////////// up, down, right, left moving coordinate x,y ///////////////
		int[] clist = { -1, 0, 1, 0 };
		int[] rlist = { 0, -1, 0, 1 };
		///////////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////// convert 2-dimension array to 1-dimension array for using dijkstra algorithm ///////////////////////////////
		for (int r = 0; r < size; r++) {
			for (int c = 0; c < size; c++) {
				for (int i = 0; i < 4; i++) {
					int x = clist[i];
					int y = rlist[i];
					if ((r + y < size) && (r + y >= 0) && (c + x < size) && (c + x >= 0) && !(y == 0 && x == 0)) {
						int start = r * size + c; // 2-dimension array index to 1-dimension array index
						int end = (r + y) * size + (c + x);
						weight[start][end] = ChessBoard[r + y][c + x];
						weight[end][start] = ChessBoard[r][c];
					}
				}
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		System.out.println("Data loaded from maps.txt");
	}
	///// set start coordinate
	public void start(int r, int c) {
		// TODO Auto-generated method stub
		this.start_r = r;
		this.start_c = c;

		System.out.println("[" + ChessBoard[r][c] + "] has been chosoen as a Start Point");
	}
	//// set end coordinate
	public void end(int r, int c) {
		// TODO Auto-generated method stub
		this.end_r = r;
		this.end_c = c;

		System.out.println("[" + ChessBoard[r][c] + "] has been chosoen as a End Point");
	}

	public void search() { // search sentence with shortest path
		dijkstra();

	}

	public void dijkstra() { // dijkstra algorithm
		int start = (this.start_r * size) + this.start_c;
		int end = (this.end_r * size) + this.end_c;

		for (int i = 0; i < number; i++) { // initialize shortest path array with INF value
			D[i] = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		}

		D[start] = ChessBoard[this.start_r][this.start_c];

		check[start] = true; // visit node check

		for (int i = 0; i < number; i++) { // On the current node, adjacent node weight update
			if (!check[i] && weight[start][i] != null && weight[start][i].length() != 0) {
				D[i] = D[start] + " " + weight[start][i];
			}
		}

		for (int i = 0; i < number - 1; i++) { 
			String min = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; // String INF value
			int index = -1;

			for (int j = 0; j < number; j++) {// On the current node, finding shortest path node
				if (!check[j] && !D[j].equals(min)) { // do not visit and do not same inf value
					if (D[j].length() < min.length()) {
						min = D[j];
						index = j;
					} else if (D[j].length() == min.length()) {
						if (D[j].compareTo(min) < 0) {
							min = D[j];
							index = j;
						}
					}
				}
			}
			check[index] = true; // visit node checking
			for (int j = 0; j < number; j++) { // shortest path update
				if (!check[j] && weight[index][j] != null && weight[index][j].length() != 0) {
					if ((D[index] + " " + weight[index][j]).length() < D[j].length()) { // current node to index node path + index node to j path < current node to j path
						D[j] = D[index] + " " + weight[index][j]; // path update
					} else if ((D[index] + " " + weight[index][j]).length() == D[j].length()) {
						if ((D[index] + " " + weight[index][j]).compareTo(D[j]) < 0) {
							D[j] = D[index] + " " + weight[index][j];
						}
					}
				}
			}
		}
		for (int i = 0; i < size; i++) { // printing chess board
			for (int j = 0; j < size; j++) {
				if (j == size - 1) {
					System.out.printf("%-10s", ChessBoard[i][j]);
					break;
				}
				System.out.printf("%-10s|", ChessBoard[i][j]);
			}
			System.out.println();
		}
		System.out.println("result : " + D[end]);
	}

}
