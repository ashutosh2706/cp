#include<bits/stdc++.h>
#define show(s) for(auto a:s) cout<<a<<" ";

using namespace std;

bool cmpfunc(int,int);
bool cmpfunc_pair(pair<int,int>,pair<int,int>);
bool cmpfunc_str(char,char);

int main()
{
    //freopen("output.txt","w",stdout);
    array<int,10> arr = {0};
    show(arr);
    cout<<endl;
    int ar[10] = {10,9,8,7,6,5,4,3,2,1};

    // SORT ELEMENTS OF ARRAY

    sort(ar,ar+10);
    show(ar);
    cout<<endl;
    cout<<"------------\n";

    vector<int> vec(5,1);
    show(vec);
    cout<<endl;
    vector<int> vec2(vec);
    show(vec2);
    cout<<endl;
    vector<int> vec3;
    for(int i=20;i>=0;i--)
        vec3.push_back(i);
    show(vec3);
    cout<<endl;

    // SORT ELEMENTS OF VECTOR

    /*
    sort() uses 'introsort', a hybrid sorting technique
    that uses insertion sort, quick sort and heap sort

    insertion sort -> best O(n) worst O(n^2)
    heap sort -> all cases O(logn)
    quick sort -> best case O(nlogn) worst case O(n)

    */

    auto itr = find(vec3.begin(),vec3.end(),15);
    auto itr2 = find(vec3.begin(),vec3.end(),10);
    sort(itr,itr2);
    show(vec3);
    cout<<endl;

    sort(itr,vec3.end());
    show(vec3);
    cout<<endl;

    sort(vec3.begin(),vec3.end());
    show(vec3);
    cout<<endl;

    show(vec3);
    cout<<endl;

    // rbegin() & rend() ITERATORS

    for(auto itr=vec3.rbegin();itr!=vec3.rend();itr++)
        cout<<*itr<<" ";
    cout<<endl;

    for(int i=10;i<=15;i++) vec3.emplace_back(i);
    show(vec3);
    cout<<endl;

    // SUM OF ELEMENTS

    int sum=accumulate(vec3.begin(),vec3.end(),0);
    cout<<"Sum: "<<sum<<endl;

    // MIN AND MAX ELEMENTS

    int min_ele = *min_element(vec3.begin(),vec3.end());
    int max_ele = *max_element(vec3.begin(),vec3.end());
    // max_ele = *max_element(vec3.begin(),vec3.begin()+3);
    // min_ele = *min_element(vec3.begin(),vec3.end()-3);
    cout<<"MIN ELE: "<<min_ele<<endl<<"MAX ELE: "<<max_ele<<endl;

    // BINARY SEARCH O(logn)

    bool present = binary_search(vec3.begin(),vec3.end(),15);
    cout<<"Check for 15: "<<present<<endl;

    // POSITION OF ELEMENT

    auto it = find(vec3.begin(),vec3.end(),10);
    cout<<"Position: "<<it-vec3.begin()<<endl;

    // LOWER & UPPER BOUND

    vector<int> nvec;
    for(int i=1,f=1,z=3;i<=10;i++){
        f=f+(z+f);
        nvec.emplace_back(f);
        z-=i;
    }
    show(nvec);
    cout<<endl;
    auto it_low = lower_bound(nvec.begin(),nvec.end(),55);
    auto it_up = upper_bound(nvec.begin(),nvec.end()-2,300);
    cout<<"LB[55]: "<<*it_low<<endl<<"UB[300]: "<<*it_up<<endl;
    /*
    lower bound finds first element which is not lesser than given element
    upper bound finds first element which is just greater than given element
    both of them returns iterator to the element
    */

    // REVERSE

    reverse(vec3.begin(),vec3.end());
    show(vec3);
    vec3.clear();
    cout<<endl<<"Size: "<<vec3.size();
    cout<<endl;
    reverse(ar,ar+10);
    show(ar);
    cout<<endl;
    cout<<"-------------\n";

    // STACK

    stack<int> st_temp;
    for(int i=0;i<20;i++) st_temp.push(i);
    stack<int> tmp(st_temp);
    while(!tmp.empty())
    {
        cout<<tmp.top()<<endl;
        tmp.pop();
    }
    cout<<"SIZE: "<<st_temp.size()<<endl;
    st_temp.emplace(10);

    /*
    Stack methods:
    push(g)
    pop()
    top()
    size()
    empty()
    emplace()

    */
    cout<<"----------\n";

    // QUEUE

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(5);
    q.push(15);
    cout<<"Front: "<<q.front()<<endl<<"Back: "<<q.back()<<endl;
    q.pop();
    cout<<"Front: "<<q.front()<<endl<<"Back: "<<q.back()<<endl;
    q.pop();
    cout<<"Front: "<<q.front()<<endl<<"Back: "<<q.back()<<endl;
    q.pop();
    cout<<"Front: "<<q.front()<<endl<<"Back: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl<<"Empty?: "<<q.empty()<<endl;
    q.emplace(90);
    cout<<"Front: "<<q.front()<<endl<<"Back: "<<q.back()<<endl;
    cout<<"Size: "<<q.size()<<endl<<"Empty?: "<<q.empty()<<endl;
    /*
    Queue methods:
    push(g)
    pop()
    front()
    back()
    size()
    empty()
    emplace()
    */

    cout<<"------------\n";

    // PRIORITY QUEUE

    // max-heap priority queue
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(5);
    pq.push(90);
    pq.emplace(12);
    priority_queue<int> tpq(pq);
    while(!tpq.empty())
    {
        cout<<tpq.top()<<" ";
        tpq.pop();
    }
    cout<<endl<<"Size of max-heap: "<<tpq.size()<<endl;

    // min-heap priority queue to store small element first
    priority_queue<int, vector<int>, greater<int>> rev_pq;
    rev_pq.emplace(90);
    rev_pq.emplace(80);
    rev_pq.emplace(70);
    rev_pq.emplace(60);
    priority_queue<int, vector<int>, greater<int>> rev_tpq(rev_pq);
    while(!rev_tpq.empty())
    {
        cout<<rev_tpq.top()<<" ";
        rev_tpq.pop();
    }
    cout<<endl<<"Size of min-heap: "<<rev_tpq.size()<<endl;

    /*
    priority queue is implemented using array,linked-list
    and heap
    but generally implemented using heap , time complexity O(logn)
    priority_queue uses heapify to convert sequence of elements
    into max-heap to store large element first
    heap sort also uses heapify
    */

    cout<<"------------\n";

    // DEQUEUE

    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    show(dq);
    cout<<endl;
    for(auto it=dq.begin();it!=dq.end();it++) cout<<*it<<" ";
    cout<<endl;
    cout<<"Size: "<<dq.size()<<endl;
    dq.push_front(5);
    dq.emplace_front(1);
    dq.emplace_back(55);
    cout<<"Size: "<<dq.size()<<endl;
    cout<<"Empty?: "<<dq.empty()<<endl;
    cout<<"Front: "<<dq.front()<<" Rear: "<<dq.back()<<endl;
    deque<int> tmp_dq(dq);
    while(!tmp_dq.empty())
    {
        cout<<tmp_dq.front()<<" ";
        tmp_dq.pop_front();
    }
    cout<<endl;
    std::deque<int>::iterator dqit = find(dq.begin(),dq.end(),10);
    for(std::deque<int>::iterator it = dqit;it!=dq.end();it++) cout<<*it<<" ";
    cout<<endl;
    dq.clear();
    show(dq);
    cout<<"-----------\n";

    /*
    dequeue implements double linked-list
    dequeue has iterators: begin() end() rbegin() rend()
    front() back() references for front and back elements
    methods:
    clear()
    emplace_back(g)
    emplace_front(g)
    push_back(g)
    push_front(g)
    pop_back()
    pop_front()
    size()
    empty()
    resize()
    swap()
    insert()
    */

    // ORDERED SET

    set<int> st;
    st.insert(10);
    st.insert(30);
    st.insert(5);
    st.insert(20);
    st.insert(15);
    st.insert(10);
    st.insert(30);
    st.insert(5);
    st.insert(20);
    st.insert(15);
    show(st);
    cout<<endl;
    for(set<int>::reverse_iterator it=st.rbegin();it!=st.rend();it++) cout<<*it<<" ";
    cout<<endl;
    //st.clear();
    pair<int,int> p1 = {10,20};
    pair<int,int> p2 = {20,30};
    set<pair<int,int>> sp;
    sp.insert(p1);
    sp.insert(p2);
    st.erase(15);
    show(st);
    set<int>::iterator itr_set = find(st.begin(),st.end(),15);

    /*
    set implements red-black tree and b-tree under the hood
    set stores elements in sorted order
    only unique elements are allowed
    time complexity: avg case -> O(logn)
    iterators: begin() end() rbegin() rend()
    methods:
    insert()
    clear()
    emplace()
    empty()

    */
    cout<<"\n------------\n";
    // UNORDERED-SET

    unordered_set<int> ust;
    ust.insert(10);
    ust.insert(30);
    ust.insert(5);
    ust.insert(15);
    ust.insert(25);
    ust.insert(10);
    ust.insert(30);
    ust.insert(5);
    ust.insert(15);
    ust.insert(25);
    show(ust);
    cout<<endl;
    ust.clear();
    if(ust.count(10)) cout<<"10 present"<<endl;
    else cout<<"10 is not present"<<endl;
    cout<<"--------------\n";

    /*
    unordered-set implements hash table
    elements are stored in unordered manner
    time complexity: avg case -> O(1) worst case -> O(n)
    */

    // MULTISET

    multiset<int> mst;
    mst.insert(20);
    mst.insert(10);
    mst.insert(30);
    mst.insert(5);
    mst.insert(20);
    mst.insert(10);
    mst.insert(30);
    mst.insert(5);
    show(mst);
    cout<<endl;
    mst.erase(find(mst.begin(),mst.end(),10),mst.end());
    show(mst);
    cout<<endl;

    /*
    multiset is an ordered set but it can store duplicate
    elements as well
    multiset and set are same among other aspects.
    multiset has the same methods as set
    */

    cout<<"------------\n";

    // MAP

    map<string,int> mp;
    mp["abc"]=10;
    mp["def"]=20;
    mp["ghi"]=30;
    mp["abc"]=40;
    pair<string,int> pr = make_pair("def",33);
    mp.insert(pr);
    for(std::map<string,int>::iterator it = mp.begin();it!=mp.end();it++)
        cout<<it->first<<" : "<<it->second<<endl;

    if(mp.find("def")==mp.end()) cout<<"Key not found"<<endl;
    else
    {
        cout<<"Key found"<<endl;
        cout<<"Key value= "<<mp["def"]<<endl;
    }
    mp.clear();

    /*
    it stores key value pair in a sorted sequence
    only unique keys are allowed
    */
    cout<<"----------\n";

    // UNORDERED MAP

    unordered_map<int,string> ump;
    ump.insert({10,"hi"});
    pair<int,string> pp = {20,"bye"};
    ump.insert(pp);
    ump.insert({30,"chi"});
    ump.insert({15,"phi"});
    ump[3]="shi";
    for(auto i:ump)
        cout<<i.first<<" "<<i.second<<endl;

    int key=3;
    cout<<"Enter key: ";
    //cin>>key;
    if(ump.find(key)!=ump.end())
    {
        cout<<"Key found"<<endl;
        cout<<key<<" "<<ump[key]<<endl;
    }else
    {
        cout<<"key not found"<<endl;
    }
    /*
    unordered map stores key-value pair in random order
    only unique keys are allowed
    different keys can have same value but different values can't have same key
    */

    cout<<"------------\n";

    //  ALGORITHMS

    string str = "abc";
    while(next_permutation(str.begin(),str.end()))
    {
        cout<<str<<" ";
    }
    cout<<endl;

    string str2 = "defg";
    while(next_permutation(str2.begin(),str2.end()))
    {
        cout<<str2<<" ";
    }
    cout<<endl;

    // COMPARATORS

    int aray[5] = {1,2,3,4,5};
    sort(aray,aray+5,cmpfunc);
    show(aray);
    cout<<endl;

    pair<int,int> parr[] = {{2,3},{5,1},{3,4},{2,8},{3,3}};
    sort(parr,parr+5,cmpfunc_pair);
    for(auto i:parr) cout<<i.first<<" "<<i.second<<endl;

    string str3 = "hello";
    sort(str3.begin(),str3.end(),cmpfunc_str);
    cout<<str3<<endl;

    // transform 
    string sstr = "lowercase";
    transform(sstr.begin(),sstr.end(),sstr.begin(),::toupper);
    // transform(sstr.begin(),sstr.end(),sstr.begin(),::tolower);

    cout<<"------------\n";

    // string to int
    string xx="10";
    int aa = stoi(xx);
    cout<<(10+aa)<<endl;

    cout<<"--------------\n";

    // to_string()

    // substring    

    string some_str = "abcdefghij";
    cout<<some_str.substr(1,4);

    /*
        string.substr(start_index, length);
    */
    
    // memset

    int some_array[10][10] = {0};  // all elements are 0
    memset(some_array,9,sizeof(some_array)); // now all elements will be 9
    for(int i=0;i<10;i++) { for(int j=0;j<10;j++) cout<<some_array[i][j]<<" "; cout<<endl; }

    return 0;
}

bool cmpfunc(int e1,int e2)
{
    if(e1>e2) return true;
    return false;
}

bool cmpfunc_pair(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.first<=p2.first && p1.second>p2.second) return true;
    return false;
}

bool cmpfunc_str(char c1, char c2)
{
    return c1>c2?true:false;
}
