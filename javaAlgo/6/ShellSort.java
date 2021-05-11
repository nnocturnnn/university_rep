import java.util.*;


public class ShellSort {
    public static void main(String[] args) {
      int[] arr = new int[10];
      for (int i = 0; i < arr.length; i++) {
          arr[i] = (int)Math.floor(Math.random()*(50-10+1)+10);
      }
      // System.out.println("Input array- " + Arrays.toString(arr));
      long a = System.currentTimeMillis();
      int[] sortedArray = shellSort(arr);
      long b = System.currentTimeMillis();
      System.out.println(b - a);
      // System.out.println("Sorted array after shell sort- " + Arrays.toString(sortedArray));
    }
      
    private static int[] shellSort(int[] arr){
      int interval = 1;
      int temp;
      int num_por = 0;
      int num_per = 0;
      while(interval <= arr.length/3){
        interval = (interval * 3) + 1;
      }
      while(interval > 0){
        for(int i = interval; i < arr.length; i++){
          num_por++;
          temp = arr[i];
          int j;                
          for(j = i; j > interval - 1 && arr[j-interval] >= temp; j=j-interval){
            arr[j] = arr[j - interval];                    
            num_per++;
          }
          arr[j] = temp;
        }
        interval = (interval - 1)/3;
      }
      System.out.println("Por : " + num_per);
      System.out.println("Shaf : " +num_por);
      return arr;
    }
  }