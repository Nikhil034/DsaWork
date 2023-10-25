#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

class AllOne {
public:
    AllOne() {
        head = new Bucket(0);
        tail = new Bucket(0);
        head->next = tail;
        tail->prev = head;
        keyCountMap.clear();
        bucketMap[0] = head;
    }

    void inc(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            keyCountMap[key] = 1;
            addKeyToBucket(head, key);
        } else {
            int count = keyCountMap[key];
            keyCountMap[key]++;
            Bucket* currentBucket = bucketMap[count];
            Bucket* nextBucket = bucketMap[count + 1];
            if (!nextBucket) {
                nextBucket = new Bucket(count + 1);
                addBucketAfter(currentBucket, nextBucket);
            }
            addKeyToBucket(nextBucket, key);
            removeKeyFromBucket(currentBucket, key);
        }
    }

    void dec(string key) {
        if (keyCountMap.find(key) != keyCountMap.end()) {
            int count = keyCountMap[key];
            if (count == 1) {
                keyCountMap.erase(key);
                removeKeyFromBucket(head, key);
            } else {
                keyCountMap[key]--;
                Bucket* currentBucket = bucketMap[count];
                Bucket* prevBucket = bucketMap[count - 1];
                if (!prevBucket) {
                    prevBucket = new Bucket(count - 1);
                    addBucketBefore(currentBucket, prevBucket);
                }
                addKeyToBucket(prevBucket, key);
                removeKeyFromBucket(currentBucket, key);
            }
        }
    }

    string getMaxKey() {
        if (tail->prev == head)
            return "";
        return tail->prev->keys.begin()->first;
    }

    string getMinKey() {
        if (head->next == tail)
            return "";
        return head->next->keys.begin()->first;
    }

private:
    struct Bucket {
        int count;
        unordered_map<string, bool> keys;
        Bucket* next;
        Bucket* prev;
        Bucket(int c) : count(c), next(nullptr), prev(nullptr) {}
    };

    Bucket* head;
    Bucket* tail;
    unordered_map<string, int> keyCountMap;
    unordered_map<int, Bucket*> bucketMap;

    void addKeyToBucket(Bucket* bucket, string key) {
        bucket->keys[key] = true;
        bucketMap[keyCountMap[key]] = bucket;
    }

    void removeKeyFromBucket(Bucket* bucket, string key) {
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            removeBucket(bucket);
        }
    }

    void addBucketAfter(Bucket* prev, Bucket* bucket) {
        bucket->next = prev->next;
        bucket->prev = prev;
        prev->next = bucket;
        bucket->next->prev = bucket;
    }

    void addBucketBefore(Bucket* next, Bucket* bucket) {
        addBucketAfter(next->prev, bucket);
    }

    void removeBucket(Bucket* bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        bucketMap.erase(bucket->count);
        delete bucket;
    }
};

int main() {
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("world");
    allOne.inc("hello");
    cout << allOne.getMaxKey() << endl; // Output: "hello"
    cout << allOne.getMinKey() << endl; // Output: "world"
    allOne.dec("world");
    cout << allOne.getMaxKey() << endl; // Output: "hello"
    cout << allOne.getMinKey() << endl; // Output: "hello"

    return 0;
}
