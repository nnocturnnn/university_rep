package thread;

public class Monitor {
        
        private static Monitor instance = new Monitor();
        
        public static Monitor getInstance() {
            return instance;
        }
        
        private Monitor() {}
        
        private long startTime;
        private long endTime;
        
        private long sum;
        
        public synchronized void setStartTime() {
            startTime = System.nanoTime();
        }
        
        public synchronized void setEndTime() {
            endTime = System.nanoTime();
        }
        
        public synchronized void incSum(long sum) {
            this.sum += sum;
        }
        
        public synchronized void showResult(String msg) {
            System.out.println(msg + ": ");
            System.out.println("Сумма элементов: " + sum);
            System.out.println("Затраченное время: " + ((double) endTime - startTime) / 1000 + " мкс");
            sum = 0;
            notify();
        }
        
        public synchronized void waitCalculating() {
            try {
                wait();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    
    }