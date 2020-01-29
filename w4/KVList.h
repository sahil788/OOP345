#pragma once

namespace w4 {
    template<class K,class V,int N>
    class KVList {
        K k[N] = {};
        V v[N] = {};
        size_t count=0;
    public:
      
        size_t size() const {
            return count;
        }
        const K& key(int i) const {
            return k[i];
        }
        const V& value(int i) const {
            return v[i];
        }
        KVList& add(const K&kvalue, const V&vvalue) {
            if (count < N) {
                k[count] = kvalue;
                v[count] = vvalue;
                count++;

            }
            return *this;
        }
        int find(const K& kvalue) const {
            for (int i=0; i < N; i++) {
                if (k[i] == kvalue) {
                    return i;
                }
            }
            return 0;
        }
        KVList& replace(int i, const K& kvalue, const V& vvalue) {
            k[i] = kvalue;
            v[i] = vvalue;
            return *this;
        }
    };
}

