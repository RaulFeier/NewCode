def build_sentences(words):
    """
    Builds a sequence of sentences using the given list of words, and returns
    the maximum number of words that can be used.
    """
    # Count the number of available words and punctuation marks
    counts = {
        'noun': 0,
        'intransitive-verb': 0,
        'transitive-verb': 0,
        'comma': 0,
        'period': 0,
        'conjunction': 0,
    }
    for word, word_type in words:
        counts[word_type] += 1

    # Try to build sentences and compound sentences
    max_words = 0
    max_sequence = []
    sentence = []
    while counts['noun'] > 0:
        # Try to build a sentence
        if len(sentence) == 0:
            if counts['intransitive-verb'] > 0:
                sentence = [words.pop(words.index((word, 'noun')))[0], words.pop(words.index((word, 'intransitive-verb')))[0]]
                counts['noun'] -= 1
                counts['intransitive-verb'] -= 1
        # Try to build a transitive verb and one or more nouns
        elif sentence[-1] == 'transitive-verb':
            if counts['noun'] > 0 and counts['comma'] > 0:
                sentence.append(words.pop(words.index((word, 'noun')))[0])
                counts['noun'] -= 1
                while counts['comma'] > 0 and counts['noun'] > 0:
                    words.pop(words.index((',', 'comma')))
                    sentence.append(words.pop(words.index((word, 'noun')))[0])
                    counts['comma'] -= 1
                    counts['noun'] -= 1
            # End the sentence with a period
            if counts['period'] > 0:
                words.pop(words.index(('.', 'period')))
                sentence.append('.')
                counts['period'] -= 1
                max_words += len(sentence)
                max_sequence += sentence
                sentence = []

        # Try to join two sentences with a conjunction
        elif sentence[-1] == 'period' and counts['conjunction'] > 0:
            words.pop(words.index((word, 'conjunction')))
            sentence.append(words.pop(words.index((word, 'noun')))[0])
            sentence.append(words.pop(words.index((word, 'intransitive-verb')))[0])
            counts['noun'] -= 1
            counts['intransitive-verb'] -= 1

    return max_words, max_sequence


def main():
    n, c, p = input().split()
    n = int(n)
    c = int(c)
    p = int(p)

    words = []

    for _ in range(n):
        word, tag = input().split()
        words.append((word, tag))

    a, sentence = build_sentences(words)
    
    print(a)
    print(sentence)

t = int(input())

for i in range(t):
    main()