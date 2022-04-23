struct Node{
    int value;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

struct Stack* initStack();