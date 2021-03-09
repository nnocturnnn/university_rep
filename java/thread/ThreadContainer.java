package thread;

public class ThreadContainer extends Thread {
	
	private static int threadCnt;
	
	private int numThread;
    private int pos;
    private int blockLength;
    private int[][] matr;
    private int[] vec;
    
    public ThreadContainer(int numThread, int pos, int blockLength, int[][] matr) {
    	privateConstructor(numThread, pos, blockLength);
    	this.matr = matr;
    }
    
    public ThreadContainer(int numThread, int pos, int blockLength, int[] vec) {
    	privateConstructor(numThread, pos, blockLength);
    	this.vec = vec;
    }
    
    private void privateConstructor(int numThread, int pos, int blockLength) {
    	this.numThread = numThread;
    	this.pos = pos;
    	this.blockLength = blockLength;
    }
    
    public void run() {
//    	System.out.println("Поток: " + getId() + " стартовал");
    	Monitor.getInstance().setStartTime();
    	if (matr != null) {
    		calcSumMatr();
    	} else if (vec != null) {
    		calcSumVec();
    	}
//    	System.out.println("Поток: " + getId() + " финишировал");
    }
    
    private void calcSumMatr() {
    	long sum = 0;
    	for (int i = pos; i < pos + blockLength; i++) {
    		for (int j = 0; j < matr[i].length; j++) {
    			sum += matr[i][j];
    		}
    	}
    	Monitor.getInstance().incSum(sum);
    	if (incThread(numThread)) {
    		threadCnt = 0;
    		Monitor.getInstance().setEndTime();
    		Monitor.getInstance().showResult(
    			"Кол. потоков: " + numThread
    			+ "; Двумерный массив(" + matr.length + "," + matr[0].length + ")"
    		);
    	}
    }
    
    
    
    private void calcSumVec() {
    	long sum = 0;
    	for (int i = pos; i < pos + blockLength; i++) {
    		sum += vec[i];
    	}
    	Monitor.getInstance().incSum(sum);
    	if (incThread(numThread)) {
    		threadCnt = 0;
    		Monitor.getInstance().setEndTime();
    		Monitor.getInstance().showResult(
    			"Кол. потоков: " + numThread
    			+ "; Одномерный массив(" + vec.length + ")"
    		);
    	}
    }
    
    private static synchronized boolean incThread(int numThread) {
		return ++threadCnt == numThread;
	}

}