using namespace std;
#include <iostream>

class stack
{
    private:
        int *S;
        int top;
        int maxsize;
    public:
        stack(int size){
            maxsize = size;
            S = new int[maxsize];
            top = -1;
        }
        ~stack(){
            delete[] S;
        }
        void push(int k){
            if (top == maxsize - 1)
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            S[top] = k;
        }
        int pop(){
            if (top == -1)
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int k = S[top];
            top--;
            return k;
        }
        bool isEmpty(){
            if (top == -1)
            {
                return true;
            }
            return false;
        }
        int getTop(){
            if (top == -1)
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return S[top];
        }
        void printStack(){
            if (top == -1)
            {
                cout << "Stack Underflow" << endl;
                return;
            }
            for (int i = top; i >= 0; i--)
            {
                cout << S[i] << " ";
            }
            cout << endl;
        }
};

template <typename T>

class queue{
    private:
        struct queueList
        {   
            T k;
            queueList *next;
        };
        typedef queueList *pqueueList;

        pqueueList q = NULL;
        
    public:

    void printq(){
        pqueueList tmp = q;
        while (tmp != NULL)
        {
            cout<<tmp->k<<"\t";
            tmp = tmp->next;
        }
        cout<<endl;
    }

    bool isEmpty(){
        if (q == NULL){
            return true;
        }
        return false;
    }

    void enqueue(T k){
        if (q == NULL)
        {
            q = new queueList;
            q->k = k;
            q->next = NULL;
        }
        else{
            pqueueList tmp = q;
            pqueueList entry = new queueList;
            entry->k = k;
            entry->next = NULL;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = entry;
        }
    }
    
    T dequeue(){
        pqueueList tmp = NULL;
        tmp = q->next;
        T x = q->k;
        q = tmp;
        return x;
    }
};
