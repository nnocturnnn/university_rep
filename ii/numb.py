
"""
https://habr.com/ru/company/ods/blog/335998/
https://www.youtube.com/watch?v=PHdw0Uk_Lc4&t=521s&ab_channel=Onigiri
"""
import keras
"""
Keras — открытая нейросетевая библиотека, написанная на языке Python.
Она представляет собой надстройку над фреймворками Deeplearning4j, 
TensorFlow и Theano. Нацелена на оперативную работу с сетями 
глубинного обучения, при этом спроектирована так, чтобы быть компактной, 
модульной и расширяемой. Она была создана как часть исследовательских 
усилий проекта ONEIROS (англ. Open-ended Neuro-Electronic Intelligent 
Robot Operating System), а ее основным автором и поддерживающим является 
Франсуа Шолле (фр. François Chollet), инженер Google.
"""
from keras.datasets import mnist 
"""
Набор данных MNIST
Это, наверное, один из самых популярных 
наборов данных среди энтузиастов, работающих в 
сфера машинного обучения и глубокого обучения. Он содержит 60 000 
тренировочных изображений написанных от руки цифр от 0 до 9, 
а также 10 000 картинок для тестирования. В наборе есть 10 разных
классов. Изображения с цифрами представлены в виде матриц 28 х 28, 
где каждая ячейка содержит определенный оттенок серого.
"""
from keras.models import Sequential
"""
В Keras, вы собираете слои (layers) для построения моделей (models).
Модель это (обычно) граф слоев. Наиболее распространенным видом 
модели является стек слоев: модель Sequential
"""
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras import backend as K

# скачиваем данные и разделяем на надор для обучения и тесовый
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# проверяем
print(x_train.shape, y_train.shape)

"""
Данные с изображения нельзя прямо передать в модель, поэтому сперва 
нужно выполнить определенные операции, обработав данные, чтобы нейронная
сеть с ними работала. Размерность тренировочных данных — (60000, 28, 28).
Модель сверточной нейронной сети требует одну размерность, поэтому 
потребуется перестроить форму (60000, 28, 28, 1).
"""

num_classes = 10
x_train = x_train.reshape(x_train.shape[0], 28, 28, 1) # меняем размерность
x_test = x_test.reshape(x_test.shape[0], 28, 28, 1)
input_shape = (28, 28, 1)

y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)

x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255
print('Размерность x_train:', x_train.shape)
print(x_train.shape[0], 'Размер train')
print(x_test.shape[0], 'Размер test')

"""
Следующий этап – создание модели сверточной нейронной сети. 
Она преимущественно состоит из сверточных и слоев подвыборки.
Модель лучше работает с данными, представленными в качестве 
сеточных структур. Вот почему такая сеть отлично подходит для 
задач с классификацией изображений. Слой исключения используется для 
отключения отдельных нейронов и во время тренировки. Он уменьшает 
вероятность переобучения. Затем происходит компиляция модели с 
помощью оптимизатора Adadelta.
"""

batch_size = 128
epochs = 10

model = Sequential()
model.add(Conv2D(32, kernel_size=(3, 3),activation='relu',input_shape=input_shape))
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.25))
model.add(Flatten())
model.add(Dense(256, activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(num_classes, activation='softmax'))
model.compile(loss=keras.losses.categorical_crossentropy,optimizer=keras.optimizers.Adadelta(),metrics=['accuracy'])
"""
tf.keras.Model.compile принимает три важных аргумента:
optimizer: Этот объект определяет процедуру обучения. Передайте в 
него экземпляры оптимизатора из модуля tf.keras.optimizers, 
такие как tf.keras.optimizers.Adam или tf.keras.optimizers.SGD. 
Если вы просто хотите использовать параметры по умолчанию, вы также 
можете указать оптимизаторы ключевыми словами, такими как 'adam' или 'sgd'.
loss: Это функция которая минимизируется в процессе обучения. Среди 
распространенных вариантов среднеквадратичная ошибка (mse), categorical_crossentropy,
binary_crossentropy. Функции потерь указываются по имени или 
передачей вызываемого объекта из модуля tf.keras.losses.
metrics: Используются для мониторинга обучения. Это строковые имена или 
вызываемые объекты из модуля tf.keras.metrics.
Кроме того, чтобы быть уверенным, что модель обучается и оценивается eagerly, 
проверьте что вы передали компилятору параметр run_eagerly=True
"""

hist = model.fit(x_train, y_train, batch_size = batch_size, epochs=epochs, verbose=1, validation_data=(x_test, y_test))
print("Модель успешно обучена")
model.save('mnist.h5')
print("Модель сохранена как mnist.h5")
"""
Функция model.fit() в Keras начнет тренировку модели. Она принимает
тренировочные, валидационные данные, эпохи (epoch) и размер батча (batch).
Тренировка модели занимает некоторое время. После этого 
веса и определение модели сохраняются в файле mnist.h5.
"""
score = model.evaluate(x_test, y_test, verbose=0)
print('Потери на тесте:', score[0])
print('Точность на тесте:', score[1])

"""
В наборе данных есть 10 000 изображений, которые используются для 
оценки качества работы модели. Тестовые данные не используются во 
время тренировки, поэтому являются новыми для модели. Набор MNIST 
хорошо сбалансирован, поэтому можно рассчитывать на точность около 99%.
"""