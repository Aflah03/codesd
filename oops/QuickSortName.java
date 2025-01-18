
public class QuickSortName{

	public static void quickSort(String arr[],int low,int high){
		if(low < high){
		int partitionIndex = parttion(arr,low,high);

			quickSort(arr,low,partitionIndex-1);
			quickSort(arr,partitionIndex+1 ,high);
		}
		
	}
	public static int parttion(String[] arr,int low,int high){
		String pivot = arr[high];
		int i = low-1;
		for(int j=low;j<high;j++){
			if(arr[j].compareToIgnoreCase(pivot)<0){
			i++;
			String temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			}
		}

		String temp = arr[high];
		arr[high]= arr[i+1];
		arr[i+1] = temp;
		return i+1;
	}

	public static void display(String arr[]){
		System.out.println("The list is ");

		for(String names: arr){
			
		System.out.println(names);

		}
	}

	public static void main(String[] args){
		String names[]={"Aflah","Abel","Babu"};

		quickSort(names,0,names.length-1);
		display(names);
	}

}

