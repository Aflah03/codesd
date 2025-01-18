
import java.util.*;



public class heapsort1 {
    static int size =0;
    private static void heapify(int[] arr,int heapsize,int i){
        int r= 2*i+2;
        int l =2*i+1;
        int largest=i;
        if(l<heapsize && arr[l]>=arr[i]){
            largest = l;
        }else if(r< heapsize && arr[r]>= arr[i]){
            largest = r;
        }

        if(arr[largest] != arr[i]){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest]= temp;
            heapify(arr,heapsize,largest);
        }
    }
    private static void buildMaxHeap(int[] arr){
        for(int i=size/2-1;i>=0;i--){
                heapify(arr, size, i);
        }

    }
    private static void heapsort(int[] arr){
        buildMaxHeap(arr);
        int currentSize = size;
        for(int i=size-1;i>=1;i--){
            int temp =arr[i];
            arr[i] = arr[0];
            arr[0]= temp;
            currentSize--;
            heapify(arr, currentSize, 0);
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1,5,3,2,6,7};
        size = arr.length;
        heapsort(arr);

        Arrays.sort(arr);
        for(int nums: arr){
            System.out.println(nums);
        }

    }
    
}
