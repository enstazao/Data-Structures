  #include <iostream>
  using namespace std;
  
  void CheckPalindrome(int size) {
     char *arr = new char[size];
     arr[0] = 'M';arr[1] = 'A';arr[2] = 'D',arr[3] = 'A',arr[4] = 'M';
      int wordMid = size/2;
      int check = 0;
      for (int i = 0; i < wordMid; i++) {
          if (*(arr + i) == *(arr + size - i - 1)) {
              // Word Matached
              check += 1;
          }
      }
      if (check == wordMid) {
          cout << "=> Given Word Is A Palindrome" << endl; 
      } else {
          cout << "=> Given Word Is Not A Palindrome" << endl;
      }
  }
  int main() {
      int size = 5;
      CheckPalindrome(size);
      return 0;
  }