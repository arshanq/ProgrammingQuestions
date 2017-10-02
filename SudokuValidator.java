/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class SudokuValidator
{
		public static boolean validate(int[][] sudoku) {
		// check each row must have all 9 elements
		Set<Integer> set = new HashSet();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				set.add(sudoku[i][j]);
			}
			if (set.size() != 9) return false;
			set.clear();
		}

		// check each column must have all 9 elements
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				set.add(sudoku[j][i]);
			}
			if (set.size() != 9) return false;
			set.clear();
		}

		//check each square must have 9 elements
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				for (int k = i; k < i+3; k++) {
					for (int l = j; l <j+ 3; l++) {
						set.add(sudoku[k][l]);
					}
				}
				if (set.size() != 9) {
					System.out.println("Here 3 i: " + i + " j: " + j);
					return false;
				}
				set.clear();
			}
		}

		return true;
	}


	public static void main (String[] args) throws java.lang.Exception
	{
		int arr2[][] = {{8, 3, 5, 4, 1, 6, 9, 2, 7},
				{2, 9, 6, 8, 5, 7, 4, 3, 1},
				{4, 1, 7, 2, 9, 3, 6, 5, 8},
				{5, 6, 9, 1, 3, 4, 7, 8, 2},
				{1, 2, 3, 6, 7, 8, 5, 4, 9},
				{7, 4, 8, 5, 2, 9, 1, 6, 3},
				{6, 5, 2, 7, 8, 1, 3, 9, 4},
				{9, 8, 1, 3, 4, 5, 2, 7, 6},
				{3, 7, 4, 9, 6, 2, 8, 1, 5}};
		System.out.println(validate(arr2));	}
}