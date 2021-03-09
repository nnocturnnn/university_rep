package thread;

import java.util.Random;
import thread.Monitor;

public class Main {
	
	public static void main(String[] args) {
		int numTests = 4; //количество запусков на каждый тест
		
		int N = 1000;
		int[][] arr1 = new int[N][N];
		int[] arr2 = new int[N * N];
		
		//Тест на 1 потоке
		System.out.println("Тест №1:*******************************************************");
		for (int i = 0; i < numTests; i++) {
			System.out.println("Расчет №" + (i + 1) + ":");
			//При каждом новом тесте заполняем массивы другими значениями
			fillArr(arr1, arr2);
			TestCalculateSumElements.startCalculateElemSum(1, arr1); //для двумерного массива
			//Перед тем как запускать след. расчет надо подождать пока выполнится пред. расчет
			Monitor.getInstance().waitCalculating();
			System.out.println("----------------------------------------------------------------------------------");
		}
		System.out.println("***************************************************************");
		System.out.println();
		
		System.out.println("Тест №2:*******************************************************");
		for (int i = 0; i < numTests; i++) {
			System.out.println("Расчет №" + (i + 1) + ":");
			fillArr(arr1, arr2);
			TestCalculateSumElements.startCalculateElemSum(2, arr1);
			Monitor.getInstance().waitCalculating();
			System.out.println("----------------------------------------------------------------------------------");
		}
		System.out.println("***************************************************************");
		System.out.println();
		
		//Тест на 9 потоках
		System.out.println("Тест №3:*******************************************************");
		for (int i = 0; i < numTests; i++) {
			System.out.println("Расчет №" + (i + 1) + ":");
			fillArr(arr1, arr2);
			TestCalculateSumElements.startCalculateElemSum(3, arr1);
			Monitor.getInstance().waitCalculating();
			System.out.println("----------------------------------------------------------------------------------");
		}
		System.out.println("***************************************************************");
		System.out.println();
	}
	
	private static void fillArr(int[][] arr1, int[] arr2) {
		Random random = new Random();
		int cnt = 0;
		for (int i = 0; i < arr1.length; i++) {
			for (int j = 0; j < arr1[i].length; j++) {
				arr1[i][j] = random.nextInt(100);
				arr2[cnt++] = arr1[i][j];
			}
		}
	}

}