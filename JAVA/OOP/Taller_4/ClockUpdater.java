final class ClockUpdater extends Thread {

    Clock reloj;
    int secondtenth = 0;

    ClockUpdater(Clock reloj) {

        this.reloj = reloj;
    }

    public void run() { //Aumenta los segundos del reloj

        while (true) {
       
            try {
                Thread.sleep(100);
                secondtenth += 1;

                if(secondtenth > 9){
                    reloj.setTime(reloj.getTime() + 1);
                    secondtenth = 0;
                }
                
            } catch (InterruptedException e) {
                System.out.println("Reloj Detenido!");
            }
        }
       
    }

  }