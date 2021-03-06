#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool exist(const vector<vector<char>>& board, const string& word) {
    board_ = board;
    row_size_ = board_.size();
    col_size_ = row_size_ ? board_[0].size() : 0ull;
    word_ = word;

    for (auto i = 0; i < row_size_; ++i) {
      for (auto j = 0; j < col_size_; ++j) {
        if (WordExist(i, j, 0)) return true;
      }
    }
    return false;
  }

 private:
  vector<vector<char>> board_;
  size_t row_size_;
  size_t col_size_;
  string word_;

  bool WordExist(int i, int j, int start) {
    if (start == word_.size()) return true;
    if (i < 0 || i >= row_size_) return false;
    if (j < 0 || j >= col_size_) return false;
    if (board_[i][j] == '0') return false;
    if (board_[i][j] != word_[start]) return false;

    auto board_bak = board_[i][j];
    board_[i][j] = '0';
    ++start;
    auto result = WordExist(i - 1, j, start) || WordExist(i + 1, j, start) ||
                  WordExist(i, j - 1, start) || WordExist(i, j + 1, start);
    board_[i][j] = board_bak;
    return result;
  }
};
