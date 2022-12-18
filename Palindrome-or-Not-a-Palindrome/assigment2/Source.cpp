#include<iostream>
#include <cassert>
#include<cstring>

using namespace std;


class phrase{
private:
        char content[100];
		char ph[100];
		char *stack;
		char stackTop;
		int maxSize;
public:
	    void push(int);
        void pop();
        int top();
        bool isEmpty();
        bool isFull();
        void readPhrase();
        bool isPalindrome();

};


bool phrase::isEmpty()
{
    return (stackTop == 0);
}

bool phrase::isFull()
{
    return (stackTop == maxSize);
}

void phrase::push(int item)
{
    if(isFull())
        cout<<"Full stack"<< endl;
    else
        stack[stackTop++] = item;
}

int phrase::top()
{
    assert(!isEmpty());
   
    return stack[stackTop - 1];
}

void phrase::pop()
{
    if(isEmpty())
        cout<<"Empty stack" << endl;
    else
        stackTop--;
}

void phrase::readPhrase()
{
    cout<<"\nEnter the Sentence : ";
    cin>>content;
}


bool phrase::isPalindrome()
{
    phrase temp;
    int i,j=0;
    for(i=0;i<strlen(content);i++)
      {
         temp.push(content[i]);
      }
    while(!temp.isEmpty())
      {
         if(temp.top()!=content[j])
         return 0;
         j++;
         temp.pop();
      }
   return 1;
}



int main()
{
   phrase a;
   
   a.readPhrase();
   
   if (a.isPalindrome())
    cout<<"\nThe String Is Palindrome"<<endl;
   else
    cout<<"\nThe String Is Not a Palindrome"<<endl;
	
   return 0;
}