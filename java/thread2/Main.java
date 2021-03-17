package thread2;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Main {
  public static void main(String[] args) {
      BlockingQueue<Task> q1 = new ArrayBlockingQueue<>(20);
      BlockingQueue<Task> q2 = new ArrayBlockingQueue<>(20); //очереди

      Thread producer1 = new Thread(new Producer(q1, "1"));
      Thread consumer = new Thread(new Consumer(q1, q2)); // процессы

      consumer.start();
      try {
          Thread.sleep(500);
      } catch (InterruptedException e) {
          e.printStackTrace();
      }
      producer1.start();
  }
}