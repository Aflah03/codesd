


import java.util.Random;

class RandomNumberThread extends Thread {
    private SharedData sharedData;

    public RandomNumberThread(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        Random random = new Random();
        while (true) {
            int number = random.nextInt(100); // Generate a random integer (0-99)
            System.out.println("Generated Number: " + number);
            sharedData.setNumber(number); // Pass number to shared data
            try {
                Thread.sleep(1000); // Sleep for 1 second
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class SquareThread extends Thread {
    private SharedData sharedData;

    public SquareThread(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        while (true) {
            int number = sharedData.getNumber();
            if (number % 2 == 0) { // Check if even
                System.out.println("Square of " + number + ": " + (number * number));
            }
            try {
                Thread.sleep(500); // Prevent excessive looping
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class CubeThread extends Thread {
    private SharedData sharedData;

    public CubeThread(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        while (true) {
            int number = sharedData.getNumber();
            if (number % 2 != 0) { // Check if odd
                System.out.println("Cube of " + number + ": " + (number * number * number));
            }
            try {
                Thread.sleep(500); // Prevent excessive looping
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class SharedData {
    private int number = 0;

    public synchronized void setNumber(int number) {
        this.number = number;
    }

    public synchronized int getNumber() {
        return number;
    }
}

public class MultiThreadedNumberProcessing {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();

        RandomNumberThread randomThread = new RandomNumberThread(sharedData);
        SquareThread squareThread = new SquareThread(sharedData);
        CubeThread cubeThread = new CubeThread(sharedData);

        randomThread.start();
        squareThread.start();
        cubeThread.start();
    }
}

