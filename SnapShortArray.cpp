class SnapshotArray {
   int id=0; 
   vector<map<int, int>> id_v;

public:
    SnapshotArray(int length) { 
        id_v.assign(length, {{0,0}});   
    }
    
    void set(int index, int val) {
        id_v[index][id]=val;
    }
    
    int snap() {
       return id++; 
    }
    
    int get(int index, int snap_id) {
        if (id_v[index].count(snap_id)==0){
            auto it=prev(id_v[index].lower_bound(snap_id));
            return it->second;
        }
        return  id_v[index][snap_id];
    }
};
