
def text_analyzer(text):
    c_maj = 0
    c_min = 0
    c_sp = 0
    c_punc = 0
    count_total = 0
    
    for char in text:
        if (char.isupper()):
            c_maj += 1
        elif (char.islower()):
            c_min += 1
        elif (char.matches("\\p{Punct}", str)):
            c_punc += 1
        elif (char.isspace()):
            c_sp += 1

    count_total = c_sp + c_maj + c_min + c_punc

    print('The text contains', count_total, 'characters:')
    print('-', c_maj, 'upper letters')
    print('-', c_min , 'lower letters')
    print('-', c_punc, 'punctuation marks')
    print('-', c_sp,  'spaces')
