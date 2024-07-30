class dll{
public:
    string url;
    dll* next, *prev;
    dll(string url){
        this->url = url;
        this->next = NULL;
        this->prev = NULL;
    }
};
class BrowserHistory {
    dll* current;
public:
    BrowserHistory(string homepage) {
        current = new dll(homepage);
    }
    
    void visit(string url) {
        dll* temp = new dll(url);
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(current->prev) current = current->prev;
            else break;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(current->next) current = current->next;
            else break;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */