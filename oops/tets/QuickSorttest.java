public class QuickSorttest{

    public static void quickSort(String[] names,int low,int high){
        if(low<high){
            int partitionIndex = partition(names,low,high);

            quickSort(names, low, partitionIndex-1);
            quickSort(names, partitionIndex+1,high);
        }
    }

    public static int partition(String names[],int low,int high){
        String pivot = names[high];
        int i = low-1;
        for(int j=low;j<high;j++){
            if(names[j].compareToIgnoreCase(pivot) < 0){
                i++;
                String temp = names[j];
                names[j] = names[i];
                names[i]= temp;
            }
        }
        String temp = names[high];
        names[high] = names[i+1];
        names[i+1] = temp;
        return i+1;
    }
   public static void main(String[] args) {
    String[] names = new String[]{"Aflah ","Abel","Umar","Agnivesh"};

quickSort(names, 0, 3);
    for(String name: names){
        System.out.println(name);
    }
   } 
}