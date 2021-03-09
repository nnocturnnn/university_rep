package thread;

public class TestCalculateSumElements {
	
	public static void startCalculateElemSum(int numThread, int[][] arr) {
		if (arr == null) {
			throw new NullPointerException();
		} else if (arr.length == 0 || arr[0].length == 0) {
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int M = arr.length % numThread;
		int pos = 0;
		int blockLength;
		for (int i = 0; i < numThread; i++) {
			if (M > 0) {
				blockLength = arr.length / numThread + 1;
				M--;
			} else {
				blockLength = arr.length / numThread;
			}
			new ThreadContainer(
				numThread,
				pos,
				blockLength,
				arr
			).start();
			pos += blockLength;
		}
	}
	
	public static void startCalculateElemSum(int numThread, int ... arr) {
		if (arr == null) {
			throw new NullPointerException();
		} else if (arr.length == 0) {
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int M = arr.length % numThread;
		int pos = 0;
		int blockLength;
		for (int i = 0; i < numThread; i++) {
			if (M > 0) {
				blockLength = arr.length / numThread + 1;
				M--;
			} else {
				blockLength = arr.length / numThread;
			}
			new ThreadContainer(
				numThread,
				pos,
				blockLength,
				arr
			).start();
			pos += blockLength;
		}
	}

}