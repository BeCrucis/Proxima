import java.awt.Toolkit;
import java.io.IOException;
import java.util.Scanner;

/**
 * Reloj
 */
public class Clock {

    int year;
    int month;
    int day;
    int time = 0; // Tiempo total del dia netamente en segundos
    int hour = time / 3600;
    int minute = (time % 3600) / 60;
    int second = (time % 3600) % 60;

    public Clock(int year, int month, int day, int time) {

        this.year = year;
        this.month = month;
        this.day = day;

        this.time = time;
        updateClock();
        updateCalendar();
    }

    public Clock(int year, int month, int day, int hour, int minute, int second) {

        this.year = year;
        this.month = month;
        this.day = day;

        this.hour = hour;
        this.minute = minute;
        this.second = second;
        updateTime();
        updateCalendar();
    }

    public void updateClock() {

        hour = time / 3600;
        minute = (time % 3600) / 60;
        second = (time % 3600) % 60;

        if (second > 59) {

            minute += second / 60;
            second = second % 60;
        }

        if (minute > 59) {

            hour += minute / 60;
            minute = minute % 60;
        }

        if (hour > 23) {

            day += hour / 24;
            hour = hour % 24;
        }

    }

    public void updateTime() {

        time = (hour * 3600) + (minute * 60) + second;

        if (time > 86399) {

            day += time / 86400;
            time = time % 86400;
        }
    }

    public void updateCalendar() {

        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                && day > 31) {
            month += 1;
            day -= 31;
            updateCalendar();
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            month += 1;
            day -= 30;
            updateCalendar();
        }

        if (month == 2 && (year % 4 == 0) && day > 29) {
            month += 1;
            day -= 29;
            updateCalendar();
        }

        if (month == 2 && (year % 4 != 0) && day > 28) {
            month += 1;
            day -= 28;
            updateCalendar();
        }

        if (month > 12) {

            year += month / 12;
            month = month % 12;
            updateCalendar();
        }

    }

    public int getTime() {
        return time;
    }

    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public int getSecond() {
        return second;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public String getFormattedTime() {

        updateClock();

        String formattedTime = String.format("%02d:%02d:%02d", hour, minute, second);
        return formattedTime;
    }

    public String getFormattedDate() {

        updateClock();
        updateCalendar();

        String formattedDate = String.format("%02d/%02d/%02d", year, month, day);
        return formattedDate;
    }

    public static void cronometro() throws IOException {

        Scanner sc = new Scanner(System.in);

        System.out.print("Presione enter para iniciar el cronometro y enter para detenerlo . . .");
        sc.nextLine();

        Thread hiloCronometro = new Thread(new Runnable() {
            public void run() {

                Clock cronometro = new Clock(0, 0, 0, 0, 0, 1);
                ClockUpdater contador = new ClockUpdater(cronometro);
                contador.start();

                while (true) {
                    try {
                        Thread.sleep(100);
                        cronometro.updateClock();
                        System.out.println(cronometro.getFormattedTime()+":"+ contador.secondtenth);

                    } catch (InterruptedException e) {
                        
                    }
                    
                    
                }
            }
        });

        hiloCronometro.start();
        sc.nextLine();
        hiloCronometro.stop(); //Siento usar esto, pero no tengo metodos mejores para manejar los hilos
    
    }

    public void alarma(){

        Scanner sc = new Scanner(System.in);
        int alarmHours, alarmMinutes, alarmSeconds;

        try {

            System.out.printf("Inserte dentro de cuantas horas desea la alarma: ");
            alarmHours = Integer.parseInt(sc.nextLine());
        } catch (Exception e) {
            alarmHours = 0;
        }
        
        try {
            
            System.out.printf("Inserte dentro de cuantos minutos desea la alarma: ");
            alarmMinutes = Integer.parseInt(sc.nextLine());
        } catch (Exception e) {
            alarmMinutes = 0;
        }

        try {
            
            System.out.printf("Inserte dentro de cuantos segundos desea la alarma: ");
            alarmSeconds = Integer.parseInt(sc.nextLine());
        } catch (Exception e) {
            alarmSeconds = 0;
        }
        

        
        int totalTimeDelta = alarmHours*3600 + alarmMinutes*60 + alarmSeconds;

        //Se crea un objeto reloj cuyo tiempo no avanza, hecho a partir del reloj actual mas la diferencia de tiempo en segundos

        Clock alarm = new Clock(year, month, day, time);
        alarm.setTime(getTime() + totalTimeDelta);
        alarm.updateClock();
        alarm.updateCalendar();

        Thread alarmChecker = new Thread(new Runnable() {
            public void run() {

                while (true) {
                    try {
                        Thread.sleep(300);
                        if(alarm.getFormattedDate() != getFormattedDate()){
                            if(alarm.getTime() <= getTime()){
                                //System.out.println("ALARMA");
                                Toolkit.getDefaultToolkit().beep();
                                break;
                            } else {
                                alarm.updateCalendar();
                                updateCalendar();
                            }
                        }
                        

                    } catch (InterruptedException e) {
                        System.out.println("ERROR EN LA ALARMA");
                    }
                    
                    
                }
            }
        });
        
        alarmChecker.start();

    }

   
    
}