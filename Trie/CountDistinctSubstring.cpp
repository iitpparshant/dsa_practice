// https://www.naukri.com/code360/problems/count-distinct-substrings_985292



struct Node {
  Node *links[26];
  bool containesKey(char ch) { return links[ch - 'a']; }
  void put(char ch, Node *node) { links[ch - 'a'] = node; }
  Node *get(char ch) { return links[ch - 'a']; }
};
int countDistinctSubstrings(string &s) {
  //    Write your code here.
  int count = 0;
  Node *root = new Node();
  for (int i = 0; i < s.size(); i++) {
    Node *node = root;
    for (int j = i; j < s.size(); j++) {
      if (!node->containesKey(s[j])) {
        count++;
       node-> put(s[j], new Node());
      }
      node = node->get(s[j]);
    }
  }
  return count + 1;
}