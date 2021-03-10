package thread;

public class Monitor { // это класс для рассчета времени
        
        private static Monitor instance = new Monitor(); // екземпляр класса 
        
        public static Monitor getInstance() { // гетер 
            return instance;
        }
        
        private Monitor() {}
        
        private long startTime;
        private long endTime;
        
        private long sum;
        
        public synchronized void setStartTime() { // функция для начала рассчетов
            startTime = System.nanoTime();
        }
        
        public synchronized void setEndTime() { // функция для окончания рассчетов 
            endTime = System.nanoTime();
        } 
        
        public synchronized void incSum(long sum) { // функция для подсчета суммы выходящий из тредов 
            this.sum += sum;
        }
        
        public synchronized void showResult(String msg) { // обычный вывод суммы и затраченого времени
            System.out.println(msg + ": ");
            System.out.println("Сумма элементов: " + sum);
            System.out.println("Затраченное время: " + ((double) endTime - startTime) / 1000 + " мкс");
            sum = 0;
            notify();
        }
        
        public synchronized void waitCalculating() { // функция которая ждет пока тред досчитает сумму
            try {
                wait();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    
    }