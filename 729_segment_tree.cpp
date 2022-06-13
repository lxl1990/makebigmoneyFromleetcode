// class MyCalendar {
// public:
//     MyCalendar() {

//     }
    
//     bool book(int start, int end) {

//     }
// };


// class SegNode {
//   public:
//     explicit SegNode(long l , long r) : l_(l), r_(r) {
//       avaliable = true;
//       left_ = nullptr;
//       right_ = nullptr;
//       need_up = false;
//     }

//     SegNode* left() {
//       if (left_ == nullptr) {
//         left_ = new SegNode(l_, mid());
//       }
//       return left_;
//     }

//     SegNode* right() {
//       if (right_ == nullptr) {
//         right_ = new SegNode(mid(), r_);
//       }
//       return right_;
//     }

//     // 10,20  15,25 true
//     bool query(long start, long end) {
//       lazy_create();
//       if (start <= l_ && r_ <= end) {
//         return avaliable;
//       }

//       bool res = true;
//       if (start <  mid()) {
//         res &= left()->query(start, end);
//       }

//       if (mid() < end) {
//         res &= right()->query(start, end);
//       }
//       return res;
//     }

//     void lazy_create() {
//       if (need_up) {
//         left()->need_up = true;
//         right()->need_up = true;
//         avaliable = false;
//         need_up = false;
//       }
//     }

//     void update(long start, long end) {
//       if (start <= l_ && r_ <= end) {
//         avaliable = false;
//         need_up = true;
//         return;
//       }
//       lazy_create();

//       if (start < mid()) {
//         left()->update(start, end);
//       }

//       if (mid() < end) {
//         right()->update(start, end);
//       }
//       // push up
//       avaliable = right()->avaliable && left()->avaliable;
//     }

//   private:
//     int mid() {
//       return l_ + (r_ - l_) / 2;
//     }

//     // 左闭右开
//     long l_;
//     long r_;
//     SegNode* left_;
//     SegNode* right_;
//     bool avaliable;
//     bool need_up;
// };

// class MyCalendar {
// public:
//     MyCalendar() {
//       root_ = new SegNode(0, 10e9);
//     }

//     bool book(int start, int end) {
//       if (root_->query(start, end)) {
//         root_->update(start, end);
//         return true;
//       }
//       return false;
//     }

// private:
//     SegNode* root_;
// };


class MyCalendar {
private:
  struct SegNode{
    int left;
    int right;
    bool flag;
    bool lazyVal;
    SegNode(): left(-1), right(-1), flag(true), lazyVal(false) {} 
  };
  vector<SegNode> trees;
  int count;
  int maxN;

  void lazyCreate(int root) {
    if (root >= count) {
      trees.emplace_back(SegNode());
      count++;
    }
    if (trees[root].left == -1) {
      trees[root].left = count;
      trees.emplace_back(SegNode());
      count++;
    }
    if (trees[root].right == -1) {
      trees[root].right = count;
      trees.emplace_back(SegNode());
      count++;
    }
  }

  void updateLazyValue(int root) {
    if (trees[root].lazyVal) {
      trees[root].flag = false;
      trees[trees[root].left].lazyVal = true;
      trees[trees[root].right].lazyVal = true;
      trees[root].lazyVal = false;
    }
  }

  bool query(int root, int lc, int rc, int l, int r) {
    // cout << "root: " << root << ", lc: " << lc << ", rc: " << rc << ", l: " << l << ", r: " << r << endl;
    if (l <= lc && rc <= r) return trees[root].flag & (~trees[root].lazyVal);
    lazyCreate(root);
    updateLazyValue(root);
    int mid = lc + ((rc - lc) >> 1);
    bool ret = true;
    if (l <= mid) ret &= query(trees[root].left, lc, mid, l, r);
    if (r > mid) ret &= query(trees[root].right, mid + 1, rc, l, r);
    return ret;
  }

  void update(int root, int lc, int rc, int l, int r) {
    if (l <= lc && rc <= r) {
      trees[root].flag = false;
      trees[root].lazyVal = true;
      return;
    }
    lazyCreate(root);
    updateLazyValue(root);
    int mid = lc + ((rc - lc) >> 1);
    if (l <= mid) update(trees[root].left, lc, mid, l, r);
    if (r >= mid + 1) update(trees[root].right, mid + 1, rc, l, r);
    trees[root].flag = trees[trees[root].left].flag & trees[trees[root].right].flag;
  }

public:
    MyCalendar() {
      count = 0;
      maxN = 1e9;
    }

    bool book(int start, int end) {
      if (!query(0, 0, maxN, start, end - 1)) return false;
      update(0, 0, maxN, start, end - 1);
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
