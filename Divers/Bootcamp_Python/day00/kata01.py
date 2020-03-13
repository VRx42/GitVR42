languages = {
'Python': 'Guido van Rossum', 'Ruby': 'Yukihiro Matsumoto', 'PHP': 'Rasmus Lerdorf',
}

#print(languages['Python'])
#Key[value]
for x in languages:#Print all key names in the dictionary, one by one:
  print('x =', x)
  print('%s was created by %s' % (x, languages[x]))


print('\n\n2e option')

for x in languages.values():
  print('x =', x)
