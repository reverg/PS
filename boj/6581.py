import sys

article = ""
for sentence in sys.stdin:
    article += sentence

splitted_article = article.split()

hr = ""
temp_list = []
temp_line_length = 0
for word in splitted_article:
    if word == "<br>":
        print(" ".join(temp_list))
        temp_list = []
        temp_line_length = 0
    elif word == "<hr>":
        if len(temp_list) != 0:
            print(" ".join(temp_list))
            temp_list = []
            temp_line_length = 0
        print("-" * 80)
    else:
        if temp_line_length + 1 + len(word) > 80:
            print(" ".join(temp_list))
            temp_list = [word]
            temp_line_length = len(word)
        else:
            temp_line_length += 1 + len(word)
            temp_list.append(word)
print(" ".join(temp_list))
