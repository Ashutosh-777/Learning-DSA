template <typename V>
class MapNode{
    string key;
    V value;
    MapNode* next;
    public:
    //constructor
    MapNode(string key, V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template <typename V>
class ourMap{
    MapNode<V>** buckets;
    int size;
    int numBuckets;
    public:
    ourMap(){
        count=0;
        numBuckets=5;
        buckets = new MapNode<V>*[numBuckets];
        //initialising all addresses to NULL
        for(int i=0;i<n;i++){
            buckets[i]=NULL;
        }
    }
    //destructor first delete linked list then only delete bucket array
    ~ourMap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    } 
    //function for performing different operations
    int size(){
        return count;
    }
    V getvalue(string key){
        int bucketIndex=getBucketIndex( key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    private:
    int getBucketIndex(string key){
        int hashcode=0;
        int currentcoeff =1;
        for(int i=key.length()-1;i>=0;i++){
            hashcode+=key[i]*currentcoeff;
            hashcode=hashcode%numBuckets;
            currentcoeff*=37;
            currentcoeff=currentcoeff % numBuckets;
        }
        return hashcode % numBuckets;
    }
    void rehash(){
        MapNode<V>** temp=buckets;
        buckets= new MapNode<V>*[2*numBuckets];
        for(int i=0;i<n;i++){
            buckets[i]=NULL;
        }
        int oldbucketcount = numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldbucketcount;i++){
            MapNode<V>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                V value= head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldbucketcount;i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    void insert(string key,V value){
        int bucketIndex=getBucketIndex( key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;;
                return;
            }
            head=head->next;
        } 
        MapNode<V> *node = new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadfactor = (1.0*count)/numBuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }
    V remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
         MapNode<V>* prev = NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;
                
                }else{
                prev->next=head->next;
                
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }

};