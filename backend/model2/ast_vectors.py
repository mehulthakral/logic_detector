#!/usr/bin/env python
# coding: utf-8


import ast
from tensorflow.keras.preprocessing.text import Tokenizer
import numpy as np
import csv

"""
tagged_pgm_list=[]

with open('dataset.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    print(reader)
    for r in reader:
        if r !=[]:
            # print(r,"\n\n\n")
            tagged_pgm_list.append(r)


# print(len(tagged_pgm_list))

docs = []
labels = []
for p in tagged_pgm_list:
    docs.append(p[1])
    labels.append(p[0])"""

# print(docs)
# print("\n\n\n")
# print(labels)

def _strip_docstring(body):
    first = body[0]
    if isinstance(first, ast.Expr) and isinstance(first.value, ast.Str):
        return body[1:]
    return body


def get_ast_repr(node):

    visited = set()
    queue = [[node, None, None, False]]
    output = []

    while queue:

        vertex, value, name, end = queue.pop(0)

        # OUTPUT
        output.append(get_leaf(vertex, value, name, end))

        if vertex not in visited:

            visited.add(vertex)

            if hasattr(vertex, '_fields'):

                for field_name, field_value in zip(vertex._fields,
                                                (getattr(vertex, attr) for attr in vertex._fields)):

                    if isinstance(field_value, ast.AST):
                        queue.append([field_value, field_name, vertex, False])

                    elif isinstance(field_value, list):

                        if field_name == 'body':
                            field_name = _strip_docstring(field_value)
                        for item in field_value:
                            if isinstance(item, ast.AST):
                                queue.append([item, field_name, vertex, False])
                            else:
                                queue.append([item, field_name, vertex, True])

                    else:
                        queue.append((field_value, field_name, vertex, True))

    return output


def get_leaf(node, value, parent, end):

    node_name = node.__class__.__name__
    node_name = next(node_name) if node_name is None else node_name
    if node_name == 'str':
        node_name = str(node)

    return {
        'Node': node,
        'Parent': parent,
        'Name': node_name,
        'Value': value,
        'End': end,
    }


def get_ast_pairs(tree):
    names = {}
    tuples = []
    for leaf in tree:
        # Values
        node = leaf['Node']
        node_name = leaf['Name']
        parent = leaf['Parent']
        value = leaf['Value']
        # Save name
        names[node] = node_name
        if node is None or parent is None:
            continue
        # Parent name
        parent_name = names[parent]
        # Add tuple
        tuples.append((parent_name, node_name))
    return tuples


# sample_code = docs[0]
# get_ast_pairs(get_ast_repr(ast.parse(sample_code)))


def flatten(l): return [item for sublist in l for item in sublist]


# print(flatten(get_ast_pairs(get_ast_repr(ast.parse(sample_code)))))


# print([(pair[0],pair[1]) for pair in get_ast_pairs(get_ast_repr(ast.parse(sample_code)))])

def encode_to_ast_vectors(docs, labels):

    ast_docs = []
    ast_labels = []
    i = 0
    while i < len(docs):
        doc = docs[i]
        label = labels[i]
        # print(get_ast_repr(ast.parse(doc)))
        try:
            ast_docs.append(flatten(get_ast_pairs(get_ast_repr(ast.parse(doc)))))
            # print(flatten(get_ast_pairs(get_ast_repr(ast.parse(doc)))))
            #[pair[1] for pair in get_ast_pairs(get_ast_repr(ast.parse(doc)))])
            ast_labels.append(label)
        except:
            pass
        i += 1

    print(len(docs), len(labels), len(ast_docs), len(ast_labels))



    i = 0
    for arr in ast_docs:
        ast_docs[i] = ' '.join(arr)
        i += 1
    # print(ast_docs)

    # print(ast_docs[0], "\n\n", ast_docs[1])

    NUM_WORDS = 20
    ast_t = Tokenizer(num_words=NUM_WORDS,
                    lower=False,
                    split=' ',
                    char_level=False)


    ast_t.fit_on_texts(ast_docs)


    ordered_ast_nodes = sorted(ast_t.word_counts.items(),
                            key=lambda t: (t[1], t[0]), reverse=True)
    N = 100
    for key, value in ordered_ast_nodes[:N]:
        print("%s: %s" % (key, value))


    encoded_ast_count = ast_t.texts_to_matrix(ast_docs, mode='count')
    return encoded_ast_count,ast_labels
    
""" 
rows=[]
# print(encoded_ast_count[0])


# for i in range(len(encoded_ast_count)):
#     print(encoded_ast_count[i],ast_labels[i])

with open('dataset_encoded.csv', 'w') as f:

    # using csv.writer method from CSV package
    write = csv.writer(f)

    for i in range(len(ast_labels)):
        v=np.array(encoded_ast_count[i])
        row=np.append(v, ast_labels[i])
        print(row,"\n\n")
        write.writerow(row)
        """
