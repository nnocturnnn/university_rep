package thread2;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class Consumer implements Runnable {  // Выполнения задач по фрагменту (если буффер полный переход в режим ожидания )
    private BlockingQueue<Task> q1;
    private BlockingQueue<Task> q2;
    private String threadId;

    public Consumer(BlockingQueue<Task> q1, BlockingQueue<Task> q2) {
        this.q1 = q1;
        this.q2 = q2;
    }

    public void run() {
        threadId = "Consumer-" + Thread.currentThread().getId(); // берем айдишник
        try {
            while (true) {
                Task task1 = q1.poll(1, TimeUnit.SECONDS); // создаем задачу и удалением элемент из начала очереди. Если очередь пуста, возвращает значение null

                if (task1 != null) { // проверяем не пустая ли задача 
                    consume(task1, "1"); // переход в ожидание если буфер полный 
                } else {
                    Task task2 = q2.poll(1, TimeUnit.SECONDS);

                    if (task2 != null) {
                        consume(task2, "2");
                    } else {
                        break;
                    }

                }
            }

            System.out.println("\n" + threadId + " STOPPED.\n");
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }
    }

    private void consume(Task task, String type) throws InterruptedException {
        System.out.printf("%s: Consuming a task number %s of type %s\n", threadId, task.id, type);
        Thread.sleep(task.timeToComplete); 
    }
}