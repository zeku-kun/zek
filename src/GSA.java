package gsa;
import java.util.ArrayList;

public class GSA
{
    public double getGSA(ArrayList<Double> averages)
    {
        double ave = 0;
        for(int i = 0; i < averages.size(); i++)
        {
            ave += averages.get(i);
        }
        return ave / averages.size();
    }
}