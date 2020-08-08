#include<iostream>
#define MAX 10
using namespace std;

class Queue{
    private:
        int head, tail;
        int a[MAX];

    public:

        Queue(){
            head = -1;
            tail = -1;
        }

        bool IsEmpty(){
            if(head == -1 && tail == -1) return true;
            else return false;
        }

        void Enqueue(int x){
            if(tail == sizeof(a) -1){
                cout<<"The queue id full. \n";
            }
            else if(IsEmpty() == true){
                head = tail = 0;
            }
            else{
                tail = (tail + 1)%MAX;
            }
            a[tail] = x;
        }

        void Dequeue(){
            cout<<"Dequeueing.....\n";
            if(IsEmpty() == true){
                cout<<"ERROR: Can't dequeue, the queue is empty.\n";
            }
            else if(head == tail){
                head = tail = -1;
            }
            else{
                head = (head + 1)%MAX;
            }
        }

        int Front(){
            if(head == -1){
                cout<<"ERROR: Can't return the front element in queue, the queue is empty.\n";
            }
            else{
                cout<<"The front element is: "<<a[head]<<endl;
            }

            return 0;
        }

        void Print(){
            int num = (tail + MAX - head) % MAX + 1;
            cout<<"Elements in queue: ";
            for(int i = 0; i < num; i++){
                int index = (head + i) % MAX;
                cout<<" "<<a[index]; 
            }
            cout<<endl;
        }


};


int main(){
    Queue qObj;
    qObj.Enqueue(2);
    qObj.Print();
    qObj.Enqueue(3);
    qObj.Print();
    qObj.Enqueue(4);
    qObj.Print();
    qObj.Dequeue();
    qObj.Print();
    qObj.Enqueue(5);
    qObj.Print();
    qObj.Front();

    return 0;

}
