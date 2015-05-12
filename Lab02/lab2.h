template <class T>
void List<T>::push_back(T val)
{
    Node* newNode = new Node(val);
    if(head == 0)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode;
    
    return;
}
template <class T>
void List<T>::elementSwap(int pos)
{
    Node* curr1 = head;
    if(pos == 0)
    {
        Node* curr2 = head;
        head = head->next;
        curr2->next = head->next;
        head->next = curr2;
        curr2 = head;
        return;
    }
    
    else if(pos >= size() - 1)
    {
        cout << "Invalid Location" << endl;
        return;
    }
    
    for(int i = 0; i < pos - 2; ++i)
    {
        curr1 = curr1->next;
    }
    Node* curr2 = curr1->next;
    curr1->next = curr2->next;
    curr2->next = (curr2->next)->next;
    (curr1->next)->next = curr2;
    return;
}
template <class T>
int List<T>::size()
{
    int sz = 0;
    Node *curr = head;
    while(curr != tail)
    {
        curr = curr->next;
        sz++;
    }
    sz = sz + 1;
    return sz;
}
template <class T>
void List<T>::print()
{
    int sz = size();
    Node *curr = head;
    for(int i = 0; i < sz; ++i)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
}
