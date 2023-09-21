using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Targa
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string targa, parte1, parte2, parte3, finale2;
            int posizione2 = 0;
            double posizione = 0, valore1 = 0, valore23 = 0, temp = 0, valore = 0;
            char[] alfabeto = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };//Alfabeto inglese
            Console.WriteLine("Inserisci targa");
            targa = Console.ReadLine();
            parte1 = targa.Substring(2, 3);
            parte2 = targa.Substring(0, 2);
            parte3 = targa.Substring(5);
            finale2 = parte2 + parte3; //Ricostruisco le prime 4 lettere della targa
            for (int i = 0; i < parte1.Length; i++)
            {
                valore1 += (parte1[i] - 'A') * Math.Pow(10, i);
            }
            for (int i = 0; i < finale2.Length; i++)
            {

                posizione2 = Array.IndexOf(alfabeto, finale2[i]);//Ricerca il valore numerico che equivale alla posizione della lettera all'interno dell'array

                if (posizione2 != -1)
                {
                    temp = posizione * Math.Pow(26, i);
                    posizione = temp + posizione2;
                }
            }
            valore23 = posizione * Math.Pow(10, 3);
            //Console.WriteLine(parte1);
            valore = valore23 + valore1;
            Console.WriteLine(valore);
            /*finale = parte2 + parte3 + parte1;//ordino la targa
            Console.WriteLine(finale);*/
            Console.ReadLine();
        }
    }
}
