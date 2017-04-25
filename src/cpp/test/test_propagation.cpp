#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <vector>

#include "inner_set_0.cpp"
#include "inner_set_1.cpp"
#include "inner_set_2.cpp"
#include "inner_set_3.cpp"
#include "inner_set_4.cpp"
#include "inner_set_5.cpp"

#include "inner_array_set.cpp"
#include "inner_unordered_set.cpp"
#include "inner_tree_set.cpp"

#include "micro_set.cpp"
#include "micro_unordered_set.cpp"
#include "micro_tree_set.cpp"

 //#define MEGABYTE 1024L * 1024L
 #define POOL_SIZE 20
 #define STOCK_SIZE 1000
 #define LISTE_CROISSANTE_SIZE 500
 #define NOMBRE_TIRAGE 1000

 using namespace std;

void test_propagation(micro_set<int> p_micro_set)
{
  chrono::time_point<chrono::system_clock> start, end;

  srand( (unsigned) time(nullptr));


  vector<int> testObjects;
  for (int i =  0; i< POOL_SIZE; i++)
    testObjects.push_back((rand() % 100) + 1);

  int randomIndiceListeCroissante [NOMBRE_TIRAGE];
  for (int i =  0; i< NOMBRE_TIRAGE; i++)
  randomIndiceListeCroissante[i] = (rand() % LISTE_CROISSANTE_SIZE) + 1;

  int randomIndiceStock [NOMBRE_TIRAGE];
  for (int i =  0; i< NOMBRE_TIRAGE; i++)
    randomIndiceStock[i] = (rand() % STOCK_SIZE) + 1;

  int numberOfObject [STOCK_SIZE];
  for (int i =  0; i< STOCK_SIZE; i++)
    numberOfObject[i] = (rand() % 4) + 1;

  vector<micro_set<int>* > stock;
  for (int i = 0; i < STOCK_SIZE; i++)
  {
    micro_set<int>* microSet = new micro_set<int>();
    for (int j = 0; j < numberOfObject[i]; j++)
    {
      microSet->insert(testObjects.at((rand() % POOL_SIZE) + 1));

      stock.push_back(microSet);
    }
  }

  vector<micro_set<int>* > listeCroissante;

  for (int i = 0; i < LISTE_CROISSANTE_SIZE; i++)
  {
    micro_set<int>* m = new micro_set<int>();
    listeCroissante.push_back(m);
  }

  start = chrono::system_clock::now();

  // START TEST
  for (int i=0; i< NOMBRE_TIRAGE; i++)
  {
    int indice = randomIndiceListeCroissante[i];
    micro_set<int>* increment = stock.at(randomIndiceStock[i]);
    //System.out.println(indice + "|" + increment);
    for (int j = indice; j < LISTE_CROISSANTE_SIZE && !increment->empty(); j++)
      increment = listeCroissante.at(j)->add_all_and_propagate(*increment);
  }


  end = chrono::system_clock::now();
  int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                           (end-start).count();


  // Calculate the used memory
  cout << elapsed_seconds << endl;
}


int main()
{
    micro_set<int> m;
    test_propagation(m);


    return 0;
}
