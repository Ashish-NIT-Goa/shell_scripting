//LRU

#include<bits/stdc++.h>

using namespace std;

bool check_page(queue<int> q, int x) {
    while(!q.empty()){ 
        if(q.front() == x){
            return true; 
        }      
        q.pop(); 
    }

    return false;
}

int main() {

    int free_frames;
    cout<<"Enter the number of free frames: "<<endl;
    cin>>free_frames;

    vector<int> v;
    int n;
    cout<<"Enter the length of the string: "<<endl;
    cin>>n;
    cout<<"Enter the sequence: "<<endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    

    queue<int> fifo_q;
    int page_fault=0;

    for (int i = 0; i < n; i++) {
        if (free_frames != 0) {
            fifo_q.push(v[i]);
            page_fault++;
            free_frames--;
        } else {
            if (check_page(fifo_q, v[i])) {
                cout<<"te"<<endl;
                fifo_q.push(v[i]);
                fifo_q.pop();
            } else {
                cout<<"te"<<endl;
                fifo_q.push(v[i]);
                fifo_q.pop();
                page_fault++;
            }
        }
    }

    cout<<page_fault<<endl;

    return 0;
}