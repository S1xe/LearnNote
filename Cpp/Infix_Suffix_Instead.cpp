#include <iostream>
#include <cassert>
#include <new>
#include <cctype>
#include <string>
typedef char StackElement;
class Stack
{
public:
    Stack(int numElements = 128);
    Stack(const Stack &original);
    ~Stack();
    Stack &operator=(const Stack &original);
    bool empty() const;
    void push(const StackElement &value);
    void display(std::ostream &out) const;
    StackElement top() const;
    void pop();

private:
    int myCapacity;
    int myTop;
    StackElement *myArray;
};

Stack::Stack(int numElements)
{
    assert(numElements > 0);
    myCapacity = numElements;
    myArray = new (std::nothrow) StackElement[myCapacity];
    if (myArray != 0)
        myTop = -1;
    else {
        std::cerr << "Inadequate memory to allocate stack \n"
                  << " -- terminating execution\n";
        exit(1);
    }
}
Stack::Stack(const Stack &original) : myCapacity(original.myCapacity), myTop(original.myTop)
{
    myArray = new (std::nothrow) StackElement[myCapacity];
    if (myArray != 0) {
        for (int pos = 0; pos <= myTop; pos++)
            myArray[pos] = original.myArray[pos];
    } else {
        std::cerr << "*Inadequate memory to allocate stack ***\n";
        exit(1);
    }
}

Stack::~Stack() { delete[] myArray; }
Stack &Stack::operator=(const Stack &original)
{
    if (this != &original) {
        if (myCapacity != original.myCapacity) {
            delete[] myArray;
            myCapacity = original.myCapacity;
            if (myArray != 0) {
                myTop = original.myTop;
                for (int pos = 0; pos <= myTop; pos++)
                    myArray[pos] = original.myArray[pos];
            } else {
                std::cerr << "*Inadequate memory to allocate stack ***\n";
                exit(1);
            }
        }
    }
    return *this;
}

bool Stack::empty() const { return (myTop == -1); }
void Stack::push(const StackElement &value)
{
    if (myTop < myCapacity - 1) {
        ++myTop;
        myArray[myTop] = value;

    } else {
        std::cerr << "*** Stack full -- can't add new value ***\n"
                  << "Must increase value of myCapacity\n";
        exit(1);
    }
}
void Stack::display(std::ostream &out) const
{
    for (int i = myTop; i >= 0; --i)
        out << myArray[i] << std::endl;
}
StackElement Stack::top() const
{
    if (!empty())
        return myArray[myTop];
    else {
        std::cerr << "*** Stack is empty -- returning -1 ***\n";
        return -1;
    }
}
void Stack::pop()
{
    if (!empty())
        myTop--;
    else {
        std::cerr << "*** Stack is empty -- can't remove a value ***\n";
    }
}

std::string postfix(std::string exp);

int main()
{
    std::string infixExp;
    std::cout << "NOTE:Enter # for infix experession to stop. \n";
    while (1) {
        std::cout << "Infix experession?";
        std::getline(std::cin, infixExp);

        if (infixExp == "#")
            break;
        std::cout << "Postfix experession is " << postfix(infixExp) << std::endl;
    }
}

std::string postfix(std::string exp)
{
    char token, topToken;
    Stack opStack;
    std::string postfixExp;
    const std::string BLANK = " ";

    for (int i = 0; i < exp.length(); i++) {
        token = exp[i];
        switch (token) {
        case ' ':
            break;
        case '(':
            opStack.push(token);
            break;
        case ')':
            for (;;) {
                assert(!opStack.empty());
                topToken = opStack.top();
                opStack.pop();
                if (topToken == '(')
                    break;
                postfixExp.append(BLANK + topToken);
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            for (;;) {
                if (opStack.empty() || opStack.top() == '(' ||
                    (token == '*' || token == '/' || token == '%') &&
                        (opStack.top() == '+' || opStack.top() == '-')) {
                    opStack.push(token);
                    break;
                } else {
                    topToken = opStack.top();
                    opStack.pop();
                    postfixExp.append(BLANK + topToken);
                }
            }
            break;
        default:
            postfixExp.append(BLANK + token);
            for (;;) {
                if (!isalnum(exp[i + 1]))
                    break;
                i++;
                token = exp[i];
                postfixExp.append(1, token);
            }
        }
    }

    for (;;) {
        if (opStack.empty())
            break;
        topToken = opStack.top();
        opStack.pop();
        if (topToken != '(') {
            postfixExp.append(BLANK + topToken);
        } else {
            std::cout << "*** Error in infix expression *** \n";
            break;
        }
    }
    return postfixExp;
}