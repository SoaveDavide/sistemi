using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Conversioni
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] dp = new int[4];

            for (int i = 0; i < dp.Length; i++)
            {
                Console.WriteLine($"Inserire la {i + 1}° otteto");
                dp[i] = Convert.ToInt32(Console.ReadLine());
            }
            bool[] bn = Convert_dp_to_binario(dp);

            for (int i = 0; i < bn.Length; i++)
            {
                Console.Write(Convert.ToInt32(bn[i]));
            }
            Console.WriteLine("*************************************");

            //Console.WriteLine(Convert_dp_to_int(dp));
            Console.WriteLine(Convert_binario_to_int(bn));
            Console.ReadLine();
        }
        static bool[] Convert_dp_to_binario(int[] dp)
        {
            int z = 0;
            //int ultimoElemento = 0;
            bool[] bn = new bool[32];

            for (int i = 0; i < dp.Length; i++)
            {
                do
                {
                    if (dp[i] % 2 == 0)
                        bn[z] = false;
                    else
                        bn[z] = true;

                    dp[i] = dp[i] / 2;
                    z++;
                    //ultimoElemento = z;
                } while (dp[i] > 0);
            }
            return bn;
        }
        static int Convert_dp_to_int(int[] dp)
        {
            int intero = 0;
            int potenza = 0;
            for (int i = dp.Length - 1; i >= 0; i--)
            {
                intero += dp[i] * (int)Math.Pow(256, potenza);
                potenza++;
            }
            return intero;
        }
        static int Convert_binario_to_int(bool[] bn)
        {
            int intero = 0;
            int potenza = 0;
            for (int i = 0; i < bn.Length; i++)
            {
                intero += (int)(Convert.ToInt32(bn[i]) * Math.Pow(2, potenza));

            }
            return intero;
        }
        /*
        static int[] Convert_binario_to_decimalePuntato (bool[] bn) 
        {

        }
        */
    }
}
        printf("%d", vetto[i]);
    }
}
void Stampa(int vettore[], int j)
{
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", vettore[i]);
    }
}

int Inserimento(int numero, int n, int vet[])
{
    vet[n] = numero;
    return n + 1;
}

void StampaInverso(int v[], int h)
{
    for (int i = h - 1; i >= 0; i--)
    {
        printf("%d \n", v[i]);
    }
}

int Ricerca(int ricerca, int ve[], int g)
{
    int uguale = ricerca;
    int posizione;
    for (int i = 0; i < g; i++)
    {
        if (ve[i] == ricerca)
        {

            posizione = i;
            break;
        }
    }
    return posizione;
}
int Max(int vet[], int k)
{
    int max = vet[0];
    for (int i = 1; i < k; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
    }
    return max;
}
int Modifica(int vettor[], int numero, int posizione)
{
    vettor[posizione] = numero;
    return posizione;
}
int inserisci_in_posizione(array, n, posizione, valore)
{
    for (int i = *n; i >= posizione; i--)
	{
		array[i] = array[i - 1];
	}
	array[posizione] = valore;
	(*n)++;
	return posizione;
}
int main(int argc, char *argv[])
{
    int array[SHRT_MAX];
    int i = 0;
    int num;
    int scelta, ricerca, trovato, elimina, valore;
    int modifica, posizione, *n;

    do
    {
        printf("Inserisci un numero (inserisci -1 per terminare):\n");
        scanf("%d", &num);
        if (num != -1)
        {
            array[i] = num;
            i++;
        }
    } while (num != -1);

    do
    {
        scelta = Menu();
        if (scelta == 1)
        {
            Stampa(array, i);
        }
        else if (scelta == 2)
        {
            printf("Quale elemento vuoi inserire?\n");
            scanf("%d", &num);
            i = Inserimento(num, i, array);
        }
        else if (scelta == 7)
        {
            StampaInverso(array, i);
        }
        else if (scelta == 0)
        {
            printf("Programma finito\n");
        }
        else if (scelta == 5)
        {
            printf("Quale elemento vuoi ricercare?\n");
            scanf("%d", &ricerca);
            trovato = Ricerca(ricerca, array, i);
            printf("L'elemento si trova in posizione:\n %d", trovato);
        }
        else if (scelta == 8)
        {
            int massimo = Max(array, i);
            printf("Il numero massimo all'interno dell'array è: %d \n", massimo);
        }
        else if (scelta == 4)
        {
            printf("Inserisci l'indice dell'elemento che vuoi eliminare: \n");
            scanf("%d", &elimina);
            Elimina(array, i, elimina);
        }
        else if (scelta == 3)
        {
            printf("Quale elemento vuoi modificare?\n");

            scanf("%d", &modifica);
            posizione = Ricerca(ricerca, array, i);
            if (posizione > -1)
            {
                printf("Inserisci il nuovo valore: ");
                scanf("%d", &valore);
                Modifica(array, valore, posizione);
            }
            else
            {
                printf("Elemento non trovato\n");
            }
        }
        else if (scelta == 6)
        {
            printf("Quale elemento vuoi inserire?\n");
            scanf("%d", &valore);
            printf("In quale posizione?");
            scanf("%d", &posizione);
            if (posizione < *n)
            {
                inserisci_in_posizione(array, n, posizione, valore);
            }
            else
            {
                printf("valore non esistente");
            }
        }
    } while (scelta != 0);

    return 0;
}
