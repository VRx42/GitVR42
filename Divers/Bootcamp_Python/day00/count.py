import string



def text_analyzer(text):
    if (len(locals()) > 1):
        print('ERROR')
    #print(len(locals()))
    up = 0
    low = 0
    punc = 0
    spaces = 0
    punctuations = '''!()-[]{};:'"\\,<>./?@#$%^&*_~'''
    for char in text:
        if (char.isupper()):
            up += 1
        if (char.islower()):
            low += 1
        if (char in punctuations):
            punc += 1
        if (char.isspace()):
            spaces += 1

    total = up + low + punc + spaces

    print('The text contains', total,'characters:')
    print('- %d upper letters' % (up))
    print('-', low,'lower letters')
    print('-', punc,'punctuation')
    print('-', spaces,'spaces')



text_analyzer("Python is an interpreted, high-level, general-purpose programming language. \
 Created by Guido van Rossum and first released in 1991, Python's design philosophy emphasizes \
  ode readability with its notable use of significant whitespace.")