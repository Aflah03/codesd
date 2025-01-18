
class ThreadAA extends Thread {
    private final Object lock;

    public ThreadAA(Object lock) {
        this.lock = lock;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                synchronized (lock) {
                    // Print ThreadA's output
                    System.out.print(Thread.currentThread().getName() + " ");
                    // Notify ThreadB to take over
                    lock.notify();
                    // Wait for ThreadB to print
                    lock.wait();
                }
                Thread.sleep(500); // Optional: delay to observe the output more clearly
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt(); // Reset the interrupt status
        }
    }
}

class ThreadBB extends Thread {
    private final Object lock;

    public ThreadBB(Object lock) {
        this.lock = lock;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                synchronized (lock) {
                    // Print ThreadB's output
                    System.out.println(Thread.currentThread().getName());
                    // Notify ThreadA to take over
                    lock.notify();
                    // Wait for ThreadA to print
                    lock.wait();
                }
                Thread.sleep(500); // Optional: delay to observe the output more clearly
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt(); // Reset the interrupt status
        }
    }
}

public class threadexample {
    public static void main(String[] args) {
        Object lock = new Object();

        ThreadAA a = new ThreadAA(lock);
        ThreadBB b = new ThreadBB(lock);

        a.setName("Thread-0");
        b.setName("Thread-1");

        a.start();
        b.start();
    }
}
