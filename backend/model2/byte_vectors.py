from tensorflow.keras.preprocessing.text import Tokenizer
import csv
import numpy as np
def encode_byte_vector(byte_snip,byte_labels):
    NUM_WORDS = 30
    byte_t = Tokenizer(num_words=NUM_WORDS,
                      lower=False,
                      split=' ',
                      char_level=False)

    byte_t.fit_on_texts(byte_snip)

    ordered_ast_nodes = sorted(byte_t.word_counts.items(),
                               key=lambda t: (t[1], t[0]), reverse=True)
    N = 120
    for key, value in ordered_ast_nodes[:N]:
        print("%s: %s" % (key, value))

    encoded_byte = byte_t.texts_to_matrix(byte_snip, mode='count')
    return encoded_byte,byte_labels


import pandas as pd

df=pd.read_csv("dataset.csv")


docs=[]
labels=[]
for i in range(len(df)) : 
#   print(df.iloc[i, 0], df.iloc[i, 2]) 
  docs.append(df.iloc[i,2])
  labels.append(df.iloc[i,0])
  encoded_docs,labels=encode_byte_vector(docs,labels)
  
with open('dataset_byte_encoded.csv', 'w') as f:

        # using csv.writer method from CSV package
    write = csv.writer(f)

    for i in range(len(labels)):
        v = np.array(encoded_docs[i])
        row = np.append(v, labels[i])
        # print(row, "\n\n")
        write.writerow(row)
