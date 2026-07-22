class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key,int val){
            this->key = key;
            this->val = val;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int curr_cap;
    int cap;

    unordered_map<int,Node*> map;

    Node* insertFront(int key,int val){
        Node* newNode = new Node(key,val);

        if(head == NULL){
            head = tail = newNode;
            return newNode;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        return newNode;
    }

    int removeEnd(){

        int dkey = tail->key;

        if(head == tail){
            delete tail;
            head = tail = NULL;
            return dkey;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;

        return dkey;
    }

    Node* changeNtoFront(Node* node){

        if(node == head)
            return head;

        if(node == tail){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = NULL;
        node->next = head;
        head->prev = node;
        head = node;

        return node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        curr_cap = 0;
        head = tail = NULL;
    }

    int get(int key) {

        if(map.count(key)==0)
            return -1;

        Node* curr = changeNtoFront(map[key]);
        return curr->val;
    }

    void put(int key, int value) {

        if(map.count(key)){
            Node* curr = changeNtoFront(map[key]);
            curr->val = value;
            return;
        }

        if(curr_cap == cap){
            int dkey = removeEnd();
            map.erase(dkey);
            curr_cap--;
        }

        Node* curr = insertFront(key,value);
        map[key] = curr;
        curr_cap++;
    }
};