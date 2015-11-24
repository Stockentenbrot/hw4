#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double *lesen(const char *filename, int N);
void filtern(double *Daten, int N);
void speichern(double *Daten,int N, const char *filename);


int main(void)
{
  int N = 237;
  double *Daten;
  const char *Quelle = "noisy.txt";
  const char *Ziel = "filtered.txt";
  
  Daten = lesen(Quelle,N);
  filtern(Daten,N);
  speichern(Daten,N,Ziel);
  
  delete[] Daten;
  exit(0);
}

double *lesen(const char *filename, int N)
{
  int i;
  ifstream daten_stream(filename);
  double *Daten = new double[N];
  for (i = 0; i < N; i++)
  {
    daten_stream >> Daten[i];
  }
  daten_stream.close();
  return Daten;
}

void filtern(double *Daten, int N)
{
  int i;
  
  double temp,temptemp;
  
  temp = Daten[0];
  
  Daten[0] = (Daten[N-1] + Daten[0] + Daten[1]) / 3.0;
  
  temptemp = Daten[0];
  for (i = 1; i < N-1; i++)
  {
    temp = Daten[i];
    Daten[i] = (temptemp + Daten[i] + Daten[i+1]) / 3.0;
    temptemp = temp;
  }
  
  Daten[N-1] = (Daten[N-2] + Daten[N-1] + Daten[0]) / 3.0;
  return;
}

void speichern(double *Daten,int N, const char *filename)
{
    ofstream out(filename);
    for(int i = 0; i < N; i++)
    {
	out << Daten[i] << endl;
    }
    out.close();
    return;
}