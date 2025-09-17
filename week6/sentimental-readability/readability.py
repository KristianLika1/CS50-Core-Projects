from cs50 import get_string
import re

phrase = get_string("Text: ")
letters = [char for char in phrase if char.isalpha()]
letter_count = len(letters)

sentence_count = 0
for i in phrase:
    if i == "." or i == "?" or i == "!" or i == "\n":
        sentence_count += 1


phrase = phrase.replace(",", "").replace("!", "")
words = phrase.split()
word_count = len(words)


L = letter_count / word_count * 100
S = sentence_count / word_count * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

print(f"Letter count: {letter_count}")
print(f"Word count: {word_count}")
print(f"Sentence count: {sentence_count}")

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
