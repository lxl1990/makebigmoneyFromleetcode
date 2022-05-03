class ProductOfNumbers {
private:
    vector<int> vec, cnt, pre;
    int n;
public:
    ProductOfNumbers() {
        vec.clear();
        cnt.clear();
        pre.clear();
        pre.emplace_back(-1);
        cnt.emplace_back(0);
        n = 0;
    }
    
    void add(int num) {
        n++;
        vec.emplace_back(num);
        cnt.emplace_back(num == 0 ? 1 : 0);
        cnt[n] += cnt[n - 1];
        pre.emplace_back(num > 1 ? n - 1 : pre[n - 1]);
    }
    
    int getProduct(int k) {
        if (cnt[n - k] < cnt[n]) return 0;
        int ans = 1;
        int index = pre[n];
        while (index >= n - k) {
            ans *= vec[index];
            index = pre[index];
        }
        cout<<endl;
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
