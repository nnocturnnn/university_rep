package thread;

import java.util.Random;
import thread.Monitor;

public class Main {
	
	public static void main(String[] args) {
		int numTests = 4; //количество запусков на каждый тест тут можно поменять кол-во тестов
		
		int N = 1000;  // тут можно вместо 1000х1000 как в задании MxN
		int[][] arr1 = new int[N][N]; //создаем массив
		int[] arr2 = new int[N];
		//Тест на 1 потоке
		System.out.println("Тест №1:*******************************************************");
		for (int i = 0; i < numTests; i++) { // цикл чтобы по 4 раза вывести каждый поток для более точных рассчетов
			System.out.println("Расчет №" + (i + 1) + ":");
			fillArr(arr1, arr2); //При каждом новом тесте заполняем массивы другими значениями
			TestCalculateSumElements.startCalculateElemSum(1, arr1); //для двумерного массива тут первый аргумент это количество потоков а второй масси
			Monitor.getInstance().waitCalculating(); //Перед тем как запускать след. расчет надо подождать пока выполнится пред. расчет
			System.out.println("----------------------------------------------------------------------------------"); 
		}
		System.out.println("***************************************************************"); // Дальше все также только меняем кол-во потоков в строках 30 и 43
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
		
		//Тест на 3 потоках
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