package thread;

public class ThreadContainer extends Thread { // класс наследующий тред поэтому запуск в отдельном
	
	private static int threadCnt; 
	
	private int numThread;
    private int pos;
    private int blockLength;
    private int[][] matr; 
    
    public ThreadContainer(int numThread, int pos, int blockLength, int[][] matr) { // констуктор для инкапсуляции 
    	privateConstructor(numThread, pos, blockLength);
    	this.matr = matr;
    }
    
    private void privateConstructor(int numThread, int pos, int blockLength) {
    	this.numThread = numThread;
    	this.pos = pos;
    	this.blockLength = blockLength;
    }
    
    public void run() {
    	Monitor.getInstance().setStartTime(); // запускаем монитор для начала времени
		calcSumMatr();
    }
    
    private void calcSumMatr() { // функция для подсчета суммы циклом
    	long sum = 0;
    	for (int i = pos; i < pos + blockLength; i++) {
    		for (int j = 0; j < matr[i].length; j++) {
    			sum += matr[i][j];
    		}
    	}
    	Monitor.getInstance().incSum(sum); // проверяем сумму
    	if (incThread(numThread)) {
    		threadCnt = 0;
    		Monitor.getInstance().setEndTime(); // вырубаем подсчет времени 
    		Monitor.getInstance().showResult(
    			"Кол. потоков: " + numThread
    			+ "; Двумерный массив(" + matr.length + "," + matr[0].length + ")"
    		); // выводим 
    	}
    }
    
    private static synchronized boolean incThread(int numThread) {
		return ++threadCnt == numThread;
	}

}