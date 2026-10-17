import gsa.GSA;
import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
    static ArrayList<Double> getStudAvg()
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Double> studListAvg = new ArrayList<>();
        final int NUM_SUBJECTS = 4;

        System.out.print("Enter how many students to record: ");
        int numStud = sc.nextInt();

        for (int i = 1; i <= numStud; i++)
        {
            double grades = 0;
            System.out.println("Enter Student " + i + " grades:");

            System.out.print("Programming-Java: ");
            grades += sc.nextInt();

            System.out.print("Inquiries, Investigation, and Immersion: ");
            grades += sc.nextInt();

            System.out.print("Introduction to Philosophy of the Human Person: ");
            grades += sc.nextInt();

            System.out.print("Filipino ng Pilig Larangan: ");
            grades += sc.nextInt();

            studListAvg.add(grades / NUM_SUBJECTS);
        }

        return studListAvg;
    }

    public static void main(String[] args)
    {
        ArrayList<Double> averages = getStudAvg();
        GSA gsa = new GSA();
        double genSchoAve = gsa.getGSA(averages);
        System.out.println("General Scholastic Average: " + genSchoAve);
    }
}