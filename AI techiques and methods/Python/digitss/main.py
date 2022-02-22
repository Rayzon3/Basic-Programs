import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

mnist = tf.keras.datasets.mnist  # 28X28 images of handwritten digits form 0 to 9

(a_train, b_train), (a_test, b_test) = mnist.load_data()

a_train = tf.keras.utils.normalize(a_train, axis=1)
a_test = tf.keras.utils.normalize(a_test, axis=1)

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(128, activation=tf.nn.relu))      '''
model.add(tf.keras.layers.Dense(128, activation=tf.nn.relu))       Layers
model.add(tf.keras.layers.Dense(10, activation=tf.nn.softmax))    '''

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metric='accuracy')

model.fit(a_train, b_train, epochs=3)

model.save('num_recognizer')
num_recognizer = tf.keras.models.load_model('num_recognizer')

predictions = num_recognizer.predict(a_test)
print(np.argmax(predictions[5]))
plt.imshow(a_test[5], cmap=plt.cm.binary)
plt.show()