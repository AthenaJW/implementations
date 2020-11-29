//Implementation based off: http://codeforces.com/blog/entry/18051

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N]; //this is the tree. It is twice as long as the maximum array to hold all the
//nodes of a tree where the bottomost layer has N nodes (N + 0.5N + 0.5^2N + ... = 2N-1)

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i)
  	t[i] = t[i<<1] + t[i<<1|1]; // add 2i and 2i + 1 (1 based tree, the least i is is 1)
	//starting from the bottom working up, obtain the value of a node by adding it's child nodes
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1)
  	t[p>>1] = t[p] + t[p^1];
  	//^ is the XOR operator
  	//the parent node = the sum of it's two child nodes
  	//the XOR value serves to reference the "other" child node. If you are the even child, you reference
  	//the odd child. If you are the odd you reference the even
}//the first statement of the for loop sets the array value, the last statement is saying 
//we bitshift left every time or divide by 2 every time

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) { // pointers are always on the same 'level' of the tree (sort of). When they cross, we know we're done
    if (l&1) res += t[l++]; //if l is odd, it is the right child and the rightmost edge of it's parents range. We can just take it and move to the next range
    if (r&1) res += t[--r]; //if r is odd, the inclusive edge (r-1) is the left child and the leftmost edge of it's parents range. We can just take it and move to the next range
  }
  return res;
}

int main() {
  scanf("%d", &n); //& is the reference operator. In this case it tells the program to store
  //the next input from stdin to n's location in memory
  for (int i = 0; i < n; ++i)
  	scanf("%d", t + n + i); //store array values in the second half of tree array (represents
	//bottom of the tree
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}
