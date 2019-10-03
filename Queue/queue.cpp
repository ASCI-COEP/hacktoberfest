#include <iostream>

using namespace std;

class Queue{

    int first, last, n, cnt;
    int queue[5];

    public:
        Queue(){
            first = last = 0;
        }

        bool fullQueue(){
            if(((last + 1) % 5) == first){
                return true;
            }
            return false;
        }

        bool emptyQueue(){
            if( last == first){
              return true;
            }
            return false;
        }
        void enqueue(int x){
            if(!fullQueue()){
                queue[last] = x;
                last = (last + 1) % 5;
            }else{
                cout << "The queue is full" << endl;
            }

        }

        int dequeue(){
            if(!emptyQueue()){
                n = queue[first];
                first = (first + 1) % 5;
                return n;
            }

            return 0;
        }
        void show(){
            int aux = first;
            while( !emptyQueue() && aux != last ){
                cout << queue[aux] << endl;
                aux = (aux + 1) % 5;
            }

        }
};

int main(){
  //for testing...

  return 0;
}
