#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class WordType { Noun, TransitiveVerb, IntransitiveVerb, Conjunction };

struct Word {
  string text;
  WordType type;
};

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, C, P;
    cin >> N >> C >> P;

    // Read words from input
    vector<Word> words;
    for (int i = 0; i < N; i++) {
      string text, typeStr;
      cin >> text >> typeStr;
      WordType type;
      if (typeStr == "noun") {
        type = WordType::Noun;
      } else if (typeStr == "transitive-verb") {
        type = WordType::TransitiveVerb;
      } else if (typeStr == "intransitive-verb") {
        type = WordType::IntransitiveVerb;
      } else if (typeStr == "conjunction") {
        type = WordType::Conjunction;
      } else {
        cerr << "Unknown word type: " << typeStr << endl;
        return 1;
      }
      words.push_back({text, type});
    }

    // Count words by type
    int numNouns = count_if(words.begin(), words.end(), [](const Word &w) {
      return w.type == WordType::Noun;
    });
    int numTransitiveVerbs =
        count_if(words.begin(), words.end(), [](const Word &w) {
          return w.type == WordType::TransitiveVerb;
        });
    int numIntransitiveVerbs =
        count_if(words.begin(), words.end(), [](const Word &w) {
          return w.type == WordType::IntransitiveVerb;
        });
    int numConjunctions =
        count_if(words.begin(), words.end(),
                 [](const Word &w) { return w.type == WordType::Conjunction; });

    int total =
        numNouns + numConjunctions + numTransitiveVerbs + numIntransitiveVerbs;

    // Check if there are enough words to form at least one sentence
    if (numNouns == 0 || numIntransitiveVerbs == 0 || numTransitiveVerbs == 0) {
      cout << "0\n";
      continue;
    }

    // Check if there are enough commas to form compound sentences
    if (numConjunctions > 0 &&
        numConjunctions > min(numNouns - 1, numTransitiveVerbs - 1)) {
      cout << "0\n";
      continue;
    }

    // Build sentences
    vector<string> sentences;
    while (numNouns > 0 && numIntransitiveVerbs > 0) {
      sentences.push_back(words.back().text + " " + words.back().text + "s.");
      words.pop_back();
      numNouns--;
      numIntransitiveVerbs--;
    }
    while (numNouns > 0 && numTransitiveVerbs > 0) {
      sentences.push_back(words.back().text + " " + words.back().text + "s," +
                          " " + words.back().text + ".");
      words.pop_back();
      numNouns--;
      numTransitiveVerbs--;
    }
    if (numConjunctions > 0) {
      // Insert conjunctions to join sentences
      for (auto it = sentences.begin() + 1; it != sentences.end(); it += 2) {
        *it = " " + words.back().text + " " + *it;
        words.pop_back();
        numConjunctions--;
      }
    }

    // Print output
    cout << total - numConjunctions - numTransitiveVerbs - numIntransitiveVerbs
         << endl;
    for (auto it = sentences.begin(); it != sentences.end(); it++) {
      cout << *it << endl;
    }
    cout << endl;
  }
}