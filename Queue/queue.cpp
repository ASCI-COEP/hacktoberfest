#include <iostream>

using namespace std;

class Queue{

    int first, last, n, cnt, limit;
    int * queue;

    public:
        Queue(int size){
            first = last = 0;
            limit = size;
            queue = new int[size];
        }

        bool fullQueue(){
            if(((last + 1) % limit) == first){
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
                last = (last + 1) % limit;
            }else{
                cout << "The queue is full" << endl;
            }

        }

        int dequeue(){
            if(!emptyQueue()){
                n = queue[first];
                first = (first + 1) % limit;
                return n;
            }

            return 0;
        }
        void show(){
            int aux = first;
            while( !emptyQueue() && aux != last ){
                cout << queue[aux] << endl;
                aux = (aux + 1) % limit;
            }

        }
};

int main(){
  //creating a queue object...
  int queue_size = 0;
  cout << "Please enter the queue size: " << endl;
  cin >> queue_size;
  Queue q = Queue(queue_size);
  /*start coding here...*/

  return 0;
}
