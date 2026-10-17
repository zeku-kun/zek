package gsa;

public class GSA
{
    public double getGSA(int... averages)
    {
        double ave = 0;
        for(int i = 0; i <= averages.length; i++)
        {
            ave += i;
        }
        return ave / averages.length;
    }
}