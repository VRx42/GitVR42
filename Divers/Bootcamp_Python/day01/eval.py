


class Evaluator():

    @staticmethod
    def verify_validity(words, coefs):
        if (isinstance(words, list) == False or isinstance(coefs, list) == False):
            exit("Wrong input: words or coefs is not a list")
        if (len(words) != len(coefs)):
            exit("Wrong size for words or coefs list")

    @staticmethod
    def zip_evaluator(words, coefs):
        Evaluator.verify_validity(words, coefs)
        result = sum(len(word) * coef for word, coef in zip(words, coefs))
        return (result)

    @staticmethod
    def enumerate_evaluate(words, coefs):
        summed = 0
        for c, word in enumerate(words, 0):
            summed += len(word) * coefs[c]
        return (summed)

    @staticmethod
    def display_two_enumerated(words, coefs):
        for c, (a, b) in enumerate(zip(words, coefs), 1):
            print(c, a, b)
        

"""TESTS
words = ["Le", "Lorem", "Ipsum", "est", "simple"]
coefs = [1.0, 2.0, 1.0, 4.0, 0.5]
enumrated_words = [(0, 'Le'), (1, 'Lorem'), (2, 'Ipsum'), (3, 'est'), (4, 'simple')]

print(Evaluator.enumerate_evaluate(words, coefs))

Evaluator.display_two_enumerated(words, coefs)
"""